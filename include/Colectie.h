#ifndef COLECTIE_H
#define COLECTIE_H

#include <vector>
#include <iostream>

template <typename T>
class Colectie {
    std::vector<T> elem;
public:
    void adauga(const T& e) {
        elem.push_back(e);
    }

    void afiseaza() const {
        for (const auto& x : elem)
            std::cout << x << "\n";
    }

    size_t size() const {
        return elem.size();
    }
};

#endif
