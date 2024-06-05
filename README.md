# Edge-Computing Global Solution FIAP 2024

### Monitoramento de Vários Locais no Mar

**Autores:** Eduardo Fakiani, Fernanda Rocha Menon, Luiza Macena Dantas

## Descrição do Projeto

O projeto Global Solution 2024 tem como objetivo monitorar diversos parâmetros ambientais em locais no mar utilizando um sistema baseado em Arduino. Este sistema será capaz de medir a temperatura da água, temperatura e umidade do ar, luminosidade e aceleração. Os dados coletados poderão ser enviados para um servidor para armazenamento e análise.

## Demonstracao

- Simulador: https://wokwi.com/projects/399820727907001345
- Video Explicativo: https://github.com/EduFaks/Edge-Computing-Global-Solution/blob/main/adicionais/explanation.mp4

## Descrição dos Arquivos

- ```main.ino``` Arquivo contendo o codigo fonte para o arduino
- ```diagram.json``` Arquivo contendo layout das peças no simulator WOKWI
- ```adicionais/``` Diretorio contendo conteudo do readme

## Componentes Utilizados

- **Sensor de Temperatura da Água:** Dallas DS18B20
- **Sensor de Temperatura e Umidade do Ar:** DHT22
- **Sensor de Luminosidade:** LDR (Light Dependent Resistor)
- **Acelerômetro e Giroscópio:** Adafruit MPU6050
- **Arduino Uno**

## Bibliotecas Necessárias

As seguintes bibliotecas devem ser instaladas no Arduino IDE para que o projeto funcione corretamente:

- OneWire
- DallasTemperature
- DHT
- Adafruit_MPU6050
- Adafruit_Sensor
- Wire

## Montagem do Circuito

1. Conecte o sensor de temperatura da água ao pino digital 7 do Arduino.
2. Conecte o sensor de temperatura e umidade do ar ao pino digital 8 do Arduino.
3. Conecte o sensor de luminosidade ao pino analógico A0 do Arduino.
4. Conecte o acelerômetro e giroscópio (MPU6050) aos pinos I2C do Arduino (A4 para SDA e A5 para SCL).


![circuit](https://github.com/EduFaks/Edge-Computing-Global-Solution/blob/main/adicionais/circuit.png?raw=true)


## Futuras Implementações

- Envio dos dados coletados para um servidor remoto utilizando ESP32 com conectividade Wi-Fi.
