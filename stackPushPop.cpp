#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;
int* stack;

void pop(){
	if(size == 0) {
		printf("nothing to pop!!\n");
		return;
	}
	
	int value = stack[0];
	printf("popped value ==> %d\n" , value);
	if(size > 1) {
		memcpy(stack,&stack[1],sizeof(int)*(size-1));
		stack = (int*) realloc(stack,(size-1)*sizeof(int));
	}
	size--;	
}

void push() {
	int value;
	printf("enter a value ==>");
	scanf("%d", &value);
	stack = (int*) realloc(stack,(size+1)*sizeof(int));
	memcpy(&stack[1],stack,sizeof(int)*size);
	stack[0] = value;
	size++;
}

void print() {
	if(size == 0) {
		printf("stack is empty !!\n");
		return;
	}
	for(int i = 0 ; i < size ; i++) {
		int value = stack[i];
		printf("%d , ", value);
	}
	printf("\n");
}

int main () {

	stack = (int*) calloc(1,sizeof(int));
	int menu;


	while(true) {
		printf("push(1)-pop(2)-exit(9) ==> ");
		scanf("%d", &menu);
		 
		if(menu == 1) {
			push();
		}
		else if(menu == 2) {
			pop();
		}
		else if(menu == 9) {
			break;
		}
		print();
	}
}
