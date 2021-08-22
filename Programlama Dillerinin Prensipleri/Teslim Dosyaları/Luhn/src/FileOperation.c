#include<stdio.h>
#include"../lib/FileOperation.h"
const char*InputFilePath="doc/inputs.txt";
const char*OutputFilePath="doc/outputs.txt";

void ReadFile(int N, int M, char lineData[N][M]){
	int line=0;
	
	int ch=0;
	FILE*fp;
    fp=fopen(InputFilePath,"r");
	
	int textLenght=0;
	while(!feof(fp))
	{
	  ch=fgetc(fp);
	  if(ch=='\n')
	  {		  
		line++;
		textLenght=0;
	  }else{
		  lineData[line][textLenght]=ch;
		  textLenght++;
	  }
	}
	fclose(fp);
}

int GetLineCount(){
	int lines=1;
	int ch=0;
	FILE*fp;
    fp=fopen(InputFilePath,"r");
	while(!feof(fp))
	{
	  ch=fgetc(fp);
	  if(ch=='\n')
	  {
		lines++;
	  }
	}
	fclose(fp);
	return lines;
}

void WriteFile(char *output)
{
    FILE *fp;
    fp = fopen(OutputFilePath, "a+");
    fprintf(fp, "%s\n", output);
    fclose(fp);
}
void CreateOutputFile(){
	FILE *fp;
    fp = fopen(OutputFilePath, "w");
    fprintf(fp, "");
    fclose(fp);
	
}