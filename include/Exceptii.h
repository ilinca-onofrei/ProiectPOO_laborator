#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>

class ExceptieStoc : public std::exception {
public:
    const char *what() const noexcept override {
        return "Stoc epuizat!";
    }
};

class ExceptieBuget : public std::exception {
public:
    const char *what() const noexcept override {
        return "Fonduri insuficiente!";
    }
};

class ExceptieIndex : public std::exception {
public:
    const char *what() const noexcept override {
        return "Index invalid!";
    }
};

#endif
