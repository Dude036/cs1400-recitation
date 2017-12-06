#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Suit {
    SPADE,
    HEART,
    CLUB,
    DIAMOND
};

struct Card {
    Suit suit;
    int value;
    Card(Suit s, int i) {
        suit = s;
        value = i;
    }
    void print() {
        string s;
        switch(suit) {
            case SPADE:
            s = "Spade";
            break;
            case HEART:
            s = "Heart";
            break;
            case CLUB:
            s = "Club";
            break;
            case DIAMOND:
            s = "Diamond";
            break;
        }
        cout << value << " " << s << endl;
    }
};

int main() {
    int a[10];
    vector<Card> v;
    
    for (int i = 0; i < 10; i++) {
        a[i] = i;
    }
    for (int i = SPADE; i <= DIAMOND; i++) {
        for (int j = 1; j < 14; ++j) {
            v.push_back(Card((Suit)i, j));
        }
    }
    
    for (int i = 0; i < 10; i++) {
        cout << "a[" << i << "] = " << a[i] << endl;
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << "v[" << i << "] = ";
        v[i].print();
    }
    
    cout << "v.size()=" << v.size()<< endl;
    v.pop_back();
    cout << "v.size()=" << v.size()<< endl;
}
