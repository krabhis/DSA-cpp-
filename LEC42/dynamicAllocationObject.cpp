#include <iostream>

using namespace std;


class Hero{

    private:
    int health;


    public:
    char level;

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
    //creation of object
    //Dynamocally
    Hero *b=new Hero;

    b->setLevel('A');
    b->setHealth(70);
    cout<<"level is=>"<<(*b).level<<endl;
    cout<<"health is=>"<<(*b).getHealth()<<endl;

    cout<<"level is=>"<<b->level<<endl;
    cout<<"health is=>"<<b->getHealth()<<endl;



}

