#include <stdio.h>
#include <string.h>


typedef struct ingfo{
	char nama[20];
	int jumlah;
	char tgl[10];
	int harga;
}ingfo;

void print_brg();
void add_brg();
void check_nama(char nama[20]);
void hapus_brg();
void edit_barang();

int main(){
	int pilih;
	do{
		printf("\n1. Tambah Data");
		printf("\n2. Print Data");
		printf("\n3. Hapus Data");
		printf("\n4. Edit Data");
		printf("\n0. Exit");
		printf("\nInput Menu : ");
		scanf("%d", &pilih);
		
		switch(pilih){
			case 1:
				add_brg();
				break;
			case 2:
				system("cls");
				print_brg();
				break;
			case 3:
				system("cls");
				print_brg();
				hapus_brg();
				break;
			case 4:
				system("cls");
				print_brg();
				edit_barang();
				break;
		}
		
	}while(pilih!=0);
	
	return 0;
}

void add_brg(){
	int id_temp;
	char nama_temp[20];
	ingfo *barang;
	FILE *fptr;
	int i, n=1;

	barang = (ingfo*)calloc(n, sizeof(ingfo));
	fptr = fopen("data.txt", "a");
	if(fptr == NULL){
		fclose(fptr);
		fptr = fopen("data.txt", "w");
	}
	
	for(i = 0; i<n;i++){
		fflush(stdin);
		printf("Nama Barang : ");
		scanf("%[^\n]s", nama_temp);
		check_nama(nama_temp);
		strcpy(barang[i].nama, nama_temp);
		printf("Jumlah Barang : ");
		scanf("%d", &barang[i].jumlah);
		fflush(stdin);
		printf("Tanggal (ex : 30/11/2022): ");
		scanf("%[^\n]s", barang[i].tgl);
		fflush(stdin);
		printf("Harga Barang : ");
		scanf("%d", &barang[i].harga);
		fwrite(&barang[i], sizeof(ingfo), 1, fptr);
	}
	fclose(fptr);
}

void print_brg(){
	ingfo barang;
	FILE *fptr;
	fptr = fopen("data.txt","r");
	if(fptr==NULL){
		printf("\n===========Data Not Found!==========\n");
		printf("\nSilahkan Tambah Data terlebih dahulu\n");
		main();
	}
	
	printf("\n====== Data Pelanggan ======\n");
	while(fread(&barang, sizeof(ingfo), 1, fptr)){
		printf("\nNama Barang : %-20s", barang.nama);
		printf("\nJumlah : %d", barang.jumlah);
		printf("\nTanggal : %-10s", barang.tgl);
		printf("\nHarga Barang : %d\n", barang.harga);
	}
	printf("\n============================\n");
	fclose(fptr);
}

void check_nama(char nama[20]){
	ingfo barang;
	FILE *fptr;
	int res_cmp;
	fptr = fopen("data.txt","r");
	if(fptr==NULL){
		printf("\n===========Data Not Found!==========\n");
		printf("\nSilahkan Tambah Data terlebih dahulu\n");
		main();
	}
	
	while(fread(&barang, sizeof(ingfo), 1, fptr)){
		res_cmp = strcmp(nama, barang.nama);
		if(res_cmp == 0){
			printf("\n==========Barang Sudah Dimasukkan!===========\n");
			printf("\n==Silahkan ke Menu Edit untuk Mengubah Data==\n");
			main();
		}
	}

	fclose(fptr);
}

void hapus_brg(){
	int res_cmp, found=0;
	char nama[5];
	
	ingfo barang;
	FILE *fptr, *fptr_temp;
	fptr = fopen("data.txt","r");
	if(fptr==NULL){
		printf("\n===========Data Not Found!==========\n");
		printf("\nSilahkan Tambah Data terlebih dahulu\n");
		main();
	}
	fptr_temp = fopen("temp.txt", "w");
	fflush(stdin);
	printf("Masukkan Nama Barang yang akan dihapus : ");
	scanf("%[^\n]s", nama);
	while(fread(&barang, sizeof(ingfo), 1, fptr)){
		res_cmp = strcmp(nama, barang.nama);
		if(res_cmp == 0){
			found = 1;
		}
		else{
			fwrite(&barang, sizeof(ingfo), 1, fptr_temp);
		}
		
	}
	
	fclose(fptr_temp);
	fclose(fptr);
	
	if(found){
		fptr_temp = fopen("temp.txt", "r");
		fptr = fopen("data.txt","w");
		
		while(fread(&barang, sizeof(ingfo), 1, fptr_temp)){
			fwrite(&barang, sizeof(ingfo), 1, fptr);
		}
		printf("\n=== Data Berhasil Dihapus! ===\n");
		
		fclose(fptr_temp);
		fclose(fptr);
	}
	else if(!found){
		printf("\n=== ERRROR 404 ===\n");
		printf("\n= Data Not Found =\n");
	}
	fclose(fptr);
	remove("temp.txt");
}

void edit_barang(){
	int num2, found=0, res_cmp;
	char nama[5];
	ingfo barang;
	FILE *fptr, *fptr_temp;
	fptr = fopen("data.txt","r");
	if(fptr==NULL){
		printf("\n===========Data Not Found!==========\n");
		printf("\nSilahkan Tambah Data terlebih dahulu\n");
		main();
	}
	fptr_temp = fopen("temp.txt", "w");
	fflush(stdin);
	printf("Masukkan Nama Barang yang akan Diubah : ");
	scanf("%[^\n]s", nama);
	while(fread(&barang, sizeof(ingfo), 1, fptr)){
		res_cmp = strcmp(nama, barang.nama);
		if(res_cmp == 0){
			found = 1;
			printf("\n1. Ganti Nama\n");
			printf("\n2. Ganti Jumlah\n");
			printf("\n3. Ganti Tanggal\n");
			printf("\n4. Ganti Harga\n");
			printf("\nMasukkan Data yang akan diganti (1/2/3/4) :\n ");
			scanf("%d", &num2);
			if(num2 == 1){
				fflush(stdin);
				printf("Nama Baru : ");
				scanf("%[^\n]s", barang.nama);
			}
			else if(num2 == 2){
				fflush(stdin);
				printf("Updated Jumlah : ");
				scanf("%d", &barang.jumlah);
			}
			else if(num2 == 3){
				fflush(stdin);
				printf("Tanggal : ");
				scanf("%[^\n]s", barang.tgl);
			}
			else if(num2 == 4){
				fflush(stdin);
				printf("Harga : ");
				scanf("%d", &barang.harga);
			}
			else{
				printf("Input Error!");
			}
		}
		fwrite(&barang, sizeof(ingfo), 1, fptr_temp);
	}
	
	fclose(fptr_temp);
	fclose(fptr);
	
	if(found){
		fptr_temp = fopen("temp.txt", "r");
		fptr = fopen("data.txt","w");
		
		while(fread(&barang, sizeof(ingfo), 1, fptr_temp)){
			fwrite(&barang, sizeof(ingfo), 1, fptr);
		}
		printf("\n=== Data Berhasil Diubah! ===\n");
		
		fclose(fptr_temp);
		fclose(fptr);
	}
	else if(!found){
		printf("\n=== ERRROR 404 ===\n");
		printf("\n= Data Not Found =\n");
	}
	fclose(fptr);
	remove("temp.txt");
}
