#include <stdio.h>
 
 int main(void){
 	int n, k, t, i, c=0;
 	scanf("%d %d", &n, &k);
 	i=2;
 	while(i<=n){c
 		scanf("%d\n", &t);
 		if(t%k==0){
 			c++;
		}
		i++;
	}
	printf("%d", c);
	return 0;
 }
