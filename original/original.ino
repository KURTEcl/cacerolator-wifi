#include <Servo.h>

Servo motor1;
int grados1 = 0;

void setup() {
  motor1.attach(9);
}

void loop() {
  grados1 = 20;
  motor1.write(grados1);
  delay(100);

  grados1 = 0;
  motor1.write(grados1);
  delay(400);

  grados1 = 20;
  motor1.write(grados1);
  delay(100);

  grados1 = 0;
  motor1.write(grados1);
  delay(420);

  grados1 = 20;
  motor1.write(grados1);
  delay(150);

  grados1 = 0;
  motor1.write(grados1);
  delay(100);

  grados1 = 20;
  motor1.write(grados1);
  delay(150);

  grados1 = 0;
  motor1.write(grados1);
  delay(100);

  grados1 = 20;
  motor1.write(grados1);
  delay(150);

  grados1 = 0;
  motor1.write(grados1);
  delay(400);

}
