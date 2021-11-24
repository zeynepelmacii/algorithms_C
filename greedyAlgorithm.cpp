#include<stdio.h>

int length = 4; //size of array


void greedy(int amount) {					//how many coins and which coins will be needed
	int i = 0;
	int number; //for greedy calculation
	int coins[length]={25,10,5,1};
	
	while(i<length) {
		if(coins[i]<=amount){
			number = amount/coins[i];
			printf("%d times %d\n", number, coins[i]);
			amount-=(number*coins[i]);
		}
		i++;
	}	
}

int main() {
	int amount;
	int coins[length]={25,10,5,1};
	printf("enter the amount of your money ==> ");
	scanf("%d", &amount);
	greedy(amount);

	return 0;
}
