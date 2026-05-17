#include "../include/HainaSport.h"

HainaSport::HainaSport(const std::string &denumire_, const std::string &marime_, double pret_,
                       const std::string &activitate_, int compresie_)
    : Haina(denumire_, marime_, "Sport", pret_),
      tipActivitate{activitate_}, nivelCompresie{compresie_} {
}

double HainaSport::calculeazaScorStil() const {
    return nivelCompresie * 10;
}

void HainaSport::afiseazaSpecific() const {
    std::cout << " -> [ECHIPAMENT SPORT] Destinat: " << tipActivitate
            << " | Nivel Compresie: " << nivelCompresie << "/5\n";
}
