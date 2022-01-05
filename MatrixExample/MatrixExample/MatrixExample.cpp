// MatrixExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

using namespace std;

//void print(const Matrix& m);

class Matrix{
 private:
    const int Linhas;
    const int Colunas;
    double* valores;

    // retorna a referência para a variável permite assim a atribuição fora, 
    // como um ponteiro mas automaticamente dereferenced
 
    // VER: https://www.cplusplus.com/articles/2LywvCM9/ para inline funtions
    inline double& preencheAt(int r, int c) const
    {
        return valores[Colunas * r + c];
    }

public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& m);
    ~Matrix();
    inline int linhas(void) const { return Linhas; } // const metodo não pode
    inline int colunas(void) const { return Colunas; } 
    void preencherAleatoriamente(void);
    double getValueAt(int r, int c) const;
    void setValueAt(double v, int r, int c);
};

Matrix::Matrix(int rows, int cols) : Linhas(rows), Colunas(cols)
{
    valores = new double[Linhas * Colunas];
}

Matrix::Matrix(const Matrix& m) : Linhas(m.Linhas), Colunas(m.Colunas)
{ // copy constructor
    valores = new double[Linhas * Colunas];
    for (int i = 0; i < Linhas * Colunas; ++i) {
        valores[i] = m.valores[i];
    }
}
// Tarefa ?  criar o operador = para cópia do construtor


Matrix::~Matrix()
{
    delete[] valores;
}

void Matrix::preencherAleatoriamente(void)
{
    for (int r = 0; r < Linhas; ++r) {
        for (int c = 0; c < Colunas; ++c) {
            preencheAt(r, c) = (rand() % 100) / 10.0; // set valores[COLUNAS * r + c]
        }
    }

}

double Matrix::getValueAt(int r, int c) const
{
    if (r < 0 or r >= Linhas or c < 0 or c >= Colunas) {
        throw out_of_range("Out of range --> Matrix::getValueAt");
    }
    return preencheAt(r, c);
}
void Matrix::setValueAt(double v, int r, int c)
{
    if (r < 0 or r >= Linhas or c < 0 or c >= Colunas) {
        throw out_of_range("Out of range --> Matrix::setValueAt");
    }
    preencheAt(r, c) = v;
}

void imprimirMatrix(const Matrix& m)
{
    //cout << fixed << setprecision(2);
    for (int r = 0; r < m.linhas(); ++r) {
        for (int c = 0; c < m.colunas(); ++c) {
            cout << (c > 0 ? " " : "") << setw(4); // setw(int n) Sets the field width to be used on output operations.
            cout << m.getValueAt(r, c);
        }
        cout << endl;
    }
}

int main()
{
    int ret = 0;
    try {
        Matrix m1(3, 3);
        m1.preencherAleatoriamente();
        
        // m1.setValueAt(10.22, 0, 1);
         m1.setValueAt(10.5, 2, 3); // coluna 3 permite a lançar a excepção (exception)

        imprimirMatrix(m1);

        cout << "Copia por Construtor" << endl;
        Matrix m2(m1);
        imprimirMatrix(m2);


    }
    catch (out_of_range& e) {
        cout << "Erro: " << e.what() << endl;
        ret = -1;
    }
    return ret;

}
