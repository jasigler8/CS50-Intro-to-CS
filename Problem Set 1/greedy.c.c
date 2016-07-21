/****************************************************************************
 * greedy.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 1
 *
 * Calculate the fewest number of coins needed for change
 ***************************************************************************/
 
 
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void){
    
    float c;
    int t;
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;
    do {
        printf("How much change is owed: ");
        c = GetFloat();
    } while (c <=0);
    
   t = round(c * 100);
   
   
        if (t >= 25)
        {
            q = (t / 25);
            //("%d Quarters\n",q);
            t = t - (q * 25);
        }
        
        if (t >= 10)
        {
            d = (t / 10);
            //printf("%d Dimes\n",d);
            t = t - (d * 10);
        }
        
        if (t >= 5)
        {
            n = (t / 5);
            //printf("%d Nickels\n",n);
            t = t - (n * 5);
        }
        
        if (t > 0)
        {
            p = (int) t;
            //printf("%d Pennies\n",p);
            t = 0;
        }
        
        
       printf("%d\n",q + d + n + p);   
    
    
}