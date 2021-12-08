// Ficha02_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include "MSG.h"
using namespace std;


// Apontamentos Teoricos: Diaposito 57 - 67 ( por ai ... :) ... )


int main()
{
    
    // Construtor usando o valor por omissão
    MSG msgO;
    
    cout << msgO.GetAsString();
   
    MSG msg1;
    cout << msg1.GetAsString();
    
    MSG msg2;
    cout << msg2.GetAsString();

    // Alinea b)
    cout << "Alinea b) \n";
    MSG& c = msgO;
    cout << c.GetAsString();


    // Alinea c)

    // MSG msg1 = msgO;


    // Alinea d)
    cout << "Alinea d)";
    msgO = msg1;
    cout << msgO.GetAsString();

    // Alinea e)
    cout << "Alinea e)";
    MSG MatrizMsg[2];

    cout << MatrizMsg[0].GetAsString();
    cout << MatrizMsg[1].GetAsString();

    cin.clear();

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
