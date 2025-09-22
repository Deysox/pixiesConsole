#include <iostream>
#include "carte.h"
#include "grille.h"

int main() {
    auto carte1 = new Carte(1, Couleur::rouge, Spirale(5, false), Statut::paquet);
    auto carte2 = new Carte(2, Couleur::rouge, Spirale(2, false), Statut::paquet);
    auto carte3 = new Carte(2, Couleur::rouge, Spirale(4, false), Statut::paquet);
    auto carte4 = new Carte(5, Couleur::rouge, Spirale(5, true), Statut::paquet);
    auto carte5 = new Carte(8, Couleur::rouge, Spirale(0, false), Statut::paquet);
    auto carte6 = new Carte(7, Couleur::jaune, Spirale(-5, false), Statut::paquet);
    auto carte7 = new Carte(2, Couleur::vert, Spirale(4, false), Statut::paquet);
    auto carte8 = new Carte(6, Couleur::multicolore, Spirale(-1, false), Statut::paquet);
    auto carte9 = new Carte(3, Couleur::vert, Spirale(4, false), Statut::paquet);
    auto carte10 = new Carte(9, Couleur::vert, Spirale(-3, false), Statut::paquet);
    auto carte11 = new Carte(9, Couleur::bleu, Spirale(-2, false), Statut::paquet);

    Grille grid;
    grid.placerCarteVisible(carte1, false);
    grid.placerCarteVisible(carte2, false);
    grid.placerCarteVisible(carte3, true);
    grid.placerCarteVisible(carte4, false);
    grid.placerCarteVisible(carte5, false);
    grid.placerCarteVisible(carte6, false);
    grid.placerCarteCache(carte7, 6);
    grid.placerCarteVisible(carte8, true);
    grid.placerCarteVisible(carte9, true);
    grid.placerCarteVisible(carte10, true);
    grid.placerCarteVisible(carte11, true);

    grid.afficher();

    std::cout << to_string(grid.score(1)) << std::endl;

    return 0;
}