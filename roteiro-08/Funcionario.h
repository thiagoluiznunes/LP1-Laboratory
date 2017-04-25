#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using namespace std;

class Funcionario {
protected:
    string nome;
    int matricula;
public:
    Funcionario(const string &nome, int mat);

    virtual ~Funcionario();
    virtual double calcularSalario() = 0;
    const string &getNome() const;
    int getMatricula() const;
};

Funcionario::Funcionario(const string &n, int mat) : nome(n), matricula(mat) {}

Funcionario::~Funcionario() {}

const string &Funcionario::getNome() const {return nome;}
int Funcionario::getMatricula() const {return matricula;}

#endif
