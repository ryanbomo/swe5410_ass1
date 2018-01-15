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
/* File Name: ssh_utils.c
 * Date:
 * About:
 * 
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>


int runSSHUtils(char *pvalue, char *mvalue){
    // Bring Over values
    // Check to Make sure Valid Input
        //If Not, break gracefully
    // Build Command String
    // Connect with SSH
    // Get String Array of output
    // Convert First Line to int (this is the main dimension (i.e. if 10, dimensions are 10x10)
    // Build Matrix based on coordinates in string array
    // Return Matrix
}

int validateInput(char *pvalue, char *mvalue){
    
}

char * createCommand(char *pvalue, char *mvalue){
    
}

// heavySSHWork
/* Connect with SSH
 * Run Command
 * Get Input from STDOUT
 * Build array of String Pointers
 */

// buildMatrix
/* Take array of string pointers
 * First index is matrix dimension
 * Each next string is a set of coordinates to fill in a 1 in matrix
 * Matrix Dimesnion should be given to an int variable like matrixSize
 * Coordinates should be saved to array like so:
 *      int table[3][2] = {{1,1}, {2,2}, {3,3}};
 */