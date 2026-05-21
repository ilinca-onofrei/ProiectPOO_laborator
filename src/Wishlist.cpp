#include "../include/Wishlist.h"
#include <iostream>
#include <algorithm>

#define SECUNDE_IN_ZI 86400
#define LIM_7_ZILE (7 * SECUNDE_IN_ZI)

void Wishlist::adauga(Haina *h) {
    EntryWishlist entry;
    entry.h = h;
    entry.dataAdaugare = std::time(nullptr);

    dorinte.push_back(entry);

    std::cout << "[Wishlist] Adaugat: " << h->getDenumire() << "\n";
}

void Wishlist::stergeExpirate() {
    std::time_t now = std::time(nullptr);

    dorinte.erase(
        std::remove_if(dorinte.begin(), dorinte.end(),
                       [&](const EntryWishlist &e) {
                           double diff = std::difftime(now, e.dataAdaugare);

                           if (diff > LIM_7_ZILE) {
                               std::cout << "[Wishlist] Expirat: "
                                       << e.h->getDenumire() << "\n";
                               return true;
                           }

                           return false;
                       }),
        dorinte.end());
}

bool Wishlist::esteGol() const {
    return dorinte.empty();
}

void Wishlist::afiseaza() {
    stergeExpirate();

    std::cout << "\n===== WISHLIST =====\n";

    if (dorinte.empty()) {
        std::cout << "GOL\n";
        return;
    }

    int i = 0;
    for (const auto &e: dorinte) {
        std::cout << i++ << ". "
                << e.h->getDenumire()
                << " | " << e.h->getPret()
                << " lei\n";
    }
}

double Wishlist::calculeazaTotal() {
    stergeExpirate();

    double total = 0;
    for (const auto &e: dorinte) {
        total += e.h->getPret();
    }

    return total;
}
