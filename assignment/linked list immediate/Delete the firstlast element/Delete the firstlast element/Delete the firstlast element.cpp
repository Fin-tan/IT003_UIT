
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
    L.pHead = L.pTail = NULL;
}

DNode* getNode(DList& L, int x) {
    DNode* p = new DNode;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
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
void addTail(DList& L, int x)
{
    DNode* p = getNode(L, x);
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    }
    else
    {
        p->pNext = NULL;
        p->pPrev = L.pTail;
        L.pTail->pNext = p;
        L.pTail = p;
    }
}
void addHead(DList& L, int x)
{
    DNode* p = getNode(L, x);
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
        p->pNext = q;
        k->pNext = p;
        p->pPrev = k;
        if (q != NULL)
            q->pPrev = p;
    }
    else cout << "\nCan't find the value " << x;
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
    else cout << "\nCan't find the value " << x;
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
void addAfterMulti(DList& L, int x, int y)
{

    DNode* k = searchE(L, x);
    DNode* q = L.pHead;
    if (k == NULL)
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    while (q != NULL)
    {
        DNode* p = getNode(L, y);
        if (q->info == x)
        {
            if (q->pNext == NULL)
            {
                q->pNext = p;
                p->pPrev = q;
                L.pTail = p;
            }
            else
            {
                p->pNext = q->pNext;
                p->pPrev = q;
                q->pNext->pPrev = p;
                q->pNext = p;
            }
            q = p;
        }
        q = q->pNext;
    }
}
void addBeforeMulti(DList& L, int x, int y)
{

    DNode* k = searchE(L, x);
    DNode* q = L.pHead;
    if (k == NULL)
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    while (q != NULL)
    {
        DNode* p = getNode(L, y);
        if (q->info == x)
        {
            if (q->pPrev == NULL)
            {
                p->pNext = q;
                q->pPrev = p;
                L.pHead = p;
            }
            else
            {
                p->pPrev = q->pPrev;
                p->pNext = q;
                q->pPrev->pNext = p;
                q->pPrev = p;
            }
        }
        q = q->pNext;
    }
}
void removeHead(DList& L)
{
    if (L.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }
    cout << "\nDo you want to delete the first element?(y/n):";
    char x;
    cin >> x;
    if (x == 'Y' || x == 'y')
    {
        DNode* temp = L.pHead;
        L.pHead = L.pHead->pNext;

        if (L.pHead != NULL) {
            L.pHead->pPrev = NULL;
        }
        else {
            L.pHead = NULL; 
            cout << "\nThe list becomes empty";
        }

        delete temp;
    }
    else return;
}
void removeTail(DList& L)
{
    if (L.pTail == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }
    cout << "\nDo you want to delete the last element?(y/n):";
    char x;
    cin >> x;
    if (x == 'Y' || x == 'y') {
        DNode* temp = L.pTail;
        L.pTail = L.pTail->pPrev;

        if (L.pTail != NULL) {
            L.pTail->pNext = NULL;
        }
        else {
            L.pHead = NULL;
            cout << "\nThe list becomes empty";
        }

        delete temp;
    }
    else return;
}
void removeNode(DList& L, int x) {
    if (L.pHead == NULL) {
        cout << "\nList is empty. Can't delete";
        return;
    }

    DNode* k = searchE(L, x);
    DNode* p = L.pHead;
    if (k == NULL)
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    cout << "\nDo you want to delete " << x << " ?(y/n): ";
    char y;
    cin >> y;
    if (y != 'Y' && y != 'y') {
        return;
    }
    while (p != NULL)
    {
        if (p->info == x) {
            if (p == L.pHead) {
                DNode* temp = L.pHead;
                L.pHead = L.pHead->pNext;
                if (L.pHead != NULL) {
                    L.pHead->pPrev = NULL;
                }
                else {
                    L.pTail = NULL;
                    cout << "\nThe list becomes empty";
                }
                delete temp;
                return;
            }
            else if (p == L.pTail) {
                DNode* temp = L.pTail;
                L.pTail = L.pTail->pPrev;
                L.pTail->pNext = NULL;
                delete temp;
                return;
            }
            else {
                DNode* q = p;
                p->pPrev->pNext = p->pNext;
                p->pNext->pPrev = p->pPrev;
                p = p->pNext;
                delete q;
                return;
            }
        }
        else {
            p = p->pNext;
        }
    }


}

