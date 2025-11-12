// includes and defines remain
// mpu and display objects remain

unsigned long lastGestureTime = 0;
//needed to make it more stable
unsigned long lastMotionTime = 0; 

// added calibration offsets - got these by leaving the MPU completely still for a couple seconds
float accelOffsetX = 0.0708;
float accelOffsetY = -0.0013;
float accelOffsetZ = -1.0221;
float gyroOffsetX = 1.6801;
float gyroOffsetY = -1.4891;
float gyroOffsetZ = -0.1652;


void loop() {
  mpu.accelUpdate();
  mpu.gyroUpdate();

  // removed difference from calibration
  float ax = mpu.accelX() - accelOffsetX;
  float ay = mpu.accelY() - accelOffsetY;
  float az = mpu.accelZ() - accelOffsetZ;

  float gx = mpu.gyroX() - gyroOffsetX;
  float gy = mpu.gyroY() - gyroOffsetY;
  float gz = mpu.gyroZ() - gyroOffsetZ;


  String gesture = detectGesture(ax, ay, az, gx, gy, gz);
  //everything stays
}

// detectGesture and showReady remain
