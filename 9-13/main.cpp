#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Declare the file name and open the file called "birthday.txt"
    ifstream file;
    file.open("birthdays.txt");
    // Declare birthday variables and an iterator for my while loop
    int month, year, day, iterator = 0;
    
    // Loop: Continues until the end of file.
    // Special Function: eof(), [end of file] returns true if you reached the end of file, and false otherwise
    //      See http://www.cplusplus.com/reference/ios/ios/eof/ for more info on eof()
    // ! [not operator]: return the opposite of a boolean function. IF true, return false
    while (!file.eof()) {
        // Input month, day, and year from the file, and store into respective variables
        file >> month >> day >> year;
        // Print stuf.
        cout << month << "/" << day << "/" << year << endl;
        // Incriment iterator
        iterator++;
    }
    
    // Close the file so I can access it later.
    file.close();
    return 0;
}
