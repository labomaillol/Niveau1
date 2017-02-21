/*  Module bluetooth HC-06 */

//Assignation des pins de l'Arduino
#define Led 2

//Déclaration de variable
char instruction; // le message recu par bluetooth;

void setup()
{
  Serial.begin(9600);
  //On initialise la LED
  pinMode(Led, OUTPUT);
  //On la fait clignotter pour vérifier son
  //bon fonctionnement
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Led, LOW);
  delay(1000);
  digitalWrite(Led, HIGH);
  delay(1000);
  digitalWrite(Led, LOW);
}


void loop()
{
  char message;
  if (Serial.available()) // réception d'un message
  {
    message = Serial.read(); // lecture du message reçu
  }
  if (message != instruction) { // alors c'est un nouveau message

    instruction = message;

    if (instruction == 'a')
    {
    digitalWrite(Led, LOW); 
    }
    else if (instruction == 'b')
    {
    digitalWrite(Led, HIGH); 
    }
  }
  delay(100);
}



