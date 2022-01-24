#include <M5Lite.h>

#include "Device.h"
#include "Ap.h"
#include "Server.h"

void setup() {
  M5Lite.begin();
  setupDevice();
  setupServer(!M5Lite.BtnA.isPressed());
}

void loop()
{
  loopServer();
  M5Lite.Ex.delay(1);
}
