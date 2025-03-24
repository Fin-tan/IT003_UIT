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
void CreateHashtable(Hashtable& hashtable,int  m)
{
    hashtable.M = m;
    hashtable.n = 0;
    hashtable.table = new Hocsinh[m];
    for (int i = 0; i < m; i++)
    {
        hashtable.table[i].Maso = EMPTY;
    }
}
void Input(Hocsinh& hs)
{
    cin >> hs.Maso;
    getline(cin >> ws, hs.Hoten);
    cin >> hs.Gioitinh;
    cin >> hs.Namsinh;
    cin >> hs.TBK;
}
int Delete(Hashtable& hashtable, int k, int& nprob)
{
    nprob = 0;
    int index = k % hashtable.M;
    int start = index;
    int i = 1;
    while (hashtable.table[index].Maso!=EMPTY  )
    {
        if (k == hashtable.table[index].Maso)
        {
            hashtable.table[index].Maso = DELETE;
          
            return 1;
        }
        else
        {
            nprob++;
            index = (k % hashtable.M + i * i) % hashtable.M;
            i++;
        }
        if (start == index) break;
    }
    return 0;
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

    int m, n, k, nprob;
    Hocsinh hs;

    cin >> m;
    CreateHashtable(hashtable, m);
    for (int i = 0; i < m; i++) {
        Input(hs);
        hashtable.table[i] = hs;
        if (hs.Maso > 0)
            hashtable.n++;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (Delete(hashtable, k, nprob)) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG XOA DUOC" << endl;
        }
    }
    PrintHashtable(hashtable);
    DeleteHashtable(hashtable);
    return 0;
}
