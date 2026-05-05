#include "../include/Promotie.h"

Promotie::Promotie(const std::string &cod, double reducere)
    : numeCod{cod}, procentReducere{reducere}, esteActiva{true} {
}

double Promotie::aplicaReducere(double pretInitial) const {
    if (esteActiva) {
        return pretInitial - (pretInitial * (procentReducere / 100.0));
    }
    return pretInitial;
}