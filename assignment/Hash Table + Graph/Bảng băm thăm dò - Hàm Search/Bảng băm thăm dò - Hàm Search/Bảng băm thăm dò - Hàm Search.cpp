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
    cin >> x.Gioitinh;
    cin >> x.Namsinh;
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
void DeleteHashtable(Hashtable& hashtable)
{
    delete[] hashtable.table;
    hashtable.table = nullptr;
    hashtable.n = 0;
    hashtable.M = 0;
}   
int Search(Hashtable& hashtable, int k, int& nprob)
{
    nprob = 0;
    int index = k % hashtable.M;
    int i = 1;
    int start = index;
    while (hashtable.table[index].Maso != EMPTY)
    {
        if (k == hashtable.table[index].Maso)
        {
            return 1;
        }
        else
        {
            nprob++;
            index = (k % hashtable.M + i * i) % hashtable.M;
            i++;
        }
        if (index == start) break;
    }
    return -1;
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
        if (Search(hashtable, k, nprob) > -1) {
            cout << "THAM DO " << nprob << endl;
        }
        else {
            cout << "KHONG TIM THAY" << endl;
        }
    }
    DeleteHashtable(hashtable);
    return 0;
}
