#include<stdio.h>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

// int capacity = 5;
// char stack[5];
// int size=-1;

string infixToPostFix(string);

// int isEmpty(){
// 	if(size <0){
// 		return 1;
// 	}
// 	return 0;
// }

// int isFull(){
// 	if(size == capacity-1){
// 		return 1;
// 	}
// 	return 0;
// }

// void push(int val){
// 	if(isFull()){
// 		printf("--OVERFLOW--");
// 		return;
// 	}

// 	size++;
// 	stack[size] = val;
// }

// void pop(){
// 	if(isEmpty()){
// 		printf("--UNDERFLOW--\n");
// 		return;
// 	}
// 	printf("%d ", stack[size]);
// 	size--;
// }

// int top(){
// 	return stack[size];
// }


int precedence(char c){
	if(c=='^'){
		return 3;
	}
	else
		if(c=='*'||c=='/')
			return 2;
		else
			if(c=='+'||c=='-')
				return 1;
			else
				return -1;
}

string infixToPostFix(string s){
	string res = "";
	stack<char> st;
	for(int i=0; i<s.length(); i++){
		if(s[i] >='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' ){
			res+=s[i];
		}
		else if(s[i] =='(')
			st.push(s[i]);
		else if(s[i] == ')'){
				while(!st.empty() && st.top()!='('){
					res+=st.top();
					st.pop();
				}
			}
			if(!st.empty()){ //this if for removing that '(' bracket
				st.pop();
			}
		else {
			while(!st.empty() && precedence(st.top())>precedence(s[i])){
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	return res;
}
int main(){
	// INFIX -> POSTFIX
	// (a+b/c) or (a+(b/c)) -> bca/+

	// OPERATOR PRECEDENCE
	// PEMDAS 

	// ALGORITHM
	/*
	if ( push onto stack
	pop till ) or any operator have higher priority
	*/

	cout<<infixToPostFix("(a-b/c)*(a/k-l)")<<endl;
}