/**
 * resize.c
 *
 * Josh Sigler
 * 
 * Harvard CS 50
 * Problem Set 4
 *
 * resizes 24-bit uncompressed BMPs by a factor of n. 
 * Your program should accept exactly three command-line arguments, 
 * per the below usage, whereby the first (n) must be a positive integer less 
 * than or equal to 100, the second the name of the file to be resized, 
 * and the third the name of the resized version to be written.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    if (n < 0 || n > 100){
        printf("n must be a positive integer <= 100\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    int pad;
    
    //printf("biWidth:%i\n",bi.biWidth);
    //printf("biHeight:%i\n",bi.biHeight);
    //pad =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //printf("biSizeImage:%i\n",bi.biSizeImage);
    //printf("padding:%i\n",pad);
    //printf("bfSize:%i\n",bf.bfSize);
    
    int old_width = bi.biWidth;
    int old_height = bi.biHeight;
    
    //printf("\nNEW\n");
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;
    pad =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    bi.biSizeImage = ((bi.biWidth * abs(bi.biHeight)) * sizeof(RGBTRIPLE) + (pad * bi.biWidth));
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    //printf("biWidth:%i\n",bi.biWidth);
    //printf("biHeight:%i\n",bi.biHeight);
    //printf("biSizeImage:%i\n",bi.biSizeImage);
    //printf("pad:%i\n",pad);
    //printf("bfSize:%i\n",bf.bfSize);
    

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // determine padding for scanlines
    int old_padding =  (4 - (old_width * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
    for (int i = 0; i < abs(old_height); i++)
    {
        for (int l = 0; l < n; l++)
        {   
            fseek(inptr, (54 + ((old_width*3 + old_padding) * i)), SEEK_SET);
            for (int j = 0; j < old_width; j++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int k = 0; k < n; k++)
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);                   
            }
            // add padding
            for (int m = 0; m < new_padding; m++)
                fputc(0x00, outptr);
        }
    }



    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
    

}
