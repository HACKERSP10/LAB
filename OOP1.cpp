#include<iostream>
using namespace std;

class Complex{
private:
    double real;
    double imag;

public:
    //Default Constructor initializes to 0+0i
    Complex(double r=0.0, double i=0.0):real(r), imag(i){}

    //Overload + operator for addition.
    Complex operator+(const Complex& b){
        return Complex(real+b.real, imag+b.imag);
    }

    //Overload * operator for multiplictaion.
    Complex operator*(const Complex& b){
        return Complex((real*b.real)-(imag*b.imag), (real*b.imag)*(imag*b.real));
    }

    friend ostream& operator<<(ostream& out, const Complex& c){
        if(c.imag>=0){
            out<<c.real<<"+"<<c.imag<<"i";
        }
        else{
            out<<c.real<<"-"<<-c.imag<<"i";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imag;
        return in;
    }
};

int main(){
    Complex c1, c2, c3;

    cout<<"\n Enter the first Complex number(real and imaginary):"<<endl;
    cin>>c1;

    cout<<"\n Enter the second Complex number(real and imaginary)"<<endl;
    cin>>c2;

    c3=c1+c2;
    cout<<"\n The sum of two Complex numbers is "<< c3 <<endl;

    c3=c1*c2;
    cout<<"\n The product of two complex numbers is "<< c3 <<endl;

    return 0;

}