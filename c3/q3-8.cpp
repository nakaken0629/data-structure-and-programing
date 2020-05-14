/* code: q3-8.c (v1.18.0) */
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    while(!q.empty()) {
        std::cout << q.front() << "\n";
        q.pop();
    }
}