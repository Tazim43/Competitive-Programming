//            Infix to Prefix

#include<bits/stdc++.h>
using namespace std;

int c_rank(char a){
    if(a=='^')return 3;
    else if(a=='*' || a=='/')return 2;
    else if(a=='+' || a=='-')return 1;
    else return -1;
}

string InfixToPrefix(string s){
    stack<char> st;
    string p = "";
    for(int i=s.length()-1; i>=0; i--){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')|| (s[i] >= '0' && s[i] <= '9')) p+=s[i];
        else if(s[i]==')')st.push(s[i]);
        else if(s[i]=='('){
            while (st.top()!=')'){
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
    string res = "";
    for(int i=p.length()-1; i>=0; i--)res.push_back(p[i]);
    return res;
}

int main(){
    string s;
    cin>>s;
    string res = InfixToPrefix(s);
    cout<<res<<endl;
    return 0;
}
