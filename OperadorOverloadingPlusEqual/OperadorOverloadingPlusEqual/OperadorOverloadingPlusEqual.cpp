// OperadorOverloadingPlusEqual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


// SEE: https://www.ibm.com/docs/en/zos/2.1.0?topic=only-overloading-operators

class Complexo {
private:
    int real, imag;
public:
    Complexo(int r = 0, int i = 0) { real = r;   imag = i; }

  
    Complexo operator + (Complexo const& obj) {
        Complexo res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};




int main()
{
   
    Complexo c1(10, 5), c2(2, 4);
    Complexo c3 = c1 + c2; 
    c3.print();




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
