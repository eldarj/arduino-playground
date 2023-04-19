#include <DHT.h>
#include <ESP8266WiFi.h>
#include <InfluxDbClient.h>
#include <InfluxDbCloud.h>

// Define DHT
#define DHT_PIN   2
#define DHT_TYPE  DHT11
DHT dht = DHT(DHT_PIN, DHT_TYPE);

// Define WiFI
const char* ssid = "Eldar";
const char* password = "********";

// Define influx client
#define INFLUXDB_URL "http://192.168.1.172:8086"
#define INFLUXDB_TOKEN "gbZGwo9g6Xi3u0z-scPY4ekkhqVkvAJSJY03duYHpvhWETI8G8pgFhgX7JrcE2YnJT2IuuuBkKux0V0RFdGUig=="
#define INFLUXDB_ORG "ping"
#define INFLUXDB_BUCKET "esp8266"

InfluxDBClient client(INFLUXDB_URL, INFLUXDB_ORG, INFLUXDB_BUCKET, INFLUXDB_TOKEN, InfluxDbCloud2CACert);
Point measurement("esp8266-dht11");

float temperature = 0.0;
float humidity = 0.0;

void setup() {
  Serial.begin(115200);

  // Connect to wifi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to wifi...");
  }

  // Start sensor listening
  dht.begin();

  // Connect to influxdb
  if (client.validateConnection()) {
      Serial.print("Connected to InfluxDB: ");
      Serial.println(client.getServerUrl());
    } else {
      Serial.print("InfluxDB connection failed: ");
      Serial.println(client.getLastErrorMessage());
    }
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  Serial.print("DHT11 Measured temperature=");
  Serial.print(temperature);
  Serial.print(", humidity=");
  Serial.println(humidity);

  measurement.clearFields();
  measurement.addField("temperature", temperature);
  measurement.addField("humidity", humidity);

  Serial.print("Sending to influxdb: ");
  Serial.println(measurement.toLineProtocol());

  // Write point
  if (!client.writePoint(measurement)) {
    Serial.println();
    Serial.print("InfluxDB write failed: ");
    Serial.println(client.getLastErrorMessage());
    Serial.println();
  }

  Serial.println();
  delay(2000);
}
