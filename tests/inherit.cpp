#include <iostream>

class A
{
protected:
    int i;
};

class B : public A
{
public:
    void print()
    {
        std::cout << "i = " << i << std::endl;
    }
};

int main()
{
    B b;
    b.print();
    return 0;
}
