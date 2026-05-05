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

int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    Manechin man{"Anna", "M"};
    Boutique shop{"ChicAtelier", adr, man};
    Clienta cl{"Ilinca", 2000.0};
    Promotie promo10{"SPRING10", 10.0};
    IstoricVanzari registru;
    std::vector<Haina> stocDisponibil = {
        // BAZA (Index 0-3)
        Haina{"Tricou Bumbac Basic", "M", "Baza", 60.0},
        Haina{"Rochie Eleganta de Seara", "M", "Baza", 350.0},
        Haina{"Camasa Oxford Alba", "M", "Baza", 120.0},
        Haina{"Blugi Slim Fit", "M", "Baza", 180.0},

        // EXTERIOR (Index 4-7)
        Haina{"Sacou Office Negru", "M", "Exterior", 250.0},
        Haina{"Geaca de Piele Rock", "M", "Exterior", 400.0},
        Haina{"Palton de Lana", "M", "Exterior", 550.0},
        Haina{"Cardigan Impletit", "S", "Exterior", 150.0},

        // INCALTAMINTE (Index 8-12)
        Haina{"Adidasi Sport Albi", "M", "Incaltaminte", 320.0},
        Haina{"Pantofi Stiletto Rosii", "M", "Incaltaminte", 450.0},
        Haina{"Balerini Casual", "M", "Incaltaminte", 130.0},
        Haina{"Slapi de Plaja", "M", "Incaltaminte", 45.0},
        Haina{"Ghete de Toamna", "M", "Incaltaminte", 380.0},

        // ACCESORII (Index 13-17)
        Haina{"Palarie Fedora", "M", "Accesoriu", 110.0},
        Haina{"Ochelari de Soare RayBan", "M", "Accesoriu", 620.0},
        Haina{"Colier Argint cu Cristal", "M", "Accesoriu", 280.0},
        Haina{"Geanta de Mana Piele", "M", "Accesoriu", 500.0},
        Haina{"Esarfa de Matase", "M", "Accesoriu", 75.0}
    };

    for (const auto &h: stocDisponibil) {
        shop.adaugaHainaInStoc(h);
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
            std::cout << "Introdu indexul hainei dorite (0-" << stocDisponibil.size() - 1 << "): ";
            std::cin >> idx;
            if (idx >= 0 && static_cast<size_t>(idx) < shop.getNrHaineInventar()) {
                Haina &hainaAleasa = shop.getHainaDinInventar(idx);
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
    std::cout << "\nSistemul ChicAtelier s-a inchis.\n";
    return 0;
}
