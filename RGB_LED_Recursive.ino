//www.elegoo.com
//2016.12.8

// Define Pins and rgb values
int redValue = 255; 
int greenValue = 0;
int blueValue = 0;
static int currentPin = 6; // these pins represent the pwm pins on the arduino where you connect the led red, green and blue to. 
static int nextPin = 5;     // e.g. red lead is conneceted to pin 6, green lead connected to 5, blue lead is connected to pin 3
static int inWaitingPin = 3;
void setup()
{
pinMode(currentPin, OUTPUT); // initializing pins
pinMode(nextPin, OUTPUT);
pinMode(inWaitingPin, OUTPUT);
digitalWrite(currentPin, HIGH);
digitalWrite(nextPin, LOW);
digitalWrite(inWaitingPin, LOW);
}

// main loop
void loop(){
  Recursion(redValue, greenValue, blueValue, currentPin, nextPin, inWaitingPin); // calls the recursion algorithim and passes values. 
  
}
 void Recursion(int current, int next, int inWaiting, int currentPin, int nextPin, int inWaitingPin)
 {

    #define delayTime 10 // fading time between colors
  current = 255;
  next = 0;
  inWaiting = 0;
  for(int i = 0; i < 255; i += 1) // fades out current brings next in full when i=255
  {
  current -= 1;
  next += 1;
  analogWrite(currentPin, current); // sends the color values and pin number
  analogWrite(nextPin, next);
  delay(delayTime);
}
   Recursion(next, inWaiting, current, nextPin, inWaitingPin, currentPin); // recursive call switching inputs after current fades out and
                                                                           // and next comes in. 
}

