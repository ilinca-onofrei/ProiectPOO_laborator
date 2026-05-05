#include "../include/Adresa.h"

Adresa::Adresa(const std::string &oras_, const std::string &strada_, int numar_)
    : oras{oras_}, strada{strada_}, numar{numar_} {
}

std::ostream &operator<<(std::ostream &os, const Adresa &a) {
    os << a.strada << " nr. " << a.numar << " , " << a.oras;
    return os;
}