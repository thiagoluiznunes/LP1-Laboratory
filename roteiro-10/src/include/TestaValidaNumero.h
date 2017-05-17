#ifndef INCLUDE_TESTA_VALIDA_H
#define INCLUDE_TESTA_VALIDA_H

#include <stdexcept>
#include "ValorAbaixoException.h"
#include "ValorAcimaException.h"
#include "ValorMuitoAcimaException.h"

class TestaValidaNumero {

public:
    void validaNumero(const int valor) throw(ValorAbaixoException, ValorAcimaException, ValorMuitoAcimaException);
};


#endif
