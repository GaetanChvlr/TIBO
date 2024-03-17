//***********************************************/*  

#include <SoftwareSerial.h>  //Librairie Software Serial Port  
#define RX 10                //Pin 10 pour RX 
#define TX 11                //Pin 11 pour TX

char buzzer = 9;               // Broche buzzer

const byte PAS_1 = A0;           // Broches moteurs
const byte PAS_2 = A1;
const byte DIR = 7;

const byte DIN_pin = 8;         // Broches Matrice de LED
const byte CS_pin = 5;
const byte CLK_pin = 6;



                                          // Creation objet serie pour le hc06
SoftwareSerial PhmHC06Serie(RX,TX);  

int cmd=0;

                                          // Musiques 
void baby_shark(){
  //servoGauche.write(90);
  //servoDroite.write(88);
  delay(1000);

  for (int j = 0; j <= 1; j++){
    tone(buzzer,392,100);
    //servoGauche.write(80);
    //servoDroite.write(98);
    delay(300);
    //servoGauche.write(90);
    //servoDroite.write(88);
    delay(300);
    tone(buzzer,440,100);
    //servoGauche.write(98);
    //servoDroite.write(80);
    delay(300);
    //servoGauche.write(90);
    //servoDroite.write(88);
    delay(300);
  
    for (int i = 0; i <= 2; i++){
      tone(buzzer,523,100);
      //servoTete.write(160);

      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(120);

      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(160);

      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(120);

      delay(150);
      tone(buzzer,523,100);
      //servoTete.write(160);

      delay(300);
      tone(buzzer,523,100);
      //servoGauche.write(98);
      //servoDroite.write(98);

      delay(200);
      //servoGauche.write(90);
      //servoDroite.write(88);
      delay(250);
      if (i <= 1){
        tone(buzzer,392,100);
        //servoGauche.write(80);
        //servoDroite.write(80);

        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);

        delay(150);
        tone(buzzer,440,100);
        //servoGauche.write(98);
        //servoDroite.write(98);

        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);

        delay(150);
      }
      else{
        tone(buzzer,523,100);
        //servoGauche.write(80);
        //servoDroite.write(80);

        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);

        delay(150);
        tone(buzzer,523,100);
        //servoGauche.write(98);
        //servoDroite.write(98);

        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);

        delay(150);
        tone(buzzer,494,100);
        delay(1200);
      }
    }
  }
}

void trololo(){
  /*servoGauche.write(110);
  servoDroite.write(110);*/
  tone(buzzer,261,80);
  delay(150);
  tone(buzzer,329,80);
  delay(150);
  tone(buzzer,392,80);
  delay(150);
  tone(buzzer,523,80);
  delay(150);
  tone(buzzer,493,80);
  delay(300);
  tone(buzzer,493,80);
  delay(150);
  tone(buzzer,392,80);
  delay(150);
  tone(buzzer,440,80);
  delay(300);
  tone(buzzer,440,80);
  delay(150);
  tone(buzzer,349,80);
  delay(150);
  tone(buzzer,392,80);
  delay(1000);
 /* servoGauche.write(90);
  servoDroite.write(88);*/
  delay(2000);
}

                                          // Ecriture dans la matrice
void write_pix(int data)
{
  analogWrite(CS_pin, LOW);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(CLK_pin, LOW);
    digitalWrite(DIN_pin, data & 0x80); // masquage de donnée
    data = data << 1; // on décale les bits vers la gauche
    digitalWrite(CLK_pin, HIGH);
  }
}

void write_line(int adress, int data)
{
  digitalWrite(CS_pin, LOW);
  write_pix(adress);
  write_pix(data);
  digitalWrite(CS_pin, HIGH);
}

void write_matrix(int *tab)
{
  for (int i = 0; i < 8; i++) write_line(i + 1, tab[i]);
}
void init_MAX7219(void)
{
  write_line(0x09, 0x00); //decoding BCD
  write_line(0X0A, 0x01); //brightness
  write_line(0X0B, 0x07); //scanlimit 8leds
  write_line(0X0C, 0x01); //power-down mode 0, normalmode1;
  write_line(0X0F, 0x00);
}

