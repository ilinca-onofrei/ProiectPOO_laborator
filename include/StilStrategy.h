#ifndef STIL_STRATEGY_H
#define STIL_STRATEGY_H

#include <iostream>

class StilStrategy {
public:
    virtual void afiseaza() const = 0;
    virtual ~StilStrategy() = default;
};

class StilElegant : public StilStrategy {
public:
    void afiseaza() const override {
        std::cout << "Outfit elegant: rochie, pantofi, geanta.\n";
    }
};

class StilSport : public StilStrategy {
public:
    void afiseaza() const override {
        std::cout << "Outfit sport: tricou, pantaloni, adidasi.\n";
    }
};

class StilCasual : public StilStrategy {
public:
    void afiseaza() const override {
        std::cout << "Outfit casual: blugi, tricou, hanorac.\n";
    }
};

#endif