#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//declara��o de vari�veis
	float numero, quadrado, operacao;
	
	//pede e recebe o n�mero
	printf("Digite um valor e saiba o seu quadrado: ");
	scanf("%f",&numero);
	
	quadrado = numero;
	
	//opera��o matem�tica
	operacao = numero * quadrado;
	
	printf("O quadrado do numero e: %f",operacao);
	
	return 0;
}
