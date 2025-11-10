🔧 Projeto: Sistema de Controle de Temperatura para Estufa

📋 Componentes Necessários

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



🔌 Esquema de Ligação

text

Sensor TMP36:

\- Pino VCC → 5V

\- Pino Vout → A0

\- Pino GND → GND



Motor DC:

\- Terminal positivo → Coletor do TIP120

\- Terminal negativo → GND

\- Base do TIP120 → Pino 9 (com resistor 1k)

\- Emissor do TIP120 → GND

\- Diodo em paralelo com o motor (proteção)



LED Vermelho:

\- Ânodo → Pino 10 (com resistor 220Ω)

\- Catodo → GND



Buzzer:

\- Terminal positivo → Pino 11

\- Terminal negativo → GND





💻 Código Arduino (Linguagem C)



// Projeto: Sistema de Controle de Temperatura para Estufa

// Autor: \[Seu Nome]

// Data: \[Data]



// Definição dos pinos

const int SENSOR\_TEMP = A0;    // Pino do sensor de temperatura

const int PIN\_MOTOR = 9;       // Pino do motor/ventilador

const int PIN\_LED = 10;        // Pino do LED vermelho

const int PIN\_BUZZER = 11;     // Pino do buzzer



// Variáveis

float temperatura = 0;         // Armazena a temperatura lida

const int TEMP\_VENTILADOR = 30; // Temperatura para ligar ventilador (30°C)

const int TEMP\_EMERGENCIA = 50; // Temperatura de emergência (50°C)



void setup() {

&nbsp; // Configuração dos pinos

&nbsp; pinMode(SENSOR\_TEMP, INPUT);

&nbsp; pinMode(PIN\_MOTOR, OUTPUT);

&nbsp; pinMode(PIN\_LED, OUTPUT);

&nbsp; pinMode(PIN\_BUZZER, OUTPUT);

&nbsp; 

&nbsp; // Inicialmente desliga todos os dispositivos

&nbsp; digitalWrite(PIN\_MOTOR, LOW);

&nbsp; digitalWrite(PIN\_LED, LOW);

&nbsp; digitalWrite(PIN\_BUZZER, LOW);

&nbsp; 

&nbsp; // Inicializa comunicação serial para monitoramento

&nbsp; Serial.begin(9600);

&nbsp; Serial.println("Sistema de Controle de Temperatura - Estufa");

&nbsp; Serial.println("===========================================");

}



void loop() {

&nbsp; // Lê a temperatura do sensor

&nbsp; temperatura = lerTemperatura();

&nbsp; 

&nbsp; // Exibe a temperatura no monitor serial

&nbsp; Serial.print("Temperatura: ");

&nbsp; Serial.print(temperatura);

&nbsp; Serial.println(" °C");

&nbsp; 

&nbsp; // Controle do ventilador

&nbsp; if (temperatura >= TEMP\_VENTILADOR) {

&nbsp;   digitalWrite(PIN\_MOTOR, HIGH);

&nbsp;   Serial.println("Ventilador LIGADO - Resfriamento ativo");

&nbsp; } else {

&nbsp;   digitalWrite(PIN\_MOTOR, LOW);

&nbsp;   Serial.println("Ventilador DESLIGADO - Temperatura normal");

&nbsp; }

&nbsp; 

&nbsp; // Controle de emergência (LED e buzzer)

&nbsp; if (temperatura >= TEMP\_EMERGENCIA) {

&nbsp;   ativarAlarme();

&nbsp;   Serial.println("ALARME! Temperatura crítica!");

&nbsp; } else {

&nbsp;   desativarAlarme();

&nbsp; }

&nbsp; 

&nbsp; delay(2000); // Aguarda 2 segundos entre as leituras

}



// Função para ler temperatura do sensor TMP36

float lerTemperatura() {

&nbsp; int valorSensor = analogRead(SENSOR\_TEMP);

&nbsp; float tensao = (valorSensor \* 5.0) / 1024.0; // Converte para tensão

&nbsp; float temperaturaC = (tensao - 0.5) \* 100;   // Converte para °C (TMP36)

&nbsp; return temperaturaC;

}



// Função para ativar alarme de emergência

void ativarAlarme() {

&nbsp; digitalWrite(PIN\_LED, HIGH);      // Acende LED vermelho

&nbsp; tone(PIN\_BUZZER, 1000, 500);           // Ativa buzzer frequência e duração(1000 Hz)

}



// Função para desativar alarme

void desativarAlarme() {

&nbsp; digitalWrite(PIN\_LED, LOW);       // Apaga LED

&nbsp; noTone(PIN\_BUZZER);               // Desliga buzzer

}





🎯 Funcionalidades Implementadas

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



🔧 Instruções para Simulação no TinkerCad

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

Temperatura	Ventilador	LED	Buzzer	Status

< 30°C	❌	❌	❌	Normal

≥ 30°C	✅	❌	❌	Aquecendo

≥ 50°C	✅	✅	✅	Emergência

🚀 Melhorias Futuras

Display LCD para mostrar temperatura



Controle PID para temperatura precisa



Sensores adicionais (umidade, luminosidade)



Comunicação WiFi para monitoramento remoto



Histórico de temperaturas

