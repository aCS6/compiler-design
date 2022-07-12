#include <stdio.h>
#include <ctype.h>
int main()
{
    char c;
    c = 'Q';
    printf("\nResult when uppercase alphabet is passed: %d", isalpha(c));

    c = 'q';
    printf("\nResult when lowercase alphabet is passed: %d", isalpha(c));

    c='+';
    printf("\nResult when non-alphabetic character is passed: %d", isalpha(c));

    return 0;
}
