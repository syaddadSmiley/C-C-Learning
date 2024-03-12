#include <stdio.h>

int main(){
	int t, a, b, c;
	int i;
	scanf("%d", &t);
	for(i=0;i<t;i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a>b & b>c || c>b & b>a){
			printf("%d\n", b);
		}
		else if(b>a & a>c || c>a & a>b){
			printf("%d\n", a);
		}
		else if(a>c & c>b || b>c & c>a){
			printf("%d\n", c);
		}
	}
	return 0;
}
