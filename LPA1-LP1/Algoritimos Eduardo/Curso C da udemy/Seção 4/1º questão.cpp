#include<stdio.h>
#include<stdlib.h>

int main(){
	int num1, num2;
	
	printf("Digite um numero: ");
	scanf("%i",&num1);
	
	printf("Digite outro numero: ");
	scanf("%i",&num2);

	//come�o do if(se)
	if(num2>num1){
		printf("%i e menor que %i.",num2, num1);
	}else if(num2==num1){//segunda condi��o caso a primeira n�o ocorra
		printf("Os numeros sao iguais!");
	}else{//ultima condi��o possivel caso as duas acimas n�o ocorram
		printf("%i e menor que %i.",num1, num2);
	}
	
	return 0;
}
