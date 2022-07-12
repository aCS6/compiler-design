#include <stdio.h>
#include <string.h>


int main () {
   const char haystack[20] = "TutorialsPoint";
   const char needle[10] = "Point";
   char *ret;

   ret = strstr(haystack, needle);
    if(ret==NULL){
        printf("no match found");
    }
    else{
        printf("The substring is: %s\n", ret);
    }


   return(0);
}
