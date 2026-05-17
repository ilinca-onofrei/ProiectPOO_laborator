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

class ExceptieReducere : public std::exception {
public:
    const char *what() const noexcept override {
        return "Procent de reducere invalid!";
    }
};

class ExceptieInput : public std::exception {
public:
    const char *what() const noexcept override {
        return "Input invalid!";
    }
};

#endif
