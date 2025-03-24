#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;


struct DONTHUC {
    int somu;
    double heso;
};
struct Node {
    DONTHUC* data;
    Node* next;

};
struct DATHUC {
    Node* head, * tail;
};


void NhapDT(DATHUC& B, double heso, int somu) 
{
        if (heso == 0) return; 

        Node* p = new Node();
        p->data = new DONTHUC();
        p->data->heso = heso;
        p->data->somu = somu;
        p->next = NULL;

        if (B.head == NULL) {
            B.head = B.tail = p;
        }
        else {
            B.tail->next = p;
            B.tail = p;
        }
    
}
void Nhap(DATHUC& DT)
{
    DT.head = DT.tail = NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
        cin >> heso >> somu;
        NhapDT(DT, heso, somu);
    }
}

void Xuat(DATHUC B) {
    Node* p = B.head;
    bool isFirstTerm = true;

    while (p != NULL) {
        double heso = p->data->heso;
        int somu = p->data->somu;

        if (heso != 0) {
            if (!isFirstTerm) {
                if (heso > 0) cout << "+";
            }
            else {
                isFirstTerm = false;
            }

            if (heso == -1 && somu != 0) cout << "-";
            else if (heso != 1 || somu == 0) cout << heso;

            if (somu > 0) cout << "x";
            if (somu > 1) cout << "^" << somu;
        }

        p = p->next;
    }

    if (isFirstTerm) cout << "0";
    cout << endl;
}
DATHUC Tong2DaThuc(DATHUC A, DATHUC B)
{
    DATHUC Tong;
    Tong.head = Tong.tail = NULL;
    Node* p = A.head;
    Node* q = B.head;
    while (p != NULL && q != NULL)
    {
        if (p->data->somu > q->data->somu)
        {
            NhapDT(Tong, p->data->heso, p->data->somu);
            p = p->next;
        }
        else if (p->data->somu < q->data->somu)
        {
            NhapDT(Tong, q->data->heso, q->data->somu);
            q = q->next;
        }
        else
        {
            NhapDT(Tong, q->data->heso + p->data->heso, q->data->somu);
            q = q->next;
            p = p->next;
        }

    }
    while (q != NULL)
    {
        NhapDT(Tong, q->data->heso, q->data->somu);
        q = q->next;
    }
    while (p != NULL)
    {
        NhapDT(Tong, p->data->heso, p->data->somu);
        p = p->next;
    }
    
    return Tong;
}
int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}