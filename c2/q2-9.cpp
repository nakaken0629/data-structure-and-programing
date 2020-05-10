/* code: q2-9.c (v1.18.0) */
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    std::cout << s.top() << "\n";
    s.pop();
}