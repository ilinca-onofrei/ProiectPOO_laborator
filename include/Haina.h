#ifndef HAINA_H
#define HAINA_H

#include <string>
#include <vector>
#include <iostream>

class Haina {
private:
    static int contorId;
    int id;
    std::string denumire;
    std::string marime;
    std::string categorie;
    double pret;
    std::vector<int> recenzii;
    int stocActual;
    bool discountWeekendAplicat;

public:
    Haina(const std::string &denumire_, const std::string &marime_, const std::string &categorie_, double pret_,
          int stoc_ = 3);

    Haina(const Haina &other);

    Haina &operator=(const Haina &other);

    ~Haina();

    const std::string &getCategorie() const;

    const std::string &getMarime() const;

    double getPret() const;

    const std::string &getDenumire() const;

    int getId() const;

    int getStocActual() const;

    int getNrRecenzii() const;

    double getMediaRecenziilor() const;

    void aplicaDiscount(double procent);

    void adaugaRecenzie(int nota);

    void scadeStoc();

    friend std::ostream &operator<<(std::ostream &os, const Haina &h);
};

#endif