#include <stdio.h>
int arr[5];
void getMinimum();
//void sort(int x, int y, int tempr, int test[5]);

void sort(int x, int y, int tempr, int test[5]) {
	for (x=0; x<5; x++) {
		for (y=x+1; y<5; y++) {
			if (test[x] > test[y]) {
				tempr = test[x];
				test[x] = test[y];
				test[y] = tempr;
			}
		}
	}
}

int main(){
	int i,j, temp;
	for(i = 0; i<5;i++){
		scanf("%d", &arr[i]);
	}
	sort(i, j, temp, arr);
	getMinimum();
}

void getMinimum(){
	int i, temp1=arr[0],temp2;
	for(i = 0; i<5; i++){
		if(temp1 > arr[i]){
			temp1 = arr[i];
		}
	}
	for(i = 0; i<5;i++){
		printf("%d ", arr[i]);
	}
	printf("\nTerkecil = %d", temp1);
}


