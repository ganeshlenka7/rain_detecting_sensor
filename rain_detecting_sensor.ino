int rainAnalog = A0;    // Analog pin for rain intensity
int rainDigital = 7;    // Digital pin for rain detection (0 or 1)
int ledPin = 13;        // LED / Buzzer / Relay for alert

void setup() {
  Serial.begin(9600);
  pinMode(rainAnalog, INPUT);
  pinMode(rainDigital, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.println("=================================");
  Serial.println("     Rain Sensor Initialized     ");
  Serial.println("=================================");
}

void loop() {
  int rainValue = analogRead(rainAnalog);    // Read analog value (0–1023)
  int rainStatus = digitalRead(rainDigital); // Read digital value (0 or 1)

  Serial.print("Rain Intensity (0-1023): ");
  Serial.print(rainValue);
  Serial.print(" | Digital: ");
  Serial.print(rainStatus);
  Serial.print(" | Status: ");

  if (rainStatus == LOW) {   // LOW = rain detected (depends on module)
    Serial.println("🌧️ Raining");
    digitalWrite(ledPin, HIGH);  // Turn ON LED
  } else {
    Serial.println("☀️ No Rain");
    digitalWrite(ledPin, LOW);   // Turn OFF LED
  }

  delay(500);
}
