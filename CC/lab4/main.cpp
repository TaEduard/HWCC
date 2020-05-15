#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
using namespace std;

void printVector(vector<int> v)
{

    for_each(v.begin(), v.end(), [](int i)
    {
        std::cout << i << " ";
    });
    cout << endl;
}

bool Odd (int i)
{
    return((i%2)==1);

}

bool Even (int i)
{
    return((i%2)==0);

}

int main()
{
    vector<int> v {7, 6, 8, 11, 55, 7};
    auto sum = [](int x, int y)
    {
        return x + y;
    };
    cout << "sum(18, 2): " <<sum(18, 2) << endl;

    auto odd= [] (int x)
    {
        if (x%2!=0)
            cout<< "element "<< x <<" is odd"<< endl;
        else
            cout<< "element "<< x <<" is even"<< endl;
        return x%2!=0;
    };

    odd(3);

    auto n = count_if(v.begin(), v.end(),
                      [](int n)
    {
        return (n % 2) != 0;
    });

    cout << "lambda count: " <<n << endl;

    vector <int> v1 {17, 12, 2, 4, 6, 8, 7, 12};
    vector <int> v2;
    vector <int> v3;
    vector <int> v4;
    vector <int> v5;

    copy(v1.begin(), v1.end(), back_inserter(v2));

    cout<<"V2 contents after copy" <<endl;
    printVector(v2);

    copy (v1.begin(), v1.begin()+4, back_inserter(v3));
    cout<< "Insert first 4 elements from v1 in v3"<<endl;
    printVector(v3);

    copy (v1.end()-4, v1.end(), back_inserter(v4));
    cout<< "Inser last 4 elements from v1 in v4"<< endl;
    printVector(v4);

    copy (v1.begin()+1, v1.end()-1, back_inserter(v5));
    cout<< "List all the elements but the first and last from v1 in v5"<< endl;
    printVector(v5);

    vector<int> first_vector = {2,8,50,2,4,5,10,12,9,27,29,33,31};
    vector<int> second_vector;
    int count_elem=0;

    second_vector.resize(first_vector.size());
    auto it2 = copy_if (first_vector.begin(), first_vector.end(), second_vector.begin(), [odd](int i){return odd(i);} );
    second_vector.resize(distance(second_vector.begin(),it2));


    second_vector.reserve(4);
    copy_if(first_vector.begin(),first_vector.end(),back_inserter(second_vector),
            [&count_elem]
            (int i){
                  return (i!=2 && count_elem !=4 && count_elem++!=4);});

    copy_if(first_vector.begin()+1,first_vector.end()-1,back_inserter(second_vector),[](int i){ return i%5==0;});


    for(int i : second_vector)
        cout<<i<<" ";
    cout<<endl;

    list <int> mylist = {17, 12, 2, 4, 6, 8, 7, 12};

    auto it = find(mylist.begin(),mylist.end(),5);

    if(it!=mylist.end())
        cout<<"The list contains at least a 5 "<<endl;
    else
        cout<<"The list doesn't contain a 5"<<endl;

    cout<<"List: "<<endl;
    for(int i: mylist)
        cout<<i<<" ";
    cout<<endl;

    cout<<"Odd elements:"<<endl;
    list<int>::iterator list_it = find_if(mylist.begin(), mylist.end(), [odd](int i){return odd(i);});
    while(list_it != mylist.end())
    {
    cout << *list_it << ' ';
    list_it = find_if(next(list_it), mylist.end(), [odd](int i){return odd(i);});
    }
    cout<<endl;

    cout<<"Even elements:"<<endl;
    list_it = find_if(mylist.begin(), mylist.end(), [](int i){return i%2==0;});
    while(list_it!=mylist.end()){
    cout<<*list_it<<' ';
    list_it = find_if(next(list_it),mylist.end(),[](int i){return i%2==0;});
    }
    cout<<endl;

    cout<<"Elements between [5,25):"<<endl;
    list_it = find_if(mylist.begin(),mylist.end(),[](int i){return i>=5 && i<25;});
    while(list_it!=mylist.end()){
    cout<<*list_it<<' ';
    list_it = find_if(next(list_it),mylist.end(),[](int i){return i>=5 && i<25;});
    }
    cout<<endl;


    vector<int> third_vector{30,40,89,75,64,39,28,54,48,1,17,34};
    list<int> another_list{30,40,89,75,64,39,28,54,48,1,17,34};
    third_vector.erase(remove(third_vector.begin(),third_vector.end(),2),third_vector.end());
    third_vector.erase(remove_if(third_vector.begin(),third_vector.end(),[](int i){return i%5==0;}),third_vector.end());
    third_vector.erase(remove_if(third_vector.begin(),third_vector.end(),[](int i){return !(i>3&&i<20);}),third_vector.end());
    another_list.erase(remove(another_list.begin(),another_list.end(),2),another_list.end());
    another_list.erase(remove_if(another_list.begin(),another_list.end(),[](int i){return i%5==0;}),another_list.end());
    another_list.erase(remove_if(another_list.begin(),another_list.end(),[](int i){return !(i>3&&i<20);}),another_list.end());

    cout<<"third_vector:"<<endl;
    for(int i: third_vector)
        cout<<i<<" ";
    cout<<endl;
    cout<<"another_list:"<<endl;
    for(int i: another_list)
        cout<<i<<" ";
    cout<<endl;



    third_vector.push_back(5);
    third_vector.push_back(6);
    third_vector.push_back(7);
    third_vector.push_back(8);

    cout<<"third_vector:"<<endl;
    for(int i: third_vector)
        cout<<i<<" ";
    cout<<endl;

    third_vector.erase(third_vector.begin(),third_vector.begin()+5);
    third_vector.erase(remove_if(third_vector.begin(),third_vector.end(),[](int i){return !(i>3&&i<7);}),third_vector.end());

    cout<<"third_vector:"<<endl;
    for(int i: third_vector)
        cout<<i<<" ";
    cout<<endl;




    return 0;

}
