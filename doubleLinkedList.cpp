#include <stdio.h>
#include <stdlib.h>

//define node struct
struct node {
	int data;
	struct node* preNode; // Address to previous node
	struct node* nextPtr; //Address to next node
};

//define fist and the last node in the list 
struct node* firstNode; //Address to the first node in the linked list
struct node* lastNode; //Address to the last node in the linked list

//creating a double linked list with the given number of node
void createDLL(int numberOfNodes) {
	int nodeCtr;
	int nodeData;
	struct node* newNode;
	
	//checking if the number of nodes is positive
	if(numberOfNodes >= 1) {
		
		//then allocate the memory to the first node 
		firstNode = (node*) malloc(sizeof(node));
		
		//checking if memory was successfully allocated
		if(firstNode == NULL) {
			printf("\tERR : memory can not be allocated !!");
		}
		else {
			printf("enter data for node 1 ==> ");
			scanf("%d", &nodeData);
			
			//initialize the first node
			firstNode->data = nodeData;
			firstNode->preNode = NULL;
			firstNode->nextPtr = NULL;
			
			//initialize the last node
			lastNode = firstNode;
			
			//loop until all of the nodes are created
			for(nodeCtr = 2 ; nodeCtr <= numberOfNodes ; nodeCtr++) {
				//allocate memory fot the new node
				newNode = (node*) malloc(sizeof(node));
				
				//checking if memory was successfully allocated
				if(firstNode == NULL) {
					printf("\tERR : memory can not be allocated !!");
				}
				else {
					printf("enter data for node %d ==> ", nodeCtr);
					scanf("%d", &nodeData);
					
					//initiliaze the new node;
					newNode->data = nodeData;
					newNode->preNode = NULL;
					newNode->nextPtr = NULL;
					
					//connect the new node to the double lnked list
					newNode->preNode = lastNode;
					lastNode->nextPtr = newNode;
					
					//update the last node;
					lastNode = newNode;
				}	
			}
		}
	}
}

//function to sort double linked list
void sortDLL(int numberOfNodes) {
	int temp;
	
	//checking if list is empty
	if(firstNode == NULL) {
		printf("\tERR : nothing to sort !!");
		return;
	}
	else{
		
	}	
}

//display the double linked list
void displayDLL() {
	struct node* currentNode;
	int nodeCtr = 1; //counter
	
	if(firstNode == NULL) {
		printf("\tERR : nothing to display !!");
	}
	else {
		//copy the adres of the first node
		currentNode = firstNode;
		
		//loop until the all of the nodes are displayed
		while(currentNode != NULL) {
			printf("node %d ==> %d\n", nodeCtr, currentNode->data);
			nodeCtr++;
			
			//go to the next node
			currentNode = currentNode->nextPtr;
		}
	}
}

int main() {
	int numberOfNodes;
	printf("how many elements will be in your list ==> ");
	scanf("%d", &numberOfNodes);
	createDLL(numberOfNodes);
	
	printf("\n");
	//display all entered datas 
	printf("-----entered datas-----\n");
	displayDLL();
	
	printf("\n");
	printf("-----the sorted list-----\n");
	sortDLL(numberOfNodes);
	displayDLL();
}
