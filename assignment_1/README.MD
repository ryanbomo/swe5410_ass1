# SWE5415 Assignment 1 README

This is the README.md for assignment 1 of Software Testing.

## Assignment

This assignment has multiple sections that can be distilled down into three bullets:
1. Set up SSH with cs-scompute
2. Develop a series of programs that can do the following:
   * Take piped output in a predifined format
   * Check the programs output set against a test specific to each program
3. Test my program to make sure that it works as intended and is not too easy to break 

This is what I've gathered I need to do from the assignment sheet and in class discussion.

## Approach

In order to assure I achieve a working and tested product, I am going to stick to the following plan as best I can.  Any changes that need to be made to the process will be added to this section. Each of the three bullets from the Assignments section will be used as phases for the assignment.

### Phase 1 - Setup SSH with cs-compute
This stage is fairly straight forward. Simply SSH into cs-scompute.cs.fit.edu, set up an SSH key and test that I can login through that key. While I am doing this, I will also be documenting the process so that I can help out any other students with this. The goal is to have this part of Phase 1 finished by January 14th.

Phase 1 also includes the task of getting the list of any programs that the user can call a set of numbers from and any parameters those programs can take. If the source for the programs is available, that will be read for this information. If it is not available, then some testing of each program will be done to try and draw reasonable conclusions on the parameters. If the source is available for this, then the deadline is also January 14th. If no source is available than an extra day will be alotted.

**Complete** - This guide can be found in the created_guides folder under the parent directory.  The guide is called ssh-swe-4415.pdf.

### Phase 2 - Development

### Take Input

