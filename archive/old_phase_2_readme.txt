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
------------ | --------------------              | -----------
eq           | \[size\]                          | ?
func         |                                   | Gives a datasat that is a Function
onetoone     | \[size\] \[seed\]                 | Gives a One to One Data set
onto         | \[size\] \[seed\]                 | Gives an ONTO dataset
reflex       | \[size\] \[numCoords\] \[seed\]   | Gives a Reflexive Dataset
ref.sym      |                                   | Gives a Reflexive and Symmetric Dataset
ref.trans    |                                   | Gives a Reflexive and Transitive Dataset
sym          |                                   | Gives a Symmetric dataset
sym.trans    |                                   | Gives a Symmetric and Transitive Dataset
testgen      |                                   | ?
trans        |                                   | Gives a Transitive Dataset

I am not 100% sold that the seed flag is a true seed. It might just be a "consistent output boolean flag". It seems that no matter what value is used for the seed, it gives the same output for a given size.  For example: ./onto 10 1 is the same as ./onto 10 560. Without the source, I can't confirm this, but I will be operating under this assumption.

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