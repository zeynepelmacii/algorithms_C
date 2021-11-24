#include <stdio.h>
#include <stdlib.h>


//defining a structure for node
struct node {
	int data; // data of the node
	struct node* nextPtr; // adress of the next node
};

struct node* startNode;

//creating the linked list
void createLL(int numberOfNodes) {
	struct node* newNode;
	struct node* tempNode;
	int input; //users input
	int nodeid;
	
	
	//allocating memory for the first node
	startNode = (node*) malloc(sizeof(node)); 
	
	 //checking if memory was successfully allocated
	 if(startNode == NULL) {
	 	printf("\tERR : memory can not be allocated !!");
	 }
	 else {
	 	printf("input data for node 1 ==> ");
	 	scanf("%d", &input);
	 	
	 	startNode->data = input;
	 	startNode->nextPtr = NULL;
	 	
	 	tempNode = startNode;
	 	
	 	//creating a loop that will create all nodes 
	 	for(nodeid = 2 ; nodeid <= numberOfNodes ; nodeid++) {
	 		newNode = (node*) malloc(sizeof(node));
			 //checking if memory was successfully allocated
	 		if(newNode == NULL) {
	 			printf("\tERR : memory can not be allocated");
	 			break;
			 }
			 else {
			 	printf("enter data for node %d ==> ", nodeid);
			 	scanf("%d",&input);
			 	
			 	newNode->data = input;
			 	newNode->nextPtr = NULL;
			 	
			 	//assing previous node to the new node
			 	tempNode->nextPtr = newNode;
			 	tempNode = tempNode->nextPtr; 	
			 }
		 }	
	 }			
}

//order the list in reverse
void orderLL(int numberOfNodes) {
	int nodeCtr; //node counter
	int ctr; //counter
	int nodeDataCopy;
	struct node* currentNode;
	struct node* nextNode;
	
	//lopp until all the nodes are sorted in increasing order
	for(nodeCtr = numberOfNodes-2 ; nodeCtr >= 0 ; nodeCtr--) {
		currentNode = startNode;
		nextNode = currentNode->nextPtr;
		//loop until the smallest value rises to the top
		for(ctr = 0 ; ctr <= nodeCtr ; ctr++) {
			if(currentNode->data > nextNode->data) {
				nodeDataCopy = currentNode->data;
				currentNode->data = nextNode->data;
				nextNode->data = nodeDataCopy;
			}
			
			currentNode = nextNode;
			nextNode = nextNode->nextPtr;	
		}
	}
}

//display the linked list
void displayLL() {
	struct node* tempNode;
	
	//checking if linked list is empty
	if(startNode == NULL) {
		printf("\tERR : nothing to display");
	}
	else{
		tempNode = startNode;
		while(tempNode != NULL) {
			printf("data ==> %d\n", tempNode->data);
			tempNode = tempNode->nextPtr;
		}
	}
}

int main() {
	int numberOfNodes;
	printf("how many elements will be in your list ==> ");
	scanf("%d", &numberOfNodes);
	
	createLL(numberOfNodes);
	printf("\n");
	//display all entered datas 
	printf("-----entered datas-----\n");
	displayLL();
	
	printf("\n");
	printf("-----the reverse ordered list-----\n");
	orderLL(numberOfNodes);
	displayLL();
	
	return 0;
}
