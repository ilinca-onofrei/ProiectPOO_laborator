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
        :oras{oras_}, strada{strada_}, numar{numar_} {}
    friend std::ostream& operator<<(std::ostream& os, const Adresa& a) {
        os <<a.strada<<" nr. "<<a.numar<<" , "<<a.oras;
        return os;
    }
};

class Haina {
private:
    std::string denumire;
    std::string marime;
    double pret;
public:
    Haina(std::string denumire_, std::string marime_, double pret_)
        : denumire{denumire_}, marime{marime_}, pret{pret_} {
        std::cout<<"S a creat haina: "<<denumire<<"\n";
    }

    Haina(const Haina& other)
        : denumire{other.denumire}, marime{other.marime}, pret{other.pret} {
        std::cout<<"CC Haina: S a copiat "<<denumire<<"\n";
    }

    Haina& operator=(const Haina& other) {
        if (this != &other) {
            denumire=other.denumire;
            marime=other.marime;
            pret=other.pret;
        }
        std::cout<<"op=Haina: S a atribuit "<<denumire<<"\n";
        return *this; // AICI SE RETURNEAZA REFERINTA
    }

    ~Haina() {
        std::cout<<"Destructorul Haina: "<<denumire<<" a fost distrus.\n";
    }

    void aplicaDiscount(double procent) {
        if (procent > 0 && procent <= 100) {
            pret -= pret * (procent / 100.0);
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Haina& h) {
        os<< h.denumire<< " (" <<h.marime<< ") - "<<h.pret<<" lei";
        return os;
    }
};

class Manechin {
private:
    std::string numeManechin;
    Haina hainaPurtata;
public:
    Manechin(std::string nume_, const Haina& haina_)
        : numeManechin{nume_}, hainaPurtata{haina_} {}
    friend std::ostream& operator<<(std::ostream& os, const Manechin& m) {
        os <<"Manechinul "<<m.numeManechin<<" poarta: "<<m.hainaPurtata;
        return os;
    }
    void schimbaTinuta(const Haina& hainaNoua) {
        hainaPurtata=hainaNoua;
        std::cout<<"Tinuta manechinului "<< numeManechin<< " a fost actualizata!\n";
    }
};

class Boutique {
private:
    std::string numeMagazin;
    Adresa locatie;
    Manechin vitrina;
public:
    Boutique(std::string nume_, const Adresa& adr_, const Manechin& m_)
        : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {}

    friend std::ostream& operator<<(std::ostream & os, const Boutique& b) {
        os <<"***"<<b.numeMagazin<<"***\n";
        os <<"Locatie: "<<b.locatie<<"\n";
        os <<"In vitrina: "<<b.vitrina<<"\n";
        return os;
    }

};

int main() {

    Haina h1{"Rochie de seara", "M", 250.0};
    Haina h2{"Sacou elegant", "S", 180.0};
    Adresa adr{"Bucuresti","Calea Victoriei",101};
    std::cout <<h1<< "\n";
    std::cout <<h2 <<"\n";
    Haina h3{h1}; // constructor de COPIERE
    h3=h2; // operator de atribuire
    Manechin man{"Anna", h1}; //compunere-manechin
    Boutique shop{"ChicAtelier", adr, man}; //compunere boutique
    std::cout<<shop<<"\n";
    h1.aplicaDiscount(10);
    man.schimbaTinuta(h2);
    std::cout << "\n*** Final ***\n";
    return 0;
}
