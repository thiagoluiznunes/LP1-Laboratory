#include <iostream>
#include "TestaValidaNumero.h"

int main(int argc, char const *argv[]) {

    TestaValidaNumero validador;

    try {
        validador.validaNumero(0);
    }
    catch (ValorAbaixoException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        validador.validaNumero(101);
    }
    catch (ValorAcimaException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        validador.validaNumero(1000);
    }
    catch (std::runtime_error &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
