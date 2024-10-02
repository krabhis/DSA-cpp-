#include <bits/stdc++.h>

using namespace std;
 
 bool valid(string str , int size){
    stack<char>stc;
    for(char c:str){
        if(c=='('|| c=='{'|| c=='['){
           stc.push(c);
        }
        else{
            if(stc.empty()) return false;
            char top=stc.top();
            if(c==')'&& top!='('||
                c=='}'&& top!='{'||
                c==']' && top!='['){
                    return false;
                }
                stc.pop();
        }
        
    }
    if(stc.empty()){
        return true;
    }


 }


int main() {
    string str="[()]{}{[()()](())}" ;
    int size =19;
     bool a=valid(str,size);
     cout << a << endl;

    cout << "Love you Zindagi" << endl;
    return 0;
}
