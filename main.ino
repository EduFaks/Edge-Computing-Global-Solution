// Global Solution 2024
// Eduardo Fakiani, Fernanda Rocha Menon, Luiza Macena Dantas

#include <OneWire.h> // Incluir bibilioteca para sensor da agua
#include <DallasTemperature.h> // Incluir bibilioteca para sensor da agua
#include <DHT.h>; // Incluir bibilioteca para sensor do ar
#include <Adafruit_MPU6050.h> // Incluir bibilioteca para o acelerometro
#include <Adafruit_Sensor.h> // Incluir bibilioteca para o acelerometro
#include <Wire.h> // Incluir bibilioteca para o acelerometro

#define LIGHT_SENSOR_PIN A0 // Pino analogico para o sensor de luz
#define AIR_SENSOR_PIN 8 // Pino digital do Sensor de temperatura e umidade do ar
#define WATER_TEMPERATURE_SENSOR_PIN 7 // Pino digital do Sensor de temperatura da agua

DHT airSensor(AIR_SENSOR_PIN, DHT22); // Objeto do sensor do ar

// Configurar objeto para sensor de temeperatura da agua
OneWire oneWire(WATER_TEMPERATURE_SENSOR_PIN);
DallasTemperature waterSensor(&oneWire);

// Configurar objeto para o acelerometro e giroscopio
Adafruit_MPU6050 mpu;

// Constantes usadas no calculo de Lux para o sensor de luz
const float GAMMA = 0.7;
const float RL10 = 50;

void setup() {
  Serial.begin(115200); // Iniciar o serial para enviar mensagems
  waterSensor.begin(); // Iniciar sensor de temperatura da agua
  airSensor.begin(); // Iniciar sensor do ar
  while (!mpu.begin()) {
    Serial.println("MPU6050 nao conectado!");
    delay(1000);
  } // Iniciar acelerometro e giroscopio
}

sensors_event_t event;

void loop() {
  // Ler e mostrar temperatura da agua
  waterSensor.requestTemperatures(); 
  float temperatureC = waterSensor.getTempCByIndex(0);
  Serial.print("- Temperatura da Agua: ");
  Serial.print(temperatureC);
  Serial.println("ºC");

  // Ler e mostrar temperatura e Umidade da agua
  Serial.print("- Temperatura do Ar: ");
  Serial.print(airSensor.readTemperature(), 0);
  Serial.println("ºC");
  Serial.print("- Umidade do Ar: ");
  Serial.print(airSensor.readHumidity());
  Serial.println("%");

  // Ler, converter para lux e mostrar iluminosidade do local
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  float voltage = analogValue / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));
  Serial.print("- Iluminosidade (Lux): ");
  Serial.println(analogValue); // 0.1 Escuridao - 100,000 Luz direta do sol


  // Ler, a aceleração e mostrar a movimentacao do mar
  mpu.getAccelerometerSensor()->getEvent(&event);
  Serial.print("- Aceleração: ");
  Serial.print("X: ");
  Serial.print(event.acceleration.x);
  Serial.print(" | Y: ");
  Serial.print(event.acceleration.y);
  Serial.print(" | Z: ");
  Serial.print(event.acceleration.z);
  Serial.println(" m/s^2");

  // Imprimir separador e pausar antes da proxima leitura
  Serial.println("----------------------------------");
  delay(2000);

  // Caso o projeto seja feito utilizando ESP32's com acesso a internet
  // Aqui seria o envio dos dados para um servidor armazenar 
  // e disponibilizar para os usuarios
}