
#include <iostream>
using namespace std;
struct Node
{
    int infor;
    Node* next;
};
struct List
{
    Node* pHead, * pTail;
};
Node* getNode(int x)
{
    Node* p = new Node;
    p->infor = x;
    p->next = NULL;
    return p;
}
void addTail(List& L, int x)
{
    Node* p = getNode(x);
    if (L.pHead == NULL && L.pTail == NULL)
    {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->next = NULL;
        L.pTail->next = p;
        L.pTail = p;
    }
}
void init(List& L)
{
    L.pHead = L.pTail = NULL;
}
void inputList(List& L, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        addTail(L, x);
    }
}
void MySort(List& L)
{
    Node* p = L.pHead; //node hien tai
    while (p != NULL)
    {
        Node* minNode = p;
        Node* Nodenext = p->next;
        while (Nodenext != NULL)
        {
            if (Nodenext->infor < minNode->infor)
                minNode = Nodenext;
            Nodenext = Nodenext->next;
        }
        if (minNode != p)
            swap(minNode->infor, p->infor);
        p = p->next;
    }

}
void outputList(List L)
{
    Node* p = L.pHead;
    while (p != NULL)
    {
        cout << p->infor<<" ";
        p = p->next;
    }
}
int MySearch(List& L, int x)
{
    Node* p = L.pHead;
    int index = 0;
    while (p != NULL)
    {
        if (p->infor == x)
            return  index;
        else
        {
            index++;
            p = p->next;
        }
        if (p == NULL) return -1;
    }
}
int main()
{
    int n; cin >> n;
    List L; init(L);
    inputList(L, n);
    MySort(L);
    cout << "Sorted List: ";
    outputList(L);// liet ke cac phan tu cach nhau boi 1 khoang cach

    cout << "\nFind an element: ";
    int x; cin >> x;
    cout << x << endl;
    int result = MySearch(L, x);
    if (result == -1) cout << x << " is not found";
    else cout << x << " is found at the position " << result;

    return 0;
}

 