#include <iostream>

using namespace std;

int main() {
    // Create variables and initialize them
    int apples = 0;
    float price = 0;
    
    // Prompt user on the number of apples bought, and how much the total was.
    cout << "How many apples did you buy? ";
    cin >> apples;
    cout << "How much did you spend on apples? $";
    cin << price;
    
    // Determine how much each apple cost and tell the user
    double pricePerApple = price/apples;
    cout << "Each apple cost $" << pricePerApple << endl;
    
    // Checks to see if we spent too much on apples with an if statement
    if (pricePerApple > 5) {
        cout << "You spent way to much on apples....";
    }
    
    return 0;
}