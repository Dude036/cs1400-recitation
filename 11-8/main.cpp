/**
 * My practice test is located at 
 * Socrative.com > student login
 * Room Number: HIGHAMCS1400
 */
#include <cstdlib>
#include <iostream>
using namespace std;

const unsigned int ARRAY_SIZE = 6;

int PBRsortArray(int (&arr)[ARRAY_SIZE]);
void printArray(int arr[ARRAY_SIZE]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(NULL));
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            arr[i] = rand() % ARRAY_SIZE + 1;
        }
        
        printArray(arr);
        cout << PBRsortArray(arr) << endl;
        printArray(arr);
    }
}

// This is pass by reference. Instead of passing the literal value, you send the
// Address of the two variables. I.e. you're editing stuff in RAM than some 
// arbitrary place on the CPU. This changes the numbers when used.
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int PBRsortArray(int (&arr)[ARRAY_SIZE]) {
    static int loopsRun = 0;
    bool swapped = true;
    do {
        swapped = false;
        for (int i = 0; i < ARRAY_SIZE - 1; i++) {
            loopsRun++;
            /*
            Condition         ? True                   : false
            arr[i] > arr[i+1] ? swap(arr[i], arr[i+1]) : ;
            */
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
            }
        } 
    } while (swapped);
    return loopsRun;
}


enum Car {
    MAZZERATTI, // = 0
    FERRARRI,   // = 1
    CHEVY,      // = 2
    FORD        // = 3
};

// int j;
// switch (j) {
//     case MAZZERATTI:
//     case FERRARRI: 
//         // do something
//         break;
//     case CHEVY:
//     case FORD:
//         // do the same thing
//         break;
// }
