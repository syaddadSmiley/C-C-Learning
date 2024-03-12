#include <stdio.h>
#include <math.h>

int main(){
	int t,n,l;
	scanf("%d", &t);
	int i;
	for(i=0;i<t;i++){
		scanf("%d", &n);
		l = sqrt(n);
		printf("%d\n", l);
	}
	return 0;
}
