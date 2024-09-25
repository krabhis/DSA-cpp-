#include <iostream>
#include<cstring>

using namespace std;

class Hero {
private:
    int health;

public:
    char *name;
    char level;
    static  int timeToComplete;

    // Default constructor
    Hero() {
        cout << "Default Constructor Called" << endl;
        name=new char[100];  //dynamically
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

       Hero(Hero& temp) {

        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;

        cout << "Copy constructor called" << endl;
       
        this->health = temp.health;
        this->level = temp.level;
    }

 void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
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
    void setName(char name[]) {
        strcpy(this->name, name);
    }
    //Destructor
    ~Hero(){
        cout<<"Destructor is called"<<endl;
    }
};

//Initialisation of static member outside the class;

int Hero::timeToComplete=5;


int main() {

//first way to print 
    cout<< Hero::timeToComplete<<endl;

    Hero a;
//Second way to print
    cout<<a.timeToComplete<<endl;

  

    return 0;
}