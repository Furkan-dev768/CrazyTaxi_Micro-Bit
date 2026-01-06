#include <Adafruit_Microbit.h>
#include <time.h>
Adafruit_Microbit_Matrix microbit;
bool buttonA_last = false;
bool buttonB_last = false;
const int buttonA = 5;
const int buttonB = 11;
int pos = 2;
int alea2;
int alea;
double t0, t1;
// on initialise les deux boutons et la carte
void setup()
{
    microbit.begin();
    randomSeed(millis());
    Serial.begin(9600);
    Serial.println("microbit matrix demo is ready!");
    pinMode(buttonA, INPUT);
    pinMode(buttonB, INPUT);
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
    t0 = millis();
    t1 = millis();
    microbit.drawPixel(2, 4, LED_ON);
    alea2 = random(1, 4);
    alea = random(1, 4);
    srand(time(0));
}
void loop()
{
    // ARRIVER ALEATOIRE DES ENNEMIS
    if (millis() - t1 < 36000)
    {
        if (millis() - t0 > 150 && millis() - t0 < 300)
        {
            microbit.drawPixel(alea, 0, LED_ON);

            microbit.drawPixel(alea, 1, LED_OFF);
        }
        if (millis() - t0 > 300 && millis() - t0 < 450)
        {
            microbit.drawPixel(alea, 0, LED_OFF);
            microbit.drawPixel(alea, 1, LED_ON);
        }
        if (millis() - t0 > 450 && millis() - t0 < 600)
        {
            microbit.drawPixel(alea, 1, LED_OFF);
            microbit.drawPixel(alea, 2, LED_ON);
        }
        if (millis() - t0 > 600 && millis() - t0 < 750)
        {
            microbit.drawPixel(alea, 2, LED_OFF);
            microbit.drawPixel(alea, 3, LED_ON);
        }
        if (millis() - t0 > 750)
        {
            microbit.drawPixel(alea, 3, LED_OFF);
        }
        if (millis() - t0 > 900 && millis() - t0 < 1050)
        {
            microbit.drawPixel(alea2, 0, LED_ON);
            microbit.drawPixel(alea2, 1, LED_OFF);
        }
        if (millis() - t0 > 1050 && millis() - t0 < 1200)
        {
            microbit.drawPixel(alea2, 0, LED_OFF);
            microbit.drawPixel(alea2, 1, LED_ON);
        }
        if (millis() - t0 > 1200 && millis() - t0 < 1350)
        {
            microbit.drawPixel(alea2, 1, LED_OFF);
            microbit.drawPixel(alea2, 2, LED_ON);
        }
        if (millis() - t0 > 1350 && millis() - t0 < 1500)
        {
            microbit.drawPixel(alea2, 2, LED_OFF);
            microbit.drawPixel(alea2, 3, LED_ON);
        }
        if (millis() - t0 > 1500)
        {
            microbit.drawPixel(alea2, 3, LED_OFF);
        }
        // COLLISIONS ET AFFICHAGE DES RESULTATS

        if ((millis() - t0 > 1500) && (alea2 == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
        if ((millis() - t0 > 750) && (millis() - t0 < 900) && (alea == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
    }
    else
    {
        if (millis() - t0 > 75 && millis() - t0 < 150)
        {
            microbit.drawPixel(alea, 0, LED_ON);
            microbit.drawPixel(alea, 1, LED_OFF);
        }
        if (millis() - t0 > 150 && millis() - t0 < 225)
        {
            microbit.drawPixel(alea, 0, LED_OFF);
            microbit.drawPixel(alea, 1, LED_ON);
        }
        if (millis() - t0 > 225 && millis() - t0 < 300)
        {
            microbit.drawPixel(alea, 1, LED_OFF);
            microbit.drawPixel(alea, 2, LED_ON);
        }
        if (millis() - t0 > 300 && millis() - t0 < 375)
        {
            microbit.drawPixel(alea, 2, LED_OFF);
            microbit.drawPixel(alea, 3, LED_ON);
        }
        if (millis() - t0 > 375)
        {
            microbit.drawPixel(alea, 3, LED_OFF);
        }
        if (millis() - t0 > 450 && millis() - t0 < 525)
        {
            microbit.drawPixel(alea2, 0, LED_ON);
            microbit.drawPixel(alea2, 1, LED_OFF);
        }
        if (millis() - t0 > 525 && millis() - t0 < 600)
        {
            microbit.drawPixel(alea2, 0, LED_OFF);
            microbit.drawPixel(alea2, 1, LED_ON);
        }
        if (millis() - t0 > 600 && millis() - t0 < 675)
        {
            microbit.drawPixel(alea2, 1, LED_OFF);
            microbit.drawPixel(alea2, 2, LED_ON);
        }
        if (millis() - t0 > 675 && millis() - t0 < 750)
        {
            microbit.drawPixel(alea2, 2, LED_OFF);
            microbit.drawPixel(alea2, 3, LED_ON);
        }
        if (millis() - t0 > 750)
        {
            microbit.drawPixel(alea2, 3, LED_OFF);
        }
        // COLLISIONS ET AFFICHAGE DES RESULTATS
        if ((millis() - t0 > 750) && (alea2 == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
        if ((millis() - t0 > 375) && (millis() - t0 < 450) && (alea == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
        if (millis() - t0 > 825 && millis() - t0 < 900)
        {
            microbit.drawPixel(alea, 0, LED_ON);
            microbit.drawPixel(alea, 1, LED_OFF);
        }
        if (millis() - t0 > 900 && millis() - t0 < 975)
        {
            microbit.drawPixel(alea, 0, LED_OFF);
            microbit.drawPixel(alea, 1, LED_ON);
        }
        if (millis() - t0 > 975 && millis() - t0 < 1050)
        {
            microbit.drawPixel(alea, 1, LED_OFF);
            microbit.drawPixel(alea, 2, LED_ON);
        }
        if (millis() - t0 > 1050 && millis() - t0 < 1125)
        {

            microbit.drawPixel(alea, 2, LED_OFF);
            microbit.drawPixel(alea, 3, LED_ON);
        }
        if (millis() - t0 > 1125)
        {
            microbit.drawPixel(alea, 3, LED_OFF);
        }
        if (millis() - t0 > 1200 && millis() - t0 < 1275)
        {
            microbit.drawPixel(alea2, 0, LED_ON);
            microbit.drawPixel(alea2, 1, LED_OFF);
        }
        if (millis() - t0 > 1275 && millis() - t0 < 1350)
        {
            microbit.drawPixel(alea2, 0, LED_OFF);
            microbit.drawPixel(alea2, 1, LED_ON);
        }
        if (millis() - t0 > 1350 && millis() - t0 < 1425)
        {
            microbit.drawPixel(alea2, 1, LED_OFF);
            microbit.drawPixel(alea2, 2, LED_ON);
        }
        if (millis() - t0 > 1425 && millis() - t0 < 1500)
        {
            microbit.drawPixel(alea2, 2, LED_OFF);
            microbit.drawPixel(alea2, 3, LED_ON);
        }
        if (millis() - t0 > 1500)
        {
            microbit.drawPixel(alea2, 3, LED_OFF);
        }
        // COLLISIONS ET AFFICHAGE DES RESULTATS
        if ((millis() - t0 > 1500) && (alea2 == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
        if ((millis() - t0 > 1200) && (millis() - t0 < 1275) && (alea == pos))
        {
            t1 = (millis() - t1) / 1000;
            microbit.print("PERDU SCORE :");
            microbit.print(t1);
            microbit.print("SECONDE");
            while (true)
                ;
        }
    }

    // ANIMATION SUR LES COTES
    if (millis() - t0 > 300 && millis() - t0 < 600)
    {
        microbit.drawPixel(0, 0, LED_OFF);
        microbit.drawPixel(0, 1, LED_ON);
        microbit.drawPixel(0, 2, LED_ON);
        microbit.drawPixel(0, 3, LED_ON);
        microbit.drawPixel(0, 4, LED_OFF);
        microbit.drawPixel(4, 0, LED_OFF);
        microbit.drawPixel(4, 1, LED_ON);
        microbit.drawPixel(4, 2, LED_ON);
        microbit.drawPixel(4, 3, LED_ON);
        microbit.drawPixel(4, 4, LED_OFF);
    }
    if (millis() - t0 > 600 && millis() - t0 < 900)
    {
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
    if (millis() - t0 > 900 && millis() - t0 < 1200)
    {
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
    if (millis() - t0 > 1200 && millis() - t0 < 1500)
    {
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
    if (millis() - t0 > 1500 && millis() - t0 < 1800)
    {
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
    if (millis() - t0 > 1800)
    {
        t0 = millis();
        alea = random(1, 4);
        alea2 = random(1, 4);
    }

    // DEPLACEMENT DU JOUEUR
    bool buttonA_now = digitalRead(buttonA);
    bool buttonB_now = digitalRead(buttonB);
    if (buttonA_now && !buttonA_last)
    {
        if (pos == 2)
        {
            microbit.drawPixel(1, 4, LED_ON);
            microbit.drawPixel(2, 4, LED_OFF);
            microbit.drawPixel(3, 4, LED_OFF);
            pos = 1;
        }
        else if (pos == 3)
        {
            microbit.drawPixel(1, 4, LED_OFF);
            microbit.drawPixel(2, 4, LED_ON);
            microbit.drawPixel(3, 4, LED_OFF);
            pos = 2;
        }
    }
    if (buttonB_now && !buttonB_last)
    {
        if (pos == 2)
        {
            microbit.drawPixel(1, 4, LED_OFF);

            microbit.drawPixel(2, 4, LED_OFF);
            microbit.drawPixel(3, 4, LED_ON);
            pos = 3;
        }
        else if (pos == 1)
        {
            microbit.drawPixel(1, 4, LED_OFF);
            microbit.drawPixel(2, 4, LED_ON);
            microbit.drawPixel(3, 4, LED_OFF);
            pos = 2;
        }
    }
    buttonA_last = buttonA_now;
    buttonB_last = buttonB_now;
}