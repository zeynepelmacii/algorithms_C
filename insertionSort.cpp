#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	int arraySize, temp, j, number[25], randomNumber;

   printf("Enter array size ==> ");
   scanf("%d",&arraySize);

   srand(time(0));//to create diffrent random numbers each time
	for (int i = 0; i < arraySize; i++){
		randomNumber = rand()%50+1;	//creating random number
		number[i] = randomNumber;		//add the random number to array
	}
	
	printf("-----Unsorted elements----- ");
   for(int i=0 ; i<arraySize ; i++)
      printf(" %d , ",number[i]);
 
   //insertion sort
   for(int i=0; i<arraySize; i++) {
	temp = number[i];
   	j=i-1;
   	while(j>=0 && temp>number[j]) {
   		number[j+1] = number[j];
  		j--;
  	 }
	number[j+1] = temp;		
   }
	
	printf("\n");
   printf("-----Sorted elements----- ");
   for(int i=0 ; i<arraySize ; i++)
      printf(" %d , ",number[i]);
	return 0;
}
