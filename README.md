# SmartDistance
Esta biblioteca para a plataforma Arduino utiliza um sensor ultrassônico HC-SR04 para o calculo da distância com base na velocidade do som. Existe 2 funções que efetuam esse calculo, a primeira utiliza o valor medio da velocidade do som e a segunda usa como base a temperatura do ambiente para calcular a respectiva velocidade do som.

#Recursos
Inicialmente será necessário instanciar um objeto do tipo smartDistance com os valores referentes aos pinos de TRIGGER e ECHO:
>smartDistance OBJ(trigger,echo);

A função getPulseTime() envia o sinal para o trigger e obtém o tempo resposta através do echo recebido. Essa função deve ser utilizada para inicializar o módulo a cada loop.Ex:

> OBJ.getPulseTime();

A função distanceAverage() utiliza o tempo de resposta obtido pelo echo e com base no valor médio da velocidade do som (340m/s) se obtém a distância em cm, é válido ressaltar que a função recebe como parâmetro o valor referente ao tempo de resposta:

> OBJ.distanceAverage(float tempo);

A função distanceSmart() utiliza o tempo de resposta obtido pelo echo, e com base no valor da velocidade do som calculada em função da temperatura ambiente, se obtém a distância em cm, é válido ressaltar que a função recebe como parâmetro o valor referente ao tempo de resposta e a temperatura atual do ambiente em Celsius (°C):

> OBJ.distanceSmart(float tempo,float temperature);

#Exemplo:

O código exemplo utiliza um thermistor para o cálculo da temperatura:

```
/*
	Autor:Ronald Lopes
	Versão:1.0
	Descrição: Esta biblioteca utiliza um sensor ultrassonico HC-SR04 para o calculo da distância com base na velocidade do som. Existe 2 funções que efetuam esse calculo, a primeira utiliza o valor medio da velocidade do som e a segunda usa como base a temperatura do ambiente para calcular a respectiva velocidade do som.
*/
#include <Thermistor.h> // necessario para o calculo da temperatura neste caso, você pode optar por outras bibliotecas que calculam a temperatura

#include <smartDistance.h>
#define trigger 13
#define echo 12

smartDistance OBJ(trigger,echo); // inicia a biblioteca com os valores do trigger e echo

Thermistor temp(0); // calculo da temperatura
void setup()
{
  Serial.begin(9600);
}

void loop()
{
	 float temperature = temp.getTemp();
	 float tempo=  OBJ.getPulseTime(); // inicializa o sensor ultrassonico e retorna o tempo de resposta do echo
	 float distancia = OBJ.distanceAverage(tempo); //retorna a distancia em CM com base no tempo e utilizando a velocidade média do som
	 Serial.print("Distancia Metodo 1: ");
	 Serial.println(distancia);
	 distancia = OBJ.distanceSmart(tempo,temperature);  //retorna a distancia em CM com base no tempo e utilizando a velocidade atual do som com base na temperatura do ambiente que foi obtida. (O valor da temperatura deve ser em °C )
	 Serial.print("Distancia Metodo 2 (Com base na temperatura ambiente): ");
	 Serial.println(distancia);
	 delay(1000);

}

``` 

