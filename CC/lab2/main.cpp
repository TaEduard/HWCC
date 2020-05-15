/* decltype vs auto*/
#include <iostream>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int global{};
int& foo()
{
    return global;
}

int labwork1()
{
    cout<<'\n'<<"labwork1 start ------------------------------"<<'\n';
    decltype(foo()) a = foo();
    auto b = foo();
    b = 2;
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    auto c = foo();
    c = 10;
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';
    cout<<'\n'<<"labwork1 end ------------------------------"<<'\n';
    return 0;
}

/* Write a class that has a constexpr defined constructor and method. Declare an object of this class and call the method.*/

class Circle
{
    float _pi;
    int  _r;
    public:
    // A constexpr constructor
    constexpr Circle (float pi, int r) : _pi(pi), _r(r) {}

    constexpr int getArea () { return _pi * (_r*_r); }
};

int labwork2()
{
    cout<<'\n'<<"labwork2 start ------------------------------"<<'\n';
    // Below object is initialized at compile time
    constexpr Circle obj(3.14, 20);
        cout << obj.getArea();
    cout<<'\n'<<"labwork2 end ------------------------------"<<'\n';
    return 0;
}

int homework()
{
    cout<<'\n'<<"hw2 start ------------------------------"<<'\n';
    int f,l,n;
    std::vector<int> v= {0,1,2,3,4,4,5,6,7,8,9};

    for (auto i:v)
        cout<<i<<" ";

    cout<<'\n';
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        if (*i % 2 != 0)
        {
            v.erase(i);
            i--;
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << ' ' << *it <<'\n';

    *(v.begin())=999;
    *(v.end()-1)=111;

    for (auto j = v.begin(); j != v.end(); ++j)
        cout << ' ' << *j;

    cout<<'\n';

    v.erase(v.begin()+4);

    for (auto f = v.begin(); f != v.end(); ++f)
        cout << ' ' << *f;
    cout<<'\n'<<"hw2 end ------------------------------"<<'\n';
    return 0;
}

int main()
{
labwork1();
labwork2();
homework();
return 0;
}
