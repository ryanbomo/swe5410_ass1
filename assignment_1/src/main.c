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
#include "main.h"
#include "ssh_utils.h"


int
main (int argc, char **argv)
{
    char *pvalue = NULL;
    char *mvalue = NULL;
    int c,index;
    opterr = 0;

    //getopt checks for options -p and -d
    //-p [program name] allows the user to specify a program
    //-m [modifiers] allows the user to specify modifiers
    while ((c = getopt (argc, argv, "p:m:")) != -1)
        switch (c)
            {
            case 'p':
                pvalue = optarg;
                break;
            case 'm':
                mvalue = optarg;
                break;
            case '?':
                if (optopt == 'p')
                    fprintf (stderr, "-%c requires an argument.\n", optopt);
                else if (optopt == 'm')
                    fprintf (stderr, "-%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                abort ();
            }
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);

    getSet(pvalue, mvalue);
  
}



int isFunc(int arr[]){
    
}

int isOneToOne(int arr[]){
    
}

int isOnTo(int arr[]){
    
}

int isReflex(int arr[]){
    
}

int isSym(int arr[]){
    
}
int isTrans(int arr[]){
    
}

int partition(int arr[]){
    
}
