#ifndef HAINAOFFICE_H
#define HAINAOFFICE_H
#include "Haina.h"

class HainaOffice : public Haina {
private:
    bool necesitaCuratareChimica;
    int gradFormalitate; // 1-10
public:
    HainaOffice(const std::string &denumire_, const std::string &marime_, double pret_,
                bool curatare_, int formalitate_);

    Haina *clone() const override { return new HainaOffice(*this); }

    void afiseazaSpecific() const override;
    double calculeazaScorStil() const override;
};
#endif
