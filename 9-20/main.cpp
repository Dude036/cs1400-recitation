#include <fstream>
#include <iostream>
#include <vector>

const int ARRAY_SIZE = 50;

int main() {
    int numbers[ARRAY_SIZE];
    std::ifstream inFile;
    inFile.open("random.txt");
    if (inFile.is_open()) {
        int i = 0;
        while (!inFile.eof()) {
            inFile >> numbers[i];
            ++i;
        }
        std::cout << "Numbers smaller than 50:" << std::endl;
        int evenNumbersBelow50 = 0;
        for (int i = 0; i < ARRAY_SIZE; ++i){
            if (numbers[i] < 50) {
                std::cout << numbers[i] << ", ";
                if (numbers[i] % 2 == 0) {
                    ++evenNumbersBelow50;
                }
            } else {
                numbers[i] /= 2;
                --i;
            }
        }
        std::cout << std::endl << "There were " << evenNumbersBelow50 << " even numbers below 50." << std::endl;
    } else {
        std::cout << "The file could not be opened." << std::endl;
    }
    inFile.close();
    
    return 0;    
}
