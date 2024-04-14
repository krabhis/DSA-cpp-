//  microsoft question
// reverse a signed or unsigned integer and print the reverse integer and if the given number ka reverse kuch aisa aata hai jiska reverse int ke range se bahar ho to print 0


#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number"<<endl;
    cin>>n;
    int ans=0;
    while(n!=0)
    {
        int digit=n%10;
        if((ans>INT16_MAX/10)||(ans<INT16_MIN/10)){
            cout<<0;

        }
        ans=ans*10+digit;
        n/=10;

    }
    cout<<"reverse is:"<<ans;

}