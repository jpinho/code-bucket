/**
 *  Question:
 *  - Implement a function void reverse(char* str) in C which reverses a null- terminated string.
 *
 *  Assumptions:
 *  - Assuming string containing unicode caracters (0-255).
 *
 *  @author João Pinho
 */

#include <stdio.h>
#include <strings.h>

void reverse(char*);

int main_2(int argc, char* argv[])
{
    char str[] =  "Yet another Hello World (YAHW)" ;
    
    printf("\nabout to reverse string: '%s'\n", str);
    printf("strlen %d\n", (unsigned)strlen(str));
    reverse(str);
    printf("reversed string: '%s'\n", str);
    
    return 0;
}

/**
 * Given a string @str reverses it in place, without aux variables.
 *
 * @param str a string to be processed
 */
void reverse(char* str)
{
    char *s, *e;
    if(str[0]==0 || str[1]==0) return;
    
    // pointer to first char
    s = str;
    
    // pointer to last char
    e = str + (strlen(str)-1);
    
    // for string with odd number of characters there is no need to switch the middle caracter,
    // so when the pointer [s] becames bigger than [e] all caracters have been properly switched.
    // also for the in-place switch, recall that s = s^e^s^e
    do{
        *s ^= *e;
        *e ^= *s;
        *s ^= *e;
    }
    while(++s < --e);
}