// CopiaConstrutor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Poema 
{

public:
	Poema (const Poema& ob);
	Poema(const string & Verso);
	~Poema ();

	void acrescentaVerso(const string& verso);
	void eliminaVerso(int ordem);

	Poema & operator=(const Poema & ob);

	string GetAsString()
	{
		ostringstream b;
		b << "titulo: " << titulo << "\n";
		return b.str();
	}

private:
	string titulo;
	string* pVersos;
	int nVersos;

};

Poema::Poema(const string& tVerso) : titulo(tVerso)
{
	
}

/*
Poema ::Poema (const Poema& ob): titulo (ob.titulo), nVersos (ob.nVersos)
{
	if (ob.pVersos == nullptr || ob.nVersos == 0)
	{
		pVersos = nullptr;
		return;
	}

	pVersos = new string[ob.nVersos];

	for (int i = 0; i < nVersos; i++)
	{
		pVersos[i] = ob.pVersos[i];
	}

}*/

Poema::Poema(const Poema& ob): pVersos(nullptr) {
	*this = ob;

}

Poema ::~Poema ()
{
}

void Poema:: acrescentaVerso(const string& verso) 
{
	string* aux = new string[nVersos + 1];
	
	for (int i = 0; i < nVersos; i++) {
		aux[i] = pVersos[i];
	}

	aux[nVersos] = verso;
	++nVersos;
	delete[] pVersos;
	pVersos = aux;

}


Poema & Poema::operator= (const Poema & ob)
{
	if (this == &ob) // prevencao de auto-atribuicao
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


void Poema::eliminaVerso(int ordem)
{
	if (ordem < 0 || ordem >= nVersos) { return; }
	if (nVersos == 1)
	{
		delete[] pVersos;
		pVersos = nullptr;
		nVersos = 0;
		return;
	}

	string* aux = new string[nVersos - 1];

	for (int i; i < ordem; ++i)
	{
		aux[i] = pVersos[i];
	}

	for (int i = ordem; i < nVersos - 1; ++i)
	{
		aux[i] = pVersos[i + 1];
	}
	--nVersos;
	delete[] pVersos;
	pVersos = aux;

}

int main()
{
	cout << "Construtor por Cópia \n";
	Poema a("Os Lusiados");
	Poema b("Liberdade");
	//Poema b (a);

	Poema c = b;

	c = a;

	cout << c.GetAsString();

	cout << a.GetAsString();


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
