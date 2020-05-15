#include <iostream>
#include <list>
#include <map>
using namespace std;



class Book
{
private:
    string author_;
    string title_;
    string currentDate_;
    string returnDate_;
    int bookRating_;
public:
    Book( string title, string author, string currentD, string returnD, int rating)
    {
        this->author_=author;
        this->title_=title;
        this->currentDate_=currentD;
        this->returnDate_=returnD;
        this->bookRating_=rating;
    }

    Book() {}

    void setRating(int r)
    {
        this->bookRating_=r;
    }

    bool returned() const
    {
        return    currentDate_ < returnDate_;
    }


    string getTitle()
    {
        return this->title_;
    }

    string getAuthor()
    {
        return this->author_;
    }

    int getRating()
    {
        return this->bookRating_;
    }
};

void Ex1(){
string current_date="2020/06/06";

    list<Book> books;
    Book b1("The Art of Deception","William L. Simon",current_date,"2020/01/03",5);
    Book b2("The Art of Invisibility","Kevin Mitnick",current_date,"2020/08/04",5);
    Book b3("The Clean Coder","Robert Cecil Martin",current_date,"2019/11/25",4);
    Book b4("The Art of Intrusion","Kevin Mitnick",current_date,"2020/08/22",5);
    Book b5("The Phoenix Project","Gene Kim",current_date,"",3);
    Book b6("Hardware Hacking","Joe Grand",current_date,"2020/04/03",5);
    Book b7("Black Hat Python","Justin Seitz",current_date,"2020/05/04",3);
    Book b8("The Web Application Hacker's Handbook","Dafydd Stuttard",current_date,"2020/06/05",5);
    Book b9("iOS Hacker's Handbook","CHARLIE MILLER",current_date,"2020/06/07",1);

    books.push_back(b1);
    books.push_back(b2);
    books.push_back(b3);
    books.push_back(b4);
    books.push_back(b5);
    cout << "Book inventory:"<<endl;
    for(Book b :books) cout<<b.getTitle()<<" - "<<b.getAuthor()<<endl;

    list<Book> friend_one;
    list<Book> friend_two;

    friend_one.push_back(b6);
    friend_one.push_back(b7);
    friend_two.push_back(b8);
    friend_two.push_back(b9);


    list<Book>::const_iterator it = books.cbegin();
    while(it != books.cend())
    {
        if(it->returned()==true)
        {
            it=books.erase(it);
        }
        else
        {
            ++it;
        }
    }
    cout<<endl;

    cout << "Books available list:"<<endl;
    for(Book b :books) cout<<b.getTitle()<<" - "<<b.getAuthor()<<endl;
    cout<<endl;


    map<string,list<Book>> friends;
    friends["Mitch"]=books;
    friends["Alex"]=friend_one;
    friends["Paul"]=friend_two;


    for (auto it = friends.begin(); it != friends.end(); it++)
    {
        cout<<it->first<<" gave 5 stars to the following books: "<<endl;
        for (auto lit = it->second.begin(); lit  != it->second.end(); lit++)
            if(lit->getRating()==5)
                cout << lit->getTitle()<<" - "<<lit->getAuthor()<< " |*****|" <<endl;
        cout << "\n";
    }
}





enum class Importance
{
    critical=5,
    high=4,
    medium=3,
    low=2
};

enum class Difficulty
{
    high=3,
    medium=2,
    low=1
};

enum class Type
{
    final,
    intermediary
};

class Exam
{
private:
    Importance importance_;
    Difficulty difficulty_;
    Type type_;
    int priority_;
    string name;
public:
    Exam() {}
    Exam(string name,Importance imp, Difficulty dif, Type t)
    {
        this->name=name;
        this->importance_=imp;
        this->difficulty_=dif;
        this->type_=t;
        this->priority_=(int)this->difficulty_*(int)this->importance_;
    }
    int getPriority()
    {
        return this->priority_;
    }
    string getName()
    {
        return this->name;
    }
};

bool descendingPriority (Exam& first,  Exam& second)
{
    return ( first.getPriority() > second.getPriority() );
}

void Ex5(){
list<Exam> exams;
    Exam ba1("Numerical Methods",Importance::medium,Difficulty::low,Type::final);
    Exam ba2("Network Administration",Importance::high,Difficulty::high,Type::final);
    Exam ba3("Data Structures",Importance::medium,Difficulty::medium,Type::final);
    Exam ba4("Graphics and User Interfaces",Importance::low,Difficulty::medium,Type::final);

    Exam ma1("BSc Thesis Preparation",Importance::critical,Difficulty::medium,Type::intermediary);
    Exam ma2("Applications Development using .NET platform",Importance::high,Difficulty::low,Type::intermediary);
    Exam ma3("Programming Environments",Importance::high,Difficulty::high,Type::intermediary);
    Exam ma4("Web Technologies",Importance::medium,Difficulty::medium,Type::intermediary);
    Exam ma5("Design Patterns",Importance::high,Difficulty::medium,Type::intermediary);
    Exam ma6("Cloud computing and IoT",Importance::low,Difficulty::high,Type::intermediary);

    exams.push_back(ba1);
    exams.push_back(ba2);
    exams.push_back(ba3);
    exams.push_back(ba4);
    exams.push_back(ma1);
    exams.push_back(ma2);
    exams.push_back(ma3);
    exams.push_back(ma4);
    exams.push_back(ma5);
    exams.push_back(ma6);

    cout<<endl<<"Exam list: "<<endl;
    for(Exam e: exams)
        cout<<e.getName()<<" "<<e.getPriority()<<endl;

    exams.sort(descendingPriority);
    cout<<endl<<"Exam list sorted: "<<endl;
    for(Exam e: exams)
        cout<<e.getName()<<" "<<e.getPriority()<<endl;
}

int main()
{
Ex1();
Ex5();
}
