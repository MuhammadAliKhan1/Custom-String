#include "String.h"

int main()
{
    int select{0}, index{0}, length{0};
    String obj;
    char a, b;
    char *str1 = new char[500];
    char *str2 = new char[500];
    char *str3 = new char[500];
    while (1)
    {
        std::cout << "\n Press:-"
                  << "\n 1-To calculate length of a string."
                  << "\n 2-To concatenate two strings."
                  << "\n 3-To get a substring."
                  << "\n 4-To find a pattern."
                  << "\n 5-To insert a string."
                  << "\n 6-To replace a string."
                  << "\n 7-Check whether the given string is Palindrome."
                  << "\n 8-To replace a character from a (.csv) file."
                  << "\n Any key to exit."
                  << "\n Input: ";
        std::cin >> select;

        switch (select)
        {
        case 1:
            std::cout << "Input a string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Length of string is: " << obj.stringLength(str1) << std::endl;//Calling length function on str1
            break;
        case 2:
            std::cout << "Input first string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Input second string: ";
            std::cin.ignore();
            std::cin.get(str2, 500, '\n');
            std::cout << "Strings after concatenation: ";
            obj.printArr(obj.concatStrings(str1, str2));//Concatenating str1 & str2
            break;
        case 3:
            std::cout << "Input a string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Input a index number: ";
            std::cin >> index;
            std::cout << "Input a length: ";
            std::cin >> length;
            std::cout << "The sub string obtained is: ";
            obj.printArr(obj.substr(str1, index, length)); //Calling substr function on str1
            break;
        case 4:
            std::cout << "Input a string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Input a pattern to find in the given string: ";
            std::cin.ignore();
            std::cin.get(str2, 500, '\n');
            std::cout << "Pattern is found at the index: " << obj.find(str1, str2); //Calling find function on str1 to find str2
            break;
        case 5:
            std::cout << "Input a string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Input the string to insert: ";
            std::cin.ignore();
            std::cin.get(str2, 500, '\n');
            std::cout << "Input index number: ";
            std::cin >> index;
            str1 = obj.insert(str1, str2, index);//Calling insert function on str1 to insert str2
            obj.printArr(str1);
            break;
        case 6:
            std::cout << "Input a string: ";
            std::cin.ignore();
            std::cin.get(str1, 500, '\n');
            std::cout << "Input a string to replace: ";
            std::cin.ignore();
            std::cin.get(str2, 500, '\n');
            std::cout << "Input a string to replace with: ";
            std::cin.ignore();
            std::cin.get(str3, 500, '\n');
            obj.replace(str1, str2, str3);//Calling replace function on str1 on find str2 and replace it with str3
            break;
        case 7:
            std::cin.ignore();
            std::cout << "Input a string: ";
            std::cin.get(str1, 500, '\n');
            if (obj.checkIfPal(str1))//Checking if str1 is a palimdrome or not
                std::cout << "Given string is palindrome." << std::endl;
            else
                std::cout << "Given string is not a palindrome." << std::endl;
            std::cin.ignore();

            break;
        case 8:
            std::cout << "Place a file in the same folder as the program named \"Sample Data.csv\" and press enter." << std::endl;
            std::cin.ignore();
            std::cin.ignore();
            std::cout << "Input character you want to replace: ";
            std::cin >> a;
            std::cout << "Input character you want to replace with: ";
            std::cin.ignore();
            std::cin >> b;
            obj.readCSV(a, b); //Calling csv file function to replace character a with character b in "Sample Data.csv"
            std::cin.ignore();
            break;
        default:
            return 0;
        }
    }
}