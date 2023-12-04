#!/bin/bash

input="The five boxing wizards jump quickly"

# Question 1: In the input string, Match "bo", followed by any string of any length, including the empty string, followed by "ng".
echo "Question1"
echo "$input" | grep -o 'bo.*ng'

# Question 2: In the input string, Match a word, at least four letters long, that doesn’t contain "u"
echo "Question2"
echo "$input" | grep -Po '\b(?![a-zA-Z]*u)[a-zA-Z]{4,}\b'

# Question 3: In the input string, match three consecutive words, where the middle word begins with "b".
echo "Question3"
echo "$input" | grep -Po '(\b\S+\b)\s+(\bb\S+\b)\s+(\b\S+\b)'

# Question 4: Identify all function declarations (including parameters)
echo "Question4"
# mfw 😭 when i parse a context-free grammar with a regular expression 
# well, provided the return type can be any value, just search for word+word+(parameters*)
# valid qualifiers are: const, volatile, struct
# valid modifiers are: *, &
# type can be any word
# where parameter must be of "qualifer* type() name"
# (\b[a-zA-z]*\b)[\s\r\n]+(\b[a-zA-z]*\b)[\s\r\n]{0,}(\()
# (\((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)+(\b[a-zA-z]*?\b)([&?])[\s\r\n]+(\b[a-zA-z]*\b)(\[\])?)
# 
# (\b[a-zA-z]+\b)[\s\r\n]+(\b[a-zA-z]+\b)[\s\r\n]{0,}(\()                                                                       # match before opening parentheses
# \(((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)*(\b[a-zA-Z]+\b)[*&]?[\s\r\n]+(\b[a-zA-Z]+\b)(\[\])?(,[\s\r\n]+)?)+\)    # match parameters
# (?=[\s\r\n]+\{)                                                                                                               # forward looking (not supported with dynamic length 😭)
# ok yes i could've seperated this w/e
grep -Po '(\b[a-zA-z]+\b)[\s\r\n]+(\b[a-zA-z]+\b)[\s\r\n]{0,}\(((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)*(\b[a-zA-Z]+\b)[\s\r\n]*[*&]?[\s\r\n]*(\b[a-zA-Z]+\b)(\[\])?(,[\s\r\n]*)?)*\)' code.c

# Question 5: Extract lines where a C++ structure is defined using awk
# struct word {anything}
echo "Question5"
# struct[\s\r\n]+(\b[a-zA-Z]*\b)[\s\r\n]*\{[^\}]*\}
# this definetly breaks if there are nested curly braces, oh well
awk '
/^struct / {
  inside_struct = 1;
  print $0;
  next;
}
inside_struct {
  print $0;
  if (/\{/) {
    brace_count++;
  }
  if (/\}/) {
    brace_count--;
  }
  if (brace_count == 0) {
    inside_struct = 0;
  }
}
' code.c

# Question 6: Replace "marks" with "score" in the code1_2.cpp using sed
echo "Question6"
sed -e 's/marks/score/g' code.c

# Question 7: Find lines where a function is defined with at least two arguments
echo "Question7"
grep -Po '(\b[a-zA-z]+\b)[\s\r\n]+(\b[a-zA-z]+\b)[\s\r\n]{0,}\(((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)*(\b[a-zA-Z]+\b)[\s\r\n]*[*&]?[\s\r\n]*(\b[a-zA-Z]+\b)(\[\])?(,[\s\r\n]*)?){2,}\)' code.c

# Question 8: Identify lines with preprocessor directives using grep
echo "Question8"
grep '#include\s*<[a-zA-Z.]*>' code.c

# Question 9: Using grep count the total number of lines that contain function declarations or definitions in both files.
echo "Question9"
grep -Poc '(\b[a-zA-z]+\b)[\s\r\n]+(\b[a-zA-z]+\b)[\s\r\n]{0,}(?=\(((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)*(\b[a-zA-Z]+\b)[\s\r\n]*[*&]?[\s\r\n]*(\b[a-zA-Z]+\b)(\[\])?(,[\s\r\n]*)?)*\))' code.c

# Question 10: Extract and list all unique function names using grep and cut
echo "Question10"
grep -Po '(\b[a-zA-z]+\b)[\s\r\n]+(\b[a-zA-z]+\b)[\s\r\n]{0,}(?=\(((const[\s\r\n]+|volatile[\s\r\n]+|struct[\s\r\n]+)*(\b[a-zA-Z]+\b)[\s\r\n]*[*&]?[\s\r\n]*(\b[a-zA-Z]+\b)(\[\])?(,[\s\r\n]*)?)*\))' code.c | cut -d ' ' -f2 | sort -u

