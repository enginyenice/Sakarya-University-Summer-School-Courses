#ifndef LuhnAlgorithm
#define LuhnAlgorithm
int Luhn(char columnData[],int size);
void ClearArray(int numberSize,int clearNumbers[numberSize],char columnData[],int size);
void EditNumber(int numberSize,int clearNumbers[numberSize]);
int NumberCheck(int number);
int TotalNumbers(int numberSize,int clearNumbers[numberSize]);
int LuhnCheck(int total);
#endif