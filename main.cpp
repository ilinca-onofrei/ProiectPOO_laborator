#include <iostream>
#include <array>
#include "include/Example.h"
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"
#include <iostream>
#include <array>
#include <vector>
#include <string>

class Adresa {
private:
    std::string oras;
    std::string strada;
    int numar;

public:
    Adresa(std::string oras_, std::string strada_, int numar_)
        : oras{oras_}, strada{strada_}, numar{numar_} {
    }

    friend std::ostream &operator<<(std::ostream &os, const Adresa &a) {
        os << a.strada << " nr. " << a.numar << " , " << a.oras;
        return os;
    }
};

class Haina {
private:
    std::string denumire;
    std::string marime;
    std::string categorie;
    double pret;

public:
    Haina(std::string denumire_, std::string marime_, std::string categorie_, double pret_)
        : denumire{denumire_}, marime{marime_}, categorie{categorie_}, pret{pret_} {
        std::cout << "S a creat haina: " << denumire << "\n";
    }

    std::string getCategorie() const { return categorie; }
    std::string getMarime() const { return marime; }
    double getPret() const { return pret; }
    std::string getDenumire() const { return denumire; }

    Haina(const Haina &other)
        : denumire{other.denumire}, marime{other.marime}, pret{other.pret} {
        std::cout << "CC Haina: S a copiat " << denumire << "\n";
    }

    Haina &operator=(const Haina &other) {
        if (this != &other) {
            denumire = other.denumire;
            marime = other.marime;
            pret = other.pret;
        }
        std::cout << "op=Haina: S a atribuit " << denumire << "\n";
        return *this; // AICI SE RETURNEAZA REFERINTA
    }

    ~Haina() {
        std::cout << "Destructorul Haina: " << denumire << " a fost distrus.\n";
    }

    void aplicaDiscount(double procent) {
        if (procent > 0 && procent <= 100) {
            pret -= pret * (procent / 100.0);
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Haina &h) {
        os << h.denumire << " (" << h.marime << ") - " << h.pret << " lei";
        return os;
    }
};

class Manechin {
private:
    std::string numeManechin;
    std::string marimeManechin;
    Haina *stratBaza;
    Haina *stratExterior;

public:
    Manechin(std::string nume_, std::string marime_)
        : numeManechin{nume_}, marimeManechin{marime_}, stratBaza{nullptr}, stratExterior{nullptr} {
    }

    void incearcaHaina(Haina &h) {
        if (h.getMarime() != marimeManechin) {
            std::cout << "Eroare: Haina " << h.getDenumire() << " este marimea " << h.getMarime()
                    << ", dar manechinul este " << marimeManechin << "!\n";
            return;
        }

        if (h.getCategorie() == "Baza") {
            stratBaza = &h;
            std::cout << h.getDenumire() << " a fost pusa ca strat de baza.\n";
        } else if (h.getCategorie() == "Exterior") {
            if (stratBaza == nullptr) {
                std::cout << "Atentie: Nu poti pune " << h.getDenumire() <<
                        " (exterior) pe un manechin fara haine de baza!\n";
            } else {
                stratExterior = &h;
                std::cout << h.getDenumire() << " a fost pusa peste stratul de baza.\n";
            }
        }
    }

    double getValoareTinuta() const {
        double total = 0;
        if (stratBaza != nullptr) total += stratBaza->getPret();
        if (stratExterior != nullptr) total += stratExterior->getPret();
        return total;
    }

    void dezbracaManechin() {
        stratBaza = nullptr;
        stratExterior = nullptr;
        std::cout << "Manechinul " << numeManechin << " a fost dezbracat complet.\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Manechin &m) {
        os << "Manechinul " << m.numeManechin << " (" << m.marimeManechin << ") poarta:\n";
        if (m.stratBaza == nullptr && m.stratExterior == nullptr) {
            os << "  - Nimic (dezbracat)";
        } else {
            if (m.stratBaza != nullptr) os << "  - Baza: " << *m.stratBaza << "\n";
            if (m.stratExterior != nullptr) os << "  - Exterior: " << *m.stratExterior;
        }
        return os;
    }
};

class Boutique {
private:
    std::string numeMagazin;
    Adresa locatie;
    Manechin vitrina;
    std::vector<Haina> inventar;

public:
    Boutique(std::string nume_, const Adresa &adr_, const Manechin &m_)
        : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {
    }

    void adaugaHainaInStoc(const Haina &h) {
        inventar.push_back(h);
        std::cout << "Haina '" << h.getDenumire() << "' a fost adaugata in stoc.\n";
    }

    void afiseazaStocComplet() const {
        std::cout << "\n*** Inventar Complet " << numeMagazin << " ***\n";
        if (inventar.empty()) {
            std::cout << "Stocul este gol!\n";
        } else {
            for (const auto &h: inventar) {
                std::cout << "- " << h << "\n";
            }
        }
    }

    void verificareDisponibilitateBuget(double buget) const {
        double pretTinuta = vitrina.getValoareTinuta();
        std::cout << "\n*** Verificare Buget Clienta ***\n";
        if (buget >= pretTinuta) {
            std::cout << "Succes! Puteti cumpara tinuta. Restul dvs: "
                    << buget - pretTinuta << " lei.\n";
        } else {
            std::cout << "Ne pare rau, mai aveti nevoie de "
                    << pretTinuta - buget << " lei pentru aceasta tinuta.\n";
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Boutique &b) {
        os << "***" << b.numeMagazin << "***\n";
        os << "Locatie: " << b.locatie << "\n";
        os << "In vitrina: " << b.vitrina << "\n";
        return os;
    }
};

int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    Haina h1{"Tricou Bumbac", "M", "Baza", 60.0};
    Haina h2{"Rochie Eleganta", "M", "Baza", 300.0};
    Haina h3{"Sacou Office", "M", "Exterior", 200.0};
    Haina h4{"Palton", "S", "Exterior", 450.0};
    Manechin man{"Anna", "M"};
    Boutique shop{"ChicAtelier", adr, man};
    man.incearcaHaina(h3);
    man.incearcaHaina(h2);
    man.incearcaHaina(h3);
    man.incearcaHaina(h4);
    shop.adaugaHainaInStoc(h1);
    shop.adaugaHainaInStoc(h2);
    shop.adaugaHainaInStoc(h3);
    shop.adaugaHainaInStoc(h4);
    shop.afiseazaStocComplet();
    std::cout << "\n" << shop << "\n";
    shop.verificareDisponibilitateBuget(600.0);
    man.dezbracaManechin();
    std::cout << "\nStare magazin dupa resetare:\n" << shop << "\n";
    return 0;
}
