#include <iostream>
#include<string>
#include <list>
#include <forward_list>
#include <algorithm>
#include<bits/stdc++.h>
#include <iterator>
#include <map>
#include <queue>

using namespace std;

int listDemo() {
    std::cout << '\n'<<"LIST DEMO ---------------------------------------" << '\n';
    std::forward_list < int > l = {
        14,
        5,
        4
    };
    l.resize(2); // remove third element from the list: {12, 3}
    l.resize(5); // adds 0-value elements up to 5 elements {12, 3, 0, 0, 0}
    auto last = l.begin();
    for (auto it = l.begin(); it != l.end(); it++) last = it; // getting last element
    l.insert_after(last, 2); // output: {12, 3, 0, 0, 0, 2}
    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout  << * it ;
    }
    std::cout << '\n';

    std::list < int > myList = {
        2,
        4,
        6
    };

    for (auto it = myList.rbegin(); it != myList.rend(); it++) {
        std::cout  << * it << std::endl;
    }
    return 0;
}

int queueDemo() {
    std::cout << '\n'<<"QUEUE DEMO ---------------------------------------" << '\n';
    int a[] = {
        1,
        2,
        3
    };
    std::priority_queue < int, std::vector < int > , std::greater < int >> pq(a, a + 3);
    std::cout <<"QUEUE SIZE:"<< pq.size() << '\n';
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << '\n' <<"QUEUE SIZE:"<< pq.size() << '\n';
    std::cout << '\n';
    return 0;
}

int pairDemo() {
    std::cout << '\n'<<"MAP DEMO ---------------------------------------" << '\n';
    map < int, int > m;

    m.insert(pair < int, int > (1, 10));
    m.insert(pair < int, int > (2, 10));
    m.insert(pair < int, int > (3, 30));
    m.insert(pair < int, int > (4, 40));
    m.insert(pair < int, int > (5, 40));
    m.insert(pair < int, int > (6, 60));
    m.insert(pair < int, int > (7, 90));
    m.insert(pair < int, int > (1, 110));

    map < int, int > ::iterator itr;
    std::cout << '\t' << "KEY" << '\t' << "ELEMENT" << '\n';
     for (itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    return 0;
}

int tupleDemo() {
    std::cout << '\n'<<"TUPLE DEMO ---------------------------------------" << '\n';

    vector<tuple<string, string, int, int,int>> cars;
    cars.emplace_back("audi","black",2012,5,123);
    cars.emplace_back("mazda","red",2010,2,123);
    cars.emplace_back("dacia","black",2009,5,123);
    cars.emplace_back("renault","silver",2013,5,123);
    cars.emplace_back("bmw","green",1997,5,123);


    auto it = find_if(begin(cars), end(cars), [](decltype(*begin(cars)) e) {

        return get<0>(e)=="renault";
    });

    if (it != end(cars))
        cout << get<0>(*it) << " " << get<1>(*it)<< " " << get<2>(*it)<<endl;

    return 0;
}
int dequeDemo() {
    std::cout << '\n'<<"DEQUE DEMO ---------------------------------------" << '\n';

    deque<string> names = {"ana","maria","ion","florin","robert","mircea","bogdan","cristi"};
    vector<string>names_two;

    for(int i=0;i<5;i++)
    {
        names_two.push_back(names[i]);
        cout<<names_two[i]<<" ";
    }

    cout<<endl;

    return 0;
}

int main() {
    listDemo();
    queueDemo();
    pairDemo();
    tupleDemo();
    dequeDemo();
    return 0;
}
