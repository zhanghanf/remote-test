#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> intStack;
    for (string& str : tokens) {
        if (str == "+" || str == "-" || str == "*" || str == "/") {
            int num1 = intStack.top();
            intStack.pop();
            int num2 = intStack.top();
            intStack.pop();
            switch (str[0]) {
            case '+':
                intStack.push(num1 + num2);
                break;
            case '-':
                intStack.push(num2 - num1);
                break;
            case '*':
                intStack.push(num1 * num2);
                break;
            case '/':
                intStack.push(num2/ num1);
                break;
            }
        }
        else {
            intStack.push(stoi(str));
        }
    }
    return intStack.top();
}
bool  Priority(char ch, char topch) {
    if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))return true;
    else if (topch == '(')return true;//Õ¸º«∆•≈‰¡À
    else return false;
}//
string MiddleToEndExpr(string& sxpr){
    string ret;
    stack<char> s;
    for (auto ch : sxpr) {
        if (ch >= '0' && ch <= '9')ret.push_back(ch);
        else if (s.empty() || ch == '(')s.push(ch);
        else if (ch == ')') {
            while (s.top() != '(') {
                ret.push_back(s.top());
                s.pop();
            }
            s.pop(); // µØ≥ˆ '('
            
        }
        else {
            char topch = s.top();
            //true ch>topch false <=
            if (Priority(ch, topch)) {
                s.push(ch);
            }
            else {
                ret.push_back(s.top());
               
                s.pop();
                s.push(ch);
            }
        }
        if (!s.empty())cout << s.top() << endl;;
    }
            
        
    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }
    return ret;
}
int main() {
    string s = "(1+2*3)/4+(5*6-7)";
    cout << MiddleToEndExpr(s);
  
   
}