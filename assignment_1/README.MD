# SWE5415 Assignment 1 README

This is the README.md for assignment 1 of Software Testing.

## Assignment

This assignment has multiple sections that can be distilled down into three bullets:
1. Set up SSH with cs-scompute
2. Develop a program that can do the following:
   * Take user input specifying which program to get the list from and the paramters to run it with
   * Interface with SSH
   * Run the desired program
   * Get the set of pairs and the size of the set
   * Check the programs output set against a series of tests
3. Test my program to make sure that it works as intended and is not too easy to break 

This is what I've gathered I need to do from the assignment sheet and in class discussion.

## Approach

In order to assure I achieve a working and tested product, I am going to stick to the following plan as best I can.  Any changes that need to be made to the process will be added to this section. Each of the three bullets from the Assignments section will be used as phases for the assignment.

### Phase 1 - Setup SSH with cs-compute
This stage is fairly straight forward. Simply SSH into cs-scomputer.cs.fit.edu, set up an SSH key and test that I can login through that key. While I am doing this, I will also be documenting the process so that I can help out any other students with this. The goal is to have this part of Phase 1 finished by January 14th.

Phase 1 also includes the task of getting the list of any programs that the user can call a set of numbers from and any parameters those programs can take. If the source for the programs is available, that will be read for this information. If it is not available, then some testing of each program will be done to try and draw reasonable conclusions on the parameters. If the source is available for this, then the deadline is also January 14th. If no source is available than an extra day will be alotted.

### Phase 2 - Develop Program
This is the nuts and bolts of the assignment. It will follow the sub bullets from above.

#### 2.1 Take User Input and Paramters
This will be accomplished by using getopt. The options will be specified as follows:

Option Flag | Description
----------- | -----------
-p          | Program to be run
-m          | String of modifiers (parameters) the user is passing


#### 2.2 Interface with program using SSH

#### 2.3 Run the user specified Gallagher Program

#### 2.4 Take the Programs output

#### 2.4 Run the Output Through Tests
Each out put must be tested for the following:
1. Is the relation one to one?
2. Is the relation onto?
3. Is the relation reflexive?
4. Is the relation symmetric?
5. Is the relation transitive?
6. Is the relation a function?
7. If the relation is reflexive, symmetric and transitive, display the partitions, one partition per line.
   - If the partitions are too large, just display the number of partitions
   - Too large is being taken to mean "won't fit on one line in a standard output (80 characters) \[Thanks IBM!\]"

### Phase 3 - Testing

## User Manual

## Bug List

## Version Control