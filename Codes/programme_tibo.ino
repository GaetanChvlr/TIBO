/* Constantes pour les broches */
const byte RX_BLUETOOTH = 0;    // Broches moodule Bluetooth
const byte TX_BLUETOOTH = 1;    
const byte TRIGGER_PIN = 2;     // Broches capteurs de distance
const byte ECHO_TETE_PIN = 3;   
const byte ECHO_PIED_PIN = 4;   
const byte ECHO_PIED_GAUCHE_PIN = 12;
const byte ECHO_PIED_DROIT_PIN = 13;
const byte PAS_1 = 5;           // Broches moteurs
const byte PAS_2 = 6;
const byte DIR = 7;
const byte DIN_pin = 8;         // Broches Matrice de LED
const byte CS_pin = 10;
const byte CLK_pin = 11;
char buzzer = 9;               // Broche buzzer
const byte LED = A0;            // Broche LED

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

                                                                                   //  FONCTIONS UTILES
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
      digitalWrite(LED, HIGH);
      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(120);
      digitalWrite(LED, LOW);
      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(160);
      digitalWrite(LED, HIGH);
      delay(300);
      tone(buzzer,523,100);
      //servoTete.write(120);
      digitalWrite(LED, LOW);
      delay(150);
      tone(buzzer,523,100);
      //servoTete.write(160);
      digitalWrite(LED, HIGH);
      delay(300);
      tone(buzzer,523,100);
      //servoGauche.write(98);
      //servoDroite.write(98);
      digitalWrite(LED, LOW);
      delay(200);
      //servoGauche.write(90);
      //servoDroite.write(88);
      delay(250);
      if (i <= 1){
        tone(buzzer,392,100);
        //servoGauche.write(80);
        //servoDroite.write(80);
        digitalWrite(LED, HIGH);
        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);
        digitalWrite(LED, LOW);
        delay(150);
        tone(buzzer,440,100);
        //servoGauche.write(98);
        //servoDroite.write(98);
        digitalWrite(LED, HIGH);
        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);
        digitalWrite(LED, LOW);
        delay(150);
      }
      else{
        tone(buzzer,523,100);
        //servoGauche.write(80);
        //servoDroite.write(80);
        digitalWrite(LED, HIGH);
        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);
        digitalWrite(LED, LOW);
        delay(150);
        tone(buzzer,523,100);
        //servoGauche.write(98);
        //servoDroite.write(98);
        digitalWrite(LED, HIGH);
        delay(150);
        //servoGauche.write(90);
        //servoDroite.write(88);
        digitalWrite(LED, LOW);
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

