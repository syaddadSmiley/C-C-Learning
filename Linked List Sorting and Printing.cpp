#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

struct tnode{
	int key;
	int value;
	struct tnode *next;
};struct tnode *head = NULL;

void push(int key, int val){
	struct tnode *newNode = (struct tnode*)malloc(sizeof(struct tnode));
	(*newNode).key = key;
	(*newNode).value = val;
	(*newNode).next = NULL;
	
	if(head == NULL){
		head = newNode;
	}
	else{
		struct tnode *ptr = head;
		while(ptr->next != NULL)ptr=ptr->next;
			ptr->next = newNode;
		
	}
}

void bubbleSort(){
	struct tnode *ptr=head;
	struct tnode *ptr2;
	for(int i=1; i<6 ; i++){
		ptr2=head;
		for(int j=0; j<i ; j++){
			if(ptr->key < ptr2 -> key){
				swap(ptr2 -> key, ptr -> key);
				swap(ptr2 -> value, ptr -> value);
			}
			else if(ptr -> key == ptr2 -> key){
				if(ptr -> value < ptr2 -> value){
					swap(ptr2 -> key, ptr -> key);
					swap(ptr2 -> value, ptr -> value);
				}
			}
			ptr2 = ptr2 -> next;
		}
		ptr = ptr->next;
	}
}

void print(){
	struct tnode *ptr = head;
	while(ptr != NULL){
		cout <<"Key : " << ptr->key <<" Value : "<<ptr -> value << endl;
		ptr = ptr -> next;
	}
}



int main(){
	int size=5, key, value;
	while(size--){
		cin >> key >> value;
		push(key, value);
	}
	cout<<"List yang tidak terurut : \n";
	print();
	cout<<"\nList yang terurut secara Ascending : \n";
	bubbleSort();
	print();
	
	return 0;
}
