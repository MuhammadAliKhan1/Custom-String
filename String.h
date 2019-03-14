#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <fstream>
class String
{
public:
  //Declaration of the functions which is defined in String.cpp
  int stringLength(char *);
  int find(char *, char *);
  int checkIfPal(char *);
  char *concatStrings(char *, char *);
  char *substr(char *, int, int);
  char *insert(char *, char *, int);
  char *replace(char *, char *, char *);
  char *deleteString(char *, int, int);
  void printArr(char *);
  void readCSV(char, char);
  void removeSpecialAndCapital(char *);
};
#endif //STRING_H