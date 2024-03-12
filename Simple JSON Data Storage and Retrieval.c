#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* PERSON_FORMAT_IN = "{\"Nama\": \"%[^\"]\", \"No Telepon\": \"%[^\"]\", \"Alamat\": \"%[^\"]\"}";
const char* PERSON_FORMAT_OUT = "{\"Nama\": \"%s\", \"No Telepon\": \"%s\", \"Alamat\": \"%s\"}";;

typedef struct ingfo{
	char nama[20];
	char noTlp[13];
	char alamat[30];
}ingfo;

int print_plgn();

int main(int argc, char* argv[]){
	ingfo plgn1 = {
		.nama = "Tes",
		.noTlp = "08124",
		.alamat = " Jl. antah",
	};
	ingfo plgn2;
	
	FILE* file;
	fopen_s(&file, "data.txt", "w+");
	if(file == NULL){
		return 1;
	}
	
	fprintf_s(file, PERSON_FORMAT_OUT, plgn1.nama, plgn1.noTlp, plgn1.alamat);
	fseek(file, 0, SEEK_SET);
	fscanf_s(file, PERSON_FORMAT_IN, plgn2.nama, 20, plgn2.noTlp, plgn2.alamat);
	fclose(file);
	print_plgn();
	return 0;
}

int print_plgn(){
	FILE *inf;
	struct ingfo tes;
	inf = fopen("data.txt", "r");
	if(inf == NULL){
		fprintf(stderr, "\nError Buka!\n");
		exit(1);
	}
	while(fread(&tes, sizeof(ingfo), 1, inf)){
		printf(" nama = %s\n no telepon = %d\n Alamat = %s\n\n", tes.nama, tes.noTlp, tes.alamat);
	}
	fclose(inf);
}
