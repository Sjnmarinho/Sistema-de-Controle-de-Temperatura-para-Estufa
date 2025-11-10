// Projeto: Sistema de Controle de Temperatura para Estufa
// Autor: [Seu Nome]
// Data: [Data]

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
  tone(PIN_BUZZER, 1000, 500);      // Ativa buzzer frequência e duração(1000 Hz)
}

// Função para desativar alarme
void desativarAlarme() {
  digitalWrite(PIN_LED, LOW);       // Apaga LED
  noTone(PIN_BUZZER);               // Desliga buzzer
}