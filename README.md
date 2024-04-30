# Cplusplus-Grocery-Item

This project is part of my academic coursework. Prompt is as follows:
-----------------------------------------------------------------------------------------------------------------
The program that the Corner Grocer is asking you to create should address the following functional requirements:

Menu Option One:

    Prompt a user to input the item, or word, they wish to look for.
    Return a numeric value for the frequency of the specific word.

Menu Option Two:

    Print the list with numbers that represent the frequency of all items purchased.
    The screen output should include every item (represented by a word) paired with the number of times that item appears in the input file, CS210_Project_Three_Input_File.txt. For example, the file might read as follows:

    Potatoes 4
    Pumpkins 5
    Onions 3

Menu Option Three:

    Print the same frequency information for all the items in the form of a histogram.
    Then print the name, followed by asterisks or another special character to represent the numeric amount.
    The number of asterisks should equal the frequency read from the CS210_Project_Three_Input_File.txt file. For example, if the file includes 4 potatoes, 5 pumpkins, and 3 onions, then your text-based histogram may appear as represented below. However, you can alter the appearance or color of the histogram in any way you choose:

Potatoes ****
Pumpkins *****
Onions ***

Menu Option Four:

    Exit the program.

Data File Creation:
Create a data file, with the naming convention frequency.dat, for backing up your accumulated data. The frequency.dat file should include every item (represented by a word) paired with the number of times that item appears in the input file.

This output file is created in the beginning of the program without user intervention and is for backup purposes. 

-----------------------------------------------------------------------------------------------------------------
The goal of the program is to take a list of grocery items (from a pre-existing file) and present them in one of three possible ways, based on the users menu selection. 

Option 1 prompts the user for an item, and then displays how many of said item were purchased (based on the file).

Option 2 displays all items purchased with a numerical value representing how many were purchased.

Option 3 displays all items purchased with a value in histogram format representing how many were purchased. 
