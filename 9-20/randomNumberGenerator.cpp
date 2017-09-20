#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

// Command Line Arguments Constants
std::string GENERATE_NUMBERS = "-n";
std::string MAX_NUMBER = "-a";
std::string MIN_NUMBER = "-i";
std::string HELP_MESSAGE = "-h";

// Function Declaration
std::vector<int> generateRandom(int, int, int);
void writeToFile(std::vector<int>);

/**
 * @brief The main function
 * @param argc # of command line arguments
 * @param argv 2d array of argument values
 * @return 0 if executed succesfully, failed otherwise
 */
int main(int argc, char* argv[]) {
    // Default values
    int upper = 50;
    int lower = 1;
    int iter = 50;
    
    if (argc % 2 == 0) {
        std::cout << "You have an odd number of arguments. Fix that." << std::endl;
    } else {
        // Command Line Argument Handling
        for (int i = 1; i < argc; i += 2) {
            std::cout << argv[i] << "\t"  << argv[i+1] << std::endl;
        }
        
        for (int i = 1; i < argc; i++) {
            std::string S = argv[i];
            i++;
            std::string arg = argv[i];
            if (S.compare(MAX_NUMBER) == 0) {
                upper = std::stoi(arg);
            }
            
            if (S.compare(MIN_NUMBER) == 0) {
                lower = std::stoi(arg);
            }
            
            if (S.compare(GENERATE_NUMBERS) == 0) {
                iter = std::stoi(arg);
            }
        }
        // Put data into the vector
        std::vector<int> v = generateRandom(lower, upper, iter);
        // Send to print
        writeToFile(v);
    }
    
    return 0;
}

/**
 * @brief Using Mersenne Twister Algorithm, generate n number of random numbers, stored into a vector and returned
 * @param min Lower bound of random numbers
 * @param max Upper bound of random numbers
 * @param iter Quantity of numbers to randomly generate
 * @return A vector of random numbers
 */
std::vector<int> generateRandom(int min, int max, int iter) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 randomNum(seed);
    std::vector<int> v;
    
    for (int i = 0; i < iter; ++i) {
        v.push_back(randomNum() % max + min);
    }
    
    return v;
}

/**
 * @brief Write a vector to a file, using enters to differentiate the numbers.
 * @param v Vector to write
 */
void writeToFile(std::vector<int> v) {
    std::ofstream out;
    out.open("random.txt");
    for (int i = 0; i < v.size(); ++i) {
        out << v[i];
        if (i != v.size() - 1) {
            out << std::endl;
        }
    }
    out.close();
}
