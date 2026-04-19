

const int RED_PIN = 5;  
const int GREEN_PIN = 6;
const int BLUE_PIN = 3; 


const int SENSOR_PIN = A0;

const int GOOD_THRESHOLD = 300;
const int BAD_THRESHOLD = 600; 



void setup() {

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  

  Serial.begin(9600);
  
  
  turnOffAllLEDs();
  
  delay(1000);
}


void loop() {

  int sensorValue = analogRead(SENSOR_PIN);
  
  
  Serial.print("Air Quality Value: ");
  Serial.println(sensorValue);
  
  
  if (sensorValue < GOOD_THRESHOLD) {
  
    showGreen();
    Serial.println("Status: GOOD AIR QUALITY (Green)");
  } 
  else if (sensorValue < BAD_THRESHOLD) {
  
    showBlue();
    Serial.println("Status: MODERATE AIR QUALITY (Blue)");
  } 
  else {
  
    showRed();
    Serial.println("Status: BAD AIR QUALITY (Red)");
  }
  
  delay(1000);
}


void turnOffAllLEDs() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void showRed() {
  turnOffAllLEDs();
  digitalWrite(RED_PIN, HIGH);
}

void showGreen() {
  turnOffAllLEDs();
  digitalWrite(GREEN_PIN, HIGH);
}

void showBlue() {
  turnOffAllLEDs();
  digitalWrite(BLUE_PIN, HIGH);
}
