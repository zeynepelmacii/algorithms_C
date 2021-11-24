#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

node* bst;

int getChoice() {
	int choice;
	printf("\n1-insert, 2-search, 3-delete, 4-find min, 5-find max, 6-find height, 9-display, 0-exit ==> ");
	scanf("%d", &choice);
	return choice;
}

void initBst() {
	bst = NULL;
}


struct node* insertDo(node* n, int data) {
	if(n == NULL) {
		n = (node*) malloc(sizeof(node));
		n->left = NULL;
		n->right = NULL;
		n->data = data;
		return n;
	}
	if(data > n->data) {
		n->right = insertDo(n->right, data);
	}
	else if(data < n->data) {		
		n->left = insertDo(n->left, data);
	}	
	return n;
}

void insert() {
	int data;
	
	printf("enter data ==> ");
	scanf("%d", &data);

	bst = insertDo(bst,data);
}


int findByData(node* n, int data, int level) {
	if(n == NULL) {
		return -1;
	}
	if(n->data == data) {
		return level;
	}
	if(n->data < data) {
		return findByData(n->right,data,level+1);
	}
	return findByData(n->left,data,level+1);	
}

struct node* getNodeByData(node* n, int data, int level) {
	if(n == NULL) {
		return NULL;
	}
	if(n->data == data) {
		return n;
	}
	if(n->data < data) {
		return getNodeByData(n->right,data,level+1);
	}
	return getNodeByData(n->left,data,level+1);	
}

struct node* getParentNodeBydata(node* root, node* parent, int data, int level) {
	if(root == NULL) {
		return NULL;
	}
	if(n->data == data) {
		return n;
	}
	if(n->data < data) {
		return getNodeByData(n->right,data,level+1);
	}
	return getNodeByData(n->left,data,level+1);	
}

void find() {
	int data;
	
	printf("enter data ==> ");
	scanf("%d", &data);
	
	int level = findByData(bst,data,1);
	if(level == -1) {
		printf("\tERR : not found !!\n");
	}
	else {
		printf("\tfound at level %d\n", level);
	}
}

int findMin(node* n, int min) {
	if(n == NULL) {
		return min;
	}
	if(n->data < min) {
		return findMin(n->left,n->data);
	}
}

void min() {
	int value = findMin(bst, 99999);
	printf("\tmin value ==> %d", value);
}


int findMax(node* n, int max) {
	if(n == NULL) {
		return max;
	}
	if(n->data > max) {
		return findMax(n->right,n->data);
	}
}

void max() {
	int value = findMax(bst, 0);
	printf("\tmax value ==> %d", value);
}

int findMaxLevel(node* n, int level) {
	if(n == NULL) {
		return level;
	}
	int leftLevel = findMaxLevel(n->left, level+1);
	int rightLevel = findMaxLevel(n->right, level+1);
	if(leftLevel > rightLevel) {
		return leftLevel;
	}
	return rightLevel;
}

void height() {
	if(bst == NULL) {
		printf("\tERR : no level !!");
		return;
	}
	int maxLevel = findMaxLevel(bst,0);
	printf("\theight ==> %d", maxLevel);
}



void removeDo(struct node* root, int data) {
	struct node* n = getNodeByData(root,data,1);
	if(n == NULL) {
		return;
	}
	
	/*if(n->left == NULL && n->right == NULL) {
		n->data = NULL;
		return;
	}
	if(n->left == NULL ) {
		n->data = n->right->data;
		return;
	}
	if(n->right = NULL) {
		n->data = n->left->data;
		return;
	}*/
}

void remove() {
	int data;
	
	printf("enter data ==> ");
	scanf("%d", &data);
	
	struct node* n =  getNodeByData(bst,data,1);
	if(n == NULL) {
		printf("\tERR : not found !!");
		return;
	}
	removeDo(bst,data);
}



void printNode(node* n, int level) {
	if(n == NULL) {
		return;
	}
	for(int i = 1 ; i < level ; i++) {
		printf("   ");
	}
	printf("|___");
	printf("%d\n",n->data);
	printNode(n->left,level+1);
	printNode(n->right, level+1);
}

void display() {
	printNode(bst,1);
}

int main() {
	initBst();
	bst = insertDo(bst, 50);
	bst = insertDo(bst, 30);
    bst = insertDo(bst, 20);
    bst = insertDo(bst, 40);
    bst = insertDo(bst, 70);
    bst = insertDo(bst, 60);
    bst = insertDo(bst, 63);
    bst = insertDo(bst, 65);
    bst = insertDo(bst, 66);
    bst = insertDo(bst, 80);
    display();
    
	while(true) {
		int menu = getChoice();
		switch(menu) {
			case 1 : insert(); break;
			case 2 : find(); break;
			case 3 : remove(); break;
			case 4 : min(); break;
			case 5 : max(); break;
			case 6 : height(); break;
			case 9 : display(); break;
			case 0 : return -1;
		}	
	}	
	return 0;
}


