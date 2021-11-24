#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXP 5

struct item {
	int value;
	int priority;	
};

int peek(item* queue,int size) {
	//checking for each priority assuming 1 is the most important priority
	for(int p = 1 ; p <= MAXP ; p++) {
		for(int i = 0 ; i < size ; i++) {
			item it = queue[i];
			//if an item found with the checking priority return its index
			if(it.priority == p) {
				return i;
			}
		}
	}
	//no item found and returning -1 to indicate no item left in the queue
	return -1;
}

item dequeue(item* queue, int* size){
	//finding item to dequeued based on its priority
	int id = peek(queue,*size);
	
	//if no item in queue build empty item which has 0 priority
	//0 priority will indicate that no item left in the queue
	if(id == -1){
		item it;
		it.value = 0;
		it.priority = 0;
		return it;
	}
	
	item it = queue[id];
	
	//rearranging the items in the queue	
	for(int i = id+1 ; i < (*size) ; i++) {
		queue[i] = queue[i+1];
	}
	
	(*size)--;
	//realllocating memory
	queue = (item*) realloc(queue,(*size)*sizeof(item));

	return it;
}

void enqueue(item* queue, int* size,int value,int priority) {
	//building new item to enqueue
	item it;
	it.value = value;
	it.priority = priority;
	//put the item at the end of the queue
	queue[*size] = it;
	(*size)++;
	//reallocating memory
	queue = (item*) realloc(queue,(*size)*sizeof(item));
}

void display(item* queue, int size) {
	for(int i = 0 ; i < size ; i++) {
		item it = queue[i];
		printf("%d(%d) - ",it.value,it.priority);
	}
	printf("\n");
}

int main () {
	
	int size = 0;
	//initiliazing queue array
	item* queue = (item*) calloc(1,sizeof(item));
	int menu,value,priority;

	while(true) {
		printf("insert into queue (1)- delete from queue (2) - exit (9) ==> ");
		scanf("%d", &menu);
		 
		if(menu == 1) {
			printf("enter a value and priority ==> ");
			scanf("%d %d", &value,&priority);
			
			//checking if given priority is valid
			if(priority < 1 || priority > MAXP) {
				printf("\tERR : invalid priority. Should be %d-%d !!\n", 1, MAXP);
				continue;
			}
			//put the given item to the queue
			enqueue(queue,&size,value,priority);
		}
		else if(menu == 2) {
			//call dequeue function and have item
			item it = dequeue(queue,&size);
			//check if any item dequeued 
			if(it.priority == 0) {
				printf("\tERR : no item in queue !!\n");
				continue;
			}
			printf("dequeued ==> %d(%d) \n",it.value,it.priority);
		}
		else if(menu == 9) {
			break;
		}
		else {
			printf("\tERR : invalid option !!");
		}
		//show all item in queue in each loop
		display(queue,size);
	}
}
