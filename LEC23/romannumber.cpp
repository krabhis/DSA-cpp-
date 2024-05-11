#include<iostream>
#include<unordered_map>

using namespace std ;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mapi;
        mapi['I']=1;
        mapi['V']=5;
        mapi['X']=10;
        mapi['L']=50;
        mapi['C']=100;
        mapi['D']=500;
        mapi['M']=1000;



        int ans=0;
        for(int i=0;i<s.size();i++){
            if(mapi[s[i]]<mapi[s[i+1]]){
                ans=ans-mapi[s[i]];
            }
                  else{
                ans += mapi[s[i]];
            }
        }
        return ans;
    }
      


};