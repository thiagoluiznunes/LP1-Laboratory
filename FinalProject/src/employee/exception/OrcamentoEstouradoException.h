#ifndef ORCAMENTO_EXCEPTION_H
#define ORCAMENTO_EXCEPTION_H

#include <stdexcept>

class OrcamentoException : public runtime_error {

public:
    OrcamentoException() : runtime_error("Orçamento estourado!") {}
};

#endif
