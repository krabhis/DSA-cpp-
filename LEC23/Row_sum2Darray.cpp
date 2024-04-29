#include<iostream>
using namespace std;

int rowSum(int a[][3],int i,int j){
    cout<<"Printing sum "<<endl;
    for(int i=0;i<4;i++){
        int sum=0;
        for(int j=0; j<3;j++){
            sum+=a[i][j];
        }
        cout<<sum<<"";

    }
    cout<<endl;

        

}


int main(){
    int arr[4][3];
    cout<<"Enter the elements"<<endl;
      for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
      }
    //   lllllllll
    cout<<"Your 2D array is--->"<<endl;
       for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
      }

      rowSum(arr,4,3);

}