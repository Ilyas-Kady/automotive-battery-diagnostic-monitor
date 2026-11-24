
const int BATTERY_PIN = 34;
const int GREEN_LED = 25;
const int YELLOW_LED = 26;
const int RED_LED = 27;

const float LOW_THRESHOLD = 11.8;
const float HIGH_THRESHOLD = 14.8;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);

  pinMode(BATTERY_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  int rawADC = analogRead(BATTERY_PIN);

  float batteryVoltage = (rawADC / 4095.0) * 16.0;

  // Turn all LEDs off before evaluating voltage
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage, 2);
  Serial.print(" V | Status: ");

  if (batteryVoltage < LOW_THRESHOLD) {
    digitalWrite(YELLOW_LED, HIGH);
    Serial.println("UNDERVOLTAGE");
  }
  else if (batteryVoltage > HIGH_THRESHOLD) {
    digitalWrite(RED_LED, HIGH);
    Serial.println("OVERVOLTAGE");
  }
  else {
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("NORMAL");
  }

  delay(500);
}
