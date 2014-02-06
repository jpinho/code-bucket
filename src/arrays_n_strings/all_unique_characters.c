/**
 *  Question:
 *  - Implement an algorithm to determine if a string has all unique characters.
 *
 *  Assumptios:
 *  - Assuming the text given contains only caracters between [a-z] (ANSI, 97-122).
 *
 *  @author João Pinho
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int checkAllUniqueChars(char[]);

int main_1(int argc, char* argv[])
{
    char text[60];
    printf("\nthis program detects whether all caracters in a string are all unique.");
    printf("\nlet's start, write something:");
    
    if(fgets(text, sizeof(text), stdin) == NULL){
        perror("No input specified.\n");
        exit(1);
    }
	
    if(!checkAllUniqueChars(text)){
        printf("\nyou have repeated characters in your text\n");
    }
    else printf("\nthe caracteres in you text are all unique\n");
    
    return 0;
}

/** 
 * Checks unique chars in @text, assuming @text contains characters only between [a-z].
 *
 * @param text a string containing the letters to be checked for unique caracters.
 * @return 0 for false and 1 for true.
 */
int checkAllUniqueChars(char text[])
{
    int checker = 0;
    char c;
    int i=0;
    
    // if the number of chars in text is greater that the number of caracters being checked
    // for uniqueness, then is impossible to not have a duplicated caracter.
    if(strlen(text) > ('z'-'a'))
        return 0;
    
    while((c = text[i++]) != 0)
    {
        // if [c] is 'a' then 'a' - 'a' (=) 97-97 = 0, so mask is 0000 ... 0001.
        int letterMask = 1 << (c - 'a');
        
        // if equal, the bit of letter [c] is already on, so, with one more it
        // means letter [c] is duplicated.
        if(checker == (checker | letterMask))
            return 0;
        
        // activates the letter bit in the checker mask.
        checker |= letterMask;
    }
    
    return 1;
}