#include <Servo.h>

// Pins
const int POT_PIN = A0;    // Potentiometer input
const int SERVO_PIN = 9;   // Servo output


double Kp = 0.6;   // Proportional (how aggressively it corrects error)
double Ki = 0.2;  // Integral (eliminates small steady-state errors)
double Kd = 0.01;   // Derivative (damps oscillations)

// Servo & PID Variables
Servo myservo;
int targetAngle = 90;      // Desired angle (from potentiometer)
int currentAngle = 90;     // Actual servo position (with lag)
unsigned long lastUpdateTime = 0;
const int UPDATE_DELAY_MS = 100; // Delay to see PID correction (increase for more lag)

void setup() {
  myservo.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  // Read potentiometer (0-1023 → 0-180°)
  targetAngle = map(analogRead(POT_PIN), 0, 1023, 0, 180);

  // Only update servo position at fixed intervals (to create lag)
  if (millis() - lastUpdateTime >= UPDATE_DELAY_MS) {
    lastUpdateTime = millis();

    // Calculate error (how far servo is from target)
    double error = targetAngle - currentAngle;

    // PID terms
    static double integral = 0, lastError = 0;
    integral += error;
    double derivative = error - lastError;

    // Compute PID correction
    double correction = Kp * error + Ki * integral + Kd * derivative;

    // Apply correction (but limit step size for realism)
    currentAngle += constrain(correction, -10, 10); // Max 10° per step
    currentAngle = constrain(currentAngle, 0, 180);

    // Command servo
    myservo.write(currentAngle);

    // Update last error
    lastError = error;

    // Debugging (view in Serial Plotter: Tools → Serial Plotter)
    Serial.print("Target:"); Serial.print(targetAngle);
    Serial.print(", Current:"); Serial.print(currentAngle);
    Serial.print(", Error:"); Serial.println(error); Serial.print("\n");
  }

  delay(10); // Small delay for loop stability
}
