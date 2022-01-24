#include <WiFi.h>

#define APSSID      "WebSDav"
#define APPSK       "#WebSDav#"
#define STASSID     "********"
#define STAPSK      "********"
#define HOSTNAME    "WebSDav"

void setupSTA() {
  WiFi.persistent(true);
  WiFi.setHostname(HOSTNAME);
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  WiFi.begin(STASSID, STAPSK);
  Serial.println("Connecting to " STASSID " ...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to "); Serial.println(STASSID);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
  Serial.print("RSSI: "); Serial.println(WiFi.RSSI());
}

void setupAP() {
  IPAddress ip(192, 168, 4,  1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.softAPConfig(ip, ip, subnet);
  WiFi.softAP(APSSID, APPSK);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("Connected to "); Serial.println(APSSID);
  Serial.print("IP address: "); Serial.println(myIP);
}
