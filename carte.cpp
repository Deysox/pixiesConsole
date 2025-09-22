//
// Created by barnab on 21/09/2025.
//

#include <string>
#include "carte.h"

#include <iostream>
using namespace std;

bool memeCouleur(Couleur c1, Couleur c2) {
    return c1 == Couleur::multicolore || c2 == Couleur::multicolore || c1 == c2;
}

// Spirale
int Spirale::getValeur() const {
    return valeur;
}

bool Spirale::getScaling() const {
    return scaling;
}

void Spirale::setValeur(int n) {
    if (-6 < n && n < 6) {
        valeur = n;
    } else {
        throw;
    }
}

void Spirale::setScaling(bool b) {
    scaling = b;
}




// Carte
Couleur Carte::getCouleur() const {
    return col;
}

int Carte::getNombre() const {
    return nombre;
}

Spirale Carte::getSpirale() const {
    return spirale;
}

Statut Carte::getStatut() const {
    return statut;
}

bool Carte::estValide() {
    return statut == Statut::valide;
}


void Carte::setNombre(const int n) {
    if (0 < n && n < 10) {
        nombre = n;
    } else {
        throw;
    }
}

void Carte::setCouleur(const Couleur c) {
    col = c;
}

void Carte::setSpirale(const Spirale sp) {
    spirale = sp;
}

void Carte::setSpirale(const int n) {
    spirale.setValeur(n);
}

void Carte::setSpirale(bool b) {
    spirale.setScaling(b);
}

void Carte::setStatut(Statut st) {
    statut = st;
}

void Carte::valider() {
    statut = Statut::valide;
}

string Carte::afficher() {
    string output;
    if (statut == Statut::vide) {
        output = "     ";
    } else if (statut == Statut::cache) {
        output = "|||||";
    } else {
        output += (statut == Statut::valide) ? "\033[7;" : "\033[0;";
        string str_col;
        switch (col) {
            case Couleur::bleu:
                str_col = "34mB";
                break;
            case Couleur::jaune:
                str_col = "33mJ";
                break;
            case Couleur::rouge:
                str_col = "31mR";
                break;
            case Couleur::vert:
                str_col = "32mV";
                break;
            case Couleur::multicolore:
                str_col = "35mM";
                break;
            default:
                str_col = "";
                break;
        }
        output += str_col;
        output += to_string(nombre);

        if (spirale.getScaling()) {
            output += "*c";
        } else
        {
            if (spirale.getValeur() != 0) {
                if (spirale.getValeur() < 0) {
                    output += "-";
                } else {
                    output += "+";
                }
                output += to_string(abs(spirale.getValeur()));
            } else {
                output += "  ";
            }

        }


        if (statut == Statut::valide) {
            output = output + "v";
        } else {
            output = output + " ";
        }

        output += "\033[0m";

    }
    return output;
}
