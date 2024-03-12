#include <stdio.h>
#include <string.h>

struct menu{
	char nama_menu[50];
	int harga;
};

void print_menu(){
	puts(" =========Makanan===========");
	puts("| (1) Croissant Almond      |");
	puts("| (2) Smoke Beef Croissant  |");
	puts("| (3) Croffle               |");
	puts("| (4) Apple Puff            |");
	puts("| (5) Pie Apple             |");
	puts("|===========================|");
	puts(" ==========Minuman==========");
	puts("| (6) Espresso              |");
	puts("| (7) Cafe Latte            |");
	puts("| (8) Cappuccino            |");
	puts("|===========================|");
	
	printf("Pilih Menu : \n");
}

int main(){
	
	struct menu croisal;
	strcpy( croisal.nama_menu, "Croissant Almond");
	croisal.harga= 25000;
	
	struct menu beefcro;
	strcpy( beefcro.nama_menu, "Smoke Beef Croissant");
	beefcro.harga= 27500;
	
	struct menu croffle;
	strcpy( croffle.nama_menu, "Croffle");
	croffle.harga= 27000;
	
	struct menu appuff;
	strcpy( appuff.nama_menu, "Apple Puff");
	appuff.harga= 22000;
	
	struct menu piapp;
	strcpy( piapp.nama_menu, "Pie Apple");
	piapp.harga= 25000;
	
	struct menu espresso;
	strcpy( espresso.nama_menu, "Espresso");
	espresso.harga= 18000;
	
	struct menu latte;
	strcpy( latte.nama_menu, "Cafe Latte");
	latte.harga= 25000;
	
	struct menu cappuccino;
	strcpy( cappuccino.nama_menu, "Cappuccino");
	cappuccino.harga= 25000;
	
	print_menu();
	int n=0, nama, jumlah, i=0;
	int lanjut;
	int namaArr[10001]={};
	int jumlahArr[10001]={};
	
	while(n==0){
		printf("Nomor Menu | Jumlah Menu\n");
		scanf("%d %d", &nama, &jumlah);
		namaArr[i] = nama;
		jumlahArr[i] = jumlah;
		system("cls");
		puts("Lanjut/Selesai (1/0)");
		scanf("%d", &lanjut);
		system("cls");
		if(lanjut == 0){
			n=1;
			system("cls");
		}
		else{
			print_menu();
			i+=1;
		}
	}
	int k=0, p=0, harga=0;
	while(k==0){
		if(namaArr[p] == 1){
			printf("%s -> %d = %d\n",croisal.nama_menu, croisal.harga, jumlahArr[p] );
			harga += jumlahArr[p]*croisal.harga;
			p++;
		}
		else if(namaArr[p] == 2){
			printf("%s -> %d = %d\n",beefcro.nama_menu, beefcro.harga, jumlahArr[p] );
			harga += jumlahArr[p]*beefcro.harga;
			p++;
		}
		else if(namaArr[p] == 3){
			printf("%s -> %d = %d\n",croffle.nama_menu, croffle.harga, jumlahArr[p] );
			harga += jumlahArr[p]*croffle.harga;
			p++;
		}
		else if(namaArr[p] == 4){
			printf("%s -> %d = %d\n",appuff.nama_menu, appuff.harga, jumlahArr[p] );
			harga += jumlahArr[p]*appuff.harga;
			p++;
		}
		else if(namaArr[p] == 5){
			printf("%s -> %d = %d\n",piapp.nama_menu, piapp.harga, jumlahArr[p] );
			harga += jumlahArr[p]*piapp.harga;
			p++;
		}
		else if(namaArr[p] == 6){
			printf("%s -> %d = %d\n",espresso.nama_menu, espresso.harga, jumlahArr[p] );
			harga += jumlahArr[p]*espresso.harga;
			p++;
		}
		else if(namaArr[p] == 7){
			printf("%s -> %d = %d\n",latte.nama_menu, latte.harga, jumlahArr[p] );
			harga += jumlahArr[p]*latte.harga;
			p++;
		}
		else if(namaArr[p] == 8){
			printf("%s -> %d = %d\n",cappuccino.nama_menu, cappuccino.harga, jumlahArr[p] );
			harga += jumlahArr[p]*cappuccino.harga;
			p++;
		}
		else if(namaArr[p] == 0){
			k=1;
		}
		
	}
	printf("Total Harga : %d", harga);
	return 0;
	
}

