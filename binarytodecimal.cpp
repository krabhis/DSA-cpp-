// #include<iostream>
// #include<math.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int bit,ans=0, i=0;
//     while(n!=0){
//         bit=n&1;
//         ans=(bit*pow(2,i))+ans;
//         n=n>>1;
//         i=i+1;}
//         cout<<"answer is"<<ans;
// }



#include<iostream>
#include <math.h>
using namespace std;


int main(){
    int n;

cout<<"Enter the number";
cin>>n;

int ans=0;
int power=0;
while(n<0){
int lastdigit=n%10;
ans=(ans+(lastdigit*power));
power=power*2;
n=n/10;
}
cout<<"Answer--"<<ans;

}
