#include<LiquidCrystal_I2C.h>// pour ecrire dans le lcd
#include <Servo.h>// pour controler le servo
#include<Wire.h>// pour utiliser le module I2C
Servo servo;// on declare le servo
LiquidCrystal_I2C lcd(0x3F, 16, 2); // I2C address 0x27, 16 column and 2 rows
int total=10;// le nombre de place dans le parking
const char echo1 = 6;
const char trig1 = 7;
const char echo2 = 4;
const char trig2 = 5;
const char echo3 = 3;
const char trig3 = 2;
int   cm1 ,cm2 ,cm3;// distance entre le capteur et la voiture
bool barriere;
int posfin = 0;// derniere position du servo
int ledRouge=9,ledVerte=10 ;// signal visuel informant sur l'etat de la barriere, vert pour ouvert, rouge pour ferme

void setup()
{ // le capteur de detection de voiture en amont a l'entree
  pinMode(echo1,INPUT);
  pinMode(trig1,OUTPUT);
  // le capteure de detection de voiture en avale a l'entree
     pinMode(echo2,INPUT); 
  pinMode(trig2,OUTPUT);
  // le capteure de detection de voiture a la sortie
   pinMode(echo3,INPUT); 
  pinMode(trig3,OUTPUT); 
  pinMode(ledRouge, OUTPUT);
  pinMode(ledVerte, OUTPUT);
  servo.attach(8);
  servo.write(0);// la barriere est initialise a 0°
  barriere = true; // barrier fermee
 lcd.init(); 
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("BIENVENNUE");
  lcd.setCursor(0, 1);
  lcd.print("Parking is empty ");
}

void loop()
{
  // si la barriere est ferme allumer rouge
  if(barriere)
  {
    digitalWrite(ledRouge, HIGH);
    digitalWrite(ledVerte, LOW);
  }
  else// sinon allumer vert;
  {
    digitalWrite(ledRouge, LOW);
    digitalWrite(ledVerte, HIGH);    
  }
  cm2=cm3=cm1=0;// on initialise tous les variable de mesure a 0 avant le traitement des donnee
  // le chien de garde verifie si il y a une voiture a la deventure ou pas(prise de mesure par le capteur 1)
  cm1 = capteurVoiture(trig1, echo1); // on prend la distance en cm au niveau du capteur 1
  if (cm1<=6 && cm1 > 2) // si on detecte une voiture a 4 ou moins de 4 cm de la barrier, 
  { 
      for(int pos = posfin; pos <= 90; pos++) {
      servo.write(pos);
      delay(60);}
      posfin = 90;  
      barriere = false; //barriere ouverte
    delay(3000);
  }
  cm2 = capteurVoiture(trig2, echo2);// mesure a l'entree
    if (cm2<=6 && total!=0 && cm2 > 2){ //vérifier l'entrée 
    total--; // nombre de place libre decremente par pas de 1
         for(int pos = posfin; pos>=0; pos--) {
      servo.write(pos);
      delay(60);
    }
    posfin = 0;
    barriere =  true;// barrire fermee
    lcd.clear();
      lcd.backlight();
        lcd.setCursor(2, 0);
  lcd.print("BIENVENNUE");
  lcd.setCursor(0, 1);
      lcd.print("place libre : ");
      lcd.print(total);
      delay(3000);
      }
      cm3 = capteurVoiture(trig3, echo3);
    if (cm3<=6 && total<10 && cm3 > 2){
      total++;
      lcd.clear();
    lcd.setCursor(2, 0);
  lcd.print("BIENVENNUE");
  lcd.setCursor(0, 1);
      lcd.print("place libre : ");
      lcd.print(total);
     delay(3000);
    }
    if (total==0){
      lcd.clear();
    lcd.print("parking is full");
    } 
      if (total==10){
      lcd.clear();
   //lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("BIENVENNUE");
  lcd.setCursor(0, 1);
  lcd.print("Parking is empty ");
    }
  }
  int capteurVoiture(const char trig, const char echo)// fonction pour prendre des mesure au niveau du capteur
  {
    int lectureEcho = 0;
    digitalWrite(trig, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trig, LOW);
    lectureEcho = pulseIn(echo, HIGH);
    return lectureEcho/58;     
  }
