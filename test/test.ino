#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient ethClient;

void setup() {
  Serial.begin(115200);

  Ethernet.init(5);

  if (Ethernet.begin(MAC)) {  // Dynamic IP setup
    Serial.println("DHCP OK!");

    // Get and print the IP address
    IPAddress ip = Ethernet.localIP();
    Serial.print("My IP address: ");
    Serial.println(ip);

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
  // The loop function is left empty if you don't need to perform any repeated action.
}