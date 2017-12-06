#include <iostream>
#include <string>
using namespace std;
void red(int i) {
    // does stuff here
}

void red(int i, int j) {
    // does stuff here
}

class Object {
    class Thing {
        
    };
    
};

int total(int size, int arr[]);
int main() {
    Object o;
    int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    std::string s = "Hello World.";
    std::cout << "String acces by index " << s[6] << endl;
    cout << "Total in the the array: " << total(10, arr) << endl;
    int arr2d[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; ++j) {
            arr2d[i][j] = i*j;
        }
    }
    
    for (auto i : arr) {
        cout << i;
    }
    
    return 0;
}

int total(int size, int arr[]) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}



Thomas Edison was the first human voice recorded
