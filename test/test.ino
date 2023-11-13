#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient ethClient;

void setup() {
  Serial.begin(115200);

  Ethernet.init(5);

  // Set a static IP address
  IPAddress ip(192, 168, 0, 177);  // Your desired IP Address
  IPAddress subnet(255, 255, 255, 0); // Subnet Mask
  IPAddress gateway(192, 168, 0, 1);  // Gateway (router) IP address
  IPAddress dns(192, 168, 0, 1);  // DNS server IP address (Google's public DNS)

  Ethernet.begin(MAC, ip, dns, gateway, subnet);

  // Print network settings
  Serial.print("IP Address: ");
  Serial.println(Ethernet.localIP());

  Serial.print("Subnet Mask: ");
  Serial.println(Ethernet.subnetMask());

  Serial.print("Gateway: ");
  Serial.println(Ethernet.gatewayIP());

  Serial.print("DNS Server: ");
  Serial.println(Ethernet.dnsServerIP());
}

void loop() {
  // The loop function is left empty if you don't need to perform any repeated action.
}
