# PID Servo Controller - Embedded Systems Project

## Table of Contents
- [Project Description](#project-description)
- [Hardware Setup](#hardware-setup)
- [Software Implementation](#software-implementation)
- [PID Tuning Guide](#pid-tuning-guide)
- [Operation](#operation)
- [Troubleshooting](#troubleshooting)
- [Extensions](#extensions)
- [License](#license)

## Project Description
This project implements a PID control system using an Arduino to precisely position a servo motor based on potentiometer input. The system demonstrates closed-loop feedback control with adjustable parameters for educational and practical applications.

**Key Features:**
- Real-time position control with feedback
- Configurable PID constants (Kp, Ki, Kd)
- Simulated mechanical response (100ms update delay)
- Safety-limited movement (10° max per step)
- Detailed serial output for monitoring

## Hardware Setup
### Components Required
| Component | Specifications | Qty |
|-----------|---------------|-----|
| Arduino Board | Uno/Nano | 1 |
| Servo Motor | SG90 (180°) | 1 |
| Potentiometer | 10kΩ linear | 1 |
| Breadboard | 400+ points | 1 |
| Jumper Wires | Male-to-male | 5-7 |

### Wiring Diagram
[POTENTIOMETER]
Left → 5V
Right → GND
Middle → A0

[SERVO]
Brown → GND
Red → 5V
Orange → Pin 9


**Power Notes:**
- Use external 5V supply if servo draws >500mA
- Add 100μF capacitor near servo for stability

## Default Parameters
double Kp = 0.6;   // Proportional gain
double Ki = 0.2;   // Integral gain
double Kd = 0.01;  // Derivative gain
const int UPDATE_DELAY_MS = 100;  // Control loop period
const int MAX_STEP = 10;          // Max degrees/update
