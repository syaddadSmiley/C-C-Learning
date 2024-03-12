#include <stdio.h>

int main(){
	int t, n, l, sum=0;
	scanf("%d", &t);
	int i;
	for(i=0;i<t;i++){
		scanf("%d", &n);
		while(n>0){
			l=n%10;
			if(l==4){
				sum+=1;
			}
			n/=10;
		}
		printf("%d\n", sum);
		sum=0;
	}
	return 0;
}
