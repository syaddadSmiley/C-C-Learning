#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ingfo{
	char nama[20];
	char noTlp[12];
	char alamat[30];
}ingfo;

int print_plgn();
bool checkFile(FILE *file);
void addPlgn();

int main(int argc, char const *argv[]){
	addPlgn();
	print_plgn();
}

void addPlgn(){
	FILE *fptr;
	fptr = fopen("info pelanggan.txt", "a");
	if(fptr == NULL){
		fprintf(stderr, "\nError Cuk\n");
		exit(1);
	}
	struct ingfo plgn1;
	printf("Nama : ");
	scanf("%s", &plgn1.nama);
	printf("No TLP : ");
	scanf("%s", &plgn1.noTlp);
	printf("Alamat : ");
	scanf("%s", &plgn1.alamat);
	printf("%s\n", plgn1.nama);
	printf("%s\n", plgn1.noTlp);
	printf("%s\n", plgn1.alamat);
	fwrite(&plgn1, sizeof(struct ingfo), 3, fptr);
	return;
}

int print_plgn(){
	FILE *inf;
	struct ingfo tes;
	inf = fopen("info pelanggan.txt", "r");
	if(inf == NULL){
		fprintf(stderr, "\nError Buka!\n");
		exit(1);
	}
	while(fread(&tes, sizeof(struct ingfo), 1, inf)){
		printf(" nama = %s\n no telepon = %d\n Alamat = %s\n\n", tes.nama, tes.noTlp, tes.alamat);
	}
	fclose(inf);
}

bool checkFile(FILE *file){
	long savedOffset = ftell(file);
	fseek(file, 0, SEEK_END);
	
	if(ftell(file) == 0){
		return true;
	}
	
	fseek(file, savedOffset, SEEK_SET);
	return false;
}



