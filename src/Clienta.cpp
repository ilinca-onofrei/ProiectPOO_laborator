#include "../include/Clienta.h"

Clienta::Clienta(const std::string &nume_, double buget_)
    : nume{nume_}, buget{buget_}, puncteLoialitate{0} {
}

bool Clienta::poateCumpara(double total) const {
    return buget >= total;
}

void Clienta::finalizeazaAchizitie(double total, const Manechin &m) {
    buget -= total;
    puncteLoialitate += static_cast<int>(total / 10); // 1 punct la fiecare 10 lei

    if (m.getStratBaza()) haineCumparate.push_back(*(m.getStratBaza()));
    if (m.getStratExterior()) haineCumparate.push_back(*(m.getStratExterior()));
    if (m.getIncaltaminte()) haineCumparate.push_back(*(m.getIncaltaminte()));
    if (m.getAccesoriu()) haineCumparate.push_back(*(m.getAccesoriu()));

    std::cout << "Achizitie reusita! " << nume << " are acum " << haineCumparate.size() << " piese in garderoba.\n";
}

double Clienta::getBuget() const {
    return buget;
}

void Clienta::tiparesteBon(double total, const std::string &codPromo) const {
    double tva = total * 0.19;
    double pretFaraTva = total - tva;
    std::cout << " Client: " << nume << "\n";
    std::cout << "\n---------- BON FISCAL CHIC ATELIER ----------\n";
    std::cout << " Produs                  | Pret\n";
    std::cout << "----------------------------------------------\n";
    std::cout << " Subtotal (fara TVA):      " << pretFaraTva << " lei\n";
    std::cout << " TVA (19%):                " << tva << " lei\n";
    if (codPromo != "SARI") {
        std::cout << " Discount aplicat:         " << codPromo << "\n";
    }
    std::cout << "----------------------------------------------\n";
    std::cout << " TOTAL DE PLATA:           " << total << " lei\n";
    std::cout << "----------------------------------------------\n";
    std::cout << " Va multumim pentru vizita!\n\n";
}

std::string Clienta::getNivelFidelitate() const {
    if (puncteLoialitate > 500) return "PLATINUM (Reducere 15%)";
    if (puncteLoialitate > 200) return "GOLD (Reducere 10%)";
    if (puncteLoialitate > 50) return "SILVER (Reducere 5%)";
    return "STANDARD";
}

double Clienta::aplicaReducereFidelitate(double suma) const {
    if (puncteLoialitate > 500) return suma * 0.85;
    if (puncteLoialitate > 200) return suma * 0.90;
    if (puncteLoialitate > 50) return suma * 0.95;
    return suma;
}

void Clienta::afiseazaGarderoba() const {
    std::cout << "\n--- Garderoba personala a lui " << nume << " ---\n";
    if (haineCumparate.empty()) {
        std::cout << "Inca nu ai cumparat nimic.\n";
    } else {
        for (const auto &h: haineCumparate) {
            std::cout << " - " << h << "\n";
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Clienta &c) {
    os << "Clienta: " << c.nume << " | Buget: " << c.buget << " lei | Puncte: " << c.puncteLoialitate;
    return os;
}