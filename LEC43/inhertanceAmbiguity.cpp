#include <iostream>

using namespace std;

class A{
    public:

    void func(){
        cout<<"I am  function A"<< endl;
    }
};

class B{
    public:

    void func(){
        cout<<"I am function B"<<endl;
    }
};

class C:public A, public B {


};

int main() {

    C obj;

    //obj.func();

    /*
    Both super class have method of same name when it is inherited by C class and accesed there is ambiguity that which method should be called  so to resolve this ambiguity we use scope resolution  operator;


    obj.A::func();
    
    */

  obj.A::func();
  obj.B::func();
    return 0;
}