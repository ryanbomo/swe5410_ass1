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
/* File Name: eq_test.c
 * Date: 02/07/2018
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
    char str[10];
    int i, x, y;
    int numCoords = 0;
    
    //get dimension
    scanf("%s", str);
    int size = atoi(str);
        
    // create matrix
    // blank out the matrix, because reasons C doesn't do that automatically
    int **matrix = (int **)malloc(size*sizeof(int*));
    for (i=0;i<size;i++){
        matrix[i] = (int *)malloc(size*sizeof(int));
    }
    for (y = 0;y<size;y++){
        for (x = 0; x<size;x++){
            matrix[y][x] = 0;
        }
    }
    
    //get coordinates
    //add a 1 for each coordinate
    i = 0;  //walking variable to differentiate X and Y input
    while(scanf("%s", str) != EOF){
        if (i%2 == 0){
            //printf("[ %s", str);        // prints X coordinate                        DEBUG
            x = atoi(str);
            i++;
        }
        else{
            //printf(" , %s ] \n", str);  // prints Y coordinate and returns new line       DEBUG
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
    
    //Transitive Symmetric and Reflexive  Check
    for ( y = 0; y<size;y++){
        for (x = 0; x<size;x++){
            if (matrix[y][x] == 1){
                //check trans
                for (int z = 0;z<size;z++){
                    if (matrix[z][y] == 1 && matrix[z][x] != 1){
                        printf("It's not Transitive\n");
                        exit(0);
                        
                    }
                }
                
                //check sym
                if (matrix[y][x] != matrix[x][y]){
                    printf("It is not Symmetric\n");
                    exit(0);
                }
            }

        }
        // check ref
        if (matrix[y][y] != 1){
            printf("It's not Reflexive\n");
            exit(0);
        }
        
    }
    printf("It is Transitive Symmetric and Reflexive\n");
    
    int printed[size];
    int numClusts = 0;
    for (y = 0; y<size; y++){
        printed[y] =0;
    }
    
    
    //will only print clusters if the total size (and thus the potential number of clusters) is less than 80
    for (y = 0; y<size; y++){
        if (printed[y] == 0){
            if (size<80){
                printf("\n");
            }
            numClusts++;
        }
        for (x = 0; x<size; x++){
            if (matrix[y][x] == 1 && printed[x] != 1){
                if(size <80){
                    printf("%d ",x+1);
                }
                printed[x] = 1;
            }
        }
    }
    
    printf("\nNumber of clusters: %d\n", numClusts);
    
    free(matrix);
  
}



