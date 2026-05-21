#include "../include/Manechin.h"

Manechin::Manechin(const std::string &nume_, const std::string &marime_)
    : numeManechin{nume_},
      marimeManechin{marime_},
      stratBaza{nullptr},
      stratExterior{nullptr},
      incaltaminte{nullptr},
      accesoriu{nullptr} {
}

const std::string& Manechin::getNume() const {
    return numeManechin;
}

const std::string& Manechin::getMarime() const {
    return marimeManechin;
}


void Manechin::incearcaHaina(Haina &h) {
    std::string nume = h.getDenumire();

    if (h.getMarime() != marimeManechin &&
        nume.find("Pantofi") == std::string::npos &&
        nume.find("Balerini") == std::string::npos &&
        nume.find("Ghete") == std::string::npos &&
        nume.find("Cizme") == std::string::npos &&
        nume.find("Slapi") == std::string::npos &&
        nume.find("Geanta") == std::string::npos &&
        nume.find("Colier") == std::string::npos &&
        nume.find("Bratara") == std::string::npos &&
        nume.find("Ceas") == std::string::npos &&
        nume.find("Esarfa") == std::string::npos &&
        nume.find("Ochelari") == std::string::npos &&
        nume.find("Palarie") == std::string::npos &&
        nume.find("Curea") == std::string::npos &&
        nume.find("Portofel") == std::string::npos &&
        nume.find("Rucsac") == std::string::npos) {
        std::cout << "Eroare: Marime incompatibila!\n";
        return;
    }

    if (nume.find("Pantofi") != std::string::npos ||
        nume.find("Balerini") != std::string::npos ||
        nume.find("Adidasi") != std::string::npos ||
        nume.find("Ghete") != std::string::npos ||
        nume.find("Cizme") != std::string::npos ||
        nume.find("Sneakers") != std::string::npos ||
        nume.find("Slapi") != std::string::npos) {
        incaltaminte = &h;
        std::cout << h.getDenumire() << " (Incaltaminte) echipata.\n";
    } else if (nume.find("Geanta") != std::string::npos ||
               nume.find("Colier") != std::string::npos ||
               nume.find("Ceas") != std::string::npos ||
               nume.find("Bratara") != std::string::npos ||
               nume.find("Palarie") != std::string::npos ||
               nume.find("Ochelari") != std::string::npos ||
               nume.find("Esarfa") != std::string::npos ||
               nume.find("Curea") != std::string::npos ||
               nume.find("Portofel") != std::string::npos ||
               nume.find("Rucsac") != std::string::npos) {
        accesoriu = &h;
        std::cout << h.getDenumire() << " (Accesoriu) adaugat.\n";
    } else if (nume.find("Geaca") != std::string::npos ||
               nume.find("Palton") != std::string::npos ||
               nume.find("Cardigan") != std::string::npos ||
               nume.find("Hanorac") != std::string::npos ||
               nume.find("Sacou") != std::string::npos) {
        stratExterior = &h;
        std::cout << h.getDenumire() << " (Exterior) echipata.\n";
    } else {
        stratBaza = &h;
        std::cout << h.getDenumire() << " (Baza) echipata.\n";
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