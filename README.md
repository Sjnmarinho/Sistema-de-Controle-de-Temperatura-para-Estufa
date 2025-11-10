# 🔧 Projeto: Sistema de Controle de Temperatura para Estufa

## 📋 Componentes Necessários

Arduino Uno
Sensor de Temperatura (TMP36 ou LM35)
Motor DC (ventilador)
LED Vermelho
Buzzer
Resistor 330Ω para o LED
Transistor TIP120 (para controlar o motor)
Resistor 1kΩ entre a base e pino 9 
Diodo 1N4001
Fios e protoboard

## 🔌 Esquema de Ligação

### Sensor TMP36:
Pino VCC → 5V
Pino Vout → A0
Pino GND → GND

### Motor DC:

Terminal positivo → Coletor do TIP120
Terminal negativo → GND
Base do TIP120 → Pino 9 (com resistor 1k)
Emissor do TIP120 → GND
Diodo em paralelo com o motor (proteção)

### LED Vermelho:

Ânodo → Pino 10 (com resistor 220Ω)
Catodo → GND

### Buzzer:

Terminal positivo → Pino 11
Terminal negativo → GND

## 💻 Código Arduino (Linguagem C)

// Projeto: Sistema de Controle de Temperatura para Estufa
// Autor: Sebastião Marinho
// Data: 10/11/2025

// Definição dos pinos
const int SENSOR_TEMP = A0;    // Pino do sensor de temperatura
const int PIN_MOTOR = 9;       // Pino do motor/ventilador
const int PIN_LED = 10;        // Pino do LED vermelho
const int PIN_BUZZER = 11;     // Pino do buzzer

// Variáveis
float temperatura = 0;         // Armazena a temperatura lida
const int TEMP_VENTILADOR = 30; // Temperatura para ligar ventilador (30°C)
const int TEMP_EMERGENCIA = 50; // Temperatura de emergência (50°C)

void setup() {
  // Configuração dos pinos
  pinMode(SENSOR_TEMP, INPUT);
  pinMode(PIN_MOTOR, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  
  // Inicialmente desliga todos os dispositivos
  digitalWrite(PIN_MOTOR, LOW);
  digitalWrite(PIN_LED, LOW);
  digitalWrite(PIN_BUZZER, LOW);
  
  // Inicializa comunicação serial para monitoramento
  Serial.begin(9600);
  Serial.println("Sistema de Controle de Temperatura - Estufa");
  Serial.println("===========================================");
}

void loop() {
  // Lê a temperatura do sensor
  temperatura = lerTemperatura();
  
  // Exibe a temperatura no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  // Controle do ventilador
  if (temperatura >= TEMP_VENTILADOR) {
    digitalWrite(PIN_MOTOR, HIGH);
    Serial.println("Ventilador LIGADO - Resfriamento ativo");
  } else {
    digitalWrite(PIN_MOTOR, LOW);
    Serial.println("Ventilador DESLIGADO - Temperatura normal");
  }
  
  // Controle de emergência (LED e buzzer)
  if (temperatura >= TEMP_EMERGENCIA) {
    ativarAlarme();
    Serial.println("ALARME! Temperatura crítica!");
  } else {
    desativarAlarme();
  }
  
  delay(2000); // Aguarda 2 segundos entre as leituras
}

// Função para ler temperatura do sensor TMP36
float lerTemperatura() {
  int valorSensor = analogRead(SENSOR_TEMP);
  float tensao = (valorSensor * 5.0) / 1024.0; // Converte para tensão
  float temperaturaC = (tensao - 0.5) * 100;   // Converte para °C (TMP36)
  return temperaturaC;
}

// Função para ativar alarme de emergência
void ativarAlarme() {
  digitalWrite(PIN_LED, HIGH);      // Acende LED vermelho
  tone(PIN_BUZZER, 1000, 500);           // Ativa buzzer frequência e duração (1000 Hz)
}

// Função para desativar alarme
void desativarAlarme() {
  digitalWrite(PIN_LED, LOW);       // Apaga LED
  noTone(PIN_BUZZER);               // Desliga buzzer
}



## 🎯 Funcionalidades Implementadas

Leitura de Temperatura ✅

Sensor TMP36 conectado ao pino analógico A0
Conversão precisa para graus Celsius

Controle do Ventilador ✅

Aciona quando temperatura ≥ 30°C
Desliga quando temperatura < 30°C
Uso de transistor para controle do motor

Sistema de Alarme ✅

LED vermelho piscante
Buzzer sonoro
Ativa quando temperatura ≥ 50°C



## 🔧 Instruções para Simulação no TinkerCad

Acesse o TinkerCad: https://www.tinkercad.com/

Crie novo circuito: "Circuits" → "Create new Circuit"

Adicione componentes:

Arduino Uno R3

TMP36 Temperature Sensor

DC Motor

LED (vermelho)

Buzzer

NPN Transistor (TIP120)

Resistors (220Ω, 1kΩ)

Diode (1N4001)

Monte o circuito conforme o esquema acima

Cole o código no editor Arduino

Simule e teste diferentes temperaturas


📊 Teste do Sistema

Temperatura	Ventilador	LED	  Buzzer	  Status

< 30°C	    ❌	        ❌	  ❌	    Normal

≥ 30°C	    ✅	        ❌	   ❌    Aquecendo

≥ 50°C	    ✅	        ✅	   ✅    Emergência

## 🚀 Melhorias Futuras

*Display LCD para mostrar temperatura
*Controle PID para temperatura precisa
*Sensores adicionais (umidade, luminosidade)
*Comunicação WiFi para monitoramento remoto



Histórico de temperaturas

