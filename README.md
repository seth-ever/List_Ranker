# List_Ranker
Given a List of Items (Movies, flavors of ice cream, etc.), will use a recursive algorithm to sort the data and output a new .txt containing the items in a ranked order. The program prompts the user for each comparison.
This Program takes in a .txt file as an input and outputs another .txt
The output will be Ranked_*inputFile*.txt
For testing purposes, entering "Random" as the input file will execute the program on a list of 30 ranom numbers 0-199.
This seems to O(n*log(n)) but is still sub-optimal. Its spacial complexity is O(n) becuase it only creates one vector containing the whole list, does not create sub-vectors during recursive steps.
