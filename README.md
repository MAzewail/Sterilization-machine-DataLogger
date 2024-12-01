# ESP32 Limit Switch Time Logger

## Overview

This project is an ESP32-based time logging system that records the start and end times of a limit switch's activation using an RTC (Real-Time Clock) module and logs the data to an SD card. It's designed to track the duration and precise timing of switch events.

## Features

- Real-time logging of limit switch activation and deactivation
- Precise time tracking using DS3231 RTC module
- Data storage on SD card
- Serial monitor debugging
- LED status indicator

## Hardware Requirements

- ESP32 Development Board
- DS3231 RTC Module
- SD Card Module
- Limit Switch
- Micro SD Card

### Pin Connections

| Component   | ESP32 Pin |
|-------------|-----------|
| RTC SDA     | GPIO 21   |
| RTC SCL     | GPIO 22   |
| SD CS       | GPIO 5    |
| SD MOSI     | GPIO 23   |
| SD MISO     | GPIO 19   |
| SD SCK      | GPIO 18   |
| Limit Switch| GPIO 4    |
| Status LED  | GPIO 2    |

## Library Dependencies

- Arduino SPI Library
- SD Card Library
- RTClib by Adafruit

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/[YourUsername]/esp32-limit-switch-logger.git
   ```

2. Open the Arduino IDE

3. Install required libraries:
   - Install RTClib from Arduino Library Manager
   - Ensure SD library is available (typically pre-installed)

4. Connect hardware as specified in pin connections

5. Upload the code to your ESP32

## Usage

- The system automatically logs when the limit switch is activated and released
- Logs are stored in `/switch_log.txt` on the SD card
- Each log entry includes:
  - Timestamp of switch activation
  - Timestamp of switch release
  - Total duration of activation

## Log File Format

```
START: DD/MM/YYYY HH:MM:SS
END: DD/MM/YYYY HH:MM:SS
DURATION: X seconds
```

## Troubleshooting

- Ensure all libraries are correctly installed
- Double-check hardware connections
- Verify SD card is formatted and inserted correctly
- Check serial monitor for debug information

## Customization

- Modify `LIMIT_SWITCH_PIN`, `SD_CS_PIN` to match your specific hardware setup
- Adjust debounce delay if needed

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Contact

Your Name - Mohamed Salem

Project Link: [https://github.com/MAzewail/esp32-limit-switch-logger](https://github.com/MAzewail/Sterilization-machine-DataLogger)

## Acknowledgments

- [Arduino](https://www.arduino.cc/)
- [Espressif Systems](https://www.espressif.com/)
- [Adafruit RTClib](https://github.com/adafruit/RTClib)
