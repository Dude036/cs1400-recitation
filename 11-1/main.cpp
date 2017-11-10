#include <iostream>
#include <fstream>

using namespace std;

struct B {
    int num1;
};

struct C {
    int num2;
};

struct A {
    B b;
    C c;
};

int main() {
    A a;
    
    a.c.num2 = a.b.num1 = 0;
    
    ofstream outFile("thing.txt");
    
    for (; a.c.num2 < 10; a.c.num2++) {
        for (; a.b.num1  < 10; a.b.num1++) {
            outFile << a.c.num2 + a.b.num1 << "\t";
        }
        outFile << endl;
    }
    return 0;
}

bool FullHouse(int dice[5]) {
    // dice[5] = {3, 5, 3, 5, 3};
    
    for (int i = 1; i < 6; i++) {
        int count = 0;
        for (int k = 0; k < 5; k++) {
            if (dice[k] == i) { count++; }
        }
        if (count == 3) {
            for (int j = 1; j < 6; j++) {
                int count2 = 0;
                for (int k = 0; k < 5; k++) {
                    if (dice[k] == j) { count2++; }
                }
                if (count2 == 2) { true; }
            }
            
        }
    }
}
