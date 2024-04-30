    #include<iostream>
    using namespace std;


    char toLowerCase(char ch){
    if(ch>='a'&& ch<='z')
    return ch;
    else{
            char temp=ch-'A'+'a';
            return temp;

        }

    }

    bool intcheckPallidrome(char arr[],int n){
    int s=0;
    int e=n-1;
    while (s<e)
    {
    if(toLowerCase(arr[s])!=toLowerCase(arr[e]))
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

    // Handelling the case when uppper case is given in  the input so uppercase would not provbide error thats why we create function to convrt uppercase to lpower case



    int length(char arr[]){
    int count=0;
    for(int i=0; arr[i]!='\0';i++){
    count++;
    }
    return count;

    }




    int main(){
    char  stri[50];
    cout<<"Enter the string to  check=>";
    cin>>stri;
    int strlength=length(stri);
    cout<<intcheckPallidrome(stri, strlength);

    }


