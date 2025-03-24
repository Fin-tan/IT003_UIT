#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

// H�m ?? x�c ??nh ?? ?u ti�n c?a c�c to�n t?
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// H�m chuy?n ??i bi?u th?c trung t? sang h?u t?
string infixToPostfix(const string& infix) {
    stack<char> st;
    string postfix;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;  // Th�m s? v�o h?u t?
        }
        else if (ch == '(') {
            st.push(ch);  // ??a '(' v�o ng?n x?p
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += ' ' + string(1, st.top());
                st.pop();
            }
            st.pop();  // Lo?i b? '('
        }
        else {  // To�n t?
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += ' ' + string(1, st.top());
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += ' ' + string(1, st.top());
        st.pop();
    }

    return postfix;
}

// H�m t�nh gi� tr? c?a bi?u th?c h?u t?
int evaluatePostfix(const string& postfix) {
    stack<int> st;
    istringstream iss(postfix);
    string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            st.push(stoi(token));
        }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (token[0]) {
            case '+': st.push(a + b); break;
            case '-': st.push(a - b); break;
            case '*': st.push(a * b); break;
            case '/': st.push(a / b); break;
            }
        }
    }

    return st.top();
}

int main() {
    string infix;
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    int result = evaluatePostfix(postfix);
    cout << result << endl; // Ch? in ra gi� tr?

    return 0;
}
