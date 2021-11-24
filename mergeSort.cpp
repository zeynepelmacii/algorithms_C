#include <stdio.h>

#define max 10

int a[11] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44, 0 };
int b[10];

void merging(int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])		//if low is smaller then mid+1
         b[i] = a[l1++];		//assign low+1 from a array to low from b array
      else
         b[i] = a[l2++];		//assign mid+1 from a array to low from b array
   }
   
   while(l1 <= mid)    			//if l1 is smaller/equal to mid
      b[i++] = a[l1++];			//assign low+1 from a array to low from b array

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void sort(int low, int high) {
   int mid;
   if(low < high) {
      mid = (low + high) / 2;	//orta nokta
      sort(low, mid);			//dividing left part
      sort(mid+1, high);		//dividing right part
      merging(low, mid, high);	//time to conquer
   } else { 
      return;
   }   
}

int main() { 
   int i;

   printf("-----Unsorted Array-----\n");
   for(i = 0; i <= max; i++) //a arrayindeki tüm elemanlarý sýrasýz display eder
      printf("%d ", a[i]);

   sort(0, max);  // dividing kýsmý burada

   printf("-----Sorted Array-----\n");
   for(i = 0; i <= max; i++)
      printf("%d ", a[i]);
}
