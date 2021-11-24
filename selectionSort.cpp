#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	int arraySize, temp, min, number[25], randomNumber;

   printf("Enter array size ==> ");
   scanf("%d",&arraySize);

   srand(time(0));//to create diffrent random numbers each time
	for (int i = 0; i < arraySize; i++){
		randomNumber = rand()%50+1;	//creating random number
		number[i] = randomNumber;		//add the random number to array
	}
	
	printf("-----Unorted elements----- ");
   for(int i=0 ; i<arraySize ; i++)
      printf(" %d , ",number[i]);
 
   //selection sort
   for(int i=0; i<=arraySize-1; i++){
   	min=i;
   	for(int j=i+1; j<arraySize; j++) {
   		if(number[j] < number[min]) {
   			j=min;
		   }
	   }
	   temp=number[i];
	   number[i]=number[min];
	   number[min]=temp;
   }
	
	printf("\n");
   printf("-----Sorted elements----- ");
   for(int i=0 ; i<arraySize ; i++)
      printf(" %d , ",number[i]);
	return 0;
}
