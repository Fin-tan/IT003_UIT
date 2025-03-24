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

typedef struct DATHUC {
	Node* head;
	Node* tail;
}List;

void Nhap(DATHUC& B, double heso, int mu)
{
    Node* p = new Node();
    p->data = new DONTHUC();
    p->data->heso = heso;
    p->data->somu = mu;
    p->next = NULL;
    if (B.head == NULL)
    {
        B.head = B.tail = p;
    }
    else
    {
        B.tail->next = p;
        B.tail = p;
    }
}
void Xuat(DATHUC B) {
    Node* p = B.head;
    bool firstTerm = true;
    bool hasNonZeroTerm = false;

    while (p != NULL) {
        if (p->data->heso != 0) {
            hasNonZeroTerm = true;
            if (!firstTerm) {
                if (p->data->heso > 0) {
                    cout << "+";
                }
                else {
                    cout << "-";
                }
            }
            else {
                if (p->data->heso < 0) cout << "-";
                firstTerm = false;
            }

            double absHeso = abs(p->data->heso);
            if (absHeso != 1 || p->data->somu == 0) cout << absHeso;
            if (p->data->somu > 0) {
                cout << "x";
                if (p->data->somu > 1) cout << "^" << p->data->somu;
            }
        }
        p = p->next;
    }

    if (!hasNonZeroTerm) {
        cout << "0";
    }
    cout << endl;
}


double  TinhDaThuc(DATHUC B, double x)
{
    Node* p = B.head;
    double sum=0;
    while (p != NULL)
    {
        sum=sum+(p->data->heso* pow(x, p->data->somu));
        p = p->next;
    }
    return sum;
}
int main() {
    DATHUC B;
    B.head = B.tail = NULL;
    int n; cin >> n;
    double heso; int somu;
    for (int i = 0; i < n; i++)
    {
        cin >> heso >> somu;
        Nhap(B, heso, somu);
    }
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
        << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
