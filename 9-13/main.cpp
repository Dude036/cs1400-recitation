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
    // If you aren't wanting to reach the endof the file, and only do it x amount of times
    // int times = 0; while (times < x) {
    while (!file.eof()) {
        // Input month, day, and year from the file, and store into respective variables
        file >> month >> day >> year;
        // Print stuf.
        cout << month << "/" << day << "/" << year << endl;
        // Incriment iterator ifyou only need to do it x amoutn of times.
        // times++;
    }
    
    // Close the file so I can access it later.
    file.close();
    return 0;
}