Pipe it in using: ssh rbomalaski2015@cs-scompute.cs.fit.edu ~kgallagher/public_html/sampleprogs/**[PROGRAM NAME]** **[MODIFIER]** **[MODIFIER]** **[MODIFIER]** | ./**[PROGRAM NAME]**

Program Name | Modifiers                         | Description                                      | Corresponding C Test Program
------------ | --------------------------------- | ----------------------------------------------   | -----------------------------
eq           | \[size\]                          | ?                                                | eq_test.c
func         |                                   | Gives a datasat that is a Function               | func_test.c
onetoone     | \[size\] \[seed\]                 | Gives a One to One Data set                      | onetoone_test.c
onto         | \[size\] \[seed\]                 | Gives an ONTO dataset                            | onto_test.c
reflex       | \[size\] \[numCoords\] \[seed\]   | Gives a Reflexive Dataset                        | reflexive_test.c
ref.sym      |                                   | Gives a Reflexive and Symmetric Dataset          | reflexive_test.c and symmetric_tst.c
ref.trans    |                                   | Gives a Reflexive and Transitive Dataset         | reflexive_test.c and transitive_test.c
sym          |                                   | Gives a Symmetric dataset                        | symmetric_test.c
sym.trans    |                                   | Gives a Symmetric and Transitive Dataset         | symmetric_test.c and transitive_test.c
testgen      |                                   | ?                                                | **N/A**
trans        |                                   | Gives a Transitive Dataset                       | transitive_test.c

### Create Matrix

Using the first return of the program as the "size", an array of Size x Size is created and populated with 0's. Then the programs will iterate over each coordinate that comes in and adds a 1 to the matrix.

### Run Tests

Basically each test for the outputs 1 through 7 will be given their own program in the end. I will update this list later once this stage of Phase 2 is reached.

### Phase 3 - Testing
Much of assignment 2 will be about running tests on the software, so not too much initial testing will be done. Outside of making sure SSH is handled securely and that results are expected for the data run, no real testing will be finalized until assignment 2.

## Quick Definitions
**One To One** - A relation R on a set A is called *one to one* if for any a1, a2 ∈ A, a1 != a2 ⇒ f(a1) != f(a2). Equivalently, for any a1, a2 ∈ A, f(a1) = f(a2) ⇒ a1 = a2. Basically, each element in X is mapped to a unique value of Y or no value. i.e. \[\[1,2\], \[2,1\]\] is one to one, \[\[1,1\],\[1,2\]\] is not.

**Onto** - for all b ∈ B, there exists an a ∈ A such that f(a) = b.   Every Y is mapped to an X value, X values need not be unique.

**Reflexive** - A relation R on a set A is called *reflexive* if (a, a) ∈ R for every element a ∈ A.

**Symmetric** - A relation R on a set A is called *symmetric* if (b, a) ∈ R whenever (a, b) ∈ R, for all a, b ∈ A. (i.e. if \[1,3\] then also \[3,1\])

**Transitive** - A relation R on a set A is called *transitive* if whenever (a, b) ∈ R and (b, c) ∈ R, then (a, c) ∈ R, for all a, b, c ∈ A. (i.e. if \[1,3\] and \[3,4\], then also \[1,4\])

**Function** - A relation f on A and B is a *function*, denoted f : A → B if for all a ∈ A, there exists a unique b ∈ B such that (a, b) is a member of the relation, denoted f : a |→ b or f(a) = b. The Quick and dirty is, each X in the ordered pair is unique.

## User Manual
### Overview
The initial idea was to create one large program where the user could specify what tests to run, and what Gallagher function to call. This was abandoned, as C does not handle matrices very well. Instead, each test is its own program.

### General Use
Run ./compile.sh in the scripts folder to compile the code.

### Reflexive Testing
Reflexive Testing is done with the reflexive_test.c code. This is compiled into ref_test. To test the reflexive program, the ./ref_test.sh script can be run with the format ```./ref_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./ref_test```.

### Symmetric Testing
Symmetric Testing is done with the symmetric_test.c code. This is compiled into sym_test. To test the symmetric program, the ./sym_test.sh script can be run with the format ```./sym_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./sym_test```.

### Transitive Testing
Transitive Testing is done with the transitive_test.c code. This is compiled into trans_test. To test the transitive program, the ./trans_test.sh script can be run with the format ```./trans_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./trans_test```.

### Equivalence Testing
Equivalence Testing is done with the eq_test.c code. This is compiled into eq_test. To test the equivalence program, the ./eq_test.sh script can be run with the format ```./eq_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./eq_test```.

The output of the Equivalence Test will be a series of cluters unless the size of the domain is larger than 80, then it outputs only the number of clusters.

### Function Testing
Function Testing is done with the func_test.c code. This is compiled into func_test. To test the function program, the ./func_test.sh script can be run with the format ```./func_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./func_test```.

This currently uses a wonky version of One to One and Onto testing, but will be fixed with a later version. It does work though.

### One to One Testing
One to One Testing is done with the onetoone_test.c code. This is compiled into onetoone_test. To test the One to One program, the ./onetoone_test.sh script can be run with the format ```./onetoone_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./onetoone_test```.

### Onto Testing
Onto Testing is done with the onto_test.c code. This is compiled into onto_test. To test the Onto program, the ./onto_test.sh script can be run with the format ```./onto_test.sh [GALLAGHER PROG NAME]``` from the scripts folder. It can also be called with just ```./onto_test```.

### Combined Tests
Initially, I though that each of the combined progams listed on Dr. Gallagher's folder would need to be their own separate programs as well. These were unnecessary, but can be found in my archive folder.

## Bug List

## Fixed Bugs
### 001 - Compile Warnings
Bug 001 is fixed.  I was passing scanf the wrong variable to write to.

### 002 - Array Sizing
Currently the max size of the 2D array is limited to roughly 1200x1200.  This is due to not allocating the memory, but relying on the compiler to do so.  For an initial submission, this is acceptable, but I need to be able to send MUCH larger arrays for the testing that the professor would like to do.  Thus a malloc based solution is needed. Now using malloc correctly.

## Version Control

This is the core version of the program. 

Version Number | Description
-------------- | -----------
Version 1.0    | Creates Nice Looking Matrix Output of 0s and 1s
Version 1.1 | Put each test into its own file (i.e. func test will be a func_test.c file)
