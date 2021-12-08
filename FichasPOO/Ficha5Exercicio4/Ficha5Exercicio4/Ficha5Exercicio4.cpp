// Ficha5Exercicio4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


using namespace std;

class Pessoa { 
    string nome;
    string pos;
public:
    Pessoa(string n, string p): nome(n), pos(p){}

}; 

class EquipaFutebol {
    Pessoa* jogadores[11]; // 11 máximo
public:
    EquipaFutebol() {
        for (unsigned int i = 0; i < 11; i++) // inicialmente equipa vazia
            jogadores[i] = NULL; // NULL significa sem jogador
    }
    void setJogador(Pessoa* p, int pos) {
        jogadores[pos] = p; // Notar que o obj. Pessoa é visto pela equipa
    } // mas a pessoa não passa para ”dentro” da
}; // equipa (é uma agregação de Pessoas)


int main()
{
    Pessoa eus("Figo", "Avançado"), ebio("Inácio", "Defesa"); // de acordo com o que estiver na classe Pessoa
    EquipaFutebol fcpoo;
    fcpoo.setJogador(&eus, 0); // eus passa a pertencer ser jogador da equipa
    fcpoo.setJogador(&ebio, 1); // Idem para ebio
    return 0;
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
