const int buttonPin = 2;
const int ledPin = 3;

int ledState = HIGH;
int buttonState;
int lastButtonState = LOW;
int buttonPushCounter = 0;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);

  if(reading != lastButtonState){
    lastDebounceTime = millis();
  }

  if((millis() - lastDebounceTime) > debounceDelay){
    if(reading != buttonState){
      buttonState = reading;

      if(buttonState == HIGH){
        //ledState = !ledState;
        buttonPushCounter++;
        Serial.println("on");
        Serial.print("number of button pushes: ");
        Serial.println(buttonPushCounter);
      }else{
        Serial.println("off");
      
      }
    }
     // lastButtonState = buttonState;

  if(buttonPushCounter % 3 == 0){
    digitalWrite(ledPin,HIGH);
    }else{
    digitalWrite(ledPin,LOW);
  }
  }
  //digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
