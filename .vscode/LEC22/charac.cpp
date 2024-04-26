#include<iostream>
using namespace std;
int main() {
    char name[90];

    cout<<"Enter the your name:"<<endl;
    cin>>name;
      name[2] ='\0';

    cout<<"Your name is----";
    cout<<name<<endl;


    return 0;

  

}