/* Fonction distance */
float calculDistanceTete(){     /* ECHO = ECHO_TETE_PIN ou ECHO_PIED_PIN */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs 
  sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique 
  et son écho (si il existe) */
  long measure = pulseIn(ECHO_TETE_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_cm = measure / (2.0 * (340.0/10));   /* On div par 2 car aller-retour et par la vitesse du son */

  return distance_cm;
}

float calculDistancePied(){     /* ECHO = ECHO_TETE_PIN ou ECHO_PIED_PIN */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs 
  sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique 
  et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIED_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_cm = measure / (2.0 * (340.0/10));   /* On div par 2 car aller-retour et par la vitesse du son */

  return distance_cm;
}

float calculDistancePiedGauche(){     /* ECHO = ECHO_TETE_PIN ou ECHO_PIED_PIN */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs 
  sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique 
  et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIED_GAUCHE_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_cm = measure / (2.0 * (340.0/10));   /* On div par 2 car aller-retour et par la vitesse du son */

  return distance_cm;
}

float calculDistancePiedDroit(){     /* ECHO = ECHO_TETE_PIN ou ECHO_PIED_PIN */
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs 
  sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique 
  et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIED_DROIT_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_cm = measure / (2.0 * (340.0/10));   /* On div par 2 car aller-retour et par la vitesse du son */

  return distance_cm;
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
  const int clean[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
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

void setup() {
  /* Initialise le port série */
  Serial.begin(9600);

  /* Initialise les broches Bluetooth */
  pinMode(RX_BLUETOOTH, OUTPUT);
  pinMode(TX_BLUETOOTH, INPUT);

  /* Initialise les broches pour les capteurs de distance */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_TETE_PIN, INPUT);
  pinMode(ECHO_PIED_PIN, INPUT);
  pinMode(ECHO_PIED_DROIT_PIN, INPUT);
  pinMode(ECHO_PIED_GAUCHE_PIN, INPUT);
  

  /* Initialise les broches pour les leds */
  pinMode(LED, OUTPUT); 

  /* Initialise les broches de la matrice de LED */
  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);

  init_MAX7219();
  clear_matrix();

  /* Initialise les broches moteurs */
  pinMode(PAS_1, OUTPUT);
  pinMode(DIR, OUTPUT);
  pinMode(PAS_2, OUTPUT);
}

void loop() {
  digitalWrite(DIR, HIGH);
  digitalWrite(ECHO_TETE_PIN, HIGH);
  digitalWrite(ECHO_PIED_PIN, HIGH);
  
  /* Allumer les leds */
  //analogWrite(LED, 200);
  //delay(200);

  /* Eteindre les leds */
  //analogWrite(LED, 0);
  //delay(200);
  
    /* Appel fonction distance */
    float t = calculDistanceTete();
    Serial.println("Distance capteur tête : ");
    Serial.println(t);
  
    float p = calculDistancePied();
    Serial.println("Distance capteur pied : ");
    Serial.println(p);

    float g = calculDistancePiedGauche();
    Serial.println("Distance capteur pied : ");
    Serial.println(p);

    float d = calculDistancePiedDroit();
    Serial.println("Distance capteur pied : ");
    Serial.println(p);

    /* Visages */
    int vis1[8] = {0x08,0x10,0x38,0x00,0x00,0x18,0x66,0x81};  // pas content
    int vis2[8] = {0x08,0x10,0x38,0x00,0x00,0x81,0x66,0x18};  // content

    analogWrite(LED,500);

    if (((d<30))&&(d != 0)){      // TRES PROCHE à droite
      digitalWrite(LED, HIGH);
      write_matrix(vis1);
      
      //tone(buzzer, 200);
      //delay(100);
      
      
    for (int x = 0; x < 1500; x++){           // Tibo tourne à gauche
        digitalWrite(PAS_2 , HIGH);
        digitalWrite(PAS_2, LOW);
        delayMicroseconds(1000);
      }
    }
    else if (((g<30))&&(d != 0)){      // TRES PROCHE à gauche
      digitalWrite(LED, HIGH);
      write_matrix(vis1);
      //tone(buzzer, 200);
      //delay(100);
      
      
    for (int x = 0; x < 1500; x++){           // Tibo tourne à droite
        digitalWrite(PAS_1 , HIGH);
        digitalWrite(PAS_1, LOW);
        delayMicroseconds(1000);
      }
    }  
    else if (((p<60)||(t<60))&&(p*t != 0)){ // TRES PROCHE à gauche ou en haut
        if (g < d){
          for (int x = 0; x < 1500; x++){           // Tibo tourne à droite
          digitalWrite(PAS_1 , HIGH);
          digitalWrite(PAS_1, LOW);
          delayMicroseconds(1000);
          }
        }
        else{
          for (int x = 0; x < 1500; x++){           // Tibo tourne à gauche
          digitalWrite(PAS_2 , HIGH);
          digitalWrite(PAS_2, LOW);
          delayMicroseconds(1000);
        }
        
        }
        
        digitalWrite(LED, HIGH);
        write_matrix(vis1);
        //tone(buzzer, 200);
        //delay(100);
      
      
    for (int x = 0; x < 1500; x++){           // Tibo tourne à droite
        digitalWrite(PAS_1 , HIGH);
        digitalWrite(PAS_1, LOW);
        delayMicroseconds(1000);
      }
    }
    else{                                       // NO DANGER
      write_matrix(vis2);
      digitalWrite(LED, LOW);   
      noTone(buzzer);
      //delay(100);

     
    for (int x = 0; x < 2500; x++){
      
      digitalWrite(PAS_1 , HIGH);               // Tibo va tout droit
      digitalWrite(PAS_2, HIGH);                // On fait un tour avec 200 pas pour le Nema 17
      delayMicroseconds(500);
      digitalWrite(PAS_1, LOW);
      digitalWrite(PAS_2, LOW);
      delayMicroseconds(500);
      }
  }
  
  // Test du buzzer
  //tone(buzzer, 440);         /* Son de fréquence 440Hz */
  //delay(20);
  //noTone(buzzer);
  
  // baby_shark();
  // trololo();
}
