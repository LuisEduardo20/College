#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	//declara��o das vari�veis
	int num1, num2, num3, conta;
	
	//pergunta e recebe o 1� valor
	printf("Digite o primeiro valor: ");	
	scanf("%i",&num1);
	
	//pergunta e recebe o 2� valor
	printf("Digite o segundo valor: ");	
	scanf("%i",&num2);
	
	//pergunta e recebe o 3� valor
	printf("Digite o terceiro valor: ");	
	scanf("%i",&num3);
	
	//opera��o matem�tica
	conta = (num1 + num2 + num3);
	
	//imprimi o resultado
	printf("A soma dos tres valores e: %i",conta);
	
	return 0;
	
}
