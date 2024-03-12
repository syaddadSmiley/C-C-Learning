#include <stdio.h>

int main(){
	int t, i, a;
	scanf("%d", &t);
	int n[10001] = {0};
	for(i=0; i<t;i++){
		scanf("%d", &a);
		n[a]++;
		printf("%d\n", n[i]);
	}
}
