/*
 * 
 * https://naylampmechatronics.com/blog/24_configuracion-del-modulo-bluetooth-hc-05-usa.html
 */
 
#include <SoftwareSerial.h>   // Software serial library  
SoftwareSerial BT(10,11);    // This defines the arduino pins (Rx, Tx) for communicate with the module 

/*
 * The connection must be this way
 * 
 *  ARDUINO |  HC05
 * 
 *   5V  -----  VCC
 *   Rx  -----  Tx
 *   Tx  -----  Rx
 *   GND -----  GND
 * 
 */
 
void setup()
{
  BT.begin(9600);       // Bluetooth Serial BaudRate
  Serial.begin(9600);   // SerialPort BaudRate  
}
 
void loop()
{
  if(BT.available())    // If something arrives from the BT port, is send throught the Serial Port 
  {
    Serial.write(BT.read());
  }
 
  if(Serial.available())  // If something arrives from the Serial port, is send throught the BT Port
  {
     BT.write(Serial.read());
     
  }
}
