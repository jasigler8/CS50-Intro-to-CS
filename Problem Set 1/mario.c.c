/****************************************************************************
 * mario.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 1
 *
 * Build Mario's half-pyramid with #
 ***************************************************************************/


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do {
      printf("height:");    
      h = GetInt();
    } 
    while (h > 23 | h < 0);
    
    for (int x = 1; x <= h; x++){
        
        for (int y = x;y<h;y++){
            printf(" ");
        }
    
        printf("#");
    
        for (int z = 0;z<x;z++){
            printf("#");
        }
        
        printf("\n");
    }
}