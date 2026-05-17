#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <memory>

#include "include/Adresa.h"
#include "include/Promotie.h"
#include "include/Haina.h"
#include "include/Manechin.h"
#include "include/Boutique.h"
#include "include/Clienta.h"
#include "include/IstoricVanzari.h"
#include "include/HainaEleganta.h"
#include "include/HainaSport.h"
#include "include/HainaCasual.h"
#include "include/HainaOffice.h"
#include "include/Exceptii.h"
#include "include/HainaLuxury.h"

int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    Manechin man{"Anna", "M"};
    Boutique shop{"ChicAtelier", adr, man};
    Clienta cl{"Ilinca", 2000.0};
    Promotie promo10{"SPRING10", 10.0};
    IstoricVanzari registru;
    std::vector<Haina *> stocInitial;

    // CATEGORIA ELEGANTE
    stocInitial.push_back(new HainaEleganta("Rochie de Seara Velvet", "M", 450.0, "Catifea", "Gala"));
    stocInitial.push_back(new HainaEleganta("Costum Smoking Negru", "M", 800.0, "Lana Super 120s", "Nunta"));
    stocInitial.push_back(new HainaEleganta("Rochie Cocktail Dantela", "S", 320.0, "Dantela", "Party"));
    stocInitial.push_back(new HainaEleganta("Rochie Eleganta de Seara", "M", 350.0, "Saten", "Receptie"));

    // CATEGORIA SPORT
    stocInitial.push_back(new HainaSport("Tricou Compresie Pro", "M", 120.0, "Running", 5));
    stocInitial.push_back(new HainaSport("Pantaloni Yoga Flex", "S", 180.0, "Yoga", 2));
    stocInitial.push_back(new HainaSport("Adidasi Sport Albi", "M", 320.0, "Multisport", 4));
    stocInitial.push_back(new HainaSport("Tricou Bumbac Basic", "M", 60.0, "Antrenament usor", 1));

    // CATEGORIA OFFICE
    stocInitial.push_back(new HainaOffice("Camasa Oxford Alba", "M", 120.0, false, 7));
    stocInitial.push_back(new HainaOffice("Sacou Office Negru", "M", 250.0, true, 9));
    stocInitial.push_back(new HainaOffice("Pantalon Stofa Gri", "L", 220.0, true, 7));
    stocInitial.push_back(new HainaOffice("Sacou Office Ajustat", "M", 350.0, true, 10));

    // CATEGORIA CASUAL
    stocInitial.push_back(new HainaCasual("Blugi Slim Fit", "M", 180.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Geaca de Piele Rock", "M", 400.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Palton de Lana", "M", 550.0, "Iarna", false));
    stocInitial.push_back(new HainaCasual("Cardigan Impletit", "S", 150.0, "Primavara", false));

    // Incaltaminte
    stocInitial.push_back(new HainaCasual("Pantofi Stiletto Rosii", "M", 450.0, "Seara", false));
    stocInitial.push_back(new HainaCasual("Balerini Casual", "M", 130.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Slapi de Plaja", "M", 45.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Ghete de Toamna", "M", 380.0, "Toamna", false));

    // Accesorii
    stocInitial.push_back(new HainaCasual("Palarie Fedora", "M", 110.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Ochelari de Soare RayBan", "M", 620.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Colier Argint cu Cristal", "M", 280.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Geanta de Mana Piele", "M", 500.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Esarfa de Matase", "M", 75.0, "Primavara", false));

    // LUXURY
    stocInitial.push_back(new HainaLuxury("Rochie Haute Couture", "M", 2500.0, 2, 10));
    stocInitial.push_back(new HainaLuxury("Geanta Designer Premium", "M", 3200.0, 1, 9));
    stocInitial.push_back(new HainaLuxury("Pantofi Luxury Cristale", "M", 1800.0, 3, 8));
    stocInitial.push_back(new HainaLuxury("Palton Luxury Limited Edition", "L", 4000.0, 1, 10));

    for (const Haina *h: stocInitial) {
        shop.adaugaHainaInStoc(*h);
    }

    man.incearcaHaina(shop.getHainaDinInventar(1));
    man.incearcaHaina(shop.getHainaDinInventar(13));
    man.incearcaHaina(shop.getHainaDinInventar(9));
    std::cout << " Buget client: " << cl.getBuget() << "\n";
    std::cout << " Nivel fidelitate: " << cl.getNivelFidelitate() << "\n";
    std::cout << "Numar total haine create: " << Haina::getNrHaine() << "\n";
    int optiune = 0;
    while (optiune != 17) {
        try {
            std::cout << "\n==========================================";
            std::cout << "\n       GESTIUNE CHIC ATELIER ";
            std::cout << "\n==========================================\n";
            std::cout << "1. Vezi vitrina magazinului\n";
            std::cout << "2. Vezi inventarul depozitului\n";
            std::cout << "3. Imbraca manechinul\n";
            std::cout << "4. Dezbraca manechinul\n";
            std::cout << "5. Procesare plata\n";
            std::cout << "6. Cauta haine\n";
            std::cout << "7. Recenzie\n";
            std::cout << "8. Reduceri\n";
            std::cout << "9. Raport\n";
            std::cout << "10. Garderoba\n";
            std::cout << "11. Top haina (cel mai bun rating)\n";
            std::cout << "12. Filtru dupa pret\n";
            std::cout << "13. Sortare dupa pret\n";
            std::cout << "14. Pret mediu\n";
            std::cout << "15. Categoria dominanta\n";
            std::cout << "16. Afiseaza produse luxury\n";
            std::cout << "17. Exit\n";

            if (!(std::cin >> optiune)) break;

            if (optiune == 1) {
                std::cout << shop << "\n";
            } else if (optiune == 2) {
                shop.afiseazaStocComplet();
            } else if (optiune == 3) {
                int idx;
                if (!(std::cin >> idx)) break;

                if (idx < 0 || idx >= (int) shop.getNrHaineInventar())
                    throw ExceptieIndex();

                Haina &h = shop.getHainaDinInventar(idx);

                if (h.getStocActual() == 0)
                    throw ExceptieStoc();

                man.incearcaHaina(h);
                h.scadeStoc();
                shop.recomandaAccesoriu(h);
            } else if (optiune == 4) {
                man.dezbracaManechin();
            } else if (optiune == 5) {
                double pretInitial = man.getValoareTinuta();

                if (pretInitial == 0)
                    throw ExceptieIndex();

                double pretFinal = cl.aplicaReducereFidelitate(pretInitial);

                std::string cod;
                if (!(std::cin >> cod)) break;

                if (cod == "SPRING10")
                    pretFinal = promo10.aplicaReducere(pretFinal);

                if (!cl.poateCumpara(pretFinal))
                    throw ExceptieBuget();

                cl.finalizeazaAchizitie(pretFinal, man);
                registru.inregistreazaTranzactie(pretFinal, man);
                cl.tiparesteBon(pretFinal, cod);
                man.dezbracaManechin();
            } else if (optiune == 6) {
                std::string cat;
                if (!(std::cin >> cat)) throw ExceptieInput();;
                shop.afiseazaHaineDupaCategorie(cat);
            } else if (optiune == 7) {
                int idx, nota;
                if (!(std::cin >> idx >> nota)) break;

                if (idx < 0 || idx >= (int) shop.getNrHaineInventar())
                    throw ExceptieIndex();

                shop.getHainaDinInventar(idx).adaugaRecenzie(nota);
            }
            else if (optiune == 8) {
                for (size_t i = 0; i < shop.getNrHaineInventar(); i++)
                    shop.getHainaDinInventar(i).aplicaDiscount(20);

                std::cout << "Reducerile aplicate!\n";
            } else if (optiune == 9) {
                registru.afiseazaRaportComplet();
            } else if (optiune == 10) {
                cl.afiseazaGarderoba();
            } else if (optiune == 11) {
                shop.afiseazaCeaMaiBunaHaina();
            } else if (optiune == 12) {
                double pret;
                std::cout << "Introdu pret maxim: ";

                if (!(std::cin >> pret)) break;

                shop.afiseazaHaineSubPret(pret);
            } else if (optiune == 13) {
                shop.afiseazaHaineSortateDupaPret();
            } else if (optiune == 14) {
                std::cout << "Pret mediu: "
                        << shop.calculeazaPretMediu()
                        << " lei\n";
            } else if (optiune == 15) {
                shop.afiseazaCategoriaDominanta();
            } else if (optiune == 16) {
                std::cout << "\n Produse Luxury: \n";

                for (size_t i = 0; i < shop.getNrHaineInventar(); i++) {
                    Haina &h = shop.getHainaDinInventar(i);

                    if (h.getCategorie() == "Luxury") {
                        h.afiseazaDetaliiComplete();
                    }
                }
            }

        } catch (const std::exception &e) {
            std::cout << "!!! EROARE: " << e.what() << "\n";
        }
        if (!std::cin) break;
    }

    for (auto h: stocInitial)
        delete h;

    std::cout << "\n TESTARE COPY \n";
    Boutique shopCopy = shop; // copy constructor
    Boutique shopAssign{"Temp", adr, man};
    shopAssign = shop; // operator=
    std::cout << "Copiere realizata cu succes!\n";

    return 0;
}