#include <stdio.h>

int main(void){
	int x;
	float y;
	scanf("%d %f", &x, &y);
	if(x%5 == 0 && x>0 && x<=2000 && y>0 && y<=2000){
		if(x <= y-0.50){
			printf("%.2f", y-x-0.50);
			return 0;
		}
		printf("%.2f", y);
	}
	else if(x<=0 || x>=2000 || y<=0 || y>=2000){
		return 0;
	}
	else{
		printf("%.2f", y);
	}
	
	
}
