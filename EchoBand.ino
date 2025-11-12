// all other code reamins the same, finishing touches

// match gesture pattern
String matchSequence() {
  String g1 = gestureSequence[0];
  String g2 = gestureSequence[1];
  String g3 = gestureSequence[2];

  if (g1 == "UP" && g2 == "UP" && g3 == "UP") return "HELLO";
  if (g1 == "DOWN" && g2 == "DOWN" && g3 == "DOWN") return "BYE";
  //new gestures
  if (g1 == "LEFT" && g2 == "LEFT" && g3 == "LEFT") return "THANK YOU";
  if (g1 == "RIGHT" && g2 == "RIGHT" && g3 == "RIGHT") return "SORRY";
  if (g1 == "UP" && g2 == "DOWN" && g3 == "RIGHT") return "GIG EM";
  if (g1 == "UP" && g2 == "DOWN" && g3 == "LEFT") return "HOWDY";
  if (g1 == "DOWN" && g2 == "DOWN" && g3 == "RIGHT") return "PERFECT";
  if (g1 == "DOWN" && g2 == "DOWN" && g3 == "LEFT") return "EXCUSE ME";
  if (g1 == "LEFT" && g2 == "RIGHT" && g3 == "UP") return "READY";
  if (g1 == "LEFT" && g2 == "RIGHT" && g3 == "DOWN") return "NO";
  if (g1 == "LEFT" && g2 == "DOWN" && g3 == "RIGHT") return "YES";
  
  return "UNKNOWN";
}

// ... (rest of file is identical)
