# PID-Servo-controller---Embedded-Systems-
This project demonstrates a basic implementation of a PID (Proportional-Integral-Derivative) control system using an Arduino, a servo motor, and a potentiometer. The servo motor smoothly follows the target angle set by the potentiometer using a PID loop for accurate and stable control.


# PID Servo Control with Arduino

![PID Control System]( https://images.app.goo.gl/N2gXBtLk7rZroady7 ) 
*Example: PID control system visualization*

## 📝 Description
This project demonstrates a PID (Proportional-Integral-Derivative) control system using:
- Arduino microcontroller
- Servo motor
- Potentiometer as input

The system reads target positions from a potentiometer and uses PID control to smoothly move the servo, simulating real-world mechanical systems with inertia.

## 🛠 Hardware Components
| Component | Quantity |
|-----------|----------|
| Arduino Board (Uno/Nano) | 1 |
| Servo Motor (180°) | 1 |
| 10kΩ Potentiometer | 1 |
| Breadboard | 1 |
| Jumper Wires | 5-7 |
| 5V Power Source | 1 |

## 🔌 Wiring Diagram
Potentiometer:
   Left pin  → 5V
   Right pin → GND
   Middle pin → A0

Servo Motor:
   Brown/Black → GND
   Red → 5V
   Orange/Yellow → Pin 9


## 🔌 PID Tuning Parameter

// Default PID values (adjust as needed)
double Kp = 0.6;  // Proportional gain
double Ki = 0.2;  // Integral gain
double Kd = 0.01; // Derivative gain

## 🔌 Serial output

Target:[value], Current:[value], Error:[value]
 make this more detailed
