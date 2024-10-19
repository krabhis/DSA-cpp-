#include <bits/stdc++.h>

using namespace std;


// nested pair
bool compare(pair<int , pair<int,int>>p , pair<int,pair<int,int>>p1 ){
    if(p.second.second!=p1.second.second)
    return (p.scond.second>p1.second.second);
    else{
        return (p.second.first<p1.second.firt);
    }
}

int main() {
    
    return 0;
}