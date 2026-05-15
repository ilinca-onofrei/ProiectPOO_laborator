#include "../include/Boutique.h"
#include <iomanip>

Boutique::Boutique(const std::string &nume_, const Adresa &adr_, Manechin &m_)
    : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {
}

Boutique::~Boutique() {
    for (auto h : inventar) {
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
    for (const auto &h : inventar) {
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
    for (const auto &articol : inventar) {
        if (articol->getCategorie() == "Accesoriu" && articol->getPret() < hainaAleasa.getPret() * 0.5) {
            std::cout << " > " << articol->getDenumire() << " la doar " << articol->getPret() << " lei!\n";
            gasit = true;
            break;
        }
    }
    if (!gasit) std::cout << " > Nicio recomandare momentan.\n";
}

size_t Boutique::getNrHaineInventar() const {
    return inventar.size();
}

std::ostream &operator<<(std::ostream &os, const Boutique &b) {
    os << "***" << b.numeMagazin << "***\n";
    os << "Locatie: " << b.locatie << "\n";
    os << "In vitrina: " << b.vitrina << "\n";
    return os;
}