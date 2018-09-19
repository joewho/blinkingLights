int buttonPush = 0;
String normalState = "normal";
String panicState = "panic";
String currentState = normalState;
int counter =0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void blinking(){
  Serial.println("blinking");
  Serial.println(counter);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH); 

    delay(250);
    //toggle leds
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(250);
  if(counter == 10){
      Serial.println("counter is 10, reset");
      counter =0;
  }
}

void normal(){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
}  

void switchState(){
  Serial.println("switchState NOW");
  if(currentState == normalState){
    currentState = panicState;
    return;
  }else{
    currentState = normalState;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonPush = digitalRead(2);
  

 if(buttonPush == 0){
    if(counter == 0){
      normal();
      return;
   // }else{
      blinking();
    }
  }else{//buttton pushed
    counter++;
    blinking();
  }
}
