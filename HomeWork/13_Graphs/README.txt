Graph homework

Topics:  Graph implementations, graph applications, problem solving with graphs, breadth first search, depth first search, topological sorting.

 

Turn in:  To receive credit for each of the problems below, schedule a meeting with Schweller or TA Aldabada.  In the meeting you will explain your solution to the instructor or TA.  If your solution is correct, efficient, and you are able to explain it well, you will receive credit for that problem. 

 

Due date:  You may attempt to receive credit for the problems below up until the last day of classes.

 

 

1.  Course Scheduler

Input:  A file consisting of a list of UTRGV courses and the prerequisites for each course.  For example, the first line states that course 2380 has prerequisites of 1370 and calc1.:

 

2380 1370 calc1

1370 1101

3333 3310 2380

seniorproject softwareeng 3333

molecularcomputing 3333

calc2 calc1

calc3 calc2

diffeq calc3

automata 3310 3333 3332

3332 calc1

calc1 kidmath

kidmath

1101 ged

3310 1101

softwareeng 3333 3310

ged

 

Output:  Print an ordering in which you could take all of the listed courses such that you don't take any course before you've taken all the required prerequisite courses.

Hints:  Read about the following topics: Depth first search, topological sorting, recursion.

 

 

2.  Virus Attack!

Input:

1) A number n denoting the number of computers in a network (labelled from 0 to n-1).

2) A list of computers that are connected to each other.

3) A number denoting a computer that just got infected with a virus.

 

For example, below there are 10 computers (named 0 - 9).  Computer 3 is connected to computer 2, etc.  Finally, the last line states that computer 1 has just become infected.

 

10

3 2

7 8

1 2

3 9

9 1

0 1

6 7

8 6

1

 

Output:  List all computers that will be infected with the virus, ie, all computers that can be reached from computer 1.  In this case, the answer is 1, 0, 9, 2, 3

Hints:  This is similar to a problem you’ve solved in the past.

 

 

3.  Maze Solver 

Input: A file with an ASCII maze consisting of walls, free spaces, and a "start" and "end".

 

Output:  A shortest path thought the maze connecting the start with the end.  Print a picture of the maze with some character used to denote the shortest path connect s to e.

 

Example input:

#############

#           #

# #####     #

#   s ###  e#

#       #   #

#  ######   #

#     #     #  

#           # 

#############

 

Corresponding output:

#############

#...........#

#.#####    .#

#...s ###  e#

#       #   #

#  ######   #

#     #     #  

#           # 

#############

 

Be sure to test your solution on many diverse mazes to make sure it always finds the shortest possible solution.

Hints: Create a basic graph from the input maze, then find a shortest path from s to e in that graph.

 

 

4. Word puzzle.

To solve this problem use the following dictionary file:

largedictionary.txt

 

Consider the following word puzzle in which you take two valid dictionary words of the same length:

                dog

                cat

And transform the first word into the second by a series of single letter switches.  For example, we can go from dog to cat in 4 jumps:

                dog

                hog

                hot

                hat

                cat

To be a valid solution, each hop can only change 1 letter and each word in the path from the start word to the finish word must be a valid dictionary word.  Write a program that takes as input any two English words of equal length up to 4 characters long, and computes a solution path connecting the two words if one exists.  An example run is given below:

 

Enter two words: 

                > time good

 

The following is a valid path from time to good:

time

dime

dike

duke

dupe

dope

dole

mole

mold

gold

good

 

Hints: Try to model the problem as a shortest path graph problem.