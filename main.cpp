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
#include "include/HainaLuxury.h"
#include "include/Wishlist.h"
#include "include/Exceptii.h"

int main() {
    Adresa adr{"Bucuresti", "Calea Victoriei", 101};
    std::vector<Manechin> manechine = {
        {"Emma", "XS"},
        {"Anna", "S"},
        {"Sophia", "M"},
        {"Ava", "L"}
    };
    int manechinSelectat = 2;
    Boutique shop{"ChicAtelier", adr, manechine[manechinSelectat]};
    Clienta cl{"Ilinca", 2000.0};
    Promotie promo10{"SPRING10", 10.0};
    IstoricVanzari registru;
    std::vector<Haina *> stocInitial;
    Wishlist wl;

    // CATEGORIA ELEGANTE
    stocInitial.push_back(new HainaEleganta("Rochie de Seara Velvet", "M", 450.0, "Catifea", "Gala"));
    stocInitial.push_back(new HainaEleganta("Costum Smoking Negru", "M", 800.0, "Lana Super 120s", "Nunta"));
    stocInitial.push_back(new HainaEleganta("Rochie Cocktail Dantela", "S", 320.0, "Dantela", "Party"));
    stocInitial.push_back(new HainaEleganta("Rochie Eleganta de Matase", "M", 350.0, "Saten", "Receptie"));
    stocInitial.push_back(new HainaEleganta("Rochie Satin Rosu", "S", 380.0, "Saten", "Gala"));
    stocInitial.push_back(new HainaEleganta("Salopeta Lunga Catifea", "L", 500.0, "Matase", "Bal"));
    stocInitial.push_back(new HainaEleganta("Costum Elegant Alb", "M", 700.0, "In", "Eveniment"));


    // CATEGORIA SPORT
    stocInitial.push_back(new HainaSport("Tricou Compresie Pro", "M", 120.0, "Running", 5));
    stocInitial.push_back(new HainaSport("Pantaloni Yoga Flex", "S", 180.0, "Yoga", 2));
    stocInitial.push_back(new HainaSport("Adidasi Sport Albi", "M", 320.0, "Multisport", 4));
    stocInitial.push_back(new HainaSport("Tricou Bumbac Basic", "M", 60.0, "Antrenament usor", 1));
    stocInitial.push_back(new HainaSport("Hanorac Sport Training", "L", 200.0, "Fitness", 3));
    stocInitial.push_back(new HainaSport("Colanti Sport Pro", "S", 150.0, "Fitness", 4));
    stocInitial.push_back(new HainaSport("Geaca Sport Outdoor", "M", 300.0, "Drumetii", 5));

    // CATEGORIA OFFICE
    stocInitial.push_back(new HainaOffice("Camasa Oxford Alba", "M", 120.0, false, 7));
    stocInitial.push_back(new HainaOffice("Sacou Office Negru", "M", 250.0, true, 9));
    stocInitial.push_back(new HainaOffice("Pantalon Stofa Gri", "L", 220.0, true, 7));
    stocInitial.push_back(new HainaOffice("Sacou Office Ajustat", "M", 350.0, true, 10));
    stocInitial.push_back(new HainaOffice("Fusta Office Neagra", "S", 180.0, true, 6));
    stocInitial.push_back(new HainaOffice("Camasa Business Albastra", "M", 160.0, false, 8));
    stocInitial.push_back(new HainaOffice("Sacou Eleganta Office", "L", 400.0, true, 10));

    // CATEGORIA CASUAL
    stocInitial.push_back(new HainaCasual("Blugi Slim Fit", "M", 180.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Geaca de Piele Rock", "M", 400.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Palton de Lana", "M", 550.0, "Iarna", false));
    stocInitial.push_back(new HainaCasual("Cardigan Impletit", "S", 150.0, "Primavara", false));
    stocInitial.push_back(new HainaCasual("Tricou Oversized", "M", 90.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Hanorac Casual Urban", "L", 220.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Blugi Relaxed Fit", "M", 200.0, "All-Season", false));

    // Incaltaminte
    stocInitial.push_back(new HainaCasual("Pantofi Stiletto Rosii", "39", 450.0, "Seara", false));
    stocInitial.push_back(new HainaCasual("Balerini Casual", "38", 130.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Slapi de Plaja", "37", 45.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Ghete de Toamna", "39", 380.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Sneakers Casual Alb", "38", 220.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Pantofi Eleganti Negri", "37", 300.0, "Office", false));
    stocInitial.push_back(new HainaCasual("Cizme Iarna Imblanite", "40", 450.0, "Iarna", false));

    // Accesorii
    stocInitial.push_back(new HainaCasual("Palarie Fedora", "M", 110.0, "Toamna", false));
    stocInitial.push_back(new HainaCasual("Ochelari de Soare RayBan", "M", 620.0, "Vara", false));
    stocInitial.push_back(new HainaCasual("Colier Argint cu Cristal", "M", 280.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Geanta de Mana Piele", "M", 500.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Esarfa de Matase", "M", 75.0, "Primavara", false));
    stocInitial.push_back(new HainaCasual("Ceas Elegant Silver", "M", 600.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Bratara Minimalista", "M", 120.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Rucsac Urban Stylish", "M", 350.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Curea Piele Premium", "M", 200.0, "All-Season", false));
    stocInitial.push_back(new HainaCasual("Portofel Slim Modern", "M", 180.0, "All-Season", false));


    // LUXURY
    stocInitial.push_back(new HainaLuxury("Rochie Haute Couture", "S", 2500.0, 2, 10));
    stocInitial.push_back(new HainaLuxury("Geanta Designer Premium", "M", 3200.0, 1, 9));
    stocInitial.push_back(new HainaLuxury("Pantofi Luxury Cristale", "37", 1800.0, 3, 8));
    stocInitial.push_back(new HainaLuxury("Palton Luxury Limited Edition", "L", 4000.0, 1, 10));
    stocInitial.push_back(new HainaLuxury("Costum Luxury Royal", "XS", 5000.0, 1, 10));
    stocInitial.push_back(new HainaLuxury("Pantofi Luxury Handmade", "39", 2700.0, 2, 9));
    stocInitial.push_back(new HainaLuxury("Geaca Luxury Blana Naturala", "S", 6000.0, 1, 10));

    for (const Haina *h: stocInitial) {
        shop.adaugaHainaInStoc(*h);
    }

    shop.getManechin().incearcaHaina(shop.getHainaDinInventar(1));
    shop.getManechin().incearcaHaina(shop.getHainaDinInventar(13));
    shop.getManechin().incearcaHaina(shop.getHainaDinInventar(9));
    std::cout << " Buget client: " << cl.getBuget() << "\n";
    std::cout << " Nivel fidelitate: " << cl.getNivelFidelitate() << "\n";
    std::cout << "Numar total haine create: " << Haina::getNrHaine() << "\n";
    int optiune = 0;
    while (optiune != 22) {
        try {
            std::cout << "\n==========================================";
            std::cout << "\n       GESTIUNE CHIC ATELIER ";
            std::cout << "\n==========================================\n";
            std::cout << "0. Alege manechin\n";
            std::cout << "1. Haine selectate\n";
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
            std::cout << "17. Adauga in wishlist\n";
            std::cout << "18. Afiseaza wishlist\n";
            std::cout << "19. Sterge din wishlist\n";
            std::cout << "20. Cauta haine dupa nume\n";
            std::cout << "21. Curata wishlist (expirate)\n";
            std::cout << "22. Exit\n";

            if (!(std::cin >> optiune)) break;

            if (optiune == 0) {
                std::cout << "\nAlege manechin:\n";
                std::cout << "0. Emma (XS)\n";
                std::cout << "1. Anna (S)\n";
                std::cout << "2. Sophia (M)\n";
                std::cout << "3. Ava (L)\n";

                int alegere;
                if (!(std::cin >> alegere))
                    throw ExceptieInput();

                if (alegere < 0 || alegere > 3)
                    throw ExceptieIndex();

                manechinSelectat = alegere;
                shop.setManechin(manechine[manechinSelectat]);
                std::cout << "Manechin selectat: "
                        << manechine[manechinSelectat].getNume()
                        << " (" << manechine[manechinSelectat].getMarime() << ")\n";
            } else if (optiune == 1) {
                std::cout << shop << "\n";
            } else if (optiune == 2) {
                int sub;
                std::cout << "\n=== AFISARE HAINE ===\n";
                std::cout << "1. Toate hainele\n";
                std::cout << "2. Filtru dupa categorie\n";
                std::cout << "3. Sortare dupa pret crescator\n";
                std::cout << "4. Sortare dupa pret descrescator\n";
                std::cout << "5. Top haina (cel mai bun rating)\n";
                std::cout << "6. Sortare dupa rating\n";
                std::cout << "Alege optiune: ";

                if (!(std::cin >> sub))
                    throw ExceptieInput();

                if (sub == 1) {
                    shop.afiseazaStocComplet();
                } else if (sub == 2) {
                    std::string cat;
                    std::cout << "Categorie (Luxury / Casual / Sport / Office / Eleganta): ";

                    if (!(std::cin >> cat))
                        throw ExceptieInput();

                    shop.afiseazaHaineDupaCategorie(cat);
                } else if (sub == 3) {
                    shop.afiseazaHaineSortateDupaPret();
                } else if (sub == 4) {
                    shop.afiseazaHaineSortateDesc();
                } else if (sub == 5) {
                    shop.afiseazaCeaMaiBunaHaina();
                } else if (sub == 6) {
                    shop.afiseazaHaineSortateDupaRating();
                } else {
                    std::cout << "Optiune invalida!\n";
                }
            } else if (optiune == 3) {
                int idx;
                if (!(std::cin >> idx)) break;

                if (idx < 0 || idx >= (int) shop.getNrHaineInventar())
                    throw ExceptieIndex();

                Haina &h = shop.getHainaDinInventar(idx);

                if (h.getStocActual() == 0)
                    throw ExceptieStoc();

                shop.getManechin().incearcaHaina(h);
                h.scadeStoc();
                shop.recomandaAccesoriu(h);
            } else if (optiune == 4) {
                shop.getManechin().dezbracaManechin();
            } else if (optiune == 5) {
                double pretInitial = shop.getManechin().getValoareTinuta();

                if (pretInitial == 0)
                    throw ExceptieIndex();

                double pretFinal = cl.aplicaReducereFidelitate(pretInitial);

                std::string cod;
                if (!(std::cin >> cod)) break;

                if (cod == "SPRING10")
                    pretFinal = promo10.aplicaReducere(pretFinal);

                if (!cl.poateCumpara(pretFinal))
                    throw ExceptieBuget();

                cl.finalizeazaAchizitie(pretFinal, shop.getManechin());
                registru.inregistreazaTranzactie(pretFinal, shop.getManechin());
                cl.tiparesteBon(pretFinal, cod);
                shop.getManechin().dezbracaManechin();
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
                    const Haina &h = shop.getHainaDinInventar(i);

                    if (h.getCategorie() == "Luxury") {
                        h.afiseazaDetaliiComplete();
                    }
                }
            } else if (optiune == 17) {
                int idx;

                if (!(std::cin >> idx))
                    throw ExceptieInput();

                if (idx < 0 || idx >= (int) shop.getNrHaineInventar())
                    throw ExceptieIndex();

                wl.adauga(&shop.getHainaDinInventar(idx));
            } else if (optiune == 18) {
                wl.afiseaza();

                std::cout << "Total wishlist: "
                        << wl.calculeazaTotal()
                        << " lei\n";
            } else if (optiune == 19) {
                int idx;

                wl.afiseaza();

                std::cout << "Index de sters: ";
                std::cin >> idx;

                wl.sterge(idx);
            } else if (optiune == 20) {
                std::string text;
                std::cout << "Introdu text: ";
                std::cin >> text;
                shop.cautaHaineDupaNume(text);
            } else if (optiune == 21) {
                wl.curataExpirate();
            }
        } catch (const ExceptieInput &e) {
            std::cout << "Eroare input!\n";
        } catch (const ExceptieIndex &e) {
            std::cout << "Index invalid!\n";
        } catch (const ExceptieBuget &e) {
            std::cout << "Fonduri insuficiente!\n";
        } catch (const ExceptieStoc &e) {
            std::cout << "Stoc indisponibil!\n";
        } catch (const std::exception &e) {
            std::cout << "Eroare generala: " << e.what() << "\n";
        }
        if (!std::cin) break; //
    }

    for (auto h: stocInitial)
        delete h;

    std::cout << "\n TESTARE COPY \n";
    Boutique shopCopy = shop; // copy constructor
    Boutique shopAssign{"Temp", adr, manechine[manechinSelectat]};
    shopAssign = shop; // operator=
    std::cout << "Copiere realizata cu succes!\n";

    return 0;
}