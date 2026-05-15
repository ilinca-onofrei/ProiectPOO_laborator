#include <iostream>
// This also works if you do not want `include/`, but some editors might not like it
// #include "Example.h"
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "include/Adresa.h"
#include "include/Promotie.h"
#include "include/Haina.h"
#include "include/Manechin.h"
#include "include/Boutique.h"
#include "include/Clienta.h"
#include "include/IstoricVanzari.h"
#include <memory>
#include "include/HainaEleganta.h"
#include "include/HainaSport.h"
#include "include/HainaCasual.h"
#include "include/HainaOffice.h"

int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    Manechin man{"Anna", "M"};
    Boutique shop{"ChicAtelier", adr, man};
    Clienta cl{"Ilinca", 2000.0};
    Promotie promo10{"SPRING10", 10.0};
    IstoricVanzari registru;
    std::vector<Haina*> stocInitial;

    // CATEGORIA ELEGANTE (Fostele haine de baza elegante)
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

    // Accesorii (le am pus ca HainaCasual pentru simplitate)
    stocInitial.push_back(new HainaCasual("Palarie Fedora", "M", 110.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Ochelari de Soare RayBan", "M", 620.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Colier Argint cu Cristal", "M", 280.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Geanta de Mana Piele", "M", 500.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Esarfa de Matase", "M", 75.0, "Primavara", false));

    for (auto h : stocInitial) {
        shop.adaugaHainaInStoc(*h);
    }
    man.incearcaHaina(shop.getHainaDinInventar(1));
    man.incearcaHaina(shop.getHainaDinInventar(13));
    man.incearcaHaina(shop.getHainaDinInventar(9));
    int optiune = 0;
    while (optiune != 11) {
        std::cout << "\n==========================================";
        std::cout << "\n       GESTIUNE CHIC ATELIER ";
        std::cout << "\n==========================================\n";
        std::cout << "1. Vezi vitrina magazinului (Manechin & Locatie)\n";
        std::cout << "2. Vezi tot inventarul depozitului\n";
        std::cout << "3. Imbraca manechinul (Alege haina dupa index)\n";
        std::cout << "4. Dezbraca manechinul (Reset Outfit)\n";
        std::cout << "5. Procesare plata (Finalizare achizitie)\n";
        std::cout << "6. Cauta haine dupa categorie (Filtru)\n";
        std::cout << "7. Lasa o recenzie pentru o haina\n";
        std::cout << "8. Aplica REDUCERI DE WEEKEND (Black Friday de Primavara!)\n";
        std::cout << "9. Vezi raport financiar (Istoric Vanzari)\n";
        std::cout << "10. Vezi garderoba mea (Haine cumparate)\n";
        std::cout << "11. Iesire program\n";
        std::cout << "Alegerea ta: ";
        std::cin >> optiune;

        if (optiune == 1) {
            std::cout << "\n" << shop << "\n";
        } else if (optiune == 2) {
            shop.afiseazaStocComplet();
        } else if (optiune == 3) {
            int idx;
            std::cout << "Introdu indexul hainei dorite (0-" << shop.getNrHaineInventar() - 1 << "): ";
            std::cin >> idx;
            if (idx >= 0 && static_cast<size_t>(idx) < shop.getNrHaineInventar()) {
                Haina &hainaAleasa = shop.getHainaDinInventar(idx);
                std::cout << "Se verifica haina cu ID-ul: " << hainaAleasa.getId() << "\n";
                if (hainaAleasa.getStocActual() > 0) {
                    man.incearcaHaina(hainaAleasa);
                    hainaAleasa.scadeStoc();
                    shop.recomandaAccesoriu(hainaAleasa);
                    std::cout << "[INFO] Stoc ramas pentru acest model: " << hainaAleasa.getStocActual() << "\n";
                } else {
                    std::cout << "!!! EROARE: Stoc epuizat pentru '" << hainaAleasa.getDenumire() << "'.\n";
                }
            } else {
                std::cout << "!!! Index invalid.\n";
            }
        } else if (optiune == 4) {
            man.dezbracaManechin();
        } else if (optiune == 5) {
            std::cout << "\n--- PROCESARE PLATA ---\n";
            std::cout << cl << "\n";
            std::cout << "Nivel fidelitate actual: " << cl.getNivelFidelitate() << "\n";
            double pretInitial = man.getValoareTinuta();
            if (pretInitial == 0) {
                std::cout << "Eroare: Manechinul nu are haine! Nimic de platit.\n";
            } else {
                // aplicam reducerea de fidelitate automat
                double pretDupaFidelitate = cl.aplicaReducereFidelitate(pretInitial);
                if (pretDupaFidelitate < pretInitial) {
                    std::cout << "[Fidelitate] S-a aplicat reducerea de nivel! Pret nou: " << pretDupaFidelitate <<
                            " lei\n";
                }
                std::string codIntrodus;
                std::cout << "Introduceti codul promotional (sau 'SARI'): ";
                std::cin >> codIntrodus;
                double pretFinal = pretDupaFidelitate;
                if (codIntrodus == "SPRING10") {
                    pretFinal = promo10.aplicaReducere(pretDupaFidelitate);
                    std::cout << "Cod aplicat cu succes! " << promo10 << "\n";
                }
                // Verificam bugetul si finalizam + afisam bonul fiscal
                if (cl.poateCumpara(pretFinal)) {
                    cl.finalizeazaAchizitie(pretFinal, man);
                    registru.inregistreazaTranzactie(pretFinal, man);
                    cl.tiparesteBon(pretFinal, codIntrodus);
                    man.dezbracaManechin();
                } else {
                    std::cout << "Eroare: Fonduri insuficiente! Lipsesc: " << pretFinal - cl.getBuget() << " lei.\n";
                }
            }
        }else if (optiune == 6) {
            std::string cat;
            std::cout << "Introdu categoria (Baza/Exterior/Incaltaminte/Accesoriu): ";
            std::cin >> cat;
            shop.afiseazaHaineDupaCategorie(cat);
        } else if (optiune == 7) {
            int idx, nota;
            std::cout << "Index haina: ";
            std::cin >> idx;
            std::cout << "Nota (1-5): ";
            std::cin >> nota;
            if (idx >= 0 && static_cast<size_t>(idx) < shop.getNrHaineInventar()) {
                shop.getHainaDinInventar(idx).adaugaRecenzie(nota);
            } else {
                std::cout << "!!! Index invalid.\n";
            }
        } else if (optiune == 8) {
            std::cout << "\n!!! BLACK FRIDAY: Se aplica o reducere de 20% la TOATE hainele din stoc !!!\n";
            for (size_t i = 0; i < shop.getNrHaineInventar(); i++) {
                shop.getHainaDinInventar(static_cast<int>(i)).aplicaDiscount(20);
            }
            std::cout << "Preturile au fost actualizate cu succes!\n";
        } else if (optiune == 9) {
            registru.afiseazaRaportComplet();
        } else if (optiune == 10) {
            cl.afiseazaGarderoba();
        }
    }
    for (auto h : stocInitial) {
        delete h;
    }
    stocInitial.clear();
    std::cout << "\nSistemul ChicAtelier s-a inchis.\n";
    return 0;
}
