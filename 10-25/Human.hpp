#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <string>
#include <iostream>
#include <iomanip>

enum Profession {
    UNEMPLOYED,
    PILOT,
    ENGINEER,
    ENTHUSIAST,
    BAKER
};

/**
 * @brief A basic Human class containing Name, Birthday, and Job info
 */
class Human {
  public:
    // Constructors
    Human();
    Human(std::string, int, int, int);
    
    // Getter Functions
    std::string getName() { return name; }
    Profession getProfession() { return myJob; }
    long int getSalary() { return salary; }
    void printMyBirthday();
    // Setter Functions
    void setNewJob(Profession newProfession, long int newSalary);
  private:
    std::string name;
    Profession myJob;
    long int salary;
    int month, day, year;

    // Friend Function to print a message with cout
  friend std::ostream& operator<<(std::ostream& os, const Human& hum);
};

#endif  // HUMAN_HPP