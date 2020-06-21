const int ledCount = 9;    // the number of LEDs in the bar graph 
 
// an array of pin numbers to which LEDs are attached
int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9,10 }; 

int RefreshTime = 6;
int BarLenght = 0;
int BuzzSpeed = 0;
int BuzzLen = 0;
int BuzzDelay = 50;

// defines --Ultrasonic-- pins numbers
const int trigPin = 12;
const int echoPin = 13;
// defines --Ultrasonic--  variables
long duration;
int distance;

////////////////////////////
void setup() {
   // loop over the pin array and set them all to output:   
   for (int i = 0; i < ledCount; i++) {
   pinMode(ledPins[i], OUTPUT);
   pinMode(11, OUTPUT);  
   }
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication
}
//////////////////////////////
 
void loop() {
  GetDistance();
    if (distance > 0 and distance <= 18){
      BarLenght = 9;
      BuzzLen   = 1;
      }
    if (distance > 18 and distance <= 36){
      BarLenght = 8;
      BuzzLen   = 1;
      }
    if (distance > 36 and distance <= 54){
      BarLenght = 7;
      BuzzLen   = 2;
      }
    if (distance > 54 and distance <= 72){
      BarLenght = 6;
      BuzzLen   = 2;
      }
    if (distance > 72 and distance <= 90){
      BarLenght = 5;
      BuzzLen   = 3;
      }
    if (distance > 90 and distance <= 108){
      BarLenght = 4;
      BuzzLen   = 3;
      }
    if (distance > 108 and distance <= 144){
      BarLenght = 3;
      BuzzLen   = 4;
      }
    if (distance > 144 and distance <= 162){
      BarLenght = 2;
      BuzzLen   = 4;
      }
    if (distance > 162) {
      BarLenght = 1;
      BuzzLen   = 5;
      }
    
  ShineBar(BarLenght);
  Buzz(BuzzLen);
  CleanBar(BarLenght);
}

//////////////////////////////
// -----------------
// --- Functions ---
// -----------------
   void Buzz(int BuzzLen){
    for (int z = 0; z < 2; z++){
      Serial.println(BuzzLen);
      digitalWrite(11, LOW);
      delay(BuzzLen*(BuzzDelay));
      digitalWrite(11, HIGH);
      delay(BuzzLen*(BuzzDelay));
    }
  }
 
 
  void ShineBar(int ledki) {
    for (int j = 0; j < ledki; j++){
      digitalWrite(ledPins[j], HIGH);
    }
  }
  
  void CleanBar(int ledki) {
    for (int j = 0; j < ledki; j++){
      digitalWrite(ledPins[j], LOW);
    }
  }
  void GetDistance(){
    //--Ultrasonic-- Clears the trigPin
      digitalWrite(trigPin, LOW);
      delay(2);
    //--Ultrasonic-- Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delay(10);
      digitalWrite(trigPin, LOW);
    //--Ultrasonic-- Reads the echoPin, returns the sound wave travel time in microseconds
      duration = pulseIn(echoPin, HIGH);
    //--Ultrasonic-- Calculating the distance
      distance = duration*0.034/2;
    //--Ultrasonic-- Prints the distance on the Serial Monitor
      Serial.print("Distance: ");
      Serial.println(distance);
  }
