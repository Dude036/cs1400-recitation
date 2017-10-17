#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <utility>

using namespace std;

int primeNumbersUnderMe(int);
long int sigma();
bool isEven(int);
std::pair<int, float> function(std::pair<float, int>);

int main() {
    // Implement a menu
    bool sentinal = true;
    int fromUser = 0;
    while (sentinal) {
        // cout options
        cout << "Options:" << endl;
        cout << "1: primeNumbersUnderMe" << endl;
        cout << "2: sigma" << endl;
        cout << "3: isEven" << endl;
        cout << "4: Pears" << endl;
        cout << "5: Quit()" << endl;
        cin >> fromUser;
        if (fromUser == 1) {
            int prime = 0;
            cout << "Prime numbers under what?" << endl;
            cin >> prime;
            primeNumbersUnderMe(prime);
        }
        else if (fromUser == 2) {
            cout << sigma();
        } else if (fromUser == 3) {
            int num = 0;
            cout << "What is even or odd?" << endl;
            cin >> num;
            if (isEven(num)) {
                cout << "That was even." << endl;
            }
            else {
                cout << "That was odd." << endl;
            }
        } else if (fromUser == 4) {
            std::pair<float, int> temp;
            cout << "Enter a float: " << endl;
            cin >> temp.first;
            cout << "Enter a int: " << endl;
            cin >> temp.second;
            std::pair<int, float> result = function(temp);
            cout << "pair = " << result.first << " " << result.second << endl;
        } else if (fromUser == 5) {
            sentinal = false;
        } else if (!isdigit(fromUser)) {
            cout << "That was not a number." <<endl;
            sentinal = false;
        }
    }
    
    
    return 0;
}

bool isEven(int n) {
    if (n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool isPrime(int number) {
    if (number != 2){
        if (number < 2 || number % 2 == 0) {
            return false;
        }
        for(int i=3; (i*i)<=number; i+=2){
            if(number % i == 0 ){
                return false;
            }
        }
    }
    return true;
}

int primeNumbersUnderMe(int num) {
    int primeNumbers = 0;
    for (int i = num; i >= 0; --i) {
        if (isPrime(i)) {
            primeNumbers++;
        }
    }
    return primeNumbers;
}

long int sigma() {
    long int total = 0;
    int temp;
    bool b = true;
    cout << "Enter a string of numbers to add together. Entering a negative number will exit." << endl;
    while (b) {
        cin >> temp;
        if (temp <= 0) {
            break;
        }
        total += temp;
    }
    return total;
}

std::pair<int, float> function(std::pair<float, int> pear) {
    std::pair<int, float> p;
    p.first = pear.second;
    p.second = pear.first;
    return p;
}
