class Solution {
public:
    bool validCharacter(char ch){
        if((ch>='a'&& ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0'&&ch<='9')){
            return 1;
        }
            return 0;
               
         }
    

char toLowecase(char ch){
    if((ch>='a'&& ch<='z')||(ch>='0'&&ch<='9')){
            return ch;
}
   else{
    char temp=ch-'A'+'a';
      return temp;
       
   }
}

     
    bool intcheckPallidrome(string arr){
    int s=0;
    int e=arr.length()-1;
    while (s<e)
    {
    if((arr[s])!=(arr[e]))
    {
    return 0;
    }
    else
    {
    s++;
    e--;
    }
    }
    return 1;


    } 
    bool isPalindrome(string s) {
   string temp;
    for(int j=0;j<s.size();j++){
      if(validCharacter(s[j])){
        temp.push_back(s[j]);
}
}
for(int j=0;j<temp.size();j++){
    temp[j]=toLowecase(temp[j]);
}
   return intcheckPallidrome(temp);
    

    
}
};

/////////////////////////////////Appproach 2///////////////////////////




// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.length() - 1;

//         while (left < right) {
//             if (!isalnum(s[left])) {
//                 left++;
//             } else if (!isalnum(s[right])) {
//                 right--;
//             } else if (tolower(s[left]) != tolower(s[right])) {
//                 return false;
//             } else {
//                 left++;
//                 right--;
//             }
//         }

//         return true;
//     }
// };