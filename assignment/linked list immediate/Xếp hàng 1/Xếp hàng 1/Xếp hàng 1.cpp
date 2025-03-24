#include <iostream>
#include <list>

int main() {
    int n, m;
    std::cin >> n >> m;


    std::list<int> queue;
    for (int i = 1; i <= n; ++i) {
        queue.push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int mssv;
        std::cin >> mssv;

      
        queue.remove(mssv);
        queue.push_front(mssv);
    }

    for (int student : queue) {
        std::cout << student << " ";
    }

    return 0;
}
