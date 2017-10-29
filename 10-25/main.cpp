#include <iostream>

#include "Human.hpp"

Profession getMyJob() {
    std::cout << "What Job do you want?" << std::endl;
    std::cout << "0: Unemployed" << std::endl;
    std::cout << "1: Pilot" << std::endl;
    std::cout << "2: Engineer" << std::endl;
    std::cout << "3: Video Game Enthusiast" << std::endl;
    std::cout << "4: Baker" << std::endl;
    int num;
    std::cin >> num;
    return (Profession) num;
}

int main() {
    Human JoshHigham("Josh Higham", 6, 5, 1994);
    
    Profession job = getMyJob();
    
    JoshHigham.setNewJob(job, 50000);
    std::cout << JoshHigham;
    
    return 0;
}