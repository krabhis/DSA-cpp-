#include<iostream>
using namespace std;

// int rowSum(int arr[][3], int row, int col){
//     for(int i=0;i<col;i++){
//     int sum=0;
        
//         for(int j=0;j<row;j++){
//             sum=sum+arr[i][j];
//         }
//     cout<<sum<<" ";

//     }
//      cout<<endl;

// }


int largestRowSum(int arr[][3], int row, int col){
    int maxi=-1;
   int rowindex=-1;
     for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0; j<3;j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            rowindex=i;
        }

    }
cout<<"The maximum sum is"<<maxi<<endl;

return rowindex;


}

int main(){
 int arr[3][3];
    cout<<"Enter the elements";
      for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
      }
    //   lllllllll
    cout<<"Your 2D array is--->"<<endl;
       for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
      }
    //   rowSum(arr,3,3);
   int ansIndex= largestRowSum(arr,3,3);
   cout<<"Max row is at index"<<ansIndex<<endl;
   

}