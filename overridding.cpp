#include <iostream>
using namespace std;

// Base class
class Shape {
public:
    // Virtual function to be overridden in derived classes
    virtual void area() {
        cout << "This is the base class Shape." << endl;
    }
};

// Derived class 1: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Overriding the virtual function
    void area() override {
        cout << "Area of Circle: " << 3.1415 * radius * radius << endl;
    }
};

// Derived class 2: Rectangle
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Overriding the virtual function
    void area() override {
        cout << "Area of Rectangle: " << length * width << endl;
    }
};

// Derived class 3: Triangle
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}

    // Overriding the virtual function
    void area() override {
        cout << "Area of Triangle: " << 0.5 * base * height << endl;
    }
};

int main() {
    // Array of base class pointers
    Shape* shapes[3];

    // Creating objects of derived classes and storing them in the array
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 7.0);

    // Accessing the appropriate area function at runtime using polymorphism
    for (int i = 0; i < 3; ++i) {
        shapes[i]->area();  // Calls the correct overridden function
    }

    // Clean up memory
    for (int i = 0; i < 3; ++i) {
        delete shapes[i];
    }

    return 0;
}
