#include "../include/Manechin.h"

Manechin::Manechin(const std::string &nume_, const std::string &marime_)
    : numeManechin{nume_},
      marimeManechin{marime_},
      stratBaza{nullptr},
      stratExterior{nullptr},
      incaltaminte{nullptr},
      accesoriu{nullptr} {
}

void Manechin::incearcaHaina(Haina &h) {
    if (h.getMarime() != marimeManechin) {
        std::cout << "Eroare: Marime incompatibila!\n";
        return;
    }
    if (h.getCategorie() == "Baza") {
        stratBaza = &h;
        std::cout << h.getDenumire() << " (Baza) echipata.\n";
    } else if (h.getCategorie() == "Exterior") {
        if (stratBaza == nullptr) std::cout << "Eroare: Pune intai ceva pe dedesubt!\n";
        else {
            stratExterior = &h;
            std::cout << h.getDenumire() << " (Exterior) echipat.\n";
        }
    } else if (h.getCategorie() == "Incaltaminte") {
        if (stratBaza == nullptr) std::cout << "Eroare: Nu poti proba pantofi fara haine!\n";
        else {
            incaltaminte = &h;
            std::cout << h.getDenumire() << " (Incaltaminte) echipata.\n";
        }
    } else if (h.getCategorie() == "Accesoriu") {
        accesoriu = &h;
        std::cout << h.getDenumire() << " (Accesoriu) adaugat.\n";
    }
}

double Manechin::getValoareTinuta() const {
    double total = 0;
    if (stratBaza) total += stratBaza->getPret();
    if (stratExterior) total += stratExterior->getPret();
    if (incaltaminte) total += incaltaminte->getPret();
    if (accesoriu) total += accesoriu->getPret();
    return total;
}

void Manechin::dezbracaManechin() {
    stratBaza = nullptr;
    stratExterior = nullptr;
    incaltaminte = nullptr;
    accesoriu = nullptr;
    std::cout << "Manechinul " << numeManechin << " a fost dezbracat complet.\n";
}

Haina *Manechin::getStratBaza() const { return stratBaza; }
Haina *Manechin::getStratExterior() const { return stratExterior; }
Haina *Manechin::getIncaltaminte() const { return incaltaminte; }
Haina *Manechin::getAccesoriu() const { return accesoriu; }

std::ostream &operator<<(std::ostream &os, const Manechin &m) {
    os << "Manechin: " << m.numeManechin << " (" << m.marimeManechin << ")\n";
    os << "  -> Strat Baza: " << (m.stratBaza ? m.stratBaza->getDenumire() : "GOL") << "\n";
    os << "  -> Strat Exterior: " << (m.stratExterior ? m.stratExterior->getDenumire() : "GOL") << "\n";
    os << "  -> Incaltaminte: " << (m.incaltaminte ? m.incaltaminte->getDenumire() : "GOL") << "\n";
    os << "  -> Accesoriu: " << (m.accesoriu ? m.accesoriu->getDenumire() : "GOL");
    return os;
}