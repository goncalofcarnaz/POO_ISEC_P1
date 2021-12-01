// CopiaConstrutor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Poema 
{

public:
	Poema (const string &t);
	~Poema ();

	void acrescentaVerso(const string& verso);
	void eliminaVerso(int ordem);

	Poema & operator=(const Poema & ob);

private:
	string titulo;
	string* pVersos;
	int nVersos;

};

Poema ::Poema (const string& t)
{
}

Poema ::~Poema ()
{
}

void Poema:: acrescentaVerso(const string& verso) {

}


Poema & Poema::operator= (const Poema & ob)
{
	if (this == &ob)
	{
		return *this;
	}
	// se os dois membros da atribuição forem objetos diferentes
	titulo = ob.titulo;
	nVersos = ob.nVersos;
	// libertar a memoria dinamica usada exclusivamente pelo primeiro membro
	delete[] pVersos;
	pVersos=nullptr;
	// se a origem da copia for de um poema sem versos
	if (ob.pVersos == nullptr || ob.nVersos == 0) {
		return *this;
	}
	// reservar memoria dinamica para conter uma copia exclusiva dos versos do segundo membro
	pVersos = new string[ob.nVersos];
	// fazer a cópia
	for  (int i = 0; i < ob.nVersos; i++)
	{
		pVersos[i] == ob.pVersos[i];
	}
	return *this;

}


int main()
{
    std::cout << "Hello World!\n";
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
