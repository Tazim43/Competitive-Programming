//      Prefix Evaluation

#include<bits/stdc++.h>
using namespace std;
bool isOperator(char a){
    if(a == '+'|| a == '-'|| a == '*'|| a == '/' || a == '^')return 1;
    return 0;
}
bool isOperand(char a){
    if(a>='0' && a<='9')return 1;
    return 0;
}
void evaluatePrefix(string s){
    stack<int> st;
    for(int i=s.length()-1; i>=0; i--){
        if(isOperand(s[i])){
            st.push(s[i]-'0');
        }
        else if(isOperator(s[i])){
            if(st.size()<2){
                cout<<"Invalid input"<<endl;
                return ;
            }
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (s[i])
            {
                case '^':st.push(pow(a,b)); break;
                case '*':st.push(a*b); break;
                case '/':st.push(a/b); break;
                case '+':st.push(a+b); break;
                case '-':st.push(a-b); break;
                default: break;
            }
        }
    }
    cout<<st.top()<<endl;
}
int main(){
    string res;
    cin>>res;
    evaluatePrefix(res);
    return 0;
}

