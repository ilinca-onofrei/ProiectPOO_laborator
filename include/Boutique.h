#ifndef BOUTIQUE_H
#define BOUTIQUE_H

#include <string>
#include <vector>
#include <iostream>
#include "Adresa.h"
#include "Manechin.h"
#include "Haina.h"

class Boutique {
private:
    std::string numeMagazin;
    Adresa locatie;
    Manechin &vitrina;
    std::vector<Haina> inventar;

public:
    Boutique(const std::string &nume_, const Adresa &adr_, Manechin &m_);

    Haina &getHainaDinInventar(int idx);

    void adaugaHainaInStoc(const Haina &h);

    void afiseazaStocComplet() const;

    void afiseazaHaineDupaCategorie(const std::string &catCautata) const;

    void recomandaAccesoriu(const Haina &hainaAleasa) const;

    size_t getNrHaineInventar() const;

    friend std::ostream &operator<<(std::ostream &os, const Boutique &b);
};

#endif