#include <iostream>
#include <cstdlib>

#include "Human.hpp"

int main() {
    srand(time(NULL));
    Human JoshHigham("Josh Higham", 6, 5, 1994);
    JoshHigham.setNewJob("Mathematician", 100000);
    std::cout << JoshHigham;
    
    for (int i = 0; i < 12; ++i) {
        // Some random num % max + min
        std::cout << rand() % 6 + 1 << '\t';
    }
    
    return 0;
}