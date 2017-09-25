#include <fstream>
#include <iostream>

// using namespace std;  // I took this off because I wanted to show you how to do it a different way.

const int ARRAY_SIZE = 50;
// Function Declarations
//      NOTE: This is valid, as long as you define the functions later.
double smallerThan50(int);
bool largerThan50(int);

int main() {
    // Declare array
    //      <variale type> variableName[<size of array>];
    //      See http://en.cppreference.com/w/cpp/container/array for C++11 Array styling
    int numbers[ARRAY_SIZE];
    // Open File called random.txt
    std::ifstream inFile;
    inFile.open("random.txt");
    
    // Check to make sure the file opened without an issue.
    if (inFile.is_open()) {
        int lines = 0;
        // Read in the contents into numbers array
        while (!inFile.eof()) {
            // This is how you access a certain index within an array
            //      NOTE: The index starts at 0, not 1;
            //      i.e. the 1st thing read from the file is stored into the 0th element of the array
            inFile >> numbers[lines];
            ++lines;
        }
        
        // Variable declaration for math to be used later.
        int evenNumbersAbove50 = 0;
        double averageRecipricalBelow50 = 0.0;
        int countBelow50 = 0;
        
        // for loop. Exactly like a while loop, just with different syntax
        /* i.e. This loop       is the same as this loop
        int i = 0;              for (int i = 0; i < thing; ++i)
        while (i < thing) {
            i++
        }
        
        // for (counter initialization; conditional statement; incriment counter)
        /* Further definitions:
            Counter Initialization - This is the definition of your counter.
            Conditional Statement: Similair to an if statement, this is what determines iterating through the loop again, or not.
            Incriment Counter: Incriment the counter you made so you don't run through an infinite loop.    */
        for (int i = 0; i < lines; ++i) {
            if (numbers[i] > 50) {
                // largerThan50 will return a bool. Otherwise known as a boolean value.
                // Booleans hold either true or false. It's a single bit of data.
                if (largerThan50(numbers[i])) {
                    evenNumbersAbove50++;
                }
            } else {
                // Add the result of smallerThan50 and incriment the count to get the average
                averageRecipricalBelow50 += smallerThan50(numbers[i]);
                countBelow50++;
            }
        }
        // Gets the average of all of the recipricals.
        averageRecipricalBelow50 /= countBelow50;
        
        // Print results.
        std::cout << "There were " << evenNumbersAbove50 << " even numbers above 50." << std::endl;
        std::cout << "The average recoprical of the numbers below 50 was " << averageRecipricalBelow50 << "." << std::endl;
        std::cout << "That average was based off of "<< lines << " numbers."<< std::endl;
    } else {  // Catch all statement for file opening errors.
        std::cout << "The file could not be opened." << std::endl;
    }
    // Close the file once I'm done with it.
    inFile.close();
    
    return 0;    
}

// Notice the color difference between this comment and the one below it?
// That's because those comments are special. They are used by a few different languages as a write up formula.
// you can initiate them with /** and end like a regular block comment.
/* Further definitions:
    @param - A definition of parameter types and their names.
    @return - The return statment. Should explain what is returning, and the type
    @brief - A brief description of the function, and what it does.
        Write your briefs as if you can't look at the actual source code to demonstrate your point.  */
/**
 * @param int num a number smaller than 50
 * @return bool true if even, false if odd. 
 * @brief Given a number larger than 50, it will determine if it's even or odd.
 */
bool largerThan50(int num) {
    // % operator: returns the remainder of a fraction.
    // i.e. 5/2 = 2, 5%2 = 1
    if (num % 2 == 0)
        return true;
    else
        return false;
}

/**
 * @brief Given a number smaller than 50, determines it's reciprical value and returns it.
 * @param int a number smaller than 50
 * @return The recoprical of that number
 */
double smallerThan50(int num) {
    // Safety statement to avoid dividing by 0
    if (num == 0) {
        return 0.0;
    }
    // I could have saved this variable, but i cast the integers to floats to do themath on the same line.
    return (double) 1/num;
}
