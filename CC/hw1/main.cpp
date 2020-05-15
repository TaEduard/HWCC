#include <iostream>
using namespace std;

class figure {
protected:
    double x, y;
public:
    void set_dim(double i, double j=0) {
        x = i;
        y = j;
    }
    virtual void show_area() {
        cout << "No area computation defined ";
        cout << "for this class.\n";
    }
} ;

class tri : public figure {
public:
    void show_area() {
        cout << "Triangle has an area of " << x * 0.5 * y << ".\n";
    }
};

class rec : public figure {
public:
    void show_area() {
        cout << "Square has an area of " << x *  y << ".\n";
    }
};

class circ : public figure {
public:
    void show_area() {
        cout << "Circle has an area of " << 3.14 * x * x << ".\n";
    }
} ;

class sqre : public figure {
public:
    void show_area() {
        cout << "Square has an area of " << x * x << ".\n";
    }
} ;
int main()
{
    string triangle;
    string rectangle;
    string circle;
    string shape;
    int dim1,dim2;

    figure *p;

    cout << "triangle, rectangle, square, circle: ";

    cin >> shape;

    if (shape =="triangle") {
            tri t; // create objects of derived types;
            cout << "base of triangle: ";
            cin >> dim1;
            cout << "height of triangle: ";
            cin >> dim2;
            p = &t;
            p->set_dim(dim2, dim1);
            p->show_area();
        }
        else
            if (shape =="rectangle") {
            rec s;
            cout << "width of rectangle: ";
            cin >> dim1;
            cout << "height of rectangle: ";
            cin >> dim2;
            p = &s;
            p->set_dim(dim2, dim1);
            p->show_area();
        }
        else
            if (shape =="square") {
            sqre s;
            cout << "width/height of rectangle: ";
            cin >> dim1;
            p = &s;
            p->set_dim(dim1);
            p->show_area();
        }
        else
            if (shape =="circle") {
            circ c;
            cout << "radius of circle: ";
            cin >> dim1;
            p = &c;
            p->set_dim(dim1);
            p->show_area();
        }
        else
            cout << "Form not supported.";

    return 0;
}
