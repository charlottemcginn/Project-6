 /*
 *  UCLA IEEE OPS 2015-16 Project 6
 *  Charlotte McGinn
 */

#define rightSensor 20
#define leftSensor 19

#define rightLED 3
#define leftLED 6

int rightBaseline = 0;
int leftBaseline = 0;

int rightSensorReading = 0;
int leftSensorReading = 0;

int rightLEDintensity = 0;
int leftLEDintensity = 0;

void setup() {
  Serial.begin(9600);

  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);

  pinMode(rightLED, OUTPUT);
  pinMode(leftLED, OUTPUT);

  // get the readings of the ambient light for right and left sensors
  for (int i = 0; i < 200; i++)
  {
    rightBaseline += analogRead(rightSensor);
    leftBaseline += analogRead(leftSensor);
  }

  // take the average of the readings to get a baseline
  rightBaseline /= 200;
  leftBaseline /= 200;

}

void loop() {
  
  rightSensorReading = analogRead(rightSensor);  // read right sensor value
  leftSensorReading = analogRead(leftSensor);    // read left sensor value

  rightLEDintensity = map (rightSensorReading, 0, rightBaseline, 0, 255);
  leftLEDintensity = map (leftSensorReading, 0, leftBaseline, 0, 255);

  analogWrite(rightLED, rightLEDintensity);
  analogWrite(leftLED, leftLEDintensity);

  Serial.print("Right sensor: ");
  Serial.println(rightSensorReading);

  Serial.print("Left sensor: ");
  Serial.println(leftSensorReading);
  Serial.println();

  delay(1000);
}
