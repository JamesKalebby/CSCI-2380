Assignment #3:  Arrays, loops, random numbers

Due: start of class

Turn in a printout of your source code along with a sample run to show it works.

 

Part 1:

As an avid Monopoly player, I've often wondered what the most common dice rolls are when you roll 2 6-sided dice and sum the result.  To answer this question experimentally, write a program that asks the user how many trials they would like to run.  Then, simulate the roll of 2 six-sided dice using rand() repeatedly, according to how many trials the user wanted to run.  Finally, report the percentage of how many of the trials yielded a given sum for each of the possible sums from 2 to 12.  Here is an example run:

 

How many times do you want to throw a pair of six-sided dice?

>  1000

The distribution of results from the 1000 trials is: (the numbers below are not actually correct)

2:            .01

3:            .04

4:            .5

5:            .10

6:            .20

7:            .30

8:            .10

9:            .10

10:          .5

11:          .3

12:          .2

 

Part 2:

Expand your program by first asking the user how many dice they want to throw in addition to how many times they wants to throw them.  For 'numdice' and 'numthrows' given by the user, compute the distribution of values from numdice to 6*numdice over numthrows rounds. 

Historical context:  For those cool enough to play dungeons and dragons, a player’s stats are determined by rolling 3 d6’s and adding the results.  Finishing part 2 will give an understanding of how common or rare various ability scores might be.

 

 