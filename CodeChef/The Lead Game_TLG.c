#include <stdio.h>

int main(){
	int n, a, b, temp1=0, temp2=0, t1=0, t2=0, l1=0, l2=0;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &a, &b);
		temp1 += a;
		temp2 += b;
		if(temp1 > temp2){
			t1 = temp1 - temp2;
		}
		if(temp2 > temp1){
			t2 = temp2 - temp1;
		}
		if(t1>l1){
			l1=t1;
		}
		if(t2>l2){
			l2=t2;
		}
	}
	if(l1>l2){
		printf("1 %d", l1);
	}
	if(l2>l1){
		printf("2 %d", l2);
	}
	return 0;	
}

//int main(){
//	int n, l=0, a, b, temp1=0, temp2=0, t1=0, t2=0;
//	scanf("%d", &n);
//	while(n--){
//		scanf("%d %d",&a,&b);
//		l = a-b;
//		if(l>0){
//			if(l>temp1){
//				t1+=l;
//				temp1 = 0;
//				temp1 += l;
//			}
//		}
//		else if(l<0){
//			l = -l;
//			if(l>temp2){
//				t2+=l;
//				temp2 = 0;
//				temp2 += l;
//			}
//		}
//	}
//	if(t1 > t2){
//		printf("1 %d", temp1);
//	}
//	else if(t2 > t1){
//		printf("2 %d", temp2);
//	}
//	return 0;
//}
