#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
#define F(a,b,var) for(int var=a;var<b;var++)

/*
Algorithm
1. Scan the infix expression from left to right.
2. If the scanned character is an operand, output it.
3. Else,
…..3.1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack(or the stack is empty), push it.
…..3.2 Else, Pop the operator from the stack until the precedence of the scanned operator is less-equal to the precedence of the operator residing on the top of the stack. Push the scanned operator to the stack.
4. If the scanned character is an ‘(‘, push it to the stack.
5. If the scanned character is an ‘)’, pop and output from the stack until an ‘(‘ is encountered.
6. Repeat steps 2-6 until infix expression is scanned.
7. Pop and output from the stack until it is not empty.

*/

int prec(char c){
    
    if(c=='^')return 3;
    if(c=='*' || c=='/')return 2;
    if(c=='+' || c=='-')return 1;
    else return -1;
    
}



void infixToPostfix(string s){
    
    stack<char> st;
    string res="";
    st.push('Q');
    F(0,s.length(),i){
        
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')res+=s[i];
        
        else if(s[i]=='(')st.push('(');
        
        else if(s[i]==')'){
            while(st.top()!='Q' && st.top()!='('){
                char c=st.top();
                st.pop();
                res+=c;
            }
            if(st.top()=='('){
                char c=st.top();
                st.pop();
            }
            
        }
        else{
            while(st.top()!='Q' && prec(s[i])<=prec(st.top())){
                char c=st.top();
                st.pop();
                res+=c;
            }
            st.push(s[i]);
        }
    }
    
     while(st.top()!='Q'){
            char c = st.top();
            st.pop();
            res += c;
        }
    cout<<res<<endl;
}



int main()
 {
	//code
        int T;
        cin>>T;
        while(T--)
        {   
            string s;
            cin>>s;
            infixToPostfix(s);
 
        }
	return 0;
}
