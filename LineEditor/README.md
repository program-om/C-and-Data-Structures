## How to run the program
- make
- ./editor <inputFile>

## Example Run

    > h

    This line editor can do the following commands:

        L file load file into this editor 
        E clear document 
        I line ­ insert line in front of current line 
        A line ­ append line to end of document 
        R line ­ replace current line 
        D ­ delete the current line 
        F target ­ makes line containing target current line 
        S n ­ set current line to nth line 
        M n ­ move current line n places 
        C ­ display current line to screen 
        P ­ display entire document to screen 
        W file ­ write document to file 
        H ­ display this list of commands 
        Q ­ quit the editor (does not save changes)

    > p 
    line 1 
    line 2 
    line 3

    > c 
    line 1

    > i first line

    > c 
    first line

    > p 
    first line 
    line 1 
    line 2 
    line 3

    > a last line

    > c 
    last line

    > p

    > m ­2

    > c 
    line 2

    > r middle line

    > p 
    first line 
    line 1 
    middle line 
    line 3 
    last line

    > s 0

    > c 
    first line

    > d

    > c 
    line 1

    > p 
    line 1 
    middle line 
    line 3 
    last line

    > f mid

    > c 
    middle line

    > w sample2.txt

    > l sampleedit.txt

    > p 
    line 1 
    line 2 
    line 3

    > e

    > p

    > q 