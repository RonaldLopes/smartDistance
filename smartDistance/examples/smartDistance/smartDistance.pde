/*
	Autor:Ronald Lopes
	Versão:1.0
	Descrição: Esta biblioteca utiliza um sensor ultrassonico HC-SR04 para o calculo da distância com base na velocidade do som. Existe 2 funções que efetuam esse calculo, a primeira utiliza o valor medio da velocidade do som e a segunda usa como base a temperatura do ambiente para calcular a respectiva velocidade do som.
*/
#include <Thermistor.h> // necessario para o calculo da temperatura neste caso, você pode optar por outras bibliotecas que calculam a temperatura

#include <smartDistance.h>
#define trigger 13
#define echo 12

smartDistance smart(trigger,echo); // inicia a biblioteca com os valores do trigger e echo

Thermistor temp(0); // calculo da temperatura
void setup()
{
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
}

void loop()
{
	 float temperature = temp.getTemp();   
	 float tempo=  smart.getPulseTime(); // inicializa o sensor ultrassonico e retorna o tempo de resposta do echo
	 float distancia = smart.distanceAverage(tempo); //retorna a distancia em CM com base no tempo e utilizando a velocidade média do som
	 Serial.print("Distancia Metodo 1: ");
	 Serial.println(distancia);
	 distancia = smart.distanceSmart(tempo,temperature);  //retorna a distancia em CM com base no tempo e utilizando a velocidade atual do som com base na temperatura do ambiente que foi obtida. (O valor da temperatura deve ser em °C )
	 Serial.print("Distancia Metodo 2 (Preciso): ");
	 Serial.println(distancia);
	 delay(1000);

}
