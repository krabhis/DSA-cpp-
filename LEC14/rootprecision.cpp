// #include<iostream>
// using namespace std;
// int rootInteger(int n){
//     int s=0,e=n;
//     int mid=s+((e-s)/2);
//     int ans=-1;
//     while(s<=e){
//         int square=mid*mid;
//         if (square==n){
//             return mid;
//         }
//         else if(square<n){  
//             ans=mid;
//             s=mid+1;

//         }
//         else{
//             e=mid-1;
//         }
//             mid=s+((e-s)/2);


//     }
//     return ans;
// }
// int main(){

// int a=rootInteger(36);
// cout<<"answer is"<<a;

// return 0;
// }

//++++++++++++++++++++++++++++++++++ABOVE CODE IS FOR FINDING ROOT USING BINARY SORT+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


#include<iostream>
using namespace std;
int rootInteger(int n){
    int s=0,e=n;
    int mid=s+((e-s)/2);
    int ans=-1;
    while(s<=e){
        int square=mid*mid;
        if (square==n){
            return mid;
        }
        else if(square<n){  
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
            mid=s+((e-s)/2);
    }
    return ans;
}

double rootPrecise(int temp,int uptodigit,int findroot){
    double factor=1;
    double ans=temp;
    for(int i=0;i<uptodigit;i++){
        factor=factor/10;
        for(double j=0;j*j<findroot;j=j+factor){
            ans=j;
        }
    }
    return ans;
    

}
int main(){

int temproot=rootInteger(37);
cout<<"Precise root of given number=>"<<rootPrecise(temproot,3,37);


}