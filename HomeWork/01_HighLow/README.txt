CSCI/CMPE 2380

Assignment #1

Due date: start of class.

 

Hand in:

Turn in a printout of your source code along with a printout of sample runs showing that your program works.

                                                            

HiLo Guessing Game and High-Score Keeping

 

This assignment utilizes:

- random numbers

- loops

- conditional statements

- basic I/O

- file I/O

- maintaining sorted data

 

 

Part 1 

Write a program to play the Hi-Lo guessing game.  In particular, your program should:

 

·         Generate a random number from 1 to 100.

·         Ask the user to guess the number

·         If the user is right, the game ends

·         If the user's guess is too high or too low, the program informs the user of that fact and asks for another guess.

·         This repeats until the user gets the number correct.

 

Further, your program should keep track of how many guesses the user takes to get the number right.  An appropriate insult/compliment should then be issued to the user.  For example:

        11 or more "What a terrible score!..."

        9-10       "Not too shabby, but not too good either...

        7-8        "That's pretty good but you can do better..."

        5-6        "That's a very good score..."

        0-4        "Amazing! Or was it luck?"

 

Here is a sample run:

 

    Let’s play a Number Guessing Game!  What is your name?

    Robbie Schweller

    Guess a number between 1 and 100

    40

    Too low!!

    Guess a number between 1 and 100

    90

    Too high!!

    Guess a number between 1 and 100

    60

    Too high!!

    Guess a number between 1 and 100

    50

    Too low!!

    Guess a number between 1 and 100

    55

    Too low!!

    Guess a number between 1 and 100

    56

    You win!!

    It took you 6 guesses Robbie Schweller!

    That's a very good score...

 

 

Part 2

Now implement a “high-score” record keeping system.  The idea is that each time you play (run the program), your name and score should be recorded in a “high-score” file (at least if you scored in the top ten).  At the start of each run, the game should list the top 10 best scores of anyone that has ever played your game.

 

Here is a sample run:

 

    Welcome to the number guessing game.  The top 10 best scores so far are:

        Ed Sheeran 4

        Camilla Cabello 4

        G Easy 5

        Robbie Schweller 6

        Lil Pump 7

        Post Malone 7

        Cardi B 9

        Dua Lipa 12

        Portugal Theman 20

        Demi Lovato 53

    Think you’ve got what it takes to make the top ten?  Let’s find out! 

    What is your name?

    Bebe Rexha

    Guess a number between 1 and 100

            (etc…)

    It took you 10 guesses Bebe Rexha!

    Not too shabby, but not too good either...

    Hey, you made the top 10!  Congratulations!

    (end program)

 

The next time the program is run, the following should be displayed.  Note that Bebe is now in the top 10, and Demi has been booted off.

 

    Welcome to the number guessing game.  The top 10 best scores so far are:

        Ed Sheeran 4

        Camilla Cabello 4

        G Easy 5

        Robbie Schweller 6

        Lil Pump 7

        Post Malone 7 

        Cardi B 9

        Bebe Rexha 10 

        Dua Lipa 12

        Portugal Theman 20

 