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
This stage is fairly straight forward. Simply SSH into cs-scompute.cs.fit.edu, set up an SSH key and test that I can login through that key. While I am doing this, I will also be documenting the process so that I can help out any other students with this. The goal is to have this part of Phase 1 finished by January 14th.

Phase 1 also includes the task of getting the list of any programs that the user can call a set of numbers from and any parameters those programs can take. If the source for the programs is available, that will be read for this information. If it is not available, then some testing of each program will be done to try and draw reasonable conclusions on the parameters. If the source is available for this, then the deadline is also January 14th. If no source is available than an extra day will be alotted.

### Phase 2 - Develop Program
This is the nuts and bolts of the assignment. It will follow the sub bullets from above.

#### 2.1 Take User Input and Paramters
This will be accomplished by using getopt. The options will be specified as follows:

Option Flag | Description
----------- | -----------
-p          | Program to be run
-m          | String of modifiers (parameters) the user is passing


#### 2.2 Establish SSH connection and run command
Because of how C handles strings, this will be a little fun. For this portion, I will use the generated key to run software on my cs-scompute.cs.fit.edu login. The command will 

#### 2.3 Run the user specified Gallagher Program

Once the program has connected to scompute using SSH and navigated to ~kgallagher/public_html/sampleprogs, the following programs are options to be run (and as such, are the potential arguments for the -p flag for getopt):

Program Name | Modifiers            | Description
------------ | -------------------- | -----------
eq           | \[size\]             | ?
func         |                      | Gives a datasat that is a Function
onetoone     | \[size\] \[seed\]    | Gives a One to One Data set
onto         | \[size\] \[seed\]    | Gives an ONTO dataset
reflex       |                      | Gives a Reflexive Dataset
ref.sym      |                      | Gives a Reflexive and Symmetric Dataset
ref.trans    |                      | Gives a Reflexive and Transitive Dataset
sym          |                      | Gives a Symmetric dataset
sym.trans    |                      | Gives a Symmetric and Transitive Dataset
testgen      |                      | ?
trans        |                      | Gives a Transitive Dataset

I am not 100% sold that the seed flag is a true seed. It might just be a "consistent output" value. It seems that no matter what value is used for the seed, it gives the same output for a given side (i.e. ./onto 10 1 is the same as ./onto 10 560 )

#### 2.4 Take the Programs output
One of the specified instructions of the assignment is that the output of the gallagher program can not be saved to my local disc. I am taking this to mean that I can have the values in memory, but not saved to a file (database or otherwise). As such, the output will be used to help define an array, and the array will be utilized. Once the array is no longer useful, it will have its memory intentionally freed.

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
Much of assignment 2 will be about running tests on the software, so not too much initial testing will be done. Outside of making sure SSH is handled securely and that results are expected for the data run, no real testing will be finalized until assignment 2.

## User Manual
TBD

## Bug List
TBD

## Version Control
Version Number format: Major Release . Minor Release . Work Release

**0.0.1** - Initial Version with outline of functions and get opt