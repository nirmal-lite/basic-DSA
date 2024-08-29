#include <iostream>
using namespace std;

class Complex {
    private:
        int real, imag;

    public:
        // Constructor
        Complex(int r = 0, int i = 0) : real(r), imag(i) {}

        // Friend function to overload the + operator (for cases like 3 + Complex)
        friend Complex operator+(int value, const Complex& c);
        friend Complex operator+(const Complex& c, int value);

        // Friend function to overload the == operator
        friend bool operator==(const Complex& c1, const Complex& c2);

        // Friend function to overload << for output (ostream)
        friend ostream& operator<<(ostream& os, const Complex& c);

        // Friend function to overload >> for input (istream)
        friend istream& operator>>(istream& is, Complex& c);
};

// Overloading + operator: (int + Complex)
Complex operator+(int value, const Complex& c) {
    return Complex(c.real + value, c.imag);
}

// Overloading + operator: (Complex + int)
Complex operator+(const Complex& c, int value) {
    return Complex(c.real + value, c.imag);
}

// Overloading == operator
bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.real == c2.real && c1.imag == c2.imag);
}

// Overloading << operator for output
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

// Overloading >> operator for input
istream& operator>>(istream& is, Complex& c) {
    cout << "Enter real part: ";
    is >> c.real;
    cout << "Enter imaginary part: ";
    is >> c.imag;
    return is;
}

int main() {
    Complex c1(2, 3), c2(3, 4);

    // Overloading + operator for Complex + int and int + Complex
    Complex c3 = c1 + 5;     // Complex + int
    Complex c4 = 7 + c2;     // int + Complex

    cout << "c1 + 5 = " << c3 << endl;
    cout << "7 + c2 = " << c4 << endl;

    // Using overloaded == operator
    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are not equal" << endl;

    // Using overloaded << and >> operators for I/O
    Complex c5;
    cin >> c5;
    cout << "Entered Complex number is: " << c5 << endl;

    return 0;
}
