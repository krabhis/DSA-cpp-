#include <iostream>

using namespace std;


class Hero{

    private:
    int health;


    public:
    char level;

    //default constructor
    Hero(){
        cout<<"Consructor Called"<<endl;
    }

    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health=h;
    }

    void setLevel(char ch){
        level=ch;
    }
    
    


};

int main() {
cout<<"hello"<<endl;
    Hero ramesh;
cout<<"Dosto"<<endl;

  
}

