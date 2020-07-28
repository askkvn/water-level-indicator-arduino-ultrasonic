/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial //Max range 10 feet /300 cm /25 inch
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

// defines pins numbers
const int trigPin = 8;
const int echoPin = 5;

// defines variables
long duration;
int distance;

//Tank level limits
//Enter Tank Total Height
int totalHeight = 117; //in cm

//Tank level indicator  //2 4 6 9 11 12 
int empty = 11; //RED LED
int low = 9; //RED LED
int lowerMiddle = 6; //RED LED
int middle = 4; //GREEN LED
int upperMiddle = 2; //GREEN LED
int full = 12; //BUZZER


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(empty, OUTPUT); // Sets the Pin as an Output //RED LED
pinMode(low, OUTPUT); // Sets the Pin as an Output //RED LED
pinMode(lowerMiddle, OUTPUT); // Sets the Pin as an Output //RED LED
pinMode(middle, OUTPUT); // Sets the Pin as an Output //GREEN LED
pinMode(upperMiddle, OUTPUT); // Sets the Pin as an Output //GREEN LED
pinMode(full, OUTPUT); // Sets the Pin as an Output //BUZZER

Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

//giving 22cm offset (distance between sensor and tank full level)
distance= distance - 22.0;

// Prints the distance on the Serial Monitor
Serial.print("Distance(cm): ");
Serial.println(distance);
delay(2000);

if ((distance  > (int((totalHeight*90)/100)))){
  Serial.println("Tank is empty (0%)");
  digitalWrite(empty, HIGH);
  digitalWrite(low, LOW);
  digitalWrite(lowerMiddle, LOW);
  digitalWrite(middle, LOW);
  digitalWrite(upperMiddle, LOW);
  digitalWrite(full, LOW);
}
else if((distance  > (int((totalHeight*70)/100))) and (distance  <= (int((totalHeight*90)/100)))){
  Serial.println("20%");
  digitalWrite(empty, HIGH);
  digitalWrite(low, HIGH);
    digitalWrite(lowerMiddle, LOW);
  digitalWrite(middle, LOW);
  digitalWrite(upperMiddle, LOW);
  digitalWrite(full, LOW);
  
}
else if((distance  > (int((totalHeight*50)/100))) and (distance  <= (int((totalHeight*70)/100)))){
  Serial.println("40%");
  digitalWrite(empty, HIGH);
  digitalWrite(low, HIGH);
  digitalWrite(lowerMiddle, HIGH);
  digitalWrite(middle, LOW);
  digitalWrite(upperMiddle, LOW);
  digitalWrite(full, LOW);
}
else if((distance  > (int((totalHeight*30)/100))) and (distance  <= (int((totalHeight*50)/100)))){
  Serial.println("60%");
  digitalWrite(empty, HIGH);
  digitalWrite(low, HIGH);
  digitalWrite(lowerMiddle, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperMiddle, LOW);
  digitalWrite(full, LOW);
}
else if((distance  > (int((totalHeight*10)/100))) and (distance  <= (int((totalHeight*30)/100)))){
  Serial.println("80%");
  digitalWrite(empty, HIGH);
  digitalWrite(low, HIGH);
  digitalWrite(lowerMiddle, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperMiddle, HIGH);
  digitalWrite(full, LOW);
}
else if(distance <= (int((totalHeight*10)/100))){
  Serial.println("100%");
  digitalWrite(empty, HIGH);
  digitalWrite(low, HIGH);
  digitalWrite(lowerMiddle, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperMiddle, HIGH);
  digitalWrite(full, HIGH);
}
else{
  Serial.println("!!!Number is out bound!!!");
}

}
