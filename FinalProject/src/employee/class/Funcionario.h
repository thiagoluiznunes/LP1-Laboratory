#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
protected:
    std::string nome;
    int matricula;
public:
    Funcionario(const std::string &nome, int mat);

    virtual ~Funcionario();
    virtual double calcularSalario() = 0;
    const std::string &getNome() const;
    int getMatricula() const;
};

Funcionario::Funcionario(const std::string &n, int mat) : nome(n), matricula(mat) {}

Funcionario::~Funcionario() {}

const std::string &Funcionario::getNome() const {return nome;}
int Funcionario::getMatricula() const {return matricula;}

#endif
