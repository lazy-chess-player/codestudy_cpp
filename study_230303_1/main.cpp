#include <iostream>
class B;

class A
{
private:
    int x;
public:
    A(int a) : x(a) {}

    friend void add(A& a, B& b);
};

class B {
private:
    int y;
public:
    B(int b) : y(b) {}

    friend void add(A& a, B& b);
};

void add(A& a, B& b) {
    int sum = a.x + b.y;
    std::cout << "The sum is: " << sum << std::endl;
}
int main() {
    A a(10);
    B b(20);
    add(a, b); // Êä³ö£ºThe sum is: 30
    return 0;
}
