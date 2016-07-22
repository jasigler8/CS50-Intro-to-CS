/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 

bool search(int value, int values[], int n){
    int start = 0;
    int end = n-1;
    int middle = (start + end)/2;
    
    sort(values, n);
    
    while (start <= end){
        if (values[middle] == value){
            return true;
        }
        else if (values[middle] < value){
            start = middle + 1;
        }
        else {
            end = middle - 1;
        }
        
        middle = (start + end)/2;
    }
    
    return false;
    
}

/**
 * Sorts array of n values.
 */

void sort(int values[] ,int n){
    
    for (int i= 0 ;i < n-1;i++){
        
        int pos_min = i;
        
        for(int j = i + 1;j < n;j++){
            
            if(values[j] < values[pos_min]){
                pos_min = j;
            }
        
            if (pos_min != i){
                int t = values[i];
                values[i] = values[j];
                values[j] = t;
            }
        }
    }
    
}
