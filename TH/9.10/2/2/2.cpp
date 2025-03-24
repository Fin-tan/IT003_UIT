
#include <iostream>

#define MAX 2000
#define NULLDATA -1

using namespace std;

struct Stack
{
    int arr[MAX];
    int t; // t là ch? s? c?a ph?n t? cu?i m?ng, t?c là ??nh stack
};
void Init(Stack& S)
{
    S.t = -1; //Khi stack ch?a có ph?n t? nào thì top ???c kh?i t?o là -1,
    // n?u kh?i t?o t = 0 là SAI vì khi ?ó s? hi?u top t?i a[0]
}
    bool isEmpty(Stack s)
    {
        return s.t == -1;
    }
     void printStack(Stack s)
    {

        if (!isEmpty(s))
        {
            for (int i = 0; i <= s.t; i++)
                cout << s.arr[i] << " ";
        }
        else
            cout << "Stack is empty";
    }
    void Push(Stack& s, int x)
    {
        if (s.t < MAX)
        {
            s.arr[++s.t] = x;
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
            return s.arr[s.t];
        }
        return NULLDATA;
    }
    void Pop(Stack& s)
    {
        if (!isEmpty(s))
        {
            s.t--;
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




