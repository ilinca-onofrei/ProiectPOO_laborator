#ifndef HAINA_FACTORY_H
#define HAINA_FACTORY_H

#include "Haina.h"
#include "HainaEleganta.h"
#include "HainaSport.h"
#include "HainaCasual.h"
#include "HainaOffice.h"

class HainaFactory {
public:
    static Haina* creeazaHaina(const std::string& tip) {

        if (tip == "elegant")
            return new HainaEleganta("Rochie Factory", "M", 300, "Matase", "Eveniment");
        if (tip == "sport")
            return new HainaSport("Tricou Factory", "M", 100, "Fitness", 3);
        if (tip == "casual")
            return new HainaCasual("Hanorac Factory", "M", 150, "Toamna", false);
        if (tip == "office")
            return new HainaOffice("Sacou Factory", "M", 250, true, 8);
        return nullptr;
    }
};

#endif
