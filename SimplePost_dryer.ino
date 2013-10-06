#include <SPI.h> // needed in Arduino 0019 or later
#include <Ethernet.h>
#include <Twitter.h>

// The includion of EthernetDNS is not needed in Arduino IDE 1.0 or later.
// Please uncomment below in Arduino IDE 0022 or earlier.
//#include <EthernetDNS.h>


// Ethernet Shield Settings
byte mac[] = { 0x00, 0x06, 0x66, 0x50, 0xA4, 0x93 };

// If you don't specify the IP address, DHCP is used(only in Arduino 1.0 or later).
byte ip[] = { 192, 168, 1, 115};

// Your Token to Tweet (get it from http://arduino-tweet.appspot.com/)
Twitter twitter("1834798862-GGokRsEaLYVl0esO0LqRx6Jifv8Hj9qsagmLOKL");

// Message to post
char msg[] = "Hello, World! I'm Arduino!";

void setup()
{
  delay(1000);
  // Ethernet.begin(mac, ip);
  // or you can use DHCP for autoomatic IP address configuration.
  Ethernet.begin(mac);
  Serial.begin(115200);
  
  Serial.println("connecting ...");
  if (twitter.post(msg)) {
    // Specify &Serial to output received response to Serial.
    // If no output is required, you can just omit the argument, e.g.
    // int status = twitter.wait();
    int status = twitter.wait(&Serial);
    if (status == 200) {
      Serial.println("OK.");
    } else {
      Serial.print("failed : code ");
      Serial.println(status);
    }
  } else {
    Serial.println("connection failed.");
  }
}

void loop()
{
}
