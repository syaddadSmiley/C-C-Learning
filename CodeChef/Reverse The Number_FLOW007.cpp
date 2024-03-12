#include <stdio.h>

int main(){
	int t, n, sum=0;
	scanf("%d", &t);
	int i;
	for(i=0;i<t;i++){
		scanf("%d", &n);
		while(n>0){
			sum = sum*10 + n%10;
			n/=10;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}
