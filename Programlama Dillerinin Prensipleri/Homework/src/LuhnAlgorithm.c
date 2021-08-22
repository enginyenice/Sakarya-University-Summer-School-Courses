#include<stdio.h>
#include"../lib/LuhnAlgorithm.h"

int Luhn(char columnData[],int size){
	int numberSize = size - 3;
	int clearNumbers[numberSize];
	
	ClearArray(numberSize,clearNumbers,columnData,size);
	EditNumber(numberSize,clearNumbers);
	int total = TotalNumbers(numberSize,clearNumbers);
	int result = LuhnCheck(total);
	return result;
	
	
}

void ClearArray(int numberSize,int clearNumbers[numberSize],char columnData[],int size){
	int k = 0;
	for(int i = 0; i< size;i++){
		int value = columnData[i] - 48;
		if(value >= 0 && value <=9){
			clearNumbers[k] = value;
			k++;
		}
	}	
}

void EditNumber(int numberSize,int clearNumbers[numberSize]){
	
	for(int k = numberSize-1; k>=0;k--){
		if((k) % 2 == 0)
		{
			clearNumbers[k] = NumberCheck(clearNumbers[k]* 2);
		}	
	}
}

int NumberCheck(int number){
	
	if(number - 9 > 0)
	{
		int a = number % 10;
		int b = number / 10;
		return a+b;
	}
	return number;
}

int TotalNumbers(int numberSize,int clearNumbers[numberSize]){
	int total = 0;
	for(int k = 0; k<numberSize;k++){
		total += clearNumbers[k];
	}
	return total;
}

int LuhnCheck(int total){
	return total % 10 == 0 ? 1 : 0;
}