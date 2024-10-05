#include <bits/stdc++.h> 


void  insertSorted(stack<int>&stack, int num){
  if (stack.empty() || stack.top() <= num) {
    stack.push(num);
    return;
  }
        int top = stack.top();
		stack.pop();
		insertSorted(stack, num);

	     stack.push(top);
 
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insertSorted(stack, num);

	
}
