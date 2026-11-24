
# Automotive Battery Diagnostic Monitor

An ESP32-based embedded diagnostic system designed to
simulate automotive battery voltage monitoring and detect
abnormal electrical operating conditions.

## Project Overview

This project demonstrates fundamental automotive
electrical engineering and embedded systems concepts
through a simulated battery monitoring application.

The system reads an analog input, converts the ADC
reading into a simulated battery voltage, and provides
real-time diagnostic feedback through LED indicators
and serial communication.

## Simulation Preview

![Overvoltage Detection](screenshots/overvoltage.png)

Overvoltage detection demonstrated at 14.87 V.

## Technologies Used

- ESP32 Microcontroller
- Embedded C++
- Arduino Framework
- Wokwi Simulation
- Analog-to-Digital Conversion (ADC)
- GPIO Control
- Serial Communication

## System Architecture

Simulated Battery Input
        |
        v
ESP32 Analog-to-Digital Converter
        |
        v
Voltage Conversion
        |
        v
Diagnostic Evaluation
        |
        v
LED Indicators and Serial Output

## Hardware Configuration

| Component | ESP32 Pin |
|---|---|
| Potentiometer Signal | GPIO 34 |
| Green LED | GPIO 25 |
| Yellow LED | GPIO 26 |
| Red LED | GPIO 27 |
| Potentiometer Supply | 3.3 V |
| Common Ground | GND |

Each LED uses a 220-ohm current-limiting resistor.

## Diagnostic Conditions

| Voltage Range | Status | Indicator |
|---|---|---|
| Below 11.8 V | Undervoltage | Yellow |
| 11.8–14.8 V | Normal | Green |
| Above 14.8 V | Overvoltage | Red |

The diagnostic thresholds are demonstration values
rather than manufacturer-specific specifications.

## ADC Conversion

The system uses a 12-bit ADC, producing digital
readings between 0 and 4095.

Simulated battery voltage = (Raw ADC / 4095) × 16

The resulting value represents a simulated battery
voltage between 0 and 16 V.

## Engineering Challenges

During initial testing, the system correctly reported
voltage conditions while the LED indicators did not
operate as expected.

The issue was isolated using a dedicated GPIO output
test before restoring the diagnostic firmware.

This demonstrated systematic troubleshooting and
embedded hardware-software debugging.

## Verification and Validation

Testing covers normal operating voltage,
undervoltage, overvoltage, and transitions between
operating conditions.

## Future Improvements

- Persistent fault detection and diagnostic debouncing
- Diagnostic trouble code storage
- CAN bus communication
- Battery voltage data logging
- Physical prototype implementation
- Automotive voltage protection circuitry

## Project Limitations

This is a software and circuit simulation, not a
production-ready automotive battery monitoring device.
No physical vehicle battery testing was performed.

## Author

Ilyas Kady

Electrical and Computer Engineering
