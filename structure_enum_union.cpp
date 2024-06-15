#include <iostream>

using namespace std;

struct employee
{
    int age; //4
    char fachar; //1
    float salary; //4
};

union money
{
    /* data */
    int rice; //4
    char car; //1
    float pounds; //4
};


int main() {
    struct employee abhi;

    struct employee vivek;
    abhi.age=19;
    abhi.fachar='c';
    abhi.salary=100000000000;
    cout<<abhi.age<<endl;
    cout<<abhi.fachar<<endl;
    cout<<abhi.salary<<endl;

    vivek.age=23;
    vivek.fachar='a';
    vivek.salary=1000000;
    cout<<vivek.age<<endl;
    cout<<vivek.fachar<<endl;
    cout<<vivek.salary<<endl;
    
    union money m1;
        m1.rice = 34;
        cout<<m1.rice<<endl;
        m1.car='c';
        cout<<m1.car;

   enum Meal{ breakfast, lunch, dinner};
    Meal m1 = lunch;
    cout<<m1;
    

    return 0;
}

//Size of structure is 4+4+1=9
//Size of union is the maximum size of vaiable because here variable share memeory at a point only one varaible is used value will be overwrite.


/*

instead of writing  struct employee repeatedly use below code and replace struct employee with ep;

typedef struct employee
{
    int eId; //4
    char favChar; //1
    float salary; //4
}
 ep;

*/

