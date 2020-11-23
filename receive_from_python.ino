String readString;

int pin_R1 = 12;
int pin_R2 = 11;
int pin_R3 = 10;
int pin_R4 = 9;
int pin_R5 = 8;
int pin_Y1 = 7;
int pin_Y2 = 6;
int pin_Y3 = 5;
int pin_Y4 = 4;
int pin_Y5 = 3;
long dir = 1;
// 0 is left, 1 is right


void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);  

  pinMode(pin_R1, OUTPUT);
  pinMode(pin_R2, OUTPUT);
  pinMode(pin_R3, OUTPUT);
  pinMode(pin_R4, OUTPUT);
  pinMode(pin_R5, OUTPUT);
  pinMode(pin_Y1, OUTPUT);
  pinMode(pin_Y2, OUTPUT);
  pinMode(pin_Y3, OUTPUT);
  pinMode(pin_Y4, OUTPUT);
  pinMode(pin_Y5, OUTPUT);

}

void loop()
{
  while (!Serial.available()) {} // wait for data to arrive
  // serial read section
  while (Serial.available())
  {
    delay(30);  //delay to allow buffer to fill 
    if (Serial.available() >0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString = c; //makes the string readString        
    }
   
  }
    if (readString.length() >0)
  {
    Serial.print("Arduino received: ");  
    Serial.println(readString); //see what was received
    if (readString == "1"){
        Serial.println("1 is right!");
        digitalWrite(pin_Y1, HIGH);
        digitalWrite(pin_Y2, HIGH);
        digitalWrite(pin_Y3, HIGH);
        digitalWrite(pin_Y4, HIGH);
        digitalWrite(pin_Y5, HIGH);
        delay(500);
        digitalWrite(pin_Y1, LOW);
        digitalWrite(pin_Y2, LOW);
        digitalWrite(pin_Y3, LOW);
        digitalWrite(pin_Y4, LOW);
        digitalWrite(pin_Y5, LOW);
        delay(500);
  
      }
    else if (readString == "0"){
        Serial.println("0 is left!");
        digitalWrite(pin_R1, HIGH);
        digitalWrite(pin_R2, HIGH);
        digitalWrite(pin_R3, HIGH);
        digitalWrite(pin_R4, HIGH);
        digitalWrite(pin_R5, HIGH);
        delay(500);
        digitalWrite(pin_R1, LOW);
        digitalWrite(pin_R2, LOW);
        digitalWrite(pin_R3, LOW);
        digitalWrite(pin_R4, LOW);
        digitalWrite(pin_R5, LOW);
        delay(500);
  
      }      

  }

  delay(500);
  Serial.flush();

}
      
