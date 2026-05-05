#ifndef CLIENTA_H
#define CLIENTA_H

#include <string>
#include <vector>
#include <iostream>
#include "Haina.h"
#include "Manechin.h"

class Clienta {
private:
    std::string nume;
    double buget;
    int puncteLoialitate;
    std::vector<Haina> haineCumparate;

public:
    Clienta(const std::string &nume_, double buget_);

    bool poateCumpara(double total) const;

    void finalizeazaAchizitie(double total, const Manechin &m);

    double getBuget() const;

    void tiparesteBon(double total, const std::string &codPromo) const;

    std::string getNivelFidelitate() const;

    double aplicaReducereFidelitate(double suma) const;

    void afiseazaGarderoba() const;

    friend std::ostream &operator<<(std::ostream &os, const Clienta &c);
};

#endif