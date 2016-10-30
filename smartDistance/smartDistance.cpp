/*
	Autor:Ronald Lopes
	Versão:1.0
	Descrição: Esta biblioteca utiliza um sensor ultrassonico HC-SR04 para o calculo da distância com base na velocidade do som. Existe 2 funções que efetuam esse calculo, a primeira utiliza o valor medio da velocidade do som e a segunda usa como base a temperatura do ambiente para calcular a respectiva velocidade do som.
*/

#include "Arduino.h"
#include "smartDistance.h"

smartDistance::smartDistance(int trigger, int echo)
{
  pinMode(trigger,OUTPUT);
  	pinMode(echo,INPUT);
  	_trigger= trigger;
  	_echo= echo;
}


float smartDistance::getPulseTime()
{
  digitalWrite(_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger,LOW);
  float tempo = pulseIn(_echo,HIGH);
  return tempo;
}

float smartDistance::distanceAverage(float tempo)
{

  float distancia = (tempo/2)/29;
  return distancia;

}
float smartDistance::soundVelocity(float temperatura)
{
  float velocity= sqrt(401.388*(temperatura+273));
  velocity= velocity*100; //converto de metro/s para cm/s
  velocity= velocity/1000000; //converto de cm/s para cm/ms
  velocity= (1/velocity);  // 1cm equivale a x microsegundos
  return velocity;
}

float smartDistance::distanceSmart(float tempo, float temp)
{

  float distancia = (tempo/2)/soundVelocity(temp);
  return distancia;

}


