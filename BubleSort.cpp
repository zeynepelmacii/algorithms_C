#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	int arraySize, temp, number[25], randomNumber;

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
 
   //bubble sort
   for(int i=0; i<arraySize; i++){
   	for(int j=i+1; j<arraySize; i++) {
   		if(number[i]<number[j]) {
   			temp=number[i];
   			number[i]=number[j];
   			number[j]=temp;
		   }
	   }
   }
	
	printf("\n");
   printf("-----Sorted elements----- ");
   for(int i=0 ; i<arraySize ; i++)
      printf(" %d , ",number[i]);
	return 0;
}
