#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outfile;
    outfile.open("thing.ppm");
    
    for (int i = 0; i < 60; i++) {
        outfile << "Hello world," << endl;
    }
    
    outfile.close();
    return 0;
}
