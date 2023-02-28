#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>

//need to make the input a file or string at same time

int typeis(char data[]);
char *ReedSolomon(char *data, char level);
int charCapacity(int codeVersion, char EC_Level);

int codeVersion;
int length = NULL; //for now
int main(int argc, char* argv[])
{
	char *dataFile = argv[1];
	codeVersion = argv[2]; // 1-40
	char EC_Level = argv[3]; //L 7%, M 15%, Q 25%, H 30%

	//char mode[50]= "";
	char *data = "1110";

	int mode = typeis(data);
	printf("%i", mode);

	//choose the error correction level	
	//length depends on code version follow table	
	char *charCount = malloc(length);
	
	
	//error correction part of main
	char *correctionData = ReedSolomon(data, EC_Level);
	if(correctionData)
	{
		//do your thing
		free(correctionData);
	}
 
	
	
//	printf("%s",&argv);
	return 0;
}

int typeis(char data[])
{
		//data analysis
	//accept string
	//findout the mode: numeric, alphanumeric, byte or kannji
	
	size_t inputLength = sizeof(data);
	int numericInt = 0;
	int alphanumericInt= 0;
	int isoInt = 0;
	int utfInt = 0;
	int utf8IsValid = 1;

	for(size_t j=0; j < inputLength; j++)
	{
		if((data[j] >= '0' && data[j] <='9') )
		{
			//strcpy(mode, "numeric");	
			//printf("%s\n", mode);
			numericInt = 1;
			break;
			//printf("yes");
		}
		else if((data[j] >= 'A' && data[j] <='Z') ||
		         data[j] == '$' || data[j] == '%' ||
		         data[j] == '*' || data[j] == '+' ||
		         data[j] == '-' || data[j] == '.' ||
		         data[j] == '/' || data[j] == ':')
		         {
		         	//strcpy(mode, "alphanumeric");
		         	//printf("%s\n", mode);
		         	alphanumericInt = 1;
		         	break;	
		         }
		//check if ISO 8859-1
		else if(data[j] < 255)
		{
			isoInt = 1;
			break;
		}
		//check if UTF-8
		else if((data[j] & 0x80) != 0 && ((data[j] & 0xC0) != 0xC0) || (data[j] & 0x20) != 0)
			{
				utf8IsValid = 0;
				break;
			}

		//if utf-8 is valid print message and exit
		else 
			{
//				printf("UTF-8 detected \n");
				utfInt = 1;
				break;
				//strcpy(mode, "byte");
				//printf("%s\n", mode);
			}
    }
	

		if((isoInt == 1) )
		{printf("byte ISO");
		return 0100;}
		
		else if((utfInt == 1))
		{printf("byte UTF-8");
		return 0100;}
		
	    else if(alphanumericInt == 1)
	    {printf("alphanumeric");
	    return 0010;}
	    
     	else if(numericInt == 1) 
    	{printf("numeric");
		return 0001;}
		
}

char *ReedSolomon(char *data, char level)
{
	//takes string as input
	//allocates memory for string output
	//return pointer of that string
	//copy that string into a new one in main
	//free space

	int length = sizeof(data);

	//correction

	char *correctedData = "";
	char *pnt = malloc(sizeof(correctedData));
	strcpy(pnt, correctedData);

	return pnt;
}

int charCapacity(int codeVersion, char EC_Level)
{
	int capacity;
	//open csv file 
	FILE *fptr;
	fptr = fopen("capacities.csv", "r+");
	//find the version
	long int line;
	int location;
	
	//find the type
	//return the character capacity and close file
	fclose(fptr);
	return capacity;
}