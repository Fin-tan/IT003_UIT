
#include <iostream>
#include <string>
using namespace std;
typedef struct Product
{
    int id;
    string name;
    string type;
    int year;
    int warranty;
}PRO;
struct node
{
    PRO data;
    node* left, * right;
};
typedef node* Tree;
node* getnode(int id,string name,string type,int year ,int warranty)
{
    node* p = new node();
    p->data.id = id;
    p->data.name = name;
    p->data.type = type;
    p->data.year = year;
    p->data.warranty = warranty;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void insertTree(Tree& T, int id, string name,string type,int year,int warranty)
{
    if (T)
    {
        if (T->data.id == id) return;
        if (T->data.id > id) insertTree(T->left, id,name,type,year,warranty);
        if (T->data.id < id) insertTree(T->right, id, name, type, year, warranty);
    }
    else T = getnode(id, name, type, year, warranty);
}
void inputTree(Tree& T)
{
    int n;
    cin >> n;
    int id,year,warranty;
    string name, type;
    for (int i = 0; i < n; i++)
    {
        cin >> id;
        cin.ignore();
        getline(cin, name);
        getline(cin, type);
        cin >> year;
        cin >> warranty;
        insertTree(T, id,name,type,year,warranty);
    }
}
void listProduct(Tree& T, string type)
{
    if (!T) return;
    if (T->data.type == type)
    {
        cout << T->data.id << " ";
        cout << T->data.name << " ";
        cout << T->data.type << " ";
        cout << T->data.year << " ";
        cout << T->data.warranty << endl;
    }
    listProduct(T->left,type);
    listProduct(T->right,type);
}
int countProduct(Tree& T, int year)
{
    if (!T) return 0;
    int count = 0;
    if (T->data.warranty > year)
        count++;
   
    return count + countProduct(T->left, year) + countProduct(T->right, year);
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    string type;  cin.ignore(); getline(cin, type);
    cout << "List of products whose type is  " << type << ": ";
    cout << "\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T, type);

    int year; cin >> year;
    cout << "Number of products with more than " << year << " years of warranty: " << countProduct(T, year) << endl;
    

    return 0;
}

