#ifndef PROMOTIE_H
#define PROMOTIE_H

#include <string>
#include <iostream>

class Promotie {
private:
    std::string numeCod;
    double procentReducere;
    bool esteActiva;

public:
    Promotie(const std::string &cod, double reducere);

    double aplicaReducere(double pretInitial) const;

    friend std::ostream &operator<<(std::ostream &os, const Promotie &p) {
        os << "Cod Promotie: " << p.numeCod << " (-" << p.procentReducere << "%) "
                << (p.esteActiva ? "[ACTIV]" : "[EXPIRAT]");
        return os;
    }
};

#endif