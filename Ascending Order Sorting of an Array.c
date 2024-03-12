#include <stdio.h>
#include <stdlib.h>

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
	printf ("Berikut angka yang telah diurutkan secara ascending.\n");
	for (x=0; x<5; x++) {
		printf ("%d\n", test[x]);
	}
}

main () {
	int i, j, temp, num[5];
	printf ("Sorting an Array Numbers\n");
	printf ("------------------------\n");
	printf ("Masukkan angka: \n");
	for (i=0; i<5; i++) {
		scanf ("%d", &num[i]);
	}
	sort(i, j, temp, num);
}
