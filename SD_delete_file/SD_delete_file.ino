/* CHANGE NAME OF FILE TO BE DELETED AS NECESSARY
  SD card basic file example

CONNECT SD SHIELD LIKE THIS:
 * SD card attached to SPI bus as follows:
 ** DI - pin 11
 ** DO - pin 12
 ** CLK - pin 13
 ** CS - pin 10

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
#include <SPI.h>
#include <SD.h>

File myFile;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");


  // Check to see if the file exists:
  if (SD.exists("test.txt")) {
    Serial.println("test.txt exists.");
  } else {
    Serial.println("test.txt doesn't exist.");
  }

  // delete the file:
  Serial.println("Removing .txt...");
  SD.remove("test.txt");

  if (SD.exists("test.txt")) {
    Serial.println(".txt exists.");
  } else {
    Serial.println(".txt doesn't exist.");
  }
}

void loop() {
  // nothing happens after setup finishes.
}
