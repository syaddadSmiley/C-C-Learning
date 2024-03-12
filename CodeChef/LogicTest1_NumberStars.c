//https://articlearn.id/article/e4536e9b-soal-tes-logika-untuk-masuk-kerja/
#include <stdio.h>
#define atoa(x) #x

int main(){
	char arr[100001]={}, b;
	int n;
	scanf("%d", &n);
	int i;
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<n+3;j++){
			char x;
			x = j+1;
			arr[j] = x;
			b = "*";
			arr[j+1] = b;
			arr[j+2] = b;
			printf("%d", arr[j]);
		}
		printf("\n");
	}
}
