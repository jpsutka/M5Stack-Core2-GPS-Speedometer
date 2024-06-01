// jacob_psutka
// 2024

#include <M5Core2.h>
#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

static const uint32_t GPSBaud = 9600;

// Create an instance of the TinyGPSPlus object
TinyGPSPlus gps;

// Create a HardwareSerial object for the GPS module
HardwareSerial gpsSerial(2); // Using UART2 for GPS

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 0);

  Serial.begin(115200); // For debugging

  gpsSerial.begin(GPSBaud, SERIAL_8N1, 13, 14);
  M5.Lcd.println("Waiting for GPS signal...");

  // For debugging
  Serial.println("Waiting for GPS signal...");
}

void loop() {

  // For debugging
  while (gpsSerial.available() > 0) {
    char c = gpsSerial.read();
    gps.encode(c); // Parse the GPS data
  }

  if (gps.speed.isUpdated()) {
    M5.Lcd.clear();
    M5.Lcd.setTextSize(4);
    M5.Lcd.setCursor(0, 0);

    // Set color based on speed
    if ((int)gps.speed.kmph() < 50) M5.Lcd.setTextColor(GREEN);
    if ((int)gps.speed.kmph() >= 50 && (int)gps.speed.kmph() < 80) M5.Lcd.setTextColor(YELLOW);
    if ((int)gps.speed.kmph() >= 80 && (int)gps.speed.kmph() < 110) M5.Lcd.setTextColor(ORANGE);
    if ((int)gps.speed.kmph() >= 110) M5.Lcd.setTextColor(RED);

    M5.Lcd.println((int)gps.speed.kmph());
    M5.Lcd.print(" KMPH");

    // For debugging
    Serial.println((int)gps.speed.kmph());
    Serial.println(" KMPH");
  }
}