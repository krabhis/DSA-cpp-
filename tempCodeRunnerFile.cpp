#include <iostream>
    using namespace std;
    int main(){
        int i,n,j,space,k,sum;
        cout<<"enter the name"<<endl;
        cin>>n;
            i=1;
        while (i<n){
            j=1;
            sum=1;
            while(j<=n-i){
                cout<<sum;
                sum=sum+1;
                j=j+1;


            }
            k=i-1;
            while(k){
                cout<<"*";
                k=k-1;
            }
            int h=i-1;
            while(h){
                cout<<"*";
                h=h-1;

            }
            int g=1;
            int kem=n-i;
            while(g<n-i+1){
                cout<<kem;
                kem=kem-1;
                g=g+1;
            }
            
            cout<<endl;
            i=i+1;


        }
    }