#include "TestaValidaNumero.h"

void TestaValidaNumero::validaNumero(const int valor) throw(ValorAbaixoException, ValorAcimaException, ValorMuitoAcimaException){
    if(valor <= 0) {
        throw ValorAbaixoException();
    }
    else if(valor > 100 && valor < 1000) {
        throw ValorAcimaException();
    }
    else if(valor >= 1000) {
        throw ValorMuitoAcimaException();
    }
}
