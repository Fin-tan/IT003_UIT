

#include  <iostream>
using namespace std;

struct DNode
{
    int info;
    DNode* pNext, * pPrev;
};

struct DList
{
    DNode* pHead, * pTail;
};

void init(DList& L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
DNode* getNode(DList& L, int x) {
    DNode* p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = L.pTail;
    return p;
}
DNode* searchE(DList& L, int x)
{
    DNode* p = L.pHead;
    while (p != NULL)
    {
        if (p->info == x)
            return p;
        p = p->pNext;
    }
    return NULL;
}
void addTail(DList& L ,int x)
{
    DNode* p = getNode(L,x);
    if (L.pHead == NULL) { 
        L.pHead = L.pTail = p;
    }else
    {
        p->pNext = NULL;
        p->pPrev = L.pTail;
        L.pTail->pNext = p;
        L.pTail = p;    
    }
}
void addHead(DList& L, int x)
{
    DNode* p = getNode(L,x);
    if (L.pHead == NULL) { 
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead->pPrev = p;
        L.pHead = p;
    }
}
void addAfter(DList& L, int x, int y)
{
    DNode* k = searchE(L, x);
    DNode* p = getNode(L, y);
    if (k != NULL)
    {
        DNode* q = k->pNext;
        p->pNext =q;
        k->pNext = p;
        p->pPrev = k;
        if (q!=NULL)
        q->pPrev = p;
    }else cout << "\nCan't find the value "<<x;
}
void addBefore(DList& L, int x, int y)
{
    DNode* k = searchE(L, x);
    DNode* p = getNode(L, y);
    if (k != NULL)
    {
        if (k == L.pHead) addHead(L, y);
        else
        {
            DNode* dau = k->pPrev;
            dau->pNext = p;
            p->pPrev = dau;
            p->pNext = k;
            k->pPrev = p;
        }
    }
    else cout << "\nCan't find the value " << x<<endl;
}
void createList(DList& L)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1) break;
        addTail(L, x);
    }
}
void printList(DList L)
{
    DNode* p = L.pHead;
    if (p == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
    cout << endl;
}



int main()
{
    DList L;
    init(L);
    int x, y, choice;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n20. Exit" << endl;

    while (true)
    {
        cout << "\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout << "\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout << "\nEnter a number: ";
            cin >> x;
            addHead(L, x);
            break;
        case 4:
            cout << "\nEnter a number: ";
            cin >> x;
            addTail(L, x);
            break;
        case 5:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfter(L, x, y);
            break;
        case 6:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBefore(L, x, y);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;

        }
    }

    return 0;
}
