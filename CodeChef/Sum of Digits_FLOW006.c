#include <stdio.h>

int main(){
	int n, t, sum=0, it;
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d", &t);
		while(t>0){
			it = t%10;
			sum += it;
			t/=10;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	
}
