#include <stdio.h>

int main(){
	int t, n;
	scanf("%d", &t);
	int i, sum=1;
	if(t>=1 && t<=100){
		for(i=0;i<t;i++){
			scanf("%d", &n);
			if(n>=1 && n<=100){
				while(n>0){
					sum=sum*n;
					n--;
				}
				printf("%d\n", sum);
				sum=1;
			}
			else{
				return 0;
			}
		}
		return 0;
	}
}
