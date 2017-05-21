#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    int height;
    // set height:
    do 
    {
        printf("Set height of pyramid you want. It must be integer less than 23. Your number: ");
        height = GetInt();
    }
    while ( height < 0 || height > 23 );
      
    // create pyramide:
    for (int i = 0; i < height; i++) 
    {
        int grids = i + 2;
        int spaces = height - grids;
        
        // print spaces: 
        for(int k = 0; k <= spaces; k++) printf(" ");
        // print grids:
        for(int k = 0; k < grids; k++) printf("#");
        printf("\n");
    }
    
}