#include "../include/Boutique.h"
#include <iomanip>

Boutique::Boutique(const std::string &nume_, const Adresa &adr_, Manechin &m_)
    : numeMagazin{nume_}, locatie{adr_}, vitrina{m_} {
}

Haina &Boutique::getHainaDinInventar(int idx) {
    if (idx < 0 || static_cast<size_t>(idx) >= inventar.size()) {
        std::cerr << "Eroare: Index " << idx << " in afara limitelor inventarului!\n";
        // Returnam primul element ca masura de siguranta in caz de eroare critica
        return inventar[0];
    }
    return inventar[idx];
}

void Boutique::adaugaHainaInStoc(const Haina &h) {
    inventar.push_back(h);
    std::cout << "Haina '" << h.getDenumire() << "' a fost adaugata in stoc.\n";
}

void Boutique::afiseazaStocComplet() const {
    std::cout << "\n*** Inventar Complet " << numeMagazin << " ***\n";
    if (inventar.empty()) {
        std::cout << "Stocul este gol!\n";
    } else {
        for (const auto &h : inventar) {
            std::cout << "- " << h << "\n";
        }
    }
}

void Boutique::afiseazaHaineDupaCategorie(const std::string &catCautata) const {
    std::cout << "\n--- Rezultate cautare pentru categoria: " << catCautata << " ---\n";
    bool gasit = false;
    for (const auto &h : inventar) {
        if (h.getCategorie() == catCautata) {
            std::cout << "- " << h
                      << " (Media: " << std::fixed << std::setprecision(1) << h.getMediaRecenziilor()
                      << " stele din " << h.getNrRecenzii() << " recenzii)\n";
            gasit = true;
        }
    }
    if (!gasit) std::cout << "Nu am gasit haine in aceasta categorie.\n";
}

void Boutique::recomandaAccesoriu(const Haina &hainaAleasa) const {
    std::cout << "\n[Smart-Matching @ " << numeMagazin << "] Deoarece ati ales " << hainaAleasa.getDenumire() << "...\n";
    bool gasit = false;
    for (const auto &articol : inventar) {
        // Logica: accesoriu sub jumatate din pretul hainei alese
        if (articol.getCategorie() == "Accesoriu" && articol.getPret() < hainaAleasa.getPret() * 0.5) {
            std::cout << " > Va recomandam si: " << articol.getDenumire() << " la doar " << articol.getPret() << " lei!\n";
            gasit = true;
            break;
        }
    }
    if (!gasit) std::cout << " > Momentan nu avem accesorii la reducere pentru acest articol.\n";
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