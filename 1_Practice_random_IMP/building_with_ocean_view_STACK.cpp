#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int>arr={4,3,2,1};
    vector<int>result;
    for(int i=0;i<arr.size();i++){
        int maxi=*max_element(arr.begin()+i,arr.end());
        if(maxi<=arr[i]){
            result.push_back(i);
        }

    }
     for(int i=0;i<result.size();i++){
    cout<<result[i];
 }
    return 0;
}



