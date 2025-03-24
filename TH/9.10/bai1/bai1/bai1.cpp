
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int n; // so luong phan tu cua stack
};
bool isEmpty(Stack s)
{
        return s.n == 0;
}
void printStack(Stack s)
{

    if(!isEmpty(s))
    {
        for (int i = 0; i < s.n; i++)
        {
            cout << s.arr[i] << " ";
        }
    }
    else
        cout << "Stack is empty";
}
void Init(Stack &s)
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
int main()
{
    Stack S; Init(S);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Push(S, x);

    }
    cout << "Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    Pop(S);
    cout << "\nUpdated Stack:";
    printStack(S);
    cout << "\nTop:" << Top(S);
    return 0;
}




