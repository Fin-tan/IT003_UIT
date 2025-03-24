#include <iostream>
#include <string>

#define LOAD 0.7
#define EMPTY 0
#define DELETE -1
using namespace std;

struct Hocsinh {
    int Maso;
    string Hoten;
    int Namsinh;
    bool Gioitinh;
    double TBK;
};

struct Hashtable {
    int M; // Kich thuoc bang bam   
    int n; // so phan tu trong bang bam
    Hocsinh* table;
};
void Input(Hocsinh& x) {
    cin >> x.Maso;
    getline(cin >> ws, x.Hoten);
    cin >> x.Namsinh;
    cin >> x.Gioitinh;
    cin >> x.TBK;
}
void CreateHashtable(Hashtable& hashtable, int m)
{
    hashtable.M = m;
    hashtable.n = 0;
    hashtable.table = new Hocsinh[m];
    for (int i = 0; i < m; i++)
    {
        hashtable.table[i].Maso = EMPTY;
    }
}
void Insert(Hashtable& hashtable, Hocsinh hs)
{
    double hesotai = double(hashtable.n+1) / hashtable.M;
    if (hesotai > LOAD) return;
    int index = hs.Maso % hashtable.M;
    while (hashtable.table[index].Maso != EMPTY && hashtable.table[index].Maso != DELETE)
    {
        index = (index + 1) % hashtable.M;
    }
    hashtable.table[index] = hs;
    hashtable.n++;
}
void PrintHashtable(Hashtable& hashtable)
{
    for (int i = 0; i < hashtable.M; i++)
    {
        if (hashtable.table[i].Maso > 0)
            cout << '[' << hashtable.table[i].Maso << ",  " << hashtable.table[i].Hoten << "  , " << hashtable.table[i].Gioitinh << ", " << hashtable.table[i].Namsinh << ", " << hashtable.table[i].TBK << "]\n";
        else
            cout << "[" << hashtable.table[i].Maso << ",  " << "  , " << ", " << ", " << "]\n";


    }
}
void DeleteHashtable(Hashtable& hashtable)
{
    delete[] hashtable.table; 
    hashtable.table = nullptr;
    hashtable.n = 0;
    hashtable.M = 0;
}
int main()
{
    Hashtable hashtable;

    int m, n;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    cin >> n;
    for (int i = 0; i < n; i++) {
        Input(hs);
        Insert(hashtable, hs);
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
