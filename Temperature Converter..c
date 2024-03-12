#include <stdio.h>

void counting(int C);
void check(int C);

int main(){
	int TC;
	printf("\nBerapa Derajat Celcius?\nCelcius : ");
	fflush(stdin);
	while(!scanf("%d", &TC)){
		printf("-----------------------------");
		printf("\nInvalid Input! Try Again\n");
		printf("-----------------------------");
		fflush(stdin);
		main();		
	}
	counting(TC);
	fflush(stdin);
}

void counting(int C){
	int F=0, R=0, K=0;
	F = (C*9.0/5.0)+32;
	R = C*4.0/5.0;
	K = C + 273;
	printf("=========================");
	printf("\nCelcius : %d C\n", C);
	printf("\nFahrenheit : %d F\n", F);
	printf("Reamur : %d R\n", R);
	printf("Kelvin : %d K\n", K);
	printf("=========================");
	main();
}


//void check(int C){
//	if(C == -1000){
//		printf("\nInvalid Input! Try Again\n");
//		main();
//	}
//	else{
//		counting(C);
//	}
//}
