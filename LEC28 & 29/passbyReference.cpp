#include<iostream>
using namespace std;

void update2(int& n){
    n++;
}

/*
int  update1(int n){
     return n++;

}
*/

int main(){
    int n=5;
  // update1(n);
    update2(n);

    cout<<n;


}



/*In your main function, when you call the update1 function, the returned value is not assigned back to the variable n. Therefore, even though n is incremented inside the update1 function, the updated value is not stored anywhere.

To ensure that the changes made inside the update1 function are reflected in the variable n in the main function, you need to assign the returned value of update1 back to n.*/