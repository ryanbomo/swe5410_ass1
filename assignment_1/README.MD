# SWE5415 Assignment 1 README

This is the README.md for assignment 1 of Software Testing.

## Assignment

This assignment has multiple sections that can be distilled down into three bullets:
1. Set up SSH with cs-scompute
2. Develop a program that can do the following:
   * Take user input specifying which program to get the list from and the paramters to run it with
   * Pipe the output to program
   * Check the programs output set against a series of tests
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

Pipe it in using: ssh rbomalaski2015@cs-scompute.cs.fit.edu ~kgallagher/public_html/sampleprogs/**[PROGRAM NAME]** **[MODIFIER]** **[MODIFIER]** **[MODIFIER]** | ./**[PROGRAM NAME}**

Program Name | Modifiers                         | Description                                      | Corresponding C Test Program
------------ | --------------------------------- | ----------------------------------------------   | -----------------------------
eq           | \[size\]                          | ?                                                | **TBD**
func         |                                   | Gives a datasat that is a Function               | **TBD**
onetoone     | \[size\] \[seed\]                 | Gives a One to One Data set                      | **TBD**
onto         | \[size\] \[seed\]                 | Gives an ONTO dataset                            | **TBD**
reflex       | \[size\] \[numCoords\] \[seed\]   | Gives a Reflexive Dataset                        | reflexive_test.c
ref.sym      |                                   | Gives a Reflexive and Symmetric Dataset          | ref_sym_test.c
ref.trans    |                                   | Gives a Reflexive and Transitive Dataset         | **TBD**
sym          |                                   | Gives a Symmetric dataset                        | symmetric_test.c
sym.trans    |                                   | Gives a Symmetric and Transitive Dataset         | **TBD**
testgen      |                                   | ?                                                | sym_trans_test.c
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
TBD

## Bug List
TBD

## Version Control

This is the core version of the program. 

Version Number | Description
-------------- | -----------
Version 1.0    | Creates Nice Looking Matrix Output of 0s and 1s
*Version 1.1*  | Perform specific test
*Version 1.2*  | Put each test into its own file (i.e. func test will be a func.c file)


*italics* mean that the version is still in progress or not started.