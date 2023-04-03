#include <iostream>

class Book
{
private:
    int qu;
    int price;
public:
    Book(int q) : qu(q), price(10 * q) {}
    int getQu() const { return qu; }
    int getPrice() const { return price; }
    int getTotal() const { return qu * price; }
    friend void fun(Book b);
    friend void fun(Book* pb);
    friend void fun(Book& rb);
};

void fun(Book b)
{ 
    b.qu++;
    std::cout << "普通对象方式：qu*price = " << b.qu * b.price << std::endl;
}

void fun(Book* pb) 
{
    pb->qu++;
    std::cout << "指针方式：qu*price = " << pb->qu * pb->price << std::endl;
}

void fun(Book& rb)
{ 
    rb.qu++;
    std::cout << "引用方式：qu*price = " << rb.qu * rb.price << std::endl;
}


int main() {
    Book books[5] = { 1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; i++) 
    {
        fun(books[i]);
        std::cout << books[i].getQu() * books[i].getPrice() << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++) 
    {
        fun(&books[i]);
        std::cout << books[i].getQu() * books[i].getPrice() << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; i++)
    {
        fun(books[i]);
        std::cout << books[i].getQu() * books[i].getPrice() << std::endl;
    }
    return 0;
}