void clear_matrix(void)
{
  int clean[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  write_matrix(clean);
}

int intToHex(int x)
{
  switch (x)
  {
    case 0: return 0x01; break; //LED sur la première case
    case 1: return 0x02; break; //LED sur 2 case
    case 2: return 0x04; break; //LED sur 3 case
    case 3: return 0x08; break; //LED sur 4 case
    case 4: return 0x10; break; //LED sur 5 case
    case 5: return 0x20; break; //LED sur 6 case
    case 6: return 0x40; break; //LED sur 7 case
    case 7: return 0x80; break; //LED sur 8 case
  }
}



void setup()  
{  
  /* Initialise les broches pour les leds ? */
  pinMode(13, OUTPUT);

  /* Initialise le port série */
  Serial.begin(9600);    
  Serial.println("Pret ...");  
  PhmHC06Serie.begin(9600);  //Valeur par défaut pour le HC06

  /* Initialise les broches moteurs */
  pinMode(PAS_1, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PAS_2, OUTPUT);
  
  /* Initialise les broches de la matrice de LED */
  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);

                                                                  //***DEFINITION DES VISAGES***//
                                                                
  int vis1[8] = {0x08,0x10,0x38,0x00,0x00,0x18,0x66,0x81};  // pas content
  int vis2[8] = {0x08,0x10,0x38,0x00,0x00,0x81,0x66,0x18};  // content

  init_MAX7219();
  clear_matrix();
  write_matrix(vis2); //On initialise Tibo content parce que merde quand même la vie est belle quoi
}  
void loop()  
{  
                                                                  //***DEFINITION DES VISAGES***//
                                                                
  int vis1[8] = {0x08,0x10,0x38,0x00,0x00,0x18,0x66,0x81};  // pas content
  int vis2[8] = {0x08,0x10,0x38,0x00,0x00,0x81,0x66,0x18};  // content

  
                                                                //**TRAITEMENT DE LA COMMANDE***//
  digitalWrite(DIR, HIGH);
  
 //Lecture des données HC06
  while(PhmHC06Serie.available()>0){
    cmd=(int)PhmHC06Serie.read();
  }

  //Traitement de la commande recue
  if(cmd!=0){
    Serial.print("Une commande a ete recue ....");
    Serial.println(cmd);
    // Commande LEDON pour allumage LED


                                                                //**LEDS***//
    if(cmd==2){
        Serial.println("Allumage LED");
        digitalWrite(13, HIGH);   
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }

    if(cmd==1){
        Serial.println("Extinction LED");
        digitalWrite(13, LOW); 
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }

                                                                //**MUSIQUES***//

    if(cmd==9){
        trololo();
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }

    if(cmd==8){
        trololo();
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }


                                                                //**DEPLACEMENT***//

    if(cmd==3){
          Serial.println("Tout droit");
          for(int x = 0; x < 200; x++) {// Permet de faire un PAS à une certaine allure. Pour tourner plus vite, changer le delay jusqu'à 1 , pour ralentir, le changer jusqu'à 30
          digitalWrite(PAS_1 , HIGH);
          digitalWrite(PAS_2, HIGH); // On fait un tour avec 200 pas pour le Nema 17
          delayMicroseconds(500);
          digitalWrite(PAS_1, LOW);
          digitalWrite(PAS_2, LOW);
          delayMicroseconds(500);
          }
    }

    if(cmd==4){
          Serial.println("A gauche");
          for(int x = 0; x < 200; x++) {// Permet de faire un PAS à une certaine allure. Pour tourner plus vite, changer le delay jusqu'à 1 , pour ralentir, le changer jusqu'à 30
          digitalWrite(PAS_2, HIGH); 
          digitalWrite(PAS_2, LOW);
          delayMicroseconds(1000);
          }
    }

    if(cmd==5){
          Serial.println("A droite");
          for(int x = 0; x < 200; x++) {// Permet de faire un PAS à une certaine allure. Pour tourner plus vite, changer le delay jusqu'à 1 , pour ralentir, le changer jusqu'à 30
          digitalWrite(PAS_1 , HIGH);
          digitalWrite(PAS_1, LOW);
          delayMicroseconds(1000);
          }
    }


                                                                //**VISAGES***//
    if(cmd==6){
        Serial.println("Tibo Content");
           write_matrix(vis2);
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }

    if(cmd==7){
        Serial.println("Tibo Triste");
           write_matrix(vis1);
        cmd=0; //Reset variable commande envoyée par Bluetooth
    }
  }
   
}
