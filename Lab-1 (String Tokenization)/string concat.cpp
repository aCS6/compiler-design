#include <stdio.h>
#include <string.h>

int main()
{
  char a[1000], b[1000];

  printf("Enter the first string\n");
  gets(a);


  strcat(a, "0");

  printf("String obtained on concatenation: %s\n", a);

  return 0;
}
