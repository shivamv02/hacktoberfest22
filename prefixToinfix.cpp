#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x){
    switch(x){
        case '+' :
        case '-' :
        case '/' :
        case '*' :
          return true;
    }
    return false;
}
string prefixToInfix(string s){
    stack<string>st;
    int n=s.size();
    for(int i=n-1;i>=0;i--){
        if(isOperator(s[i])){
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            string temp="(" + op1 + s[i] + op2 + ")";
            st.push(temp);
        }
        else
           st.push(string(1,s[i]));
    }
    return st.top();
}
int main(){
    string s="*-a/bc-/akl";
    cout<<prefixToInfix(s);
    return 0;
}