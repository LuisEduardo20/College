//Imprime o dobro de um numero
#include<stdio.h>
#include<stdlib.h>

int dobro(int x){//fun��o que pegara o numero e  multiplicar� por 2
	return x*2;
}

int main(){
	int num;
	
	printf("Digite um numero: ");
	scanf("%d",&num);
	
	printf("\nO numero e %d e seu dobro e %d.", num, dobro(num));//passagem do num digitado pelo usuario para a fun��o
	
	return 0;
}
