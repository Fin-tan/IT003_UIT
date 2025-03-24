/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include<string>
#include<cstring>
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; 
};


bool isEmpty(Stack s)
{
    return s.n == 0;
}
void printStack(Stack s)
{

    if (!isEmpty(s))
    {
        for (int i = 0; i < s.n; i++)
        {
            cout << s.arr[i] << " ";
        }
    }
    else
        cout << "Stack is empty";
}
void Init(Stack& s)
{
    s.n = 0;
    for (int i = 0; i < s.n; i++)
        s.arr[i] = NULLDATA;
}
void Push(Stack& s, int x)
{
    if (s.n < MAX)
    {
        s.arr[s.n] = x;
        s.n++;
    }
    else
    {
        cout << " Stack is empty ";
    }
}
int Top(Stack s)
{
    if (!isEmpty(s))
    {
        return s.arr[s.n - 1];
    }
    return NULLDATA;
}
void Pop(Stack& s)
{
    if (!isEmpty(s))
    {
        s.n--;
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

bool isValid(string& expr)
{
    Stack s;
    Init(s);
    for (char ch : expr)
    {
        if (ch == '(' || ch == '[' || ch == '{') Push(s, ch);
        else if (ch == ')' || ch == '}' || ch==']')
        {
            if (isEmpty(s)) return false;
            int topChar = Top(s);
            Pop(s);
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) return false;
        }
    }
    return isEmpty(s);
}
int main()
{
	string expr; cin >> expr;
	cout << isValid(expr);

	return 0;
}



