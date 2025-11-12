// both mpu and oled initialization code remains
//threshold to detect motion
#define MOTION_THRESHOLD 0.7 
//records milliseconds
unsigned long lastGestureTime = 0; 
//time inbetween movements
#define DEBOUNCE_DELAY 300


void setup() {
  // everything remains the same, just removed the Serial.print lines
}

// MPU detects movement using threshold
String detectGesture(float ax, float ay, float az, float gx, float gy, float gz) {
  if (abs(ax) > MOTION_THRESHOLD && ax > 0.6) return "UP";
  if (abs(ax) > MOTION_THRESHOLD && ax < -0.6) return "DOWN";
  if (abs(ay) > MOTION_THRESHOLD && ay > 0.6) return "LEFT";
  if (abs(ay) > MOTION_THRESHOLD && ay < -0.6) return "RIGHT";
  return "";
}

//method for the user to know when the product is ready to use (displays on OLED)
void showReady() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(30, 25);
  display.print("Ready...");
  display.display();
}


void loop() {
  //remains the same
  mpu.accelUpdate();
  mpu.gyroUpdate();

  float ax = mpu.accelX();
  float ay = mpu.accelY();
  float az = mpu.accelZ();
  float gx = mpu.gyroX();
  float gy = mpu.gyroY();
  float gz = mpu.gyroZ();

  // replaced the Serial.print
  String gesture = detectGesture(ax, ay, az, gx, gy, gz);
  unsigned long now = millis();

  if (gesture != "" && now - lastGestureTime > DEBOUNCE_DELAY) {
    lastGestureTime = now;
    
    // show gesture on OLED
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(25, 20);
    display.print(gesture);
    display.display();
    
    delay(500); // Hold gesture on screen
    showReady();
  }
  
  delay(10);
}
