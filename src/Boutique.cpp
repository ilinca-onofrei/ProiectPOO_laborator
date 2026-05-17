#include "../include/Boutique.h"
#include <iomanip>
#include <algorithm>
#include <map>
#include "../include/HainaEleganta.h"
#include "../include/HainaSport.h"
#include "../include/HainaOffice.h"


Boutique::Boutique(const std::string &nume_, const Adresa &adr_, Manechin &m_)
    : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {
}

Boutique::~Boutique() {
    for (auto h: inventar) {
        delete h;
    }
    inventar.clear();
}

Haina &Boutique::getHainaDinInventar(int idx) {
    if (idx < 0 || static_cast<size_t>(idx) >= inventar.size()) {
        std::cerr << "Eroare: Index " << idx << " invalid!\n";
        return *(inventar[0]);
    }
    return *(inventar[idx]);
}

void Boutique::adaugaHainaInStoc(const Haina &h) {
    inventar.push_back(h.clone());
    std::cout << "Haina '" << h.getDenumire() << "' a fost adaugata polimorfic.\n";
}

void Boutique::afiseazaStocComplet() const {
    std::cout << "\n*** Inventar Complet " << numeMagazin << " ***\n";
    if (inventar.empty()) {
        std::cout << "Stocul este gol!\n";
    } else {
        for (size_t i = 0; i < inventar.size(); ++i) {
            std::cout << i << ". ";
            inventar[i]->afiseazaDetaliiComplete();
        }
    }
}

void Boutique::afiseazaHaineDupaCategorie(const std::string &catCautata) const {
    std::cout << "\n--- Rezultate cautare pentru categoria: " << catCautata << " ---\n";
    bool gasit = false;
    for (const Haina *h: inventar) {
        if (h->getCategorie() == catCautata) {
            std::cout << "- " << *h
                    << " (Media: " << std::fixed << std::setprecision(1) << h->getMediaRecenziilor()
                    << " stele)\n";
            gasit = true;
        }
    }
    if (!gasit) std::cout << "Nu am gasit haine in aceasta categorie.\n";
}


void Boutique::recomandaAccesoriu(const Haina &hainaAleasa) const {
    std::cout << "\n[Smart-Matching] Pentru " << hainaAleasa.getDenumire() << " recomandam:\n";
    bool gasit = false;
    for (const Haina *articol: inventar) {
        if (articol->getCategorie() == "Accesoriu" &&
            articol->getPret() < hainaAleasa.getPret() * 0.5) {
            std::cout << " > " << articol->getDenumire()
                    << " la doar " << articol->getPret() << " lei!\n";
            gasit = true;
            break;
        }
    }

    if (!gasit)
        std::cout << " > Nicio recomandare automata.\n";

    std::cout << "[Sugestie stilistica]\n";

    if (dynamic_cast<const HainaEleganta *>(&hainaAleasa)) {
        std::cout << " Recomandare: Colier elegant sau geanta premium.\n";
    } else if (dynamic_cast<const HainaSport *>(&hainaAleasa)) {
        std::cout << " Recomandare: Rucsac sport sau sticla fitness.\n";
    } else if (dynamic_cast<const HainaOffice *>(&hainaAleasa)) {
        std::cout << " Recomandare: Ceas business sau geanta office.\n";
    } else {
        std::cout << " Recomandare: Accesorii casual cool.\n";
    }
}

size_t Boutique::getNrHaineInventar() const {
    return inventar.size();
}

void Boutique::afiseazaCeaMaiBunaHaina() const {
    if (inventar.empty()) {
        std::cout << "Nu exista haine in inventar.\n";
        return;
    }
    const Haina *best = inventar[0];
    for (const Haina *h: inventar) {
        if (h->getMediaRecenziilor() > best->getMediaRecenziilor()) {
            best = h;
        }
    }
    std::cout << "\n[TOP HAINA]\n";
    std::cout << "Cea mai apreciata haina este:\n";
    std::cout << *best << " cu rating: "
            << std::fixed << std::setprecision(1)
            << best->getMediaRecenziilor() << "\n";
}

void Boutique::afiseazaHaineSubPret(double pretMaxim) const {
    bool gasit = false;

    std::cout << "\n[Haine sub " << pretMaxim << " lei]\n";

    for (const Haina *h: inventar) {
        if (h->getPret() <= pretMaxim) {
            std::cout << *h
                    << " - " << h->getPret() << " lei\n";
            gasit = true;
        }
    }

    if (!gasit) {
        std::cout << "Nu exista haine in acest interval de pret.\n";
    }
}


void Boutique::afiseazaHaineSortateDupaPret() const {
    std::vector<const Haina *> copie;

    for (const Haina *h: inventar)
        copie.push_back(h);

    std::sort(copie.begin(), copie.end(), [](const Haina *a, const Haina *b) {
        return a->getPret() < b->getPret();
    });

    std::cout << "\n[Haine sortate dupa pret]\n";
    for (const Haina *h: copie) {
        std::cout << *h << " - " << h->getPret() << " lei\n";
    }
}

double Boutique::calculeazaPretMediu() const {
    if (inventar.empty()) return 0;

    double suma = 0;

    for (const Haina *h: inventar)
        suma += h->getPret();

    return suma / inventar.size();
}

void Boutique::afiseazaCategoriaDominanta() const {
    std::map<std::string, int> frecventa;

    for (const Haina *h: inventar) {
        frecventa[h->getCategorie()]++;
    }
    std::string best;
    int maxVal = 0;
    for (const auto &p: frecventa) {
        if (p.second > maxVal) {
            maxVal = p.second;
            best = p.first;
        }
    }
    std::cout << "Categoria dominanta: " << best
            << " (" << maxVal << " articole)\n";
}

Boutique::Boutique(const Boutique& other)
    : numeMagazin(other.numeMagazin),
      locatie(other.locatie),
      vitrina(other.vitrina)
{
    std::cout << "[COPY CONSTRUCTOR Boutique]\n";

    for (const Haina* h : other.inventar) {
        inventar.push_back(h->clone());
    }
}

void swap(Boutique& a, Boutique& b) noexcept {
    using std::swap;

    swap(a.numeMagazin, b.numeMagazin);
    swap(a.locatie, b.locatie);
    swap(a.vitrina, b.vitrina);
    swap(a.inventar, b.inventar);
}

Boutique& Boutique::operator=(Boutique other) {
    std::cout << "[OPERATOR= Boutique]\n";

    swap(*this, other);

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Boutique &b) {
    os << "***" << b.numeMagazin << "***\n";
    os << "Locatie: " << b.locatie << "\n";
    os << "In vitrina: " << b.vitrina << "\n";
    return os;
}