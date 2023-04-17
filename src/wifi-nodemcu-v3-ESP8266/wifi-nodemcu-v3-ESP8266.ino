#include <ESP8266WiFi.h>

const char* ssid = "Eldar";
const char* password = "****";

WiFiServer server(80);

const int ledPin = 2;
int value = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(1000);
  }

  Serial.println("Wifi connected!");

  server.begin();
  Serial.println("Server started");

  Serial.print("Listening on: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();

  if (!client) {
    return;
  }

  Serial.println("Client connected");
  while (!client.available()) {
    delay(10);
  }

  String request = client.readStringUntil('r');
  Serial.println("Request:");
  Serial.println(request);
  client.flush();

  if (request.indexOf("/LED=OFF") != -1) {
    value = HIGH;
  }

  if (request.indexOf("/LED=ON") != -1) {
    value = LOW;
  }

  digitalWrite(ledPin, value);

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); 
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<body>");

  client.print("Led pin is now: ");
  client.print(value);


  client.println("<br>");
  client.println("<br>");

  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");

  // Uncomment the below for some estrada
  // client.println("<img src=\"https://static.kupindoslike.com/Seka-Aleksic-Balkan_slika_L_128560237.jpg\">");

  // client.println("<audio controls autoplay>");
  // client.println("<source src=\"http://193.68.19.127/AZBUCHNIK/S/SEKA%20ALEKSIC/02-BALKAN-2003/01%20-%20Crno%20I%20Zlatno.mp3\" type=\"audio/mp3\"");
  // client.println("</audio>");
  
  client.println("</body>");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}