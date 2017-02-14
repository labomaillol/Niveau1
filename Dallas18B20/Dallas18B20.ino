//On inclue les librairies
#include <OneWire.h>
#include <DallasTemperature.h>

//On connecte la broche de lecture à la pin 2 de l'Arduino
#define ONE_WIRE_BUS 2
//On cherche les thermomètres connectés à cette pin:
OneWire oneWire(ONE_WIRE_BUS);
//On envoie les références trouvées à la librairie Dallas
DallasTemperature sensors(&oneWire);

void setup(void)
{
  //On initialise la communication avec le moniteur série
  Serial.begin(9600); 
  //On initialise les capteurs dallas
  sensors.begin();
}

void loop(void)
{ 
  //On envoie la commande de récupération de température
  sensors.requestTemperatures();  
  Serial.print("La temperature est: ");                                         
  //On lui demande d'afficher la valeur du premier capteur (le 0)
  Serial.println(sensors.getTempCByIndex(0));
  //On laisse souffler une seconde avant de relancer.
  delay(1000);
}

