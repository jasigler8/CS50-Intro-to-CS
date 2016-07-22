/**
 * recover.c
 *
 * Josh Sigler
 * 
 * Harvard CS 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 * 
 * 1) Open Memory Card File
 * 2) Find Beginning of jpg
 * 3) Open a new jpg
 * 4) Write 512 bytes until new jpg is found
 * 5) Detect end of file
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define JPEG 512

typedef uint8_t BYTE;

int main(int argc, char* argv[])
{

    //open infile
    FILE* infile = fopen("card.raw", "r");
    if (infile == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }
    
    BYTE buffer[JPEG];
    int counter = 0;
    FILE *outfile = NULL;
    
    while (fread(buffer,JPEG,1,infile) > 0)
    {
        
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] == 0xe0) || (buffer[3] == 0xe1)))
        {
            if (outfile!=NULL)
                fclose(outfile);
                    
            char title[10];
            sprintf(title,"%03d.jpg",counter);
            counter +=1;
            outfile = fopen(title,"w");
                
        }
        
        if (outfile!=NULL)
            fwrite(buffer, JPEG, 1, outfile);
            
    }
    
    if(outfile!=NULL)    
        fclose(outfile);
        
    if(infile!=NULL)    
        fclose(infile);
        
    return 0;
    
}
