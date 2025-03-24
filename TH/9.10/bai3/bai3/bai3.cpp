
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
void DecimaltoBinary2(int n, Stack &s)
{
    Init(s);
    if (n == 0)
    {
        cout << 0;
        return;
    }
    while (n > 0)
    {
        Push(s, n % 2);
        n /= 2;
    }
}
void printStack(Stack s)
{

    while (!isEmpty(s))
    {
        cout << Top(s);
        Pop(s);
    }
}
int main()
{
    Stack S; Init(S);
    int n, x;
    cin >> n;
    DecimaltoBinary2(n, S);
    printStack(S);
    return 0;
}




