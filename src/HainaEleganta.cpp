#include "../include/HainaEleganta.h"

HainaEleganta::HainaEleganta(const std::string &denumire_, const std::string &marime_, double pret_,
                             const std::string &material_, const std::string &dressCode_)
    : Haina(denumire_, marime_, "Elegant", pret_),
      material{material_}, dressCode{dressCode_} {
}

double HainaEleganta::calculeazaScorStil() const {
    return 50 + material.length();
}

void HainaEleganta::afiseazaSpecific() const {
    std::cout << " -> [STIL ELEGANT] Material: " << material
            << " | Recomandat pentru: " << dressCode << "\n";
}
