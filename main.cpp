#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "OutilsCreationImage.h"
#include "couleur.h"
#include "geometrie.h"
using namespace std;

int main() {
    string chemin = "..\\images_creees";
    string nomFichierImage = chemin + "\\saturne_perspective_jeudi2.bmp";

    const int NOMBRE_LIGNES = 428;
    const int NOMBRE_COLONNES = 760;

    unsigned long matrice[NOMBRE_LIGNES][NOMBRE_COLONNES];
    int m = NOMBRE_LIGNES - 1;
    int n = NOMBRE_COLONNES - 1;

    double xc = n / 2;
    double yc = m / 2;

    // Couleurs
    unsigned long Orangevif = 0xFF0000FF;
    unsigned long Orangeclair = 0xF0E68CFF;
    unsigned long Blanc = 0xFFFFFFFF;
    unsigned long solcaliente = 0xffb200FF;
    unsigned long seaGreen = 0x20B2AAFF;

    int k = 3;
    unsigned long couleurs[k] = {seaGreen, Orangeclair, seaGreen};

    // Paramètres du disque
    int rayon = 100;
    int x_degrade = xc - 70;
    int y_degrade = yc - 10;
    double distance_max = rayon + distance(x_degrade, y_degrade, xc, yc);
    int s = 4;
    unsigned long couleursplanete[s] = {Blanc, solcaliente, Orangevif, seaGreen};

    // Limite du dégradé
    double limite_intervalle = 0.4;

    // Paramètres des anneaux inclinés
    int a1 = 225, b1 = 50, a2 = 265, b2 = 57;  // Premier anneau
    int a3 = 165, b3 = 40, a4 = 215, b4 = 47;  // Deuxième anneau
    double aincline = cos(-M_PI / 6);
    double bincline = sin(-M_PI / 6);

    // Paramètres de l'ombre
    double xOmbre, yOmbre, aOmbre, bOmbre, p, q;
    xOmbre = n / 2 + 100;
    yOmbre = m / 2 - 100 / 2 - 30;
    aOmbre = 250;
    bOmbre = 50;
    p = cos(-M_PI / 6) + aincline;
    q = sin(-M_PI / 6) + bincline;


    // Calcul de la droite qui sépare la partie supérieure et inférieure


    for (int i = 0; i < NOMBRE_LIGNES; i++) {
        for (int j = 0; j < NOMBRE_COLONNES; j++) {
            // Calcul de la distance au centre du disque
            double d_cercle = distance(j, i, xc, yc);

            // Dessiner le disque en premier
            if (d_cercle <= rayon ) {
                double d_degrade = distance(j, i, x_degrade, y_degrade);
                double distance_normalisee = d_degrade / distance_max;

                unsigned long couleurFinale;
                couleurFinale = tachePlanete(distance_normalisee,couleursplanete,limite_intervalle);
                matrice[i][j] = couleurFinale;
            }

            // Partie supérieure des anneaux (masquée par le disque)

            if ((appartientanneauSuperieurIncline(j,i,xc,yc,a1,b1,a2,b2,aincline,bincline) && d_cercle > rayon  )||
                (appartientanneauSuperieurIncline(j,i,xc,yc,a3,b3,a4,b4,aincline,bincline) && d_cercle > rayon )) {
                if (appartientanneauInclinee(j, i, xc, yc, a1, b1, a2, b2, aincline, bincline)) {
                    double tDebut = 0;
                    double tfin = 0.4;
                    double t = Fxy(j, i, xc, yc, a1, b1, aincline, bincline);
                    unsigned long cf = melange(t, tDebut, tfin, couleurs, k);

                    if (appartientEllipseInclinee(j, i, xOmbre, yOmbre, aOmbre, bOmbre, p, q)) {
                        cf = monBlend2(0.5, cf, 0x000000FF);
                    }

                    matrice[i][j] = cf;
                }

                if (appartientanneauInclinee(j, i, xc, yc, a3, b3, a4, b4, aincline, bincline)) {
                    double tDebut = 0;
                    double tfin = 0.6;
                    double t = Fxy(j, i, xc, yc, a3, b3, aincline, bincline);
                    unsigned long cf = melange(t, tDebut, tfin, couleurs, k);

                    if (appartientEllipseInclinee(j, i, xOmbre, yOmbre, aOmbre, bOmbre, p, q)) {
                        cf = monBlend2(0.5, cf, 0x000000FF);
                    }

                    matrice[i][j] = cf;
                }
            }

            // Partie inférieure des anneaux (au-dessus du disque)
            if (!appartientanneauSuperieurIncline(j,i,xc,yc,a1,b1,a2,b2,aincline,bincline) && !appartientanneauSuperieurIncline(j,i,xc,yc,a3,b3,a4,b4,aincline,bincline)) {
                if (appartientanneauInclinee(j, i, xc, yc, a1, b1, a2, b2, aincline, bincline)) {
                    double tDebut = 0;
                    double tfin = 0.4;
                    double t = Fxy(j, i, xc, yc, a1, b1, aincline, bincline);
                    unsigned long cf = melange(t, tDebut, tfin, couleurs, k);

                    if (appartientEllipseInclinee(j, i, xOmbre, yOmbre, aOmbre, bOmbre, p, q)) {
                        cf = monBlend2(0.5, cf, 0x000000FF);
                    }

                    matrice[i][j] = cf;
                }

                if (appartientanneauInclinee(j, i, xc, yc, a3, b3, a4, b4, aincline, bincline)) {
                    double tDebut = 0;
                    double tfin = 0.6;
                    double t = Fxy(j, i, xc, yc, a3, b3, aincline, bincline);
                    unsigned long cf = melange(t, tDebut, tfin, couleurs, k);

                    if (appartientEllipseInclinee(j, i, xOmbre, yOmbre, aOmbre, bOmbre, p, q)) {
                        cf = monBlend2(0.5, cf, 0x000000FF);
                    }

                    matrice[i][j] = cf;
                }
            }
        }
    }

    // Création de l'image
    OutilsCreationImage::creeImage<NOMBRE_COLONNES>(nomFichierImage, matrice, NOMBRE_LIGNES);

    return 0;
}
