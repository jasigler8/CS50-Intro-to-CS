/****************************************************************************
 * initials.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 2
 *
 * prompts a user for their name and then outputs their initials in uppercase 
 * with no spaces or periods
 ***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){
    string name = GetString();
    printf("%c",toupper(name[0]));
    
    for(int i = 1, n = strlen(name);i < n; i++){
        if (name[i] == ' '){
            printf("%c",toupper(name[i+1]));
        }
    }
    printf("\n");
    
    
}