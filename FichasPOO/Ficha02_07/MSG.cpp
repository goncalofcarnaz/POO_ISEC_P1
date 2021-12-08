#include "MSG.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int MSG::nObj = 0;

MSG::MSG() : letra( 'x' ), numero(++nObj)  {
   
}

MSG::~MSG()
{
    cout << "A destruir ..." << "\n";
}

string MSG::GetAsString() const {
    ostringstream b;
    b << "letra: " << letra << " numero: " << numero << "\n";
    return b.str();
}


