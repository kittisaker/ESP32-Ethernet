#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient ethClient;

void setup() {
  Serial.begin(115200);

  Ethernet.init(5);

  if (Ethernet.begin(MAC)) {  // Dynamic IP setup
    Serial.println("DHCP OK!");
  } else {
    Serial.println("Failed to configure Ethernet using DHCP");

    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);
      }
    }

    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
  }
}

void loop() {
  // Check Ethernet connection status
  checkEthernetStatus();
  delay(10000); // Delay between checks (10 seconds)
}

void checkEthernetStatus() {
  switch (Ethernet.linkStatus()) {
    case LinkON:
      Serial.println("Ethernet cable is connected.");
      break;
    case LinkOFF:
      Serial.println("Ethernet cable is not connected.");
      break;
    default:
      Serial.println("Unknown Ethernet status.");
      break;
  }
}