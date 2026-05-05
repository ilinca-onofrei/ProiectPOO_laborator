#ifndef ADRESA_H
#define ADRESA_H

#include <string>
#include <iostream>

class Adresa {
private:
    std::string oras;
    std::string strada;
    int numar;

public:
    Adresa(const std::string &oras_, const std::string &strada_, int numar_);

    friend std::ostream &operator<<(std::ostream &os, const Adresa &a);
};

#endif