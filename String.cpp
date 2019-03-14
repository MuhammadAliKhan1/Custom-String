#include "String.h"

//Definition to count length of string
int String::stringLength(char *user)
{
    int length = 0;

    //Traverse each index till null character and increment in length
    for (int i = 0; user[i] != '\0'; ++i)
        ++length;
    return length;
}
int String::find(char *userString, char *pattern)
{
    String tempObject;
    //Outerloop traverses each index
    for (int i = 0; userString[i] != '\0'; ++i)
    {
        //Condition to check if the element of the main string is equal to the first index of the pattern
        if (userString[i] == pattern[0])
        {
            //For loop to traverse the index of the pattern
            for (int j = 0;; ++j)
            {
                if (j == (tempObject.stringLength(pattern)))
                    return i;//If every index matches it returns the starting index of the pattern
                if (userString[i + j] != pattern[j])
                    break;//If a index doesn't matches it breaks the inner loop
            }
        }
    }
    return -1;
}
//Definition to check if the string is palindrome
int String::checkIfPal(char *userStr)
{
    
    String obj;
    obj.removeSpecialAndCapital(userStr);//Calling this function to get a stripped down version of it

    //matches the index from the starting and ending
    for (int i = 0, j = (obj.stringLength(userStr)); i <= (obj.stringLength(userStr) / 2); ++i, --j)
    {
        //If one of the index doesn't match it returns a '0' indicating not a palindrome
        if (userStr[i] != userStr[j])
            return 0;
    }
    //After passing through the loop successfully it returns a 1 indicating its a palindrome
    return 1;
}
//Definition to concatenate two strings
char *String::concatStrings(char *user1, char *user2)
{
    String object;
    int i = 0;
    //Making an array which is the combination of length of the both strings +1 to make space for null character
    char *array = new char[((object.stringLength(user1)) + (object.stringLength(user1)) + 1)];
    //Transferring first string
    for (; user1[i] != '\0'; ++i)
        array[i] = user1[i];
    //Transferring second string
    for (int j = 0; user2[j] != '\0'; ++i, ++j)
        array[i] = user2[j];
    //Putting null character at the end
    array[i] = '\0';
    return array;
}
//Definition to get substring
char *String::substr(char *userStr, int index, int length)
{
    String object;
    char *array = new char[length + 1];//Making an array for substring
    array[length] = '\0';//Inputting null character at the end

    if (index > (object.stringLength(userStr)) || index < 0)
    {   
        //If the index is invalid it returns a NULL
        std::cout << "Invalid index." << std::endl;
        return NULL;
    }
    for (int i = 0; length != 0 && userStr[index] != '\0'; --length, ++index, ++i)
        array[i] = userStr[index];//Transferring the substring to the new array
    return array;
}
//Definition to insert a string in another string
char *String::insert(char *userStr, char *toInsert, int index)
{
    String obj;
    if (index > obj.stringLength(userStr))
    {
        //If the index is invalid it returns a NULL
        std::cout << "Invalid Index." << std::endl;
        return NULL;
    }
    //Inserting string using existing functions
    return obj.concatStrings(obj.substr(userStr, 0, index), (obj.concatStrings(toInsert, (obj.substr(userStr, index, (obj.stringLength(userStr) - 1))))));
}
//Definition to replace a string from another string 
char *String::replace(char *userStr, char *toReplace, char *replaceWith)
{
    String obj;
    int find = obj.find(userStr, toReplace);
    if (find == -1)
    {
        //If the index is invalid it returns a NULL
        std::cout << "String not found." << std::endl;
        return NULL;
    }
    else
    {
        //Replacing using existing functions
        obj.printArr(obj.concatStrings(obj.concatStrings(obj.substr(userStr, 0, obj.find(userStr, toReplace)), replaceWith), obj.substr(userStr, obj.stringLength(toReplace), obj.stringLength(userStr))));
    }
}
//Defintion to read a csv file
void String::readCSV(char charToReplace, char toReplaceWith)
{
    //Creating a file pointer to read
    std::ifstream reader;
    char temp;
    int i = 0;
    //Opening "Sample Data.csv" and returning it's address to file pointer called reader
    reader.open("Sample Data.csv");
    
    if (!reader.is_open())
    {
        //If file doesn't open it exits the function
        std::cout << "ERROR! Cannot open file." << std::endl;
        return;
    }

    while (reader >> std::noskipws >> temp)
    {
        //Counting number of words inside csv file
        ++i;
    }
    //Closing and opening the file to return the file pointer to the start of the csv file
    reader.close();
    reader.open("Sample Data.csv");
    //Creating an array to contain all the characters in the .csv file
    char array[i + 1];
    //Loop to read all the characters in .csv file and store it in the newly created array
    for (i = 0; reader >> temp; ++i)
    {
        //If a character is found which is to be replaced it is replaced with given character to be replace with
        if (temp == charToReplace)
            array[i] = toReplaceWith;
        else
            array[i] = temp;//Else the character is stored as it is
    }
    //Placing null character at the end of array
    array[i] = '\0';
    //Closing the file
    reader.close();
    //Creating a file pointer to write a new .csv file
    std::ofstream writer;
    //Opening Proccessed Data.csv file if it's not present it is created
    writer.open("Processed Data.csv");
    //Writing the Proccessed Data.csv file with the data inside the array
    for (i = 0; array[i] != '\0'; ++i)
    {
        writer << array[i];
    }
    //Closing the file processed data .csv
    writer.close();
}

void String::printArr(char *userStr)
{
    String tempObj;
    //If a NULL is present instead of the base address it exits the function
    if (userStr == NULL)
        return;
    //If a NULL is not present it prints the array by traversing
    for (int i = 0; i < tempObj.stringLength(userStr); ++i)
        std::cout << userStr[i];
    std::cout << std::endl;
}

void String::removeSpecialAndCapital(char *userStr)
{
    //This loop makes all the capital letters small
    for (int i = 0; userStr[i] != '\0'; ++i)
        if (userStr[i] > 64 && userStr[i] < 91)
            userStr[i] += 32;
    //This loop removes all the special characters
    for (int i = 0; userStr[i] != '\0'; ++i)
        if (userStr[i] < 97 || userStr[i] > 122)
        {
            for (int j = i; userStr[j] != '\0'; ++j)
                userStr[j] = userStr[j + 1];

            i = 0;
        }
}