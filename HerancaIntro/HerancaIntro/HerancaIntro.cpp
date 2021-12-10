// HerancaIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Caixa {
    int altura;
    int largura;
    int lista[10];
protected:
    string nome;
public:
    Caixa (int a,  int l): altura(a), largura(l) {}
    
    void setAltura(int a) {
        altura = a;
    }
    void setLargura(int l) {
        largura = l;
    }


};


class CaixaColorida :public Caixa {
    string cor;
public:
    CaixaColorida(int a, int l, string c) : Caixa(a, l), cor (c) { }
    
    
    void SetCor(string c) {
        cor = c;
    }
    string getNome() const {
        return nome;
    }

  

};

int main()
{
    CaixaColorida cc(100,100,"Verde");
    cc.SetCor("Amarelo");
    Caixa a(100, 200);
    cc.setAltura(100); // herdado.
    // O que não é herdado:
    /*
        Construtores;
        Destrutores;
        Operadores new;
        Operadores de atribuição;
        Relacionamentos friend;
        Atributos privados.
    
    */
    cout << cc.getNome(); // exemplo do protected
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
