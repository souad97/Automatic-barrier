#include <Servo.h> 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;
int total=10;
int   lecture_echo1,lecture_echo2,lecture_echo3;
int   cm1 ,cm2 ,cm3;


void setup() {
  
  pinMode(6,INPUT); // ECHO1
  pinMode(7,OUTPUT);// TRIG1 
   pinMode(4,INPUT); // ECHO2 
  pinMode(5,OUTPUT);// TRIG2
   pinMode(3,INPUT); // ECHO3 
  pinMode(2,OUTPUT);// TRIG3 
   //pinMode(ledRouge, OUTPUT);
  //pinMode(ledVerte, OUTPUT);
  //digitalWrite(ledRouge, HIGH); 
  servo.attach(6);
  Serial.begin(9600);
  servo.write(0);
    lcd.init(); 
  lcd.setCursor(2, 0);
  lcd.print("BIENVENNUE");
  lcd.setCursor(0, 1);
  lcd.print("Parking is empty ");
}

void loop() {
  lcd.backlight();
  cm1=cm2=cm3=lecture_echo1=lecture_echo2=lecture_echo3=0;
/* digitalWrite(4, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(4, LOW); 
   lecture_echo1 = pulseIn(3, HIGH); 
  cm1 = lecture_echo1 / 58; */
  digitalWrite(5, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(5, LOW); 
   lecture_echo2 = pulseIn(4, HIGH); 
  cm2 = lecture_echo2 / 58; 
  digitalWrite(2, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(2, LOW); 
   lecture_echo3 = pulseIn(3, HIGH); 
  cm3 = lecture_echo3 / 58; 
  if (cm1==4 ) // capteur de detection voiture 
  {   Serial.print("ok");
   for(int pos = 0; pos <= 90; pos++) {
      servo.write(pos);
      delay(15);
    }
    //digitalWrite(ledRouge, LOW);
    //digitalWrite(ledVerte, HIGH);
    delay(5000);
    //digitalWrite(ledVerte, LOW);
    //digitalWrite(ledRouge, HIGH);
    
    // enfin, on redescend la barrière
    for(int pos = 90; pos>=0; pos--) {
      servo.write(pos);
      delay(15);
    }
    }
    if (cm2==4 && total!=0){ //vérifier l'entrée 
      total--;
      lcd.setCursor(2, 0);
      
      lcd.print("BIENVENNUE");
      lcd.setCursor(0, 1);
      //lcd.print();
    lcd.print("nombre de place reste : ");
      lcd.print(total);
     
      }
      
     if (cm3<=4 && total<10){
      total++;
      lcd.print("nombre de place reste 2: ");
      lcd.println(total);
    }
    if (total==0){
    lcd.print("parking is full ");
    }
}