void  removeMultiNodeS(DList& L, int x)
{
    DNode* k = searchE(L, x);
    DNode* p = L.pHead;
    if (k == NULL)
    {
        cout << "\nCan't find the value " << x;
        return;
    }
    cout << "\nDo you want to delete " << x << "s ?(y/n): ";
    char y;
    cin >> y;
    if (y == 'Y' || y == 'y') {
        while (p != NULL)
        {
            if (p->info == x) {
                if (p == L.pHead) {
                    DNode* temp = L.pHead;
                    L.pHead = L.pHead->pNext;
                    if (L.pHead != NULL) {
                        L.pHead->pPrev = NULL;
                    }
                    else {
                        L.pTail = NULL;
                        cout << "\nThe list becomes empty";
                    }
                    delete temp;
                    p = L.pHead;
                }
                else if (p == L.pTail) {
                    DNode* temp = L.pTail;
                    L.pTail = L.pTail->pPrev;
                    if (L.pTail != NULL) {
                        L.pTail->pNext = NULL;
                    }
                    else {
                        L.pHead = NULL;
                        cout << "\nThe list becomes empty";
                    }
                    delete temp;
                    break;
                }
                else {
                    DNode* q = p;
                    p->pPrev->pNext = p->pNext;
                    p->pNext->pPrev = p->pPrev;
                    p = p->pNext;
                    delete q;

                }
            }
            else {
                p = p->pNext;
            }

        }
    }
}
void removeAfter(DList& L, int x)
{
    DNode* k = searchE(L, x);

    if (k == NULL) {
        cout << "\nCan't find the value " << x;
        return;
    }

    if (k->pNext == NULL) {
        cout << endl << x << " is the last element. Can't delete the element after it";
        return;
    }

    cout << "\nDo you want to delete the element after " << x << " ?(y/n): ";
    char y;
    cin >> y;
    if (y != 'Y' && y != 'y') {
        return;
    }

    DNode* q = k->pNext;
    if (q->pNext != NULL) {
        k->pNext = q->pNext;
        q->pNext->pPrev = k;
    }
    else {
        k->pNext = NULL;
        L.pTail = k; 
    }

    delete q;
    if (L.pHead == NULL && L.pTail == NULL) {
        cout << "\nThe list becomes empty";
    }
}
void removeBefore(DList& L, int x)
{
    DNode* k = searchE(L, x);

    if (k == NULL) {
        cout << "\nCan't find the value " << x;
        return;
    }

    if (k->pPrev == NULL) {
        cout << endl << x << " is the first element. Can't delete the element before it";
        return;
    }

    cout << "\nDo you want to delete the element before " << x << " ?(y/n): ";
    char y;
    cin >> y;
    if (y != 'Y' && y != 'y') {
        return;
    }

    DNode* q = k->pPrev;
    if (q->pPrev != NULL) {
        q->pPrev->pNext = k;
        k->pPrev = q->pPrev;
    }
    else {
        k->pPrev = NULL;
        L.pHead = k;
    }

    delete q;
    if (L.pHead == NULL && L.pTail == NULL) {
        cout << "\nThe list becomes empty";
    }
}
void  removeMultiAfters(DList& L, int x)
{
    DNode* k = searchE(L, x);
    DNode* p = L.pHead;
    if (k == NULL) {
        cout << "\nCan't find the value " << x;
        return;
    }

    if (k->pNext == NULL) {
        cout << "\nList has only one " << x << " and " << x << " is the last element. Can't delete the element after it";
        return;
    }

    cout << "\nDo you want to delete all elements after " << x << " ?(y/n): ";
    char y;
    cin >> y;
    if (y != 'Y' && y != 'y') {
        return;
    }
    while (k!=NULL && k->pNext!= NULL)
    {
        DNode* q = k->pNext;
        
            if (q->pNext != NULL) {
                k->pNext = q->pNext;
                q->pNext->pPrev = k;
            }
            else {
                k->pNext = NULL;
                L.pTail = k;
            }

            delete q;
            k = k->pNext; 

            while (k != NULL && k->info != x) { 
                k = k->pNext;
            }
        
    }
    if (L.pHead == NULL && L.pTail == NULL) {
        cout << "\nThe list becomes empty";
    }
}
void removeMultiBefores(DList& L, int x)
{
    int dem = 0;
    DNode* k = searchE(L, x);
    DNode* p = L.pHead;
    if (k == NULL) {
        cout << "\nCan't find the value " << x;
        return;
    }
    while (p != NULL)
    {
        if (p->info == k->info)
            dem++;
        p = p->pNext;
    }
   

    if (L.pHead==k && k->pNext==NULL ) {
        cout << "\nList has only one " << x << " and " << x << " is the first element. Can't delete the element before it"; 
        return;
    }
    if (dem==1 && k==L.pHead)  cout << endl << x << " is the first element. Can't delete the element before it";
    if (dem >= 2) {
        cout << "\nDo you want to delete all elements before " << x << " ?(y/n): ";
        char y;
        cin >> y;
        if (y != 'Y' && y != 'y') {
            return;
        }
        while (k != NULL)
        {

            DNode* q = k->pPrev;
            if (q != NULL)
            {
                if (q->pPrev != NULL) {
                    q->pPrev->pNext = k;
                    k->pPrev = q->pPrev;
                }
                else {
                    k->pPrev = NULL;
                    L.pHead = k;
                }
                delete q;
            }
            k = k->pNext;
            while (k != NULL && k->info != x) {
                k = k->pNext;
            }
        }
    }
    if (L.pHead == NULL && L.pTail == NULL) {
        cout << "\nThe list becomes empty";
    }
}
void  removeAll(DList& L)
{
    cout << "\nDo you want to delete all elements?(y/n): ";
    char y;
    cin >> y;
    if (y != 'Y' && y != 'y') {
        return;
    }
    else
    {
        cout << "\nThe list becomes empty";
        L.pHead = L.pTail = NULL;
        return;
    }
   
}
int main()
{
    DList L;
    init(L);
    int x, y, choice; char c;

    cout << "MENU:";
    cout << "\n1. Create a DList";
    cout << "\n2. Print the DList";
    cout << "\n3. Insert a value at the front";
    cout << "\n4. Insert a value at the end";
    cout << "\n5. Insert a value after a given value (only for the first value found)";
    cout << "\n6. Insert a value before a given value (only for the first value found)";
    cout << "\n7. Insert a value after a given value (for all the same values)";
    cout << "\n8. Insert a value before a given value (for all the same values)";
    cout << "\n9. Delete the first element";
    cout << "\n10. Delete the last element";
    cout << "\n11. Delete the first element containing a specific value";
    cout << "\n12. Delete all elements storing a particular value";
    cout << "\n13. Delete the element after a specific value (only for the first one found)";
    cout << "\n14. Delete the element before a specific value (only for the first one found)";
    cout << "\n15. Delete all elements after a specific value";
    cout << "\n16. Delete all elements before a specific value";
    cout << "\n17. Delete all elements";
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
        case 7:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addAfterMulti(L, x, y);
            break;
        case 8:
            cout << "\nEnter two numbers: ";
            cin >> x >> y;
            addBeforeMulti(L, x, y);
            break;
        case 9:
            removeHead(L);
            break;
        case 10:
            removeTail(L);
            break;
        case 11:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeNode(L, x);
            break;
        case 12:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiNodeS(L, x);
            break;
        case 13:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeAfter(L, x);
            break;
        case 14:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeBefore(L, x);
            break;
        case 15:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiAfters(L, x);
            break;
        case 16:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            cout << "\nEnter a number: ";
            cin >> x;
            removeMultiBefores(L, x);
            break;
        case 17:
            if (L.pHead == NULL) { cout << "\nList is empty. Can't delete"; break; }
            removeAll(L);
            break;
        case 20:
            cout << "\nGOOD BYE";
            return 0;

        }
    }

    return 0;
}
