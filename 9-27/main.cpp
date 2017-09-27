#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const float GRAVITY = 9.8;

int change(int);
void report(int, int);
float twiceGravity(float);
float halfGravity(float);

int main() {
	int a = 3;
	int b = change(a);
	report(a, b);

	// print a, b
	int i = 0;
	ifstream joeDirt;
	string s = "random.txt";
	joeDirt.open(s);
	int numberOfFriends = 0, numberOfEnemies = 0;
	while (i < 10) {  // !joeDirt.eof() to reach the end of the file
		joeDirt >> numberOfFriends >> numberOfEnemies;
		cout << "Friends: " << numberOfFriends << '\t';
		cout << "Enemies: " << numberOfEnemies << endl;
		report(numberOfEnemies, numberOfFriends);
		i++;
	}
	// i == 10
	float f1 = twiceGravity(static_cast<float>(i));
	float f2 = halfGravity((float) i);
	
	return 0;
}

int change(int a) {
	// int fred = a++;
	return ++a;
}

float twiceGravity(float g) {
	return g*2;
}

float halfGravity(float g) {
    return g/2;
}

void report(int num1, int num2) {
	if (num1 > num2) {
		cout << num1 << " is the biggest number.";
	}
	else {
		cout << num2 << " is the biggest number.";
	}
	cout << endl;
}
