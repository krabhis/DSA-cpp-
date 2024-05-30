// ++++++++++++++++++++++++WAys of declaring or initializing pointers++

// #include<iostream>
// using namespace std;

// int main(){
//     int i=5;
//     int *q=&i;
//     cout<<q<<endl;
//     cout<<*q<<endl;

//     int *p=0;
//     p=&i;
//     cout<<p<<endl;
//     cout<<*p<<endl;


//     return 0;

// }


///////////////////size of integer and pointer


// #include<iostream>
// using namespace std;
// int main(){

// int num=5;
// int *p=&num;


// double d=4.3;
// double *p2=&d;

// cout<<"size of integer"<<sizeof(num)<<endl;
// cout<<"size of pointer "<<sizeof(p)<<endl;


// cout<<"size of integer of double"<<sizeof(num)<<endl;
// cout<<"size of pointer double "<<sizeof(p);



// }


//////////////////understanding pointer variable incrementing///

#include<iostream>
using namespace std;
int main(){

    // int num=5;
    // int a=num;
    // a++;

    // cout<<"a before"<<num<<endl;
    // cout<<"a after"<<num<<endl;

    // int *p=&num;
    // cout<<"before"<< num <<endl;
    // (*p)++;
    // cout<<"after"<< num <<endl;


// ///copying a pointer

    // int *q=p;
    // cout << p<<"-"<<q<<endl;
    // cout << *p<<"-"<<*q<<endl;


//////important concept//
// 1.
// int i=3;
// int *t =&i;

// cout<<"Before t "<<t<<endl;
// t=t+1;

// cout<<"After t"<<t<<endl;

// 2.

int *ptr=0;
int d=7;
*ptr=d;
cout<<*ptr<<endl;

// if t=100 then after incrementing it will go to next integer of four bit





}
