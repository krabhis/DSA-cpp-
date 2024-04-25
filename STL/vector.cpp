#include<iostream>
using namespace std;

void explainVector(){

    vector<int>v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int , int>>vec;

    v.push_back{(1,2)};
    v.emplace_back(1,2);

    vector<int> v(5,100);

    vector<int> v(5);

    vector<int>v1(5,20);
    vector<int>v2(v1);

    vector<int>::iterator it =v.begin();

    it++;
    cout<<*(it)<<" ";

    it=it+2;
    cout<<*(it)<<" ";

    vector<int>::iterator it =v.end();
    vector<int>::iterator it =v.rend();
    vector<int>::iterator it =v.rbegin();

    
    cout<<v[0]<<" "<<v.at(0);
    cout<<v.back()<<" ";

    for(vector<int>::iterator it = v.begin; it!=v.end(); it++){
        cout<<*(it)<<" ";
    }

    for(auto it = v.begin(); it!=v.end();it++){
        cout<<*(it)<<" ";

    }

    for (auto it:v){
        cout<<it<<" ";
    }


    v.erase(v.begin()+1);

    v.erase(v.begin()+2,v.begin()+4);


    // insert function

    vector<int>v(2,100);//{100,100}
    v.insert(v.begin(),300);//{300,100,100}
    v.insert(v.begin()+1,2,10);//{300,10,10,100,100}

    vector<int>copy(2,50);//{50,50}
    v.insert(v.begin(),copy.begin(),copy.end());//{50,50,300,10,10,100,100}
//{10,20}
    cout<<v.size();//2
//{10,20}
    v.pop_back();//{10}
//v1-->{10,20}
//v2-->{30,40}

v1.swap(v2); //{30,40},v2-->{10,20}





}




int main() {
    explainVector();
    return 0;
}

//////////////////////////////////////////////////////notesss////////////////////////////////////////////////////////////////////////////////////////

// #include <iostream>
// #include <vector>
// using namespace std;

// void explainVector() {

//     // Creating vectors
//     vector<int> v;                      // Empty vector
//     v.push_back(1);                      // Add 1 to the end
//     v.emplace_back(2);                   // Efficiently add 2 to the end (C++11+)

//     vector<pair<int, int>> vec_pairs;    // Empty vector of pairs
//     vec_pairs.push_back({1, 2});          // Add a pair (1, 2) to the end

//     vector<int> v_filled(5, 100);         // Vector with 5 elements initialized to 100
//     vector<int> v_uninitialized(5);      // Vector with 5 uninitialized elements (default-initialized)

//     // Creating a copy of a vector
//     vector<int> v1(5, 20);
//     vector<int> v2(v1);                  // Copy elements from v1 to v2

//     // Iterators
//     vector<int>::iterator it = v.begin();  // Iterator pointing to the first element
//     cout << *(it++) << " ";              // Print first element, then move to the next
//     cout << *(it) << endl;                // Print element at current position (second)

//     // Reverse iterators (C++11+)
//     // Uncomment these lines if you want to use reverse iterators
//     // vector<int>::reverse_iterator rit = v.rbegin();
//     // cout << *rit << endl; // Print the last element using reverse iterator

//     // Accessing elements
//     cout << v[0] << " " << v.at(0) << endl; // Access elements using index or at()

//     // Printing elements (various loops)
//     for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
//         cout << *(it) << " ";
//     }
//     cout << endl;

//     for (auto it = v.begin(); it != v.end(); ++it) {
//         cout << *it << " ";
//     }
//     cout << endl;

//     for (int element : v) { // Range-based for loop (C++11+)
//         cout << element << " ";
//     }
//     cout << endl;

//     // Erasing elements
//     v.erase(v.begin() + 1);               // Erase the second element (index 1)
//     v.erase(v.begin() + 2, v.begin() + 4); // Erase elements from index 2 (inclusive) to 4 (exclusive)

//     // Inserting elements
//     vector<int> v_insert(2, 100);
//     v_insert.insert(v_insert.begin(), 300);        // Insert 300 at the beginning
//     v_insert.insert(v_insert.begin() + 1, 2, 10);   // Insert two 10s after the first element

//     vector<int> copy = {50, 50};                    // Create a temporary vector
//     v_insert.insert(v_insert.begin(), copy.begin(), copy.end());  // Insert elements from copy at the beginning

//     // Size and pop_back
//     cout << v_insert.size() << endl;              // Print the number of elements
//     v_insert.pop_back();                         // Remove the last element

//     // Swapping vectors
//     vector<int> v3 = {30, 40};  // Create another vector
//     v1.swap(v3);                // Swap elements between v1 and v3

//     // (Optional) Printing swapped vectors (can be commented out if not needed)
//     // for (int element : v1) {
//     //     cout << element << " ";
//     // }
//     // cout << endl;
//     // for (int element : v3) {
//     //     cout << element << " ";
//     // }
//     // cout << endl;
// }

// int main() {
//     explainVector();
//     return 0;
// }



