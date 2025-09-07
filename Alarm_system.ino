// Définition des numéros de port 
const int trigPin = 6; // Trigger (emission) 
const int echoPin = 5; // Echo (réception) 
const int redPin = 11; // Red color 
const int bluePin = 10; // Blue color 
const int greenPin = 9; // Green color 
const int buzzerPin = 3; // Buzzer
// Variables utiles 
long duree; // durée de l'echo 
int distance; // distance 

void setup() { 
   pinMode(trigPin, OUTPUT); // Configuration du port du Trigger comme une SORTIE 
   pinMode(echoPin, INPUT); // Configuration du port de l'Echo comme une ENTREE 
   Serial.begin(9600); // Démarrage de la communication série
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
} 

void loop() { 
   // Émission d'un signal de durée 10 microsecondes 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(10); 
   digitalWrite(trigPin, LOW); 

   // Écoute de l'écho 
   duree = pulseIn(echoPin, HIGH); 

   // Calcul de la distance 
   distance = duree*0.034/2; 

   // Affichage de la distance dans le Moniteur Série 
   Serial.print("Distance : "); 
   Serial.print(distance); 
   Serial.println("cm"); 
  
  // Déclenche l'alarme si la distance est inférieur à un certain seuil.
  if (distance < 50) {
  	analogWrite(redPin, 255);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 0);
    analogWrite(buzzerPin, 5);
  } else {
    analogWrite(redPin,0);
    analogWrite(bluePin, 0);
    analogWrite(greenPin, 255);
    digitalWrite(buzzerPin, 0);
  }
   // Un délai de 100ms entre deux mesures
  delay(100);
}