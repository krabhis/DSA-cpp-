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
//Parameterised constructor
    Hero(int health){
        cout<<"this=>"<<this<<endl;
        this->health=health;

         
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
    Hero ramesh(10);
    cout<<"address of ramesh=>"<<&ramesh;

  
}

