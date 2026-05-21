#pragma once
#include <vector>
#include <ctime>
#include "Haina.h"


#ifndef OOP_WISHLIST_H
#define OOP_WISHLIST_H

struct EntryWishlist {
    Haina* h;
    std::time_t dataAdaugare;
};

class Wishlist {
private:
    std::vector<EntryWishlist> dorinte;

public:
    void adauga(Haina* h);
    void afiseaza();
    void stergeExpirate();
    double calculeazaTotal();
    bool esteGol() const;
};




#endif //OOP_WISHLIST_H