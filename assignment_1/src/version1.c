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
/* File Name: main.c
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
    //print input
    char str[100];
    int i = 0;
    int x, y;
    
    //get dimension
    scanf("%s", &str);
    printf("Entered string is %s \n", str);
    int size = atoi(str);
    printf("Size is: %d\n",size);
    
    
    // create matrix
    int matrix[size][size];
    
    //get coordinates
    while(scanf("%s", &str) != EOF){
        if (i%2 == 0){
            printf("A coordinate %s", str);
            x = atoi(str);
            i++;
        }
        else{
            printf(" , %s \n", str);
            y = atoi(str);
            matrix[y-1][x-1] = 1;
            i++;
            
        }
        
    }
    
    //fill in zeros
    for (y = 0;y<size;y++){
        for (x = 0; x<size;x++){
            if (matrix[y][x] != 1){
                matrix[y][x] = 0;
            }
            printf("%d", matrix[y][x]);
        }
        printf("%s", "\n");
    }
    
    //print out matrix
    
  
}



