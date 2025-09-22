//
// Created by barnab on 21/09/2025.
//

#ifndef PIXIES_CARTE_H
#define PIXIES_CARTE_H

#include <string>
using namespace std;

enum class Couleur {rouge, bleu, vert, jaune, multicolore};
bool memeCouleur(Couleur c1, Couleur c2);

enum class Statut{vide, visible, cache, valide, paquet};

class Spirale {
    int valeur;
    bool scaling;
public:
    Spirale(int n, bool b) : valeur(n), scaling(b) {};
    int getValeur() const;
    bool getScaling() const;
    void setValeur(int n);
    void setScaling(bool b);
};

class Carte {
    int nombre;
    Couleur col;
    Spirale spirale;
    Statut statut;
public:
    Carte() : nombre(1), col(Couleur::rouge), spirale(Spirale(0,false)), statut(Statut::vide)  {};
    Carte(int n, Couleur c, Spirale sp, Statut st) : nombre(n), col(c), spirale(sp), statut(st) {};
    Couleur getCouleur() const;
    int getNombre() const;
    Spirale getSpirale() const;
    Statut getStatut() const;
    bool estValide();
    void setNombre(int n);
    void setCouleur(Couleur c);
    void setSpirale(int n);
    void setSpirale(bool b);
    void setSpirale(Spirale sp);
    void setStatut(Statut st);
    void valider();
    string afficher();
};

#endif //PIXIES_CARTE_H