#include <iostream>

class Complex {
    private:
    float real;
    float imag;

    public:
    //Constructor to initialize to imaginary parts
    Complex(float r = 0, float i = 0){
        real = r;
        imag = i;
    }

    //Overloading the '+' operator
    //Syntax: ReturnType operator OperatorSymbol (Parameter)
    Complex operator + (const Complex& obj){
        Complex temp;
        temp.real = real + obj.real; //
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main(){
    Complex c1(3.5, 2.5);
    Complex c2(1.2, 4.3);

    Complex c3 = c1 + c2;

    std::cout << "First Complex Number: "; c1.display();
    std::cout << "Second Complex Number: "; c2.display();
    std::cout << "Sum: "; c3.display();

    return 0;


}