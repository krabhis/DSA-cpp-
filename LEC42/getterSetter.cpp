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
    //Static allocation.
    Hero ramesh;
    cout<<"size of ramesh is=>" <<  sizeof(ramesh) << endl;
    ramesh.setHealth(78);


    cout<<" Ramesh health is=>"<<ramesh.getHealth()<<endl;

    return 0;
}

