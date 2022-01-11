// Use a sample android application to connect the esp32 via Bluetooth and fetch any values from the app to print on the serial terminal.
// For mobile I am using Serial Bluetooth Terminal app.

#include <BluetoothSerial.h>

//if makefile didnt created.
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("MYESP32");
}
void loop() {
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(100);
}
