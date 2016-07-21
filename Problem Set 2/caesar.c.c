/****************************************************************************
 * caesar.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 2
 *
 * Encode an user supplied string using a caesar cipher.              
 * Numerical key is being entered by the user as a command line argument.
 ***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int convert(int x, int y);

int main (int argc, string argv[]){
    
    if(argc != 2){
        printf("There should only be 1 argument!\n");
        return 1;
    }
    
    int k = atoi(argv[1]) % 26;
    
    //printf("%i\n",k);
    
    //printf("Enter a string:");
    string decrypt = GetString();
    
    for (int i = 0, n = strlen(decrypt); i < n; i++){
        printf("%c", convert(decrypt[i],k));
    }
    printf("\n");
    
    return 0;
}

int convert(int x, int y){
    
    if ((x < 'A') | ((x > 'Z') & (x < 'a')) | (x > 'z')){
        return x;
    }
    
    int z = x + y;
    
    
    
    if (isupper(x) && (z > 'Z')){
        z = z - 'Z' + 'A' -1;
        return z;
    }
    if (islower(x) && (z > 'z')) {
        z = z - 'z' + 'a' -1;
        return z;
    }
    
    return z;   
    
}