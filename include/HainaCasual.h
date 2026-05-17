#ifndef HAINACASUAL_H
#define HAINACASUAL_H
#include "Haina.h"

class HainaCasual : public Haina {
private:
    std::string sezon;
    bool areGluga;

public:
    HainaCasual(const std::string &denumire_, const std::string &marime_, double pret_,
                const std::string &sezon_, bool gluga_);

    Haina *clone() const override { return new HainaCasual(*this); }

    void afiseazaSpecific() const override;

    double calculeazaScorStil() const override;
};
#endif
