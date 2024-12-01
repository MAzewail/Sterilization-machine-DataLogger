#include <SPI.h>
#include <SD.h>
#include <RTClib.h>

#define LIMIT_SWITCH_PIN 4
#define SD_CS_PIN 5
#define LED_PIN 2

RTC_DS3231 rtc;
File logFile;

bool lastSwitchState = false;
unsigned long startTime = 0;
unsigned long endTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP);
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD Card initialization failed!");
    while (1);
  }
  Serial.println("SD Card and RTC initialized successfully");
}

void logTimeToSD(DateTime time, bool isStartTime) {
  logFile = SD.open("/switch_log.txt", FILE_WRITE);
  
  if (logFile) {
    char timeStr[30];
    snprintf(timeStr, sizeof(timeStr), 
             "%s: %02d/%02d/%04d %02d:%02d:%02d\n", 
             isStartTime ? "START" : "END",
             time.day(), time.month(), time.year(), 
             time.hour(), time.minute(), time.second());
    
    logFile.print(timeStr);
    logFile.close();
    
    Serial.print(timeStr);
    
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  } else {
    Serial.println("Error opening log file");
  }
}

void calculateAndLogDuration() {
  unsigned long duration = endTime - startTime;
  
  logFile = SD.open("/switch_log.txt", FILE_WRITE);
  if (logFile) {
    char durationStr[50];
    snprintf(durationStr, sizeof(durationStr), 
             "DURATION: %lu seconds\n\n", duration / 1000);
    
    logFile.print(durationStr);
    logFile.close();
    
    Serial.print("Total Duration: ");
    Serial.print(duration / 1000);
    Serial.println(" seconds");
  }
}

void loop() {
  bool currentSwitchState = !digitalRead(LIMIT_SWITCH_PIN);
  DateTime now = rtc.now();
  if (currentSwitchState != lastSwitchState) {
    if (currentSwitchState) {
      startTime = millis();
      logTimeToSD(now, true);
    } else {
      endTime = millis();
      logTimeToSD(now, false);
      calculateAndLogDuration();
    }
    lastSwitchState = currentSwitchState;
    delay(50);
  }
}