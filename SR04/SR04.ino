/* Utilisation du capteur de distance à Ultrason SR04  */

//Assignation des pins de l'Arduino

#define echoPin 6
#define trigPin 7

//On initialise les valeurs utiles par la suite 
int mesure = 0;
int total = 0;
//La vitesse du son variant en fonction de la température
//et de l'atmosphère, elle pourra être réglée  par
//étalonnage
int vitesse=340;

void setup()
{
  Serial.begin(9600);
  //On définit les modes des pins
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  //On s'assure que l'émetteur est éteint
  digitalWrite(trigPin, LOW);
}

void loop()
{
  //On définit le temps et la distance pour le SR04
  long temps, distance;
  //variable servant à mesurer plusieurs fois la distance
  //avant d'en afficher la moyenne
  mesure=mesure+1; 
  //On allume l'émetteur ultrason
  digitalWrite(trigPin, HIGH);
  //Durée d'initialisation du capteur
  delayMicroseconds(10);
  //Pulsation ultrasonore émise, on éteint l'émetteur
  digitalWrite(trigPin, LOW);
  //On définit la pin Echo comme en attente de message
  pinMode(echoPin, INPUT);
  //On recoit l'impulsion sur le récepteur
  temps = pulseIn(echoPin, HIGH);
  //On définit la distance comme étant le produit de la 
  //vitesse par le temps divisé par deux pour l'A-R.
  //Le temps étant en microsec(10^-6) et pour avoir d 
  //en cm (10-2), on divise par 10 000 (10^-4)
  distance = temps * vitesse/(2*10000);
  //On créé une variable total qui sera la distance totale
  // pour 10 mesures.
  total=total+distance;
  //Si les 10 mesures sont faites :
  if (mesure==10){
    //On fait la moyenne des 10 mesures
    distance=total/10;
    // on affiche l'information sur le moniteur série:
    Serial.print("Distance:  ");
    Serial.print(distance);
    Serial.println(" cm");
    //On remet mesure à 0 pour recommencer une série
    mesure=0;
    }
}
