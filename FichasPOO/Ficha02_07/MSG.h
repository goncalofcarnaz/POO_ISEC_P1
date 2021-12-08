#pragma once
#include <string>
using namespace std;

class MSG {
private:
    char letra;
    int numero;
    static int nObj;
public:
    MSG();
  
    ~MSG();
    string GetAsString() const;
};
