#include "../include/HainaCasual.h"

HainaCasual::HainaCasual(const std::string &denumire_, const std::string &marime_, double pret_,
                         const std::string &sezon_, bool gluga_)
    : Haina(denumire_, marime_, "Casual", pret_),
      sezon{sezon_}, areGluga{gluga_} {
}

double HainaCasual::calculeazaScorStil() const {
    return areGluga ? 20 : 10;
}

void HainaCasual::afiseazaSpecific() const {
    std::cout << " -> [CASUAL] Sezon recomandat: " << sezon
            << " | Caracteristica: " << (areGluga ? "Cu gluga" : "Fara gluga") << "\n";
}


