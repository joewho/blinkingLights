const int interval = 500;
unsigned long currentMillis = millis();
unsigned long previousMillis = 0;

const int buttonPin = 2;
const int ledPin = 3;

int ledState = LOW;
int buttonState;
int lastButtonState = LOW;
int buttonPushCounter = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

boolean alarmState = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
  Serial.println("Ready...");
}

void setLights(){
  if(!alarmState){
    digitalWrite(ledPin,HIGH);
  }
  else blinkLights();
}

void blinkLights(){
  digitalWrite(ledPin,HIGH);
//  digitalWrite(4,LOW);
//  digitalWrite(5,HIGH);
  delay(interval);
  digitalWrite(ledPin,LOW);
//  digitalWrite(4,HIGH);
//  digitalWrite(5,LOW);
  delay(interval);  
}

void smartDelay(int timeDelay){
  currentMillis = millis();
  while(currentMillis - previousMillis < timeDelay){
    
    currentMillis = millis();
  }
  previousMillis = currentMillis;
  return;
}

/*variables - int - value of digitalRead of button
 * objectives - determine when a button has been pushed using state changes
 * - use button Debounce methods to remove noise of button push
 * return - boolean - true if button has changed state from off or on
 */
boolean buttonPushed(int reading){
    if(reading != lastButtonState){
      lastDebounceTime = millis();
      Serial.println("button action");
    }

    if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonState){
      buttonState = reading;
      Serial.println("reading != state");
      if(buttonState == HIGH){
        return true;
      }
    }
  }
  return false;
}
void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);
   
  //button has successfully been pushed
  if(buttonPushed(reading)){
    alarmState = !alarmState;
    Serial.println("alarmState: "+String(alarmState));
  
/*    buttonPushCounter++;
     Serial.println("on");
     Serial.print("number of button pushes: ");
     Serial.println(buttonPushCounter);
*/
  }
/*  if(buttonPushCounter % 3 == 0){
    digitalWrite(ledPin,HIGH);
    }else{
    digitalWrite(ledPin,LOW);
    Serial.println("off");

  }
  */
  if(alarmState){
      // check to see if it's time to change the state of the LED
      unsigned long currentMillis = millis();
     
      if((ledState == HIGH) && (currentMillis - previousMillis >= interval))
      {
        ledState = LOW;  // Turn it off
        previousMillis = currentMillis;  // Remember the time
        digitalWrite(ledPin, ledState);  // Update the actual LED
      }
      else if ((ledState == LOW) && (currentMillis - previousMillis >= interval))
      {
        ledState = HIGH;  // turn it on
        previousMillis = currentMillis;   // Remember the time
        digitalWrite(ledPin, ledState);    // Update the actual LED
      }
  }else{
        digitalWrite(ledPin,HIGH);

  }
  lastButtonState = reading;
}
