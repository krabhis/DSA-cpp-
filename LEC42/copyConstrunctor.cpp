#include <iostream>

using namespace std;

class Hero {
private:
    int health;

public:
    char level;

    // Default constructor
    Hero() {
        cout << "Default Constructor Called" << endl;
    }

    // Parameterized constructor
    Hero(int health) {
        cout << "this => " << this << endl;
        this->health = health;
    }

    // Parameterized constructor with two parameters
    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

   //copy constructor

   Hero(Hero&temp){
    cout<<"Copy construcor called"<<endl;
    this->health=temp.health;
    this->level=temp.level;
   }

    void print() {
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
};

int main() {
    Hero S(70, 'C');
    S.print();

    Hero R(S);  // Using the copy constructor
    R.print();

    return 0;
}


/*Constructors in C++ are essential for initializing objects. While the compiler provides a default constructor if none is defined, you often need parameterized constructors to initialize objects with specific values. The this keyword is crucial in constructors to avoid ambiguity and to refer to the current object's fields and methods.

*/