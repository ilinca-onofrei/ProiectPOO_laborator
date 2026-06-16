#include "../include/HainaLuxury.h"
#include <iostream>

HainaLuxury::HainaLuxury(const std::string &denumire,
                         const std::string &marime,
                         double pret,
                         int stoc,
                         int nivel)
    : Haina(denumire, marime, "Luxury", pret, stoc),
      nivelExclusivitate(nivel) {
}

void HainaLuxury::afiseazaSpecific() const {
    std::cout << " [Luxury] Nivel exclusivitate: "
            << nivelExclusivitate << "\n";
}

double HainaLuxury::calculeazaScorStil() const {
    return pret / 100 + nivelExclusivitate * 2;
}

Haina *HainaLuxury::clone() const {
    return new HainaLuxury(*this);
}

