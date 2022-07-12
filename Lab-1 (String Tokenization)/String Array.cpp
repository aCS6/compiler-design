#include <stdio.h>
#include <string.h>

#define NUMBER_OF_STRING 4
#define MAX_STRING_SIZE 40


int main()
{
	char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
	{ "array of c string",
	  "is fun to use",
	  "make sure to properly",
	  "tell the array size"
	};



	for (int i = 0; i < NUMBER_OF_STRING; i++)
	{
			printf("%s\n",arr+i);
	}


	return 0;
}
