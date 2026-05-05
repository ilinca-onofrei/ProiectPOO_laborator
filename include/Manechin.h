#ifndef MANECHIN_H
#define MANECHIN_H

#include <string>
#include <iostream>
#include "Haina.h"

class Manechin {
private:
    std::string numeManechin;
    std::string marimeManechin;
    Haina *stratBaza;
    Haina *stratExterior;
    Haina *incaltaminte;
    Haina *accesoriu;

public:
    Manechin(const std::string &nume_, const std::string &marime_);

    void incearcaHaina(Haina &h);

    double getValoareTinuta() const;

    void dezbracaManechin();

    Haina *getStratBaza() const;

    Haina *getStratExterior() const;

    Haina *getIncaltaminte() const;

    Haina *getAccesoriu() const;

    friend std::ostream &operator<<(std::ostream &os, const Manechin &m);
};

#endif