/*
	Autor:Ronald Lopes
	Versão:1.0
	Descrição: Esta biblioteca utiliza um sensor ultrassonico HC-SR04 para o calculo da distância com base na velocidade do som. Existe 2 funções que efetuam esse calculo, a primeira utiliza o valor medio da velocidade do som e a segunda usa como base a temperatura do ambiente para calcular a respectiva velocidade do som.
*/

#ifndef smartDistance_h
#define smartDistance_h

#include "Arduino.h"

class smartDistance
{
  public:
    smartDistance(int trigger, int echo);
    float getPulseTime();
	float distanceAverage(float tempo);
	float distanceSmart(float tempo, float temperatura);
  private:
    int _trigger, _echo;
    float soundVelocity(float temperatura);
};

#endif