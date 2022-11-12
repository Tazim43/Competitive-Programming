#include<bits/stdc++.h>
using namespace std;

int c_rank(char a){
    if(a=='^')return 3;
    else if(a=='*' || a=='/')return 2;
    else if(a=='+' || a=='-')return 1;
    else return -1;
}
string InfixToPostfix(string s){
    stack<char> st;
    string p="";
    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9')) p+=s[i];
        else if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while (st.top()!='('){
                p+=st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && c_rank(st.top())>=c_rank(s[i])){
                p+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        p+=st.top();
        st.pop();
    }
    return p; 
}
int main(){
    string s;
    cin>>s;
    string res = InfixToPostfix(s);
    cout<<res<<endl;
    return 0;
}
