/* ------------------------------------------------------------------------- */
/*   Copyright (C) 2017 
                Author:  Ryan Bomalaski, rbomalaski2015@my.fit.edu
                Florida Tech, Computer Science
   
       This program is free software; you can redistribute it and/or modify
       it under the terms of the GNU Affero General Public License as published by
       the Free Software Foundation; either the current version of the License, or
       (at your option) any later version.
   
      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.
  
      You should have received a copy of the GNU Affero General Public License
      along with this program; if not, write to the Free Software
      Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.              */
/* ------------------------------------------------------------------------- */
/* File Name: onetoone_test.c
 * Date:
 * About:
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>


int
main (int argc, char **argv){
    char str[100];
    int i, x, y;
    int numCoords = 0;
    
    // get dimension
    scanf("%s", &str);
    int size = atoi(str);
    
    
    // create matrix and blank out the matrix, because reasons 
    // (C doesn't do that automatically)

    int matrix[size][size];
    for (y = 0;y<size;y++){
        for (x = 0; x<size;x++){
            matrix[y][x] = 0;
        }
    }
    
    // get coordinates
    // add a 1 for each coordinate
    i = 0;  //walking variable to differentiate X and Y input
    while(scanf("%s", &str) != EOF){
        if (i%2 == 0){
            // printf("[ %s", str);        // prints X coordinate                           DEBUG
            x = atoi(str);
            i++;
        }
        else{
            // printf(" , %s ] \n", str);  // prints Y coordinate and returns new line      DEBUG
            y = atoi(str);
            matrix[y-1][x-1] = 1;
            numCoords++;
            i++;
        }
    }
    /*                                                                                      DEBUG
    //print matrix
    for (y = 0;y<size;y++){
        for (x = 0; x<size;x++){
            
            printf("%d", matrix[y][x]);
        }
        printf("%s", "\n");
    }
    */
    
    // One to One test
    int yHasX = 0;
    for ( y = 0; y<size;y++){
        yHasX = 0;
        for (x = 0; x<size;x++){
            //check for more than one X
            if (matrix[y][x] == 1){
                if (yHasX == 1){
                    printf("It is not One to One\n");
                    exit(0);
                }
                yHasX = 1;
            }
        }
        /*
        // check if it has no X
        if (yHasX == 0){
            printf("It is not onetoone\n");
            exit(0);
        }
        */
    }
    printf("It is One to One\n");
    
  
}



