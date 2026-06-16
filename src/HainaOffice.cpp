#include "../include/HainaOffice.h"

HainaOffice::HainaOffice(const std::string &denumire_, const std::string &marime_, double pret_,
                         bool curatare_, int formalitate_)
    : Haina(denumire_, marime_, "Office", pret_),
      necesitaCuratareChimica{curatare_}, gradFormalitate{formalitate_} {
}

double HainaOffice::calculeazaScorStil() const {
    return gradFormalitate * 8;
}

void HainaOffice::afiseazaSpecific() const {
    std::cout << " -> [BUSINESS] Grad Formalitate: " << gradFormalitate << "/10 | "
            << (necesitaCuratareChimica ? "Necesita curatare chimica." : "Se poate spala acasa.") << "\n";
}


