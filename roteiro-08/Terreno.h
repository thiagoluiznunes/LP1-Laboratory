#ifndef TERRENO_H
#define TERRENO_H

#include <string>
#include "Imovel.h"
using namespace std;

class Terreno : public Imovel {
private:
  double area;
public:
  Terreno(double area, const Endereco &end);
  const string &getDescricao() const override;
};

Terreno::Terreno(double a, const Endereco &end) : Imovel(end){
  area = a;
}
const string &Terreno::getDescricao() const {
    stringstream areaStream;
    areaStream << fixed << setprecision(2) << area;

    static string s = "";
    s = "Descrição do terreno\n" + endereco.getEnderecoString();
    s += "\nArea: " + areaStream.str();
    
    return s;
}
#endif
