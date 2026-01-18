/************************************************************************
Date: 14/01/2026
Auteur: Emirhan KARAHAN – Hakan OZATA – Furkan AKTAS – Tomás DE ALMEIDA
Role: jeu "Crazy Taxi"
*************************************************************************/
#include <Adafruit_Microbit.h>
#include <time.h>
Adafruit_Microbit_Matrix microbit;

//Initialisation des variables

const int buzzerPin=8;
bool buttonA_last = false;
bool buttonB_last = false;
const int button_A = 5;
const int button_B = 11;
int pos = 2;
int alea2;
int alea;

double t0, t1;

// on initialise les deux boutons et la carte

void setup() {


  Serial.begin(9600);
  Serial.println("microbit matrix demo is ready!");
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(buzzerPin, OUTPUT);
  microbit.begin();

  microbit.drawPixel(0, 0, LED_ON);
  microbit.drawPixel(0, 1, LED_ON);
  microbit.drawPixel(0, 2, LED_ON);
  microbit.drawPixel(0, 3, LED_OFF);
  microbit.drawPixel(0, 4, LED_OFF);

  microbit.drawPixel(4, 0, LED_ON);
  microbit.drawPixel(4, 1, LED_ON);
  microbit.drawPixel(4, 2, LED_ON);
  microbit.drawPixel(4, 3, LED_OFF);
  microbit.drawPixel(4, 4, LED_OFF);

    microbit.begin();
  randomSeed(millis());

//On initialise l'aléatoire et le temps des boucles

  t0 = millis();
  t1 = millis();

  microbit.drawPixel(2, 4, LED_ON);
  alea2 = random(1, 4);
  alea = random(1, 4);
  srand(analogRead(0));
}

