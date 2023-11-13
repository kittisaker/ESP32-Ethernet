#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
EthernetClient ethClient;

void setup() {
  Serial.begin(115200);
  Ethernet.init(5);

  if (Ethernet.begin(MAC)) {
    Serial.println("DHCP OK!");
  } else {
    handleEthernetError();
  }
}

void loop() {
  testEthernetConnection();
  delay(10000); // Delay between tests (10 seconds)
}

void handleEthernetError() {
  Serial.println("Failed to configure Ethernet using DHCP");
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.");
    while (true) {
      delay(1); // Halt the program
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }
}

void testEthernetConnection() {
  // Try to connect to a known server (e.g., Google's public DNS server)
  if (ethClient.connect("8.8.8.8", 80)) {
    Serial.println("Connection test successful");
    ethClient.stop(); // Disconnect after the test
  } else {
    Serial.println("Connection test failed");
  }
}