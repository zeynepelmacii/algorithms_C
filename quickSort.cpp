#include <stdio.h>

//swap operation
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high]; 				//assign the last index to pivot
  int i = (low - 1);					//i should start index -1;
  for (int j = low; j < high; j++) {	
    if (array[j] <= pivot) {   			//if current element smaller then pivot
      i++;  							//increase i 
      swap(&array[i], &array[j]);		//make swap operation between them two
    }
  }
  swap(&array[i + 1], &array[high]);	//making pivot again
  return (i + 1);
}

//quick sort implementation
void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pivot = partition(array, low, high);
    quickSort(array, low, pivot - 1); //left part form pivot
    quickSort(array, pivot + 1, high); //right part from pivot
  }
}

//printing array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {8, 7, 2, 1, 0, 9, 6};
  
  int size = sizeof(data) / sizeof(data[0]);
  
  printf("-----Unsorted Array-----\n");
  printArray(data, size);
  
  quickSort(data, 0, size-1);
  
  printf("-----Sorted array-----\n");
  printArray(data, size);
}
