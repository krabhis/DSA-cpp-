#include <iostream>

using namespace std;


class Hero{
    
    public:
    int health;
    char level;


};

int main() {

    Hero ramesh;

    ramesh.health=45;
    ramesh.level='A';

    cout<<"health is=>"<<ramesh.health<<endl;
    cout<<"Level is=>"<<ramesh.level<<endl;



    cout << "Hello, World!" << endl;
    return 0;
}


/*
=>In class by default acces modifier is private .
=>Random value is comming when variables are not intialized.


*/