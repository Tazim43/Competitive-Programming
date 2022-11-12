#include<bits/stdc++.h>
using namespace std;
int c_rank(char a){
    if(a=='^')return 3;
    else if(a=='*' || a=='/')return 2;
    else if(a=='+' || a=='-')return 1;
    else return -1;
}
bool isOperator(char a){
    if(a == '+'|| a == '-'|| a == '*'|| a == '/' || a == '^')return 1;
    return 0;
}
bool isOperand(char a){
    if(a>='0' && a<='9')return 1;
    return 0;
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
void evaluatePostfix(string s){
    stack<int> st;
    for(int i=0; i<s.length(); i++){
        if(isOperand(s[i])){
            st.push(s[i]-'0');
        }
        else if(isOperator(s[i])){
            if(st.size()<2){
                cout<<"Invalid input"<<endl;
                return ;
            }
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (s[i])
            {
                case '^':
                    st.push(pow(a,b));
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a-b);
                    break;
                default:
                    break;
            }
        }
    }
    cout<<st.top()<<endl;
}
int main(){
    string s;
    cin>>s;
    string res = InfixToPostfix(s);
    cout<<res<<endl;
    evaluatePostfix(res);
    return 0;
}
