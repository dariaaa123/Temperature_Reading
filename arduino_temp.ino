#include <DHT.h>
#define DHTPIN 7      // Pin connected to the DHT sensor
#define DHTTYPE DHT11
#define RELAY_PIN 22   // Pin connected to the fan relay

DHT dht(DHTPIN, DHTTYPE);
float temperature;

void setup() {
  Serial.begin(9600);
  dht.begin(); 
  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, LOW);  // Ensure the fan is off initially
}

void loop() {
  temperature = dht.readTemperature();  // Read temperature
  if (isnan(temperature)) {
    Serial.println("Error reading temperature");
  } else {
    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" °C");

    if (temperature > 24.0) {
      digitalWrite(RELAY_PIN, LOW);  
      Serial.println("Fan ON");
    } else {
      digitalWrite(RELAY_PIN, HIGH); 
      Serial.println("Fan OFF");
    }
  }

  delay(5000);  // Wait 5 seconds before the next reading
}
