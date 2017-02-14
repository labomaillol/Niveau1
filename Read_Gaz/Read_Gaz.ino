/*Lecture entrée analogique*/
int concentration_max=50000;
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Lecture de la valeur de la pin A7:
  int sensorValue = analogRead(A7);
  // Conversion de la valeur (0 - 1023) en concentration:
  float concentration = sensorValue * (concentration_max / 1023.0);
  // print out the value you read:
  Serial.print(concentration);
  Serial.println(" ppm");
}


