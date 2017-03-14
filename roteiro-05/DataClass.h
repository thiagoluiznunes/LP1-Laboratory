#include <iostream>
using namespace std;

#define MAX_DIA 30
#define MIN_DIA 1

class DataClass {

public:
  DataClass(int dia, int mes, int ano);

  void setDia(int dia);
  void setMes(int mes);
  void setAno(int ano);
  void avancarDia(void);

  int getDia(void);
  int getMes(void);
  int getAno(void);

private:
  int dia, mes, ano;
};

DataClass::DataClass(int dia, int mes, int ano){
  cout << "Object is being created." << '\n';
  DataClass::dia = dia;
  DataClass::mes = mes;
  DataClass::ano = ano;
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
    dia = 1;
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
