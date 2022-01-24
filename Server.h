#include <WiFi.h>
#include <ESPmDNS.h>
#include <ESPWebDAV.h>

#define SERVER_STA  0
#define SERVER_AP   1

FS& gfs = SD;

// WiFiServerSecure tcp(443);
WiFiServer tcp(80);

ESPWebDAV dav;

void setupServer(uint16_t kind) {
  if (kind) setupSTA();
  else      setupAP();
  MDNS.begin(HOSTNAME);
  tcp.begin();
  dav.begin(&tcp, &gfs);
  dav.setTransferStatusCallback([](const char* name, int percent, bool receive) {
    Serial.printf("%s: '%s': %d%%\n", receive ? "recv" : "send", name, percent);
  });
  Serial.print(HOSTNAME);
  Serial.println(" Server Started");
}

void loopServer()
{
  dav.handleClient();
}
