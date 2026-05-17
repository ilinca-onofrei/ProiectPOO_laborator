#include "../include/Haina.h"
#include "../include/Exceptii.h"

int Haina::contorId = 0;
int Haina::nrHaine = 0;

Haina::Haina(const std::string &denumire_, const std::string &marime_, const std::string &categorie_, double pret_,
             int stoc_)
    : id{++contorId}, denumire{denumire_}, marime{marime_}, categorie{categorie_}, pret{pret_}, stocActual{stoc_},
      discountWeekendAplicat{false} {
    std::cout << "S a creat haina: " << denumire << "\n";
    nrHaine++;
}

Haina::Haina(const Haina &other)
    : id{other.id}, denumire{other.denumire}, marime{other.marime},
      categorie{other.categorie}, pret{other.pret}, recenzii{other.recenzii},
      stocActual{other.stocActual}, discountWeekendAplicat{other.discountWeekendAplicat} {
    std::cout << "CC Haina: S a copiat " << denumire << "\n";
    nrHaine++;
}

Haina &Haina::operator=(const Haina &other) {
    if (this != &other) {
        id = other.id;
        denumire = other.denumire;
        marime = other.marime;
        pret = other.pret;
        categorie = other.categorie;
        recenzii = other.recenzii;
        stocActual = other.stocActual;
        discountWeekendAplicat = other.discountWeekendAplicat;
    }
    std::cout << "op=Haina: S a atribuit " << denumire << "\n";
    return *this;
}

Haina::~Haina() {
    std::cout << "Destructorul Haina: " << denumire << " a fost distrus.\n";
}

const std::string &Haina::getCategorie() const { return categorie; }
const std::string &Haina::getMarime() const { return marime; }
double Haina::getPret() const { return pret; }
const std::string &Haina::getDenumire() const { return denumire; }
int Haina::getId() const { return id; }
int Haina::getStocActual() const { return stocActual; }
int Haina::getNrRecenzii() const { return static_cast<int>(recenzii.size()); }

void Haina::aplicaDiscount(double procent) {
    if (procent < 0 || procent > 100)
        throw ExceptieReducere();
    if (discountWeekendAplicat) return;

    pret -= pret * (procent / 100.0);
    discountWeekendAplicat = true;
}

void Haina::adaugaRecenzie(int nota) {
    if (nota >= 1 && nota <= 5) {
        recenzii.push_back(nota);
        std::cout << "Recenzie de " << nota << " stele adaugata pentru " << denumire << ".\n";
    }
}

double Haina::getMediaRecenziilor() const {
    if (recenzii.empty()) return 0.0;
    double suma = 0;
    for (int r: recenzii) suma += r;
    return suma / (double) recenzii.size();
}

void Haina::scadeStoc() {
    if (stocActual > 0) stocActual--;
}

int Haina::getNrHaine() {
    return nrHaine;
}

std::ostream &operator<<(std::ostream &os, const Haina &h) {
    os << "[ID:" << h.getId() << "] " << h.getDenumire()
            << " (Recenzii: " << h.getNrRecenzii() << ")"; // Adaugă asta
    return os;
}