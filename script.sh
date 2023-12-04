#!/bin/bash

input="The five boxing wizards jump quickly"

# Question 1: In the input string, Match "bo", followed by any string of any length, including the empty string, followed by "ng".
echo "Question1"
echo "$input" | grep -o 'regex_goes_here'

# Question 2: In the input string, Match a word, at least four letters long, that doesn’t contain "u"
echo "Question2"
echo "$input" | grep -o 'regex_goes_here'


# Question 3: In the input string, match three consecutive words, where the middle word begins with "b".
echo "Question3"
echo "$input" | grep -o 'regex_goes_here'

# Question 4: Identify all function declarations (including parameters)
echo "Question4"
grep -E 'regex_goes_here' code.c

# Question 5: Extract lines where a C++ structure is defined using awk
echo "Question5"
awk 'regex_goes_here' code.c


# Question 6: Replace "marks" with "score" in the code1_2.cpp using sed
echo "Question6"
sed -e 'regex_goes_here' code.c

# Question 7: Find lines where a function is defined with at least two arguments
echo "Question7"
grep -E 'regex_goes_here' code.c


# Question 8: Identify lines with preprocessor directives using grep
echo "Question8"
grep 'regex_goes_here' code.c

# Question 9: Using grep count the total number of lines that contain function declarations or definitions in both files.
echo "Question9"
awk 'regex_goes_here' code.c

# Question 10: Extract and list all unique function names using grep and cut
echo "Question10"
grep -Eo 'regex_goes_here' code.c | cut -d' ' -f2 | sort -u

