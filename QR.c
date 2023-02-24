#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iconv.h>


int main(int argc, char* argv[])
{
	//data analysis
	//accept string
	//findout the mode: numeric, alphanumeric, byte or kannji
	char mode[50]= "";

	char data[] = "1110";
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
	/*	//check if the input is a valid ISO-8859-1
		iconv_t conv = iconv_open("UTF-8", "ISO-8859-1");
		char* inbuf = data;
		size_t inbytesleft = inputLength;
		char *outbuf = malloc(strlen(inbuf) + 1);
		size_t outbytesleft = sizeof(outbuf);
		size_t result = iconv(conv, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
		char **outptr = &outbuf;
		//if the message can be converted to UTF-8 using ISO-8859-1 encoding, print a message and exit
		if(result != (size_t)-1)
		{
//			printf("ISO_8859-1 encoding detcted. \n");
			isoInt = 1;
			
		}

//		free(outbuf);*/

		if((isoInt == 1) )
		printf("byte ISO");
		else if((utfInt == 1))
		printf("byte UTF-8");
	    else if(alphanumericInt == 1)
	    printf("alphanumeric");
     	else if(numericInt == 1) 
    	printf("numeric");
			
	
//	printf("%s",&argv);
	return 0;
}
