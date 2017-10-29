#include "Human.hpp"

/**
 * @brief Parametered cosntructor for a human
 * @param _name Name of the Human
 * @param _month Month they were born
 * @param _day Date of Birth
 * @param _year Birth year
 */
Human::Human(std::string _name, int _month, int _day, int _year) {
    name = _name;
    myJob = UNEMPLOYED;
    salary = 0;
    month = _month;
    day = _day;
    year = _year;
    std::cout << "You just made a human. Yay!" << std::endl; 
}

/**
 * @brief Setter for getting a new job
 * @param _profession String of the name of the job
 * @param _salary How much you'll earn
 */
void Human::setNewJob(Profession  _profession, long int _salary) {
    myJob = _profession;
    salary = _salary;
}

/**
 * @brief Prints Human's birthday in MM/DD/YYYY fashion
 */
void Human::printMyBirthday() {
    std::cout << std::setw(2) << month << "/"
        << std::setw(2) << day  << "/"
        << std::setw(4) << year << std::endl;
}

/* Don't try to understand this. This is for demonstration purposes only. */
std::ostream& operator<<(std::ostream& os, const Human& hum) {
    std::string printProf = "";
    switch (hum.myJob) {
        case UNEMPLOYED:
            printProf = "Unemployed";
            break;
        case PILOT:
            printProf = "Pilot";
            break;
        case ENGINEER:
            printProf = "Engineer";
            break;
        case ENTHUSIAST:
            printProf = "Video Game Enthusiast";
            break;
    }
    
    
	os << "Hi, my name is " << hum.name << ". I work as a "
	    << printProf << " making $" << hum.salary
	    << " annually. If you want to throw me a party, my birthday is "
	    << std::setw(2) << hum.month << "/"
	    << std::setw(2) << hum.day   << "/" 
	    << std::setw(4) << hum.year  << "."
	    << " Have a great day!" << std::endl;
	return os;  
}
