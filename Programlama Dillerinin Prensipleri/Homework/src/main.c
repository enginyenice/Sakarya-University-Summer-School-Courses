#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/FileOperation.h"
#include "../lib/LuhnAlgorithm.h"

int main()
{	
	const int line 		= GetLineCount();
    const int column 	= 16 + 3;
    char lineData[line][column];

	ReadFile(line,column,lineData);
	CreateOutputFile();
	
	for(int selectedLine = 0; selectedLine<line;selectedLine++){
		int result = Luhn(lineData[selectedLine],column);
		char *isValid = result == 1 ? " Gecerli" : " Gecersiz";

		char selectedNumbers[column];
		strncpy(selectedNumbers, lineData[selectedLine],column );
		
		char *output = strcat(selectedNumbers, isValid);
		WriteFile(output);
		printf("%s\n", output);
	}	
	system("PAUSE");
}


