#pragma once
#include "Haina.h"

class HainaLuxury : public Haina {
    int nivelExclusivitate;

public:
    HainaLuxury(const std::string &denumire,
                const std::string &marime,
                double pret,
                int stoc,
                int nivel);

    void afiseazaSpecific() const override;

    double calculeazaScorStil() const override;

    Haina *clone() const override;
};
