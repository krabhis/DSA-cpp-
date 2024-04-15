// #include<iostream>
// using namespace std;

// void explainPairs(){
//     pair<int,int>p={1,3};
//     cout<<p.first<<"" <<p.second;
//     pair<int, pair<int, int>> p={1,{3,4}};
//     cout << p.first <<" "<< p.second.second<<" "<<p.second.first;
//     pair<int,int>arr[]={{1,2},{2,5},{5,1}};

//     cout<< arr[1].second;


// } 
//  int main(){


//  }


#include <iostream>
using namespace std;

void explainPairs() {
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl; // Add newline for better output

    pair<int, pair<int, int>> nested_pair = {1, {3, 4}};
    cout << nested_pair.first << " " << nested_pair.second.second << " " << nested_pair.second.first << endl;

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].second << endl;
}

int main() {
    explainPairs();
    return 0;
}
