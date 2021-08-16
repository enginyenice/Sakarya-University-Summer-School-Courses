#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2 basamaklı bir sayıysa eğer rakamlarını toplar.
int SumOfDigits(int value);
// Luhn algoritması başlatılır.
void LuhnFunc(char *number);
// Input.txt dosyasını okur.
void ReadFile(char *file_name);
// Gereksiz karakterleri temizle ve kart numarasını tersine çevir.
char *UnnecessaryCleanerAndReverser(char *array, int arrayLenght);
// Luhn algoritmasına göre sayıların toplamını hesapla
int CalculateNumbers(char *justNumbers, int justNumbersLenght);
// Output.txt
void WriteFile(char *output);
int main(void)
{
    //Clear Output
    FILE *fp;
    fp = fopen("outputs.txt", "w+");
    fprintf(fp, " ");
    fclose(fp);
    //Clear Output

    ReadFile("inputs.txt");
}
void ReadFile(char *file_name)
{

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("\n\nDosya yolu bulunamadi...\n\n");
        exit(EXIT_FAILURE);
    }

    int lineCount = 1;
    while ((read = getline(&line, &len, fp)) != -1)
    {
        LuhnFunc(line);
    }

    fclose(fp);
    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}
void LuhnFunc(char *numbers)
{

    if (numbers[strlen(numbers) - 1] == '\n')
    {
        numbers[strlen(numbers) - 1] = '\0';
    }

    int arrayLenght = strlen(numbers);
    char *justNumbers = UnnecessaryCleanerAndReverser(numbers, arrayLenght);
    int justNumbersLenght = strlen(justNumbers);
    int totalValue = CalculateNumbers(justNumbers, justNumbersLenght);

    int result = totalValue % 10;
    char *isValid = result == 0 ? " Gecerli" : " Gecersiz";
    char *output = strcat(numbers, isValid);
    printf("%s\n", output);
    WriteFile(output);
}
void WriteFile(char *output)
{
    FILE *fp;
    fp = fopen("outputs.txt", "a+");
    fprintf(fp, "%s\n", output);
    fclose(fp);
}
int CalculateNumbers(char *justNumbers, int justNumbersLenght)
{
    int total = 0;
    for (int i = 1; i < justNumbersLenght - 1; i += 2)
    {

        int value = (justNumbers[i] - 48) * 2;
        if (value > 9)
        {
            value = SumOfDigits(value);
            ;
        }
        total += value;
    }

    for (int i = 0; i < justNumbersLenght - 1; i += 2)
    {
        total += justNumbers[i] - 48;
        // printf("Def: %d\t\tIndex: %d\t\tLenght: %d\n",(justNumbers[i] - 48),i,justNumbersLenght);
    }

    return total;
}
int SumOfDigits(int value)
{
    int bigStep = value / 10;
    int smallStep = value % 10;
    return bigStep + smallStep;
}
char *UnnecessaryCleanerAndReverser(char *array, int arrayLenght)
{

    char justNumbers[arrayLenght];

    int m = 0;
    for (int i = arrayLenght - 1; i >= 0; i--)
    {
        int value = array[i] - 48;
        if (value > -1 && value < 10)
        {
            justNumbers[m] = array[i];
            m++;
        }
    }
    char *str = strcpy(str, justNumbers);
    return str;
}
