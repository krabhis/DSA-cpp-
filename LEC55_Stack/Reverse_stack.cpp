 void solve_insert(stack<int>&stc, int x){
     if(stc.empty()){
         stc.push(x);
         return;
     }
     int num=stc.top();
     stc.pop();
     solve_insert(stc, x);
     stc.push(num);
 }

 void reverseStack(stack<int> &stack ){

     if(stack.empty()){
         return;
         

     }
     int num=stack.top();
     stack.pop();
     reverseStack(stack);
     solve_insert(stack ,num);

 }
 
 