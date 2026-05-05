#ifndef ISTORICVANZARI_H
#define ISTORICVANZARI_H

#include <vector>
#include <iostream>
#include "Haina.h"
#include "Manechin.h"

class IstoricVanzari {
private:
    std::vector<Haina> haineVandute;
    int numarTotalVanzari;
    double venitTotal;

public:
    IstoricVanzari();

    void inregistreazaTranzactie(double suma, const Manechin &m);

    void afiseazaRaportComplet() const;
};

#endif