void loop() {

  tone(buzzerPin, 440);
  delay(500);
  noTone(buzzerPin);

  // ARRIVER ALEATOIRE DES ENNEMIS
// Vitesse lente car on est en dessous des 15 secondes

  if (millis() - t1 < 15000) {

// Si le temps est entre 150 et 450 ms, la LED sur la première ligne s'allume, colonne aléatoire.   

    if (millis() - t0 > 150 && millis() - t0 < 450) {
      microbit.drawPixel(alea, 0, LED_ON);
      microbit.drawPixel(alea, 1, LED_OFF);
    }

// Si le temps est entre 450 et 750 ms, la LED sur la deuxième ligne s'allume, meme colonne que la précedente.   

    if (millis() - t0 > 450 && millis() - t0 < 750) {
      microbit.drawPixel(alea, 0, LED_OFF);
      microbit.drawPixel(alea, 1, LED_ON);
    }

// Si le temps est entre 750 et 1050 ms, la LED sur la troisième ligne s'allume, meme colonne que la précedente.

    if (millis() - t0 > 750 && millis() - t0 < 1050) {
      microbit.drawPixel(alea, 1, LED_OFF);
      microbit.drawPixel(alea, 2, LED_ON);
    }

// Si le temps est entre 1050 et 1350 ms, la LED sur la quatrième ligne s'allume, meme colonne que la précedente.

    if (millis() - t0 > 1050 && millis() - t0 < 1350) {
      microbit.drawPixel(alea, 2, LED_OFF);
      microbit.drawPixel(alea, 3, LED_ON);
    }

// Une fois qu'on a dépassé les 1350 ms la LED s'éteint pour pas intérferé avec la voiture et éviter les BUGS.

    if (millis() - t0 > 1350) {
      microbit.drawPixel(alea, 3, LED_OFF);
    }

    // COLLISIONS ET AFFICHAGE DES RESULTATS

// Une fois que la voiture touche un obstacle le jeu s'arrete et affiche le résultat converti en seconde.

    if ((millis() - t0 > 1500) && (alea == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }

// Vitesse moyenne entre 15 et 54 secondes

// On fait la meme chose en rajoutant un deuxieme obstacle et en multipliant la vitesse par 2.

  } else if (millis() - t1 < 54000) {
    if (millis() - t0 > 150 && millis() - t0 < 300) {
      microbit.drawPixel(alea, 0, LED_ON);
      microbit.drawPixel(alea, 1, LED_OFF);
    }

    if (millis() - t0 > 300 && millis() - t0 < 450) {
      microbit.drawPixel(alea, 0, LED_OFF);
      microbit.drawPixel(alea, 1, LED_ON);
    }

    if (millis() - t0 > 450 && millis() - t0 < 600) {
      microbit.drawPixel(alea, 1, LED_OFF);
      microbit.drawPixel(alea, 2, LED_ON);
    }

    if (millis() - t0 > 600 && millis() - t0 < 750) {
      microbit.drawPixel(alea, 2, LED_OFF);
      microbit.drawPixel(alea, 3, LED_ON);
    }

    if (millis() - t0 > 750) {
      microbit.drawPixel(alea, 3, LED_OFF);
    }

    if (millis() - t0 > 900 && millis() - t0 < 1050) {
      microbit.drawPixel(alea2, 0, LED_ON);
      microbit.drawPixel(alea2, 1, LED_OFF);
    }

    if (millis() - t0 > 1050 && millis() - t0 < 1200) {
      microbit.drawPixel(alea2, 0, LED_OFF);
      microbit.drawPixel(alea2, 1, LED_ON);
    }

    if (millis() - t0 > 1200 && millis() - t0 < 1350) {
      microbit.drawPixel(alea2, 1, LED_OFF);
      microbit.drawPixel(alea2, 2, LED_ON);
    }

    if (millis() - t0 > 1350 && millis() - t0 < 1500) {
      microbit.drawPixel(alea2, 2, LED_OFF);
      microbit.drawPixel(alea2, 3, LED_ON);
    }

    if (millis() - t0 > 1500) {
      microbit.drawPixel(alea2, 3, LED_OFF);
    }

    // COLLISIONS ET AFFICHAGE DES RESULTATS

    if ((millis() - t0 > 1500) && (alea2 == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }

    if ((millis() - t0 > 750) && (millis() - t0 < 900) && (alea == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }
  }

  // Vitesse au dessus des 54 secondes (vitesse X4).

  else {
    if (millis() - t0 > 75 && millis() - t0 < 150) {
      microbit.drawPixel(alea, 0, LED_ON);
      microbit.drawPixel(alea, 1, LED_OFF);
    }

    if (millis() - t0 > 150 && millis() - t0 < 225) {
      microbit.drawPixel(alea, 0, LED_OFF);
      microbit.drawPixel(alea, 1, LED_ON);
    }

    if (millis() - t0 > 225 && millis() - t0 < 300) {
      microbit.drawPixel(alea, 1, LED_OFF);
      microbit.drawPixel(alea, 2, LED_ON);
    }

    if (millis() - t0 > 300 && millis() - t0 < 375) {
      microbit.drawPixel(alea, 2, LED_OFF);
      microbit.drawPixel(alea, 3, LED_ON);
    }

    if (millis() - t0 > 375) {
      microbit.drawPixel(alea, 3, LED_OFF);
    }

    if (millis() - t0 > 450 && millis() - t0 < 525) {
      microbit.drawPixel(alea2, 0, LED_ON);
      microbit.drawPixel(alea2, 1, LED_OFF);
    }

    if (millis() - t0 > 525 && millis() - t0 < 600) {
      microbit.drawPixel(alea2, 0, LED_OFF);
      microbit.drawPixel(alea2, 1, LED_ON);
    }

    if (millis() - t0 > 600 && millis() - t0 < 675) {
      microbit.drawPixel(alea2, 1, LED_OFF);
      microbit.drawPixel(alea2, 2, LED_ON);
    }

    if (millis() - t0 > 675 && millis() - t0 < 750) {
      microbit.drawPixel(alea2, 2, LED_OFF);
      microbit.drawPixel(alea2, 3, LED_ON);
    }

    if (millis() - t0 > 750) {
      microbit.drawPixel(alea2, 3, LED_OFF);
    }

    // COLLISIONS ET AFFICHAGE DES RESULTATS

    if ((millis() - t0 > 750) && (alea2 == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }

    if ((millis() - t0 > 375) && (millis() - t0 < 450) && (alea == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true);
    }

    // Ajout de 2 obstacles pour accélerer la vitesse

    if (millis() - t0 > 825 && millis() - t0 < 900) {
      microbit.drawPixel(alea, 0, LED_ON);
      microbit.drawPixel(alea, 1, LED_OFF);
    }

    if (millis() - t0 > 900 && millis() - t0 < 975) {
      microbit.drawPixel(alea, 0, LED_OFF);
      microbit.drawPixel(alea, 1, LED_ON);
    }

    if (millis() - t0 > 975 && millis() - t0 < 1050) {
      microbit.drawPixel(alea, 1, LED_OFF);
      microbit.drawPixel(alea, 2, LED_ON);
    }

    if (millis() - t0 > 1050 && millis() - t0 < 1125) {
      microbit.drawPixel(alea, 2, LED_OFF);
      microbit.drawPixel(alea, 3, LED_ON);
    }

    if (millis() - t0 > 1125) {
      microbit.drawPixel(alea, 3, LED_OFF);
    }

    if (millis() - t0 > 1200 && millis() - t0 < 1275) {
      microbit.drawPixel(alea2, 0, LED_ON);
      microbit.drawPixel(alea2, 1, LED_OFF);
    }

    if (millis() - t0 > 1275 && millis() - t0 < 1350) {
      microbit.drawPixel(alea2, 0, LED_OFF);
      microbit.drawPixel(alea2, 1, LED_ON);
    }

    if (millis() - t0 > 1350 && millis() - t0 < 1425) {
      microbit.drawPixel(alea2, 1, LED_OFF);
      microbit.drawPixel(alea2, 2, LED_ON);
    }

    if (millis() - t0 > 1425 && millis() - t0 < 1500) {
      microbit.drawPixel(alea2, 2, LED_OFF);
      microbit.drawPixel(alea2, 3, LED_ON);
    }

    if (millis() - t0 > 1500) {
      microbit.drawPixel(alea2, 3, LED_OFF);
    }

    // COLLISIONS ET AFFICHAGE DES RESULTATS

    if ((millis() - t0 > 1500) && (alea2 == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }

    if ((millis() - t0 > 1200) && (millis() - t0 < 1275) && (alea == pos)) {
      t1 = (millis() - t1) / 1000;
      microbit.print("PERDU SCORE :");
      microbit.print(t1,1);
      microbit.print("SECONDES");
      while (true)
        ;
    }
  }

    // LIGNE DE SÉCURITÉ SUR LES COTÉS
  

  if (millis() - t0 > 300 && millis() - t0 < 600) {

  // Ligne de sécurité a gauche

    microbit.drawPixel(0, 0, LED_OFF);
    microbit.drawPixel(0, 1, LED_ON);
    microbit.drawPixel(0, 2, LED_ON);
    microbit.drawPixel(0, 3, LED_ON);
    microbit.drawPixel(0, 4, LED_OFF);

  // Ligne de sécurité a droite

    microbit.drawPixel(4, 0, LED_OFF);
    microbit.drawPixel(4, 1, LED_ON);
    microbit.drawPixel(4, 2, LED_ON);
    microbit.drawPixel(4, 3, LED_ON);
    microbit.drawPixel(4, 4, LED_OFF);
  }

  // Décalage des lignes de sécurité toute les 300ms.

  if (millis() - t0 > 600 && millis() - t0 < 900) {
    microbit.drawPixel(0, 0, LED_OFF);
    microbit.drawPixel(0, 1, LED_OFF);
    microbit.drawPixel(0, 2, LED_ON);
    microbit.drawPixel(0, 3, LED_ON);
    microbit.drawPixel(0, 4, LED_ON);

    microbit.drawPixel(4, 0, LED_OFF);
    microbit.drawPixel(4, 1, LED_OFF);
    microbit.drawPixel(4, 2, LED_ON);
    microbit.drawPixel(4, 3, LED_ON);
    microbit.drawPixel(4, 4, LED_ON);
  }

  if (millis() - t0 > 900 && millis() - t0 < 1200) {
    microbit.drawPixel(0, 0, LED_ON);
    microbit.drawPixel(0, 1, LED_OFF);
    microbit.drawPixel(0, 2, LED_OFF);
    microbit.drawPixel(0, 3, LED_ON);
    microbit.drawPixel(0, 4, LED_ON);

    microbit.drawPixel(4, 0, LED_ON);
    microbit.drawPixel(4, 1, LED_OFF);
    microbit.drawPixel(4, 2, LED_OFF);
    microbit.drawPixel(4, 3, LED_ON);
    microbit.drawPixel(4, 4, LED_ON);
  }

  if (millis() - t0 > 1200 && millis() - t0 < 1500) {
    microbit.drawPixel(0, 0, LED_ON);
    microbit.drawPixel(0, 1, LED_ON);
    microbit.drawPixel(0, 2, LED_OFF);
    microbit.drawPixel(0, 3, LED_OFF);
    microbit.drawPixel(0, 4, LED_ON);

    microbit.drawPixel(4, 0, LED_ON);
    microbit.drawPixel(4, 1, LED_ON);
    microbit.drawPixel(4, 2, LED_OFF);
    microbit.drawPixel(4, 3, LED_OFF);
    microbit.drawPixel(4, 4, LED_ON);
  }

  if (millis() - t0 > 1500 && millis() - t0 < 1800) {
    microbit.drawPixel(0, 0, LED_ON);
    microbit.drawPixel(0, 1, LED_ON);
    microbit.drawPixel(0, 2, LED_ON);
    microbit.drawPixel(0, 3, LED_OFF);
    microbit.drawPixel(0, 4, LED_OFF);

    microbit.drawPixel(4, 0, LED_ON);
    microbit.drawPixel(4, 1, LED_ON);
    microbit.drawPixel(4, 2, LED_ON);
    microbit.drawPixel(4, 3, LED_OFF);
    microbit.drawPixel(4, 4, LED_OFF);
  }

  // REINITIALISATION DE LA BOUCLE

  if (millis() - t0 > 1800) {
    t0 = millis();
    alea = random(1, 4);
    alea2 = random(1, 4);
  }

  // DEPLACEMENT DU JOUEUR

  bool buttonA_now = digitalRead(button_A);
  bool buttonB_now = digitalRead(button_B);

  if (buttonA_now && !buttonA_last) { // si le bouton A est pressé

    // Si on est au milieu, on va à gauche.
    if (pos == 2) { 
      microbit.drawPixel(1, 4, LED_ON);
      microbit.drawPixel(2, 4, LED_OFF);
      microbit.drawPixel(3, 4, LED_OFF);
      pos = 1;
    } 

    // Si on est a droite, on va au milieu.
    else if (pos == 3) {
      microbit.drawPixel(1, 4, LED_OFF);
      microbit.drawPixel(2, 4, LED_ON);
      microbit.drawPixel(3, 4, LED_OFF);
      pos = 2;
    }
  }

  if (buttonB_now && !buttonB_last) { // Si le bouton B est pressé

    // Si on est milieu, on va à droite.
    if (pos == 2) {
      microbit.drawPixel(1, 4, LED_OFF);
      microbit.drawPixel(2, 4, LED_OFF);
      microbit.drawPixel(3, 4, LED_ON);
      pos = 3;

    // Si on va a gauche, on va au milieu.
    } else if (pos == 1) {
      microbit.drawPixel(1, 4, LED_OFF);
      microbit.drawPixel(2, 4, LED_ON);
      microbit.drawPixel(3, 4, LED_OFF);
      pos = 2;
    }
  }

  // On affecte la valeur actuelle
  buttonA_last = buttonA_now;
  buttonB_last = buttonB_now;
}

