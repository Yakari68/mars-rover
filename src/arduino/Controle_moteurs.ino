// ============================================================
// CHOIX DU SENS DE ROTATION
// ============================================================
//
//  1  = Marche avant
//  0  = Arrêt
// -1  = Marche arrière
//
// ============================================================

// ============================================================
// STRUCTURE DE PINS
// ============================================================
struct Trio
{
  int pin_avant;
  int pin_arriere;
  int pin_pwm;
};

// ============================================================
// definition des pins
// ============================================================
const Trio mot_av_d = {22,23, 6};   // MOTEUR AVANT DROIT
const Trio mot_ar_d = {24,25, 7};   // MOTEUR ARRIÈRE DROIT
const Trio mot_av_g = {28,29, 5};   // MOTEUR AVANT GAUCHE
const Trio mot_ar_g = {26,27, 4};   // MOTEUR ARRIÈRE GAUCHE

const int codeurMAD = 31; //codeur incrémentale 

int inputs[4];
uint8_t buffer[sizeof(inputs)];
size_t index = 0;


// ============================================================
// SETUP
// ============================================================
void setup() {

  pinMode (codeurMAD, INPUT);

  set_Pins(mot_av_d);// Moteur Avant Droit
  set_Pins(mot_ar_d);// Moteur Arrière Droit
  set_Pins(mot_av_g);// Moteur Avant Gauche
  set_Pins(mot_ar_g);// Moteur Arrière Gauche

  Serial.begin(9600);
}


// ============================================================
// LOOP
// ============================================================
void loop() {
  
}

void set_Pins(Trio trio)
{
  pinMode(trio.pin_avant, OUTPUT);
  pinMode(trio.pin_arriere, OUTPUT);
  pinMode(trio.pin_pwm, OUTPUT);
}

void controleMoteur(Trio trio, short sens, short vitesse)
{
  // Limitation de la vitesse
  if (vitesse < 0) vitesse = 0;
  if (vitesse > 255) vitesse = 255;

  // Marche avant
  if (sens == 1) 
  {
    digitalWrite(trio.pin_avant, LOW);
    digitalWrite(trio.pin_arriere, HIGH);
    analogWrite(trio.pin_pwm, vitesse);
  }

  // Marche arrière
  else if (sens == -1) {

    digitalWrite(trio.pin_avant, HIGH);
    digitalWrite(trio.pin_arriere, LOW);
    analogWrite(trio.pin_pwm, vitesse);
  }

  // Arrêt
  else if (sens == 0) {

    digitalWrite(trio.pin_avant, LOW);
    digitalWrite(trio.pin_arriere, LOW);
    analogWrite(trio.pin_pwm, 0);
  }
}
