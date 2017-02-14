#include <CapacitiveSensor.h>
//La pin qui envoie le signal est la D4 (sendPin) et
//la variation est lue sur la pin 2 (ReceivePin) :
CapacitiveSensor surface = CapacitiveSensor(4,2);

void setup() {
  Serial.begin(9600);
}

void loop() {
  long start = millis();
  //On règle la sensibilité du capteur à 30
  //l'unité est arbitraire
  long valeur = surface.capacitiveSensor(30);
  //Quelques lignes pour connaitre le temps de réponse.
  // en millisecondes
  Serial.print(millis() - start);
  //Caractere de tabulation du port serie
  Serial.print("\t");
  Serial.println(valeur);
  if (valeur>6000){
    Serial.println("On a touché!");
  }
  delay(200);
}


