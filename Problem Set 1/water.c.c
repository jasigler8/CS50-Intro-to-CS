/****************************************************************************
 * water.c
 *
 * Josh Sigler
 *
 * Harvard CS 50
 * Problem Set 1
 *
 * Prompt user for how long their shower is and return number of bottle waters
 * used
 ***************************************************************************/


#include <stdio.h>
#include <cs50.h>

int main (void)
{
    printf("minutes:");
    int water = GetInt();
    int bottles = water * 1.5 * 128 / 16;
    printf("bottles: %i\n",bottles);
}