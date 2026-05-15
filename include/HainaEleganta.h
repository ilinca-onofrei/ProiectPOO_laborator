#ifndef HAINAELEGANTA_H
#define HAINAELEGANTA_H
#include "Haina.h"

class HainaEleganta : public Haina {
private:
    std::string material;
    std::string dressCode;
public:
    HainaEleganta(const std::string& denumire_, const std::string& marime_, double pret_,
                  const std::string& material_, const std::string& dressCode_);

    Haina* clone() const override { return new HainaEleganta(*this); }
    void afiseazaSpecific() const override;
};
#endif