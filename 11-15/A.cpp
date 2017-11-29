#include <iostream>
#include <string>
using namespace std;

class Student {
  public:
    string getStudentName();
    Student(string newName, double newCash);
    ~Student();
  private:
    void changeStudentName(string);
    
    string name;
    double cashOnCard;
};

Student::Student(string newName = "None", double newCash = 5) {
    cout << "Hi, I'm new here. " << endl;
    name = newName;
    cashOnCard = newCash;
}
Student::~Student() {
    cashOnCard = 0;
    cout << "Goodbye" << endl;
}


int main() {
    Student student;
    
    return 0;
}

