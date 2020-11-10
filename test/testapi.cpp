#include <iostream>

class A
{
public:
    int operator>>(int num)
    {
        num = m_num;
        return m_num;
    }
    int m_num = 1;
};

int main()
{
    A a;
    int num(0);
    a >> num;
    std::cout << num << "\n";
    return 0;
}