//everything with the oled remains the same 
#include <MPU9250_asukiaaa.h> // added MPU library

MPU9250_asukiaaa mpu; // created MPU object

void setup() {
  Serial.begin(115200);
  Wire.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  //code remains the same as previous
  }
  
  // the display hello code was temporary and being replaced
  display.println("Booting...");
  display.display();

  // added code to check if MPU was properly wired and connected
  mpu.setWire(&Wire);
  mpu.beginAccel();
  mpu.beginGyro();
  Serial.println("MPU9250 Ready.");

  
  display.clearDisplay();
  display.print("Ready.");
  display.display();
}

void loop() {
  //code to get acceleration from the MPU 
  mpu.accelUpdate();
  mpu.gyroUpdate();

  float ax = mpu.accelX();
  float ay = mpu.accelY();
  float gx = mpu.gyroX();

  Serial.print("AX: "); Serial.print(ax);
  Serial.print(" | AY: "); Serial.print(ay);
  Serial.print(" | GX: "); Serial.println(gx);
  
  
  delay(100); //added a delay so that it's easier to read
}
