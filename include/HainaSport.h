#ifndef HAINASPORT_H
#define HAINASPORT_H
#include "Haina.h"

class HainaSport : public Haina {
private:
    std::string tipActivitate;
    int nivelCompresie;
public:
    HainaSport(const std::string& denumire_, const std::string& marime_, double pret_,
                const std::string& activitate_, int compresie_);

    Haina* clone() const override { return new HainaSport(*this); }
    void afiseazaSpecific() const override;
};
#endif