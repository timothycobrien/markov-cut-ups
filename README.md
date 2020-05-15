# Markov Cut Ups
Markov Chain Cut-up project for French 3730. Inspired by technique of the same name by William S. Burroughs.
# How to use
* Clone the repo.
* Have to compile using G++-8, Clang not updated to handle filesystem yet. CMake should be configured to handle GCC compilation.
* run `cmake` followed by `make` to generate the executable inside of `/bin`.
* Place desired author's texts into a distinct directory inside the texts directory with their last name, likely needs to be .txt formatting. Other formatting may work but have only tested for .txt.
* Run program from command line with at least 1 argument. Argument list is as follows:
    1. **Mandatory argument!** Number of words in the output for each author's texts. If there are 3 authors, then total output will be 3 times the number of words marked by this argument.
    2. Prefix size for Markov-Chain implementation. Defaults to 2, but 3 can also work well. Any greater produces uninteresting results for the most part.
    3. List of authors, or all if all authors are desired, needs to be the same as the corresponding directory in texts. Defaults to all.
# Results
This produces an output file in the output directory called output.txt. It contains the results of the algorithm.

The algorithm will generate text for each author provided, then randomly combine the generated texts into one large text and write that to output.

# Thanks and credit
Special thanks to my French professor Robert Barsky who allowed me to do this as my final project. It was a lot of fun and I learned a great deal.

I consulted several stack overflow posts, which are marked in the code. I also used CPP reference.
