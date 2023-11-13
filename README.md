# ESP32-Ethernet : Chapter 5 Set an Ethernet Static IP address

## Tested by KOPE

### Before :
```cpp
#include <SPI.h>
#include <Ethernet.h>

byte MAC[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

EthernetClient ethClient;

void setup() {
  Serial.begin(115200);

  Ethernet.init(5);

  if (Ethernet.begin(MAC)) {  // Dynamic IP setup
    Serial.println("DHCP OK!");

    Serial.print("Local IP : ");
    Serial.println(Ethernet.localIP());
    Serial.print("Subnet Mask : ");
    Serial.println(Ethernet.subnetMask());
    Serial.print("Gateway IP : ");
    Serial.println(Ethernet.gatewayIP());
    Serial.print("DNS Server : ");
    Serial.println(Ethernet.dnsServerIP());

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
```

Serial Monitor :
```shell
DHCP OK!
Local IP : 192.168.0.101
Subnet Mask : 255.255.255.0
Gateway IP : 192.168.0.1
DNS Server : 192.168.0.1
```

### After :
```cpp
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
```

Serial Monitor :
```shell
IP Address: 192.168.0.177
Subnet Mask: 255.255.255.0
Gateway: 192.168.0.1
DNS Server: 192.168.0.1
```

---