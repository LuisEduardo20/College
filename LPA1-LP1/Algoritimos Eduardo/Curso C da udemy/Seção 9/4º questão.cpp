//diz se um numero � quadrado perfeito ou n�o
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>

void quadrado_perf(int x);

int main(){
	setlocale(LC_ALL,"Portuguese");
	int num;
	
	printf("Digite um n�mero para saber se � quadrado perfeito ou n�o: ");
	scanf("%d",&num);
	
	if(num==1){
		printf("\nO numero � um quadrado perfeito!");
		return 0;
	}
	
	quadrado_perf(num);
	
	return 0;
}

void quadrado_perf(int x){
	int i = sqrt(x);
	if(i)
}
