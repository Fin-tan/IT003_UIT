#include <iostream>
#include <list>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    list<int> queue;
    for (int i = 1; i <= n; ++i) {
        queue.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int mssv;
        cin >> mssv;

    
        if (queue.front() != mssv) {
          
            for (auto it = queue.begin(); it != queue.end(); ++it) {
                if (*it == mssv) {
                    queue.erase(it);
                    break;
                }
            }
            queue.push_front(mssv);     
        }

       
        cout << queue.back() << " ";
    }

    return 0;
}
