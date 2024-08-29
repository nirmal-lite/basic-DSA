#include <iostream>
using namespace std;

// ClassA definition
class ClassA {
private:
    int i;  // private member variable

public:
    // Default constructor
    ClassA(int ii = 0) : i(ii) {
        cout << "ClassA: Constructor called with value: " << i << endl;
    }

    // Copy constructor
    ClassA(const ClassA& other) : i(other.i) {
        cout << "ClassA: Copy constructor called" << endl;
    }

    // Assignment operator overloading
    ClassA& operator=(const ClassA& other) {
        cout << "ClassA: Assignment operator called" << endl;
        if (this != &other) {
            i = other.i;
        }
        return *this;
    }

    // Show function to display the value of 'i'
    void show() const {
        cout << "ClassA: i = " << i << endl;
    }
};

// ClassB definition
class ClassB {
private:
    int x;  // private member variable

public:
    // Constructor
    ClassB(int xx = 0) : x(xx) {
        cout << "ClassB: Constructor called with value: " << x << endl;
    }

    // Copy constructor
    ClassB(const ClassB& other) : x(other.x) {
        cout << "ClassB: Copy constructor called" << endl;
    }

    // Assignment operator overloading
    ClassB& operator=(const ClassB& other) {
        cout << "ClassB: Assignment operator called" << endl;
        if (this != &other) {
            x = other.x;
        }
        return *this;
    }

    // Conversion operator to convert ClassB to ClassA
    operator ClassA() const {
        cout << "ClassB: Conversion operator to ClassA called" << endl;
        return ClassA(x);  // Conversion from ClassB to ClassA
    }

    // Show function to display the value of 'x'
    void show() const {
        cout << "ClassB: x = " << x << endl;
    }
};

// Function g that accepts a ClassA object
void g(ClassA a) {
    cout << "Function g(ClassA) called" << endl;
    a.show();
}

int main() {
    // Direct construction of ClassA object
    ClassA a1(5);    // Calls ClassA constructor
    a1.show();

    // Direct construction of ClassB object
    ClassB b1(10);   // Calls ClassB constructor
    b1.show();

    // Conversion from ClassB to ClassA using the conversion operator
    ClassA a2 = b1;  // ClassB -> ClassA conversion
    a2.show();

    // Passing ClassB object to function expecting ClassA (conversion happens)
    g(b1);           // Calls ClassB to ClassA conversion and then g()

    // Passing integer directly to function expecting ClassA (int -> ClassA conversion)
    g(20);           // Calls ClassA constructor directly

    // Copy constructor demonstration
    ClassB b2 = b1;  // Calls ClassB copy constructor
    b2.show();

    // Assignment operator demonstration
    ClassB b3;
    b3 = b1;         // Calls ClassB assignment operator
    b3.show();

    // Copy constructor and assignment operator in ClassA
    ClassA a3 = a1;  // Calls ClassA copy constructor
    a3.show();

    ClassA a4;
    a4 = a1;         // Calls ClassA assignment operator
    a4.show();

    return 0;
}
