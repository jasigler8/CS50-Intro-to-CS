/****************************************************************************
 * vigenere.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 2
 *
 * Encode an user supplied string using a Vigenere style cipher.              
 * Alphabetical key is being entered by the user as a command line argument
 ***************************************************************************/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int convert(int x, int y);

int main (int argc, string argv[]){
    
    //check how many arguments are being passed
    if(argc != 2){
        printf("There should be 1 argument!\n");
        return 1;
    }
    
    //check that argument only contains letters
    int argv_length = strlen(argv[1]);
    for(int i = 0; i < argv_length ;i++){
        if(isdigit(argv[1][i])){ 
            printf("All arguments must be text\n");
            return 1;
        }
    }
    
    
    string decrypt = GetString();
    int string_length = strlen(decrypt);
    
    int j = 0;
    for (int i = 0; i < string_length ; i++){
        if (isalpha(decrypt[i])){
            printf("%c", convert(decrypt[i], tolower(argv[1][(j % argv_length)])-97 ));
            j++;
        }
        else {
            printf("%c",decrypt[i]);   
        }
    }
    
    printf("\n");
    
    //(int) argv[1][(j % argv_length)-97]
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


