#include <stdio.h>
 
int main(){
	int t,n;
	int i, sum=0, l;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d", &n);
		while(n>0){
			sum += n%10;
			while(n>0){
				l=n%10;
				n/=10;
			}
			sum+=l;
			printf("%d\n", sum);
		}
		sum = 0;		
	}
	return 0;
} 

