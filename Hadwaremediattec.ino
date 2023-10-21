// Importa las bibliotecas necesarias
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const byte pHpin = A0;// conectar el sensor en analogo 0
float Po;
const int rele1 = 2;
const int rele2 = 3;
const int rele3 = 4;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//Inicimos la librería
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Define el sensor de pH


// Variables
float ph;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1000);
//Limpiamos la pantalla
  display.clearDisplay();


  // Inicializa los relés
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  pinMode(rele3, OUTPUT);

}

// Bucle principal
void loop() {
  // Lee el pH
Po = (1023 - analogRead(pHpin)) / 73.07; //invierta el valor de entrada analógica del sensor de pH y luego escale 0-14
Serial.println(Po, 2);// imprimir resultados
delay(1000);// esperar un segundo

  // Si el pH es menor que 8, activa el primer relé
  if (ph > 8) {
    digitalWrite(rele1, HIGH);
  } else {
    digitalWrite(rele1, LOW);
  }

  // Si el pH es mayor que 8, activa el segundo y tercer relé
  if (Po < 8) {
    digitalWrite(rele2, HIGH);
    digitalWrite(rele3, HIGH);
  } else {
    digitalWrite(rele2, LOW);
    digitalWrite(rele3, LOW);
  }
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(50, 10);
  display.println("pH");
  display.setCursor(50, 50);
  display.println(Po);
  display.display(); 
  // Espera 1 segundo
  delay(1000);
}
