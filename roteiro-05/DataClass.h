#include <iostream>
#include <stdexcept>
using namespace std;

#define MIN_DIA 1
#define MAX_DIA 30
#define MIN_MES 1
#define MAX_MES 12
#define MIN_ANO 1
#define MAX_ANO 2017

class DataClass {

private:
  int dia, mes, ano;

public:
  DataClass(int dia, int mes, int ano);

  void setDia(int dia);
  void setMes(int mes);
  void setAno(int ano);
  void avancarDia(void);

  int getDia(void);
  int getMes(void);
  int getAno(void);

};

DataClass::DataClass(int dia, int mes, int ano) {
  if(dia < MIN_DIA || dia > MAX_DIA){
    throw invalid_argument("Dia invalido!");
  }
  if(mes < MIN_MES || mes > MAX_MES){
    throw invalid_argument("Mês invalido!");
  }
  if(ano < MIN_ANO || ano > MAX_ANO){
    throw invalid_argument("Ano invalido!");
  }

  DataClass::dia = dia;
  DataClass::mes = mes;
  DataClass::ano = ano;

  cout << '\n' << "Object is being created." << '\n';
}
/*Methods Set and Void*/
void DataClass::setDia(int novoDia){
  DataClass::dia = novoDia;
}
void DataClass::setMes(int novoMes){
  DataClass::mes = novoMes;
}
void DataClass::setAno(int novoAno){
  DataClass::ano = novoAno;
}
void DataClass::avancarDia(void){
  if(dia < MAX_DIA){
    dia++;
  }
  else{
    DataClass::dia = 1;
    if(DataClass::mes < MAX_MES){
      DataClass::mes++;
    }
    else{
      DataClass::mes = 1;
      DataClass::ano++;
    }
  }
}
/*Methods Get*/
int DataClass::getDia(void){
  return DataClass::dia;
}
int DataClass::getMes(void){
  return DataClass::mes;
}
int DataClass::getAno(void){
  return DataClass::ano;
}
