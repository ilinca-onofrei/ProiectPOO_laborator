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
    std::vector<Haina *> inventar;

public:
    Boutique(const std::string &nume_, const Adresa &adr_, Manechin &m_);

    ~Boutique();

    Haina &getHainaDinInventar(int idx);

    void adaugaHainaInStoc(const Haina &h);

    void afiseazaStocComplet() const;

    void afiseazaHaineDupaCategorie(const std::string &catCautata) const;

    void recomandaAccesoriu(const Haina &hainaAleasa) const;

    size_t getNrHaineInventar() const;

    void afiseazaCeaMaiBunaHaina() const;

    void afiseazaHaineSubPret(double pretMaxim) const;

    void afiseazaHaineSortateDupaPret() const;

    double calculeazaPretMediu() const;

    void afiseazaCategoriaDominanta() const;

    void setManechin(const Manechin &m);

    friend std::ostream &operator<<(std::ostream &os, const Boutique &b);

    void afiseazaHaineSortateDesc() const;

    void afiseazaHaineSortateDupaRating() const;

    // COPY CONSTRUCTOR
    Boutique(const Boutique &other);

    // OPERATOR (copy & swap)
    Boutique &operator=(Boutique other);

    // functie helper pentru swap
    friend void swap(Boutique &a, Boutique &b) noexcept;

    Manechin &getManechin();

    void cautaHaineDupaNume(const std::string &text) const;
};

#endif