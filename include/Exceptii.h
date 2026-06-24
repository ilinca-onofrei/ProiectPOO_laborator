#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>

// baza comuna pentru toate exceptiile !!!!
class ExceptieMagazin : public std::exception {
public:
    const char* what() const noexcept override {
        return "Exceptie generala magazin!";
    }
};

class ExceptieStoc : public ExceptieMagazin {
public:
    const char* what() const noexcept override {
        return "Stoc epuizat!";
    }
};

class ExceptieBuget : public ExceptieMagazin {
public:
    const char* what() const noexcept override {
        return "Fonduri insuficiente!";
    }
};

class ExceptieIndex : public ExceptieMagazin {
public:
    const char* what() const noexcept override {
        return "Index invalid!";
    }
};

class ExceptieReducere : public ExceptieMagazin {
public:
    const char* what() const noexcept override {
        return "Procent de reducere invalid!";
    }
};

class ExceptieInput : public ExceptieMagazin {
public:
    const char* what() const noexcept override {
        return "Input invalid!";
    }
};

#endif