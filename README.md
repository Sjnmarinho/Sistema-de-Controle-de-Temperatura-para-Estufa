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

## 🎯 Funcionalidades Implementadas

### Leitura de Temperatura ✅

Sensor TMP36 conectado ao pino analógico A0
Conversão precisa para graus Celsius

### Controle do Ventilador ✅

Aciona quando temperatura ≥ 30°C
Desliga quando temperatura < 30°C
Uso de transistor para controle do motor

### Sistema de Alarme ✅

LED vermelho piscante
Buzzer sonoro
Ativa quando temperatura ≥ 50°C


## 🔧 Instruções para Simulação no TinkerCad

1 - Acesse o TinkerCad: https://www.tinkercad.com/

2 - Crie novo circuito: "Circuits" → "Create new Circuit"

3 - Adicione componentes:

* Arduino Uno R3
* TMP36 Temperature Sensor
* DC Motor
* LED (vermelho)
* Buzzer
* NPN Transistor (TIP120)
* Resistors (220Ω, 1kΩ)
* Diode (1N4001)

4 - Monte o circuito conforme o esquema acima

5 - Cole o código no editor Arduino

6 - Simule e teste diferentes temperaturas


## 📊 Teste do Sistema

Temperatura	Ventilador	LED	  Buzzer	  Status

< 30°C	    ❌	        ❌	  ❌	    Normal

≥ 30°C	    ✅	        ❌	   ❌    Aquecendo

≥ 50°C	    ✅	        ✅	   ✅    Emergência

## 🚀 Melhorias Futuras

* Display LCD para mostrar temperatura
* Controle PID para temperatura precisa
* Sensores adicionais (umidade, luminosidade)
* Comunicação WiFi para monitoramento remoto


