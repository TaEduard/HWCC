#include <iostream>
#include <map>
#include <string>
#include <cstddef>
#include <climits>
#include <cstddef>

using namespace std;


/*
template<class T>
constexpr T angle = T(60)
std::cout<<angle<int>;


template<typename T>
using myAlias = std::map<std::string, T>;
myAlias<int> alias;
alias[std::string("A")] = 5;
*/


template <typename T>
constexpr std::size_t
bit_size() noexcept
{
  return sizeof(T) * CHAR_BIT;
}


template<typename T>
using myAlias = std::map<std::string, T>;

void practice1(){
    //Using variable templates get the number of bytes of some primitive data types (int,double etc.)
std::cout << bit_size<int>() << std::endl;
  std::cout << bit_size<long>() << std::endl;
  std::cout << bit_size<double>() << std::endl;
  std::cout << bit_size<string>() << std::endl;
  }
void practice2(){
    //Using alias template initialize map with several {key,value} pairs, value being of different data types.
myAlias<int> alias;
myAlias<string> aliasS;
alias[std::string("A")] = 5;
aliasS[std::string("B")] = "a";

     for (auto itr = alias.begin(); itr != alias.end(); ++itr) {
        std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
     for (auto itr2 = aliasS.begin(); itr2 != aliasS.end(); ++itr2) {
        std::cout << '\t' << itr2->first << '\t' << itr2->second << '\n';
    }
}

/*
template<typename… Ts>
function (Ts… Vs)
{
// some magic here
}
*/
template <typename T>
void printE(T t) {
   std::cout << t << std::endl;
}

template<typename T>
T SumParSquare(T t) {
  return t;
}

void printL() {}

template <typename T, typename...Ts>
void printL(T &&first, Ts&&... rest) {
    // print it
    printE(std::forward<T>(first));
    // Forward the rest.
    printL(std::forward<Ts>(rest)...);
}
template<typename T, typename... Args>
T SumParSquare(T first, Args... args) {
  return first * first + SumParSquare(args...);
}

template <typename A>
A MaxEl(A a,A b)      //this is an overload, not specialization
{
   if (a>b)
      return a;
   else
      return b;
}

template <typename A, typename ... Args>
A MaxEl(A a, A b, Args ... args)
{
   return MaxEl(MaxEl(a,b),args...);
}



void practice4(){
/*
Write a variadic template function that calculates the square parameters' sum
Write a variadic template function that calculates the maximum from its parameters
*/
printL(1,2,3);
  const int c = SumParSquare(1,2,3);
  std::cout << c << '\n';
  const int m = MaxEl(1,2,3);
  std::cout << m << '\n';
}

/*
template<class T1>
void method(T1 var1) {}
//overloading
template<class T1, class T2>
void method(T1 var1, T2 var2) {}
//specialization
template<>
void method(int var1, double var2) { }
*/

template<class T1>
void method(T1 var1) { /*do something*/
 std::cout << var1<<endl;
}
//overloading
template<class T1, class T2>
void method(T1 var1, T2 var2) {/*do something*/
 std::cout << var1<<var2<<endl;
}
template<>
void method(int var1, int var2) { /*do something*/
if((var1%2==1)&&(var2%2==1)){
    std::cout << var1<<var2<<endl;
    return;
}else if(var1%2==1){
    std::cout << var1<<endl;
    return;
}else if(var2%2==1){
    std::cout << var2<<endl;
    return;
}
std::cout << "no odd"<<endl;
}




void practice3(){
/*
Using function templates do the following:
Create a function template with 1 parameter that prints it
Overload this function template with a second parameter that concatenates the parameters and prints the output
If we get two integers the method should just print the odd one.
*/
method(1);
method("a");
method("b","a");
method(2,3);
method(4,5);
method("c",6);
}
int main()
{
  practice1();
  practice2();
  practice3();
  practice4();
}
