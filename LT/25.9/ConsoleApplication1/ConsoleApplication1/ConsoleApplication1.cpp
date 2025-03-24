
    #include <iostream>
    #include <cstring>
    #include <string>
    using namespace std;


    typedef struct Province
    {
	    int id;
	    string name;
	    int danso;
	    float dientich;
    }pro;
    struct node
    {
        pro info;
        node* next;
    };
    node* getnode(pro x)
    {
        node* p;
        p = new node;
        p->info = x;
        p->next = NULL;
        return  p;
    }
    struct List
    {
        node* head, * tail;
    };
    void Init(List& L) {
        L.head = L.tail = NULL;
    }
    void inputprovince(pro &x)
    {
        cin >> x.id;
        cin.ignore();
        getline(cin, x.name);
        cin >> x.danso;
        cin >> x.dientich;
    }
    void outputProvince(pro x)
    {
        cout << x.id << "\t" << x.name << "\t" << x.danso << "\t" << x.dientich << endl;
    }
    void addTail(List& L, pro x)
    {
        node* p = getnode(x);
        if (L.head == NULL && L.tail == NULL)
        {
            L.head = L.tail = p;
        }
        else
        {
            p->next = NULL;
            L.tail->next = p;
            L.tail = p;
        }
    }
    void inputListProvinces(List &L)
    {
        int n; cin >> n;
        pro x;
        for (int i = 0; i < n; i++)
        {
            pro x;
            inputprovince(x);
            addTail(L, x);
        }
    }
    void outputListProvinces(List L)
    {
        node* p = L.head;
        while (p != NULL)
        {
            outputProvince(p->info);
            p = p->next;
        }
    }
    void outputProvincesMore1MillionPop(List L)
    {
        node* p = L.head;
        while (p != NULL)
        {
            if (p->info.danso > 1000)
                outputProvince(p->info);
            p = p->next;
        }
    }
    node* findProMaxArea(List L)
    {
        node* maxNode = L.head;
        node* p = L.head->next;
        while (p != NULL)
        {
            if (maxNode->info.dientich < p->info.dientich)
                maxNode = p;
            p = p->next;
        }
        return maxNode;
    }
    int main()
    {
        List L;
       Init(L);
        inputListProvinces(L);
        cout << "List of provinces:" << endl;
        cout << "ID\t|Province\t|Population\t|Area" << endl;
        outputListProvinces(L);

        cout << "Provinces with a population of more than 1 million:" << endl;
        outputProvincesMore1MillionPop(L);

        cout << "The largest province:" << endl;
        node* p = findProMaxArea(L);
        if (p) outputProvince(p->info);
    
        return 0;
    }



