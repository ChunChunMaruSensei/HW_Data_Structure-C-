#include <iostream>
#include "HW03.cpp"
using namespace std;

int main()
{
    Polynomial f1;
    Polynomial f2;
    f1.addTerm(9,9);
    f1.addTerm(7,1);
    f1.addTerm(9,2);
    f1.addTerm(-30,0);
    f1.printPolynomial();
    f2.addTerm(10,5);
    f2.addTerm(5,5);
    f2.addTerm(9,33);
    f2.addTerm(5,0);
    f2.printPolynomial();
    f1.plus(f2);
    f1.printPolynomial();
    return 0;
}
