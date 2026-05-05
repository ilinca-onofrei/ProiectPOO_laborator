#include "../include/IstoricVanzari.h"

IstoricVanzari::IstoricVanzari() : numarTotalVanzari{0}, venitTotal{0.0} {
}

void IstoricVanzari::inregistreazaTranzactie(double suma, const Manechin &m) {
    venitTotal += suma;
    numarTotalVanzari++;

    // Salvăm efectiv copiile hainelor vândute pentru raport
    if (m.getStratBaza()) haineVandute.push_back(*(m.getStratBaza()));
    if (m.getStratExterior()) haineVandute.push_back(*(m.getStratExterior()));
    if (m.getIncaltaminte()) haineVandute.push_back(*(m.getIncaltaminte()));
    if (m.getAccesoriu()) haineVandute.push_back(*(m.getAccesoriu()));

    std::cout << "[Sistem] Tranzactie salvata. Produse inregistrate in inventarul de vanzari.\n";
}

void IstoricVanzari::afiseazaRaportComplet() const {
    std::cout << "\n==========================================";
    std::cout << "\n       RAPORT ACTIVITATE MAGAZIN ";
    std::cout << "\n==========================================\n";
    std::cout << "Numar total de vanzari: " << numarTotalVanzari << "\n";
    std::cout << "Venit total realizat: " << venitTotal << " lei\n";

    if (numarTotalVanzari > 0) {
        std::cout << "Media per clienta: " << venitTotal / numarTotalVanzari << " lei\n";
    } else {
        std::cout << "Nu s-au inregistrat vanzari astazi.\n";
    }

    std::cout << "------------------------------------------\n";
    std::cout << "Produse vandute individual:\n";
    if (haineVandute.empty()) {
        std::cout << "Niciun produs vandut inca.\n";
    } else {
        for (const auto &h: haineVandute) {
            std::cout << " - " << h << "\n";
        }
    }
    std::cout << "==========================================\n";
}