//MOST AMOUNT OF CHANGES HAPPENED HERE

// all objects, defines, remains, and includes remain
//how long a word is displayed after gestures 
#define WORD_DISPLAY_TIME 2000 

unsigned long lastMotionTime = 0;
//if the object isn't in use for 3 seconds, it times out and is ready for the next gesture
#define SEQUENCE_TIMEOUT 3000
//store 3 gestures
String gestureSequence[3];
int gestureCount = 0;


void loop() {
  //setup and sensors remain

  String gesture = detectGesture(ax, ay, az, gx, gy, gz);
  unsigned long now = millis();

  //3 seconds time out for each combination 
  if (gestureCount > 0 && (now - lastMotionTime > SEQUENCE_TIMEOUT)) {
    Serial.println("Sequence timed out — resetting.");
    resetSequence();
  }
 

  if (gesture != "" && now - lastGestureTime > DEBOUNCE_DELAY) {
    lastGestureTime = now;
    lastMotionTime = now; // <-- ADDED
    // recordGesture(gesture); // <-- This replaces the old loop logic
    // --- REPLACED loop logic with function call ---
    recordGesture(gesture);
  }

  delay(10);
}

//detection remains

//THESE ARE ALL NEW FUNCTIONS

//count gestures 
void recordGesture(String gesture) {
  if (gestureCount < 3) {
    gestureSequence[gestureCount] = gesture;
    gestureCount++;
    showGesture(gesture);
    Serial.println("Gesture: " + gesture);
  }

  //print combination
  if (gestureCount == 3) {
    String word = matchSequence();
    Serial.println("Word: " + word);
    showWord(word);
    delay(WORD_DISPLAY_TIME);
    resetSequence();
  }
}

//gathers information and matches it with a phrase/word
String matchSequence() {
  String g1 = gestureSequence[0];
  String g2 = gestureSequence[1];
  String g3 = gestureSequence[2];

  if (g1 == "UP" && g2 == "UP" && g3 == "UP") return "HELLO";
  if (g1 == "DOWN" && g2 == "DOWN" && g3 == "DOWN") return "BYE";
  // (add more later)
  
  return "UNKNOWN"; //if combination isn't recognized 
}

//display gesture on OLED
void showGesture(String gesture) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(25, 20);
  display.print(gesture);
  display.display();
}

//display WORD on OLED (3 gestures = 1 phrase/word)
void showWord(String word) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 20);
  display.print(word);
  display.display();
}

//if we time out/getting ready for new set of combinations
void resetSequence() {
  gestureCount = 0;
  for (int i = 0; i < 3; i++) gestureSequence[i] = "";
  lastMotionTime = millis();
  showReady();
}


//everything else remains
