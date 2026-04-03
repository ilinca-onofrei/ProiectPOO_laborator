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
    std::vector<int> recenzii;

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
        : denumire{other.denumire}, marime{other.marime},
          categorie{other.categorie}, pret{other.pret}, recenzii{other.recenzii} {
        std::cout << "CC Haina: S a copiat " << denumire << "\n";
    }

    Haina &operator=(const Haina &other) {
        if (this != &other) {
            denumire = other.denumire;
            marime = other.marime;
            pret = other.pret;
            categorie = other.categorie;
            recenzii = other.recenzii;
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

    void adaugaRecenzie(int nota) {
        if (nota >= 1 && nota <= 5) {
            recenzii.push_back(nota);
            std::cout << "Recenzie de " << nota << " stele adaugata pentru " << denumire << ".\n";
        }
    }

    double getMediaRecenziilor() const {
        if (recenzii.empty()) return 0.0;
        double suma = 0;
        for (int r: recenzii) suma += r;
        return suma / recenzii.size();
    }
};

class Manechin {
private:
    std::string numeManechin;
    std::string marimeManechin;
    Haina *stratBaza;
    Haina *stratExterior;
    Haina *incaltaminte;
    Haina *accesoriu;

public:
    Manechin(std::string nume_, std::string marime_)
        : numeManechin{nume_},
          marimeManechin{marime_},
          stratBaza{nullptr},
          stratExterior{nullptr},
          incaltaminte{nullptr},
          accesoriu{nullptr} {
    }

    void incearcaHaina(Haina &h) {
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

    double getValoareTinuta() const {
        double total = 0;
        if (stratBaza) total += stratBaza->getPret();
        if (stratExterior) total += stratExterior->getPret();
        if (incaltaminte) total += incaltaminte->getPret();
        if (accesoriu) total += accesoriu->getPret();
        return total;
    }

    void dezbracaManechin() {
        stratBaza = nullptr;
        stratExterior = nullptr;
        incaltaminte = nullptr; // Reset pt noul slot
        accesoriu = nullptr;    // Reset pt noul slot
        std::cout << "Manechinul " << numeManechin << " a fost dezbracat complet.\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const Manechin &m) {
        os << "Manechin: " << m.numeManechin << " (" << m.marimeManechin << ")\n";
        os << "  -> Strat Baza: " << (m.stratBaza ? m.stratBaza->getDenumire() : "GOL") << "\n";
        os << "  -> Strat Exterior: " << (m.stratExterior ? m.stratExterior->getDenumire() : "GOL") << "\n";
        os << "  -> Incaltaminte: " << (m.incaltaminte ? m.incaltaminte->getDenumire() : "GOL") << "\n";
        os << "  -> Accesoriu: " << (m.accesoriu ? m.accesoriu->getDenumire() : "GOL");
        return os;
    }
};

class Boutique {
private:
    std::string numeMagazin;
    Adresa locatie;
    Manechin &vitrina;
    std::vector<Haina> inventar;

public:
    Boutique(std::string nume_, const Adresa& adr_, Manechin& m_)
        : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {
    }

    Haina &getHainaDinInventar(int idx) {
        return inventar[idx];
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
public:
    void afiseazaHaineDupaCategorie(std::string catCautata) const {
        std::cout << "\n--- Rezultate cautare pentru categoria: " << catCautata << " ---\n";
        bool gasit = false;
        for (const auto &h: inventar) {
            if (h.getCategorie() == catCautata) {
                std::cout << "- " << h << " (Media review-uri: " << h.getMediaRecenziilor() << ")\n";
                gasit = true;
            }
        }
        if (!gasit) std::cout << "Nu am gasit haine in aceasta categorie.\n";
    }
};

class Clienta {
private:
    std::string nume;
    double buget;
    int puncteLoialitate;
    std::vector<std::string> haineCumparate;
public:
    Clienta(std::string nume_, double buget_): nume{nume_}, buget{buget_}, puncteLoialitate{0} {}
    bool poateCumpara(double total) const {
        return buget >= total;
    }
    void finalizeazaAchizitie(double total, const Manechin& m) {
        buget -= total;
        puncteLoialitate += static_cast<int>(total / 10); // 1 punct la fiecare 10 lei
        haineCumparate.push_back("Outfit Complet");
        std::cout << "Achizitie reusita! " << nume << " mai are " << buget << " lei si " << puncteLoialitate << " puncte.\n";
    }
    double getBuget() const {
        return buget;
    }
    friend std::ostream& operator<<(std::ostream& os, const Clienta& c) {
        os << "Clienta: " << c.nume << " | Buget: " << c.buget << " lei | Puncte: " << c.puncteLoialitate;
        return os;
    }
};

class Promotie {
private:
    std::string numeCod;
    double procentReducere;
    bool esteActiva;

public:
    Promotie(std::string cod, double reducere)
        : numeCod{cod}, procentReducere{reducere}, esteActiva{true} {}

    double aplicaReducere(double pretInitial) const {
        if (esteActiva) {
            return pretInitial - (pretInitial * (procentReducere / 100.0));
        }
        return pretInitial;
    }

    void dezactiveaza() {
        esteActiva = false;
    }

    friend std::ostream& operator<<(std::ostream& os, const Promotie& p) {
        os << "Cod Promotie: " << p.numeCod << " (-" << p.procentReducere << "%) "
           << (p.esteActiva ? "[ACTIV]" : "[EXPIRAT]");
        return os;
    }
};
int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    Manechin man{"Anna", "M"};
    Boutique shop{"ChicAtelier", adr, man};
    Clienta cl{"Ilinca", 2000.0};
    Promotie promo10{"SPRING10", 10.0};
    std::vector<Haina> stocDisponibil = {
        // BAZA (Index 0-3)
        Haina{"Tricou Bumbac Basic", "M", "Baza", 60.0},
        Haina{"Rochie Eleganta de Seara", "M", "Baza", 350.0},
        Haina{"Camasa Oxford Alba", "M", "Baza", 120.0},
        Haina{"Blugi Slim Fit", "M", "Baza", 180.0},

        // EXTERIOR (Index 4-7)
        Haina{"Sacou Office Negru", "M", "Exterior", 250.0},
        Haina{"Geaca de Piele Rock", "M", "Exterior", 400.0},
        Haina{"Palton de Lana", "M", "Exterior", 550.0},
        Haina{"Cardigan Impletit", "S", "Exterior", 150.0}, // Test eroare marime

        // INCALTAMINTE (Index 8-12)
        Haina{"Adidasi Sport Albi", "M", "Incaltaminte", 320.0},
        Haina{"Pantofi Stiletto Rosii", "M", "Incaltaminte", 450.0},
        Haina{"Balerini Casual", "M", "Incaltaminte", 130.0},
        Haina{"Slapi de Plaja", "M", "Incaltaminte", 45.0},
        Haina{"Ghete de Toamna", "M", "Incaltaminte", 380.0},

        // ACCESORII (Index 13-17)
        Haina{"Palarie Fedora", "M", "Accesoriu", 110.0},
        Haina{"Ochelari de Soare RayBan", "M", "Accesoriu", 620.0},
        Haina{"Colier Argint cu Cristal", "M", "Accesoriu", 280.0},
        Haina{"Geanta de Mana Piele", "M", "Accesoriu", 500.0},
        Haina{"Esarfa de Matase", "M", "Accesoriu", 75.0}
    };

    for (const auto &h: stocDisponibil) {
        shop.adaugaHainaInStoc(h);
    }

    int optiune = 0;
    while (optiune != 8) {
        std::cout << "\n==========================================";
        std::cout << "\n       GESTIUNE CHIC ATELIER ";
        std::cout << "\n==========================================\n";
        std::cout << "1. Vezi vitrina magazinului (Manechin & Locatie)\n";
        std::cout << "2. Vezi tot inventarul depozitului\n";
        std::cout << "3. Imbraca manechinul (Alege haina dupa index)\n";
        std::cout << "4. Dezbraca manechinul (Reset Outfit)\n";
        std::cout << "5. Verifica buget clienta (Calcul total)\n";
        std::cout << "6. Cauta haine dupa categorie (Filtru)\n";
        std::cout << "7. Lasa o recenzie pentru o haina\n";
        std::cout << "8. Iesire program\n";
        std::cout << "Alegerea ta: ";
        std::cin >> optiune;

        if (optiune == 1) {
            std::cout << "\n" << shop << "\n";
        } else if (optiune == 2) {
            shop.afiseazaStocComplet();
        } else if (optiune == 3) {
            int idx;
            std::cout << "Introdu indexul hainei dorite (0-" << stocDisponibil.size() - 1 << "): ";
            std::cin >> idx;
            if (idx >= 0 && (size_t) idx < stocDisponibil.size()) {
                man.incearcaHaina(shop.getHainaDinInventar(idx));
            } else {
                std::cout << "!!! Index invalid. Te rugam sa alegi din lista depozitului.\n";
            }
        } else if (optiune == 4) {
            man.dezbracaManechin();
        } else if (optiune == 5) {
            std::cout << "\n--- PROCESARE PLATA ---\n";
            std::cout << cl << "\n"; // Afiseaza bugetul actual al Mariei
            double pretTotal = man.getValoareTinuta();
            std::string codIntrodus;
            std::cout << "Introduceti codul promotional (sau 'SARI' pentru pret intreg): ";
            std::cin >> codIntrodus;
            double pretFinal = pretTotal;
            if (codIntrodus == "SPRING10") {
                pretFinal = promo10.aplicaReducere(pretTotal);
                std::cout << "Cod aplicat cu succes! " << promo10 << "\n";
            }
            std::cout << "Total de plata: " << pretFinal << " lei\n";
            if (cl.poateCumpara(pretFinal)) {
                cl.finalizeazaAchizitie(pretFinal, man);
                man.dezbracaManechin(); // Dupa ce cumpara, manechinul ramane gol pentru urmatoarea clienta
            } else {
                std::cout << "Eroare: Fonduri insuficiente! Mai aveti nevoie de " << pretFinal - cl.getBuget() << " lei.\n";
            }
        } else if (optiune == 6) {
            std::string cat;
            std::cout << "Introdu categoria (Baza/Exterior/Incaltaminte/Accesoriu): ";
            std::cin >> cat;
            shop.afiseazaHaineDupaCategorie(cat);
        } else if (optiune == 7) {
            int idx, nota;
            std::cout << "Index haina: ";
            std::cin >> idx;
            std::cout << "Nota (1-5): ";
            std::cin >> nota;
            if (idx >= 0 && (size_t) idx < stocDisponibil.size()) {
                shop.getHainaDinInventar(idx).adaugaRecenzie(nota);
            }
        }
    }

    std::cout << "\nSistemul ChicAtelier s-a inchis.\n";
    return 0;
}
