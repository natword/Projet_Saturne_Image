//
// Created by USER on 08/12/2024.
//

#ifndef GEOMETRIE_H
#define GEOMETRIE_H
#include <math.h>
#include <stdbool.h>
/* TACHE: Calcule le carree de la distance entre 2 points P1(x1,y1) et P2(x2,y2)
 *
 * DONNEES : x1, x2, y1, y2
 *
 * RESULTATS : Le carre de la distance entre P1 et P2
 */

inline double distanceCarree(const double x1, const double y1, const double x2, const double y2){
    double dx = x1-x2;
    double dy = y1-y2;

    return (dx*dx + dy*dy);
};

inline double distance(const double x1, const double y1, const double x2, const double y2) {
    return sqrt(distanceCarree(x1,y1,x2,y2));
}

/*
 *  TACHE: determine si un point (x,y) est situe a l'interieur d'une ellipse de centre (x0,y0) et de rayon a et b
 *
 *  DONNEE: Les coordonnes du point (x,y) , les coordonnees (x0,yo) de l'ellipse et son petit et grand rayon a et b
 *
 *  RESULTAT : renvoie vrai si le point appartient a l'ellipse et dans le cas contraire renvoie faux
 *
 */
inline bool appartenanceEllipse(const int x, const int y, const int x0, const int y0, const double a, const double b) {
    double condition;
    condition = pow((x-x0)/a,2) + pow((y-y0)/b,2) - 1; // le point appartient a l'ellipse si condition <= 0
    return (condition <= 0);
}

/*
 * TACHE : Determine si un point (x,y) est situe a l'interieur d'un anneau elliptique A forme par deux ellipses E1 et E2
 *         concentriques de centre (x0,y0) et de rayons respectifs a1,b1 et a2,b2
 *
 * DONNEE: les coordonnees (x,y) du point , les coordonnees du centre des deux ellipses et leurs deux rayons respectifs
 *
 * RESULTAT : renvoie vrai si le point apppartient a l'interieur de A et dans le cas contraire renvoie faux
 */

inline bool appartientAnneau(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2) {
    if (appartenanceEllipse(x,y,x0,y0,a2,b2) && !appartenanceEllipse(x,y,x0,y0,a1,b1)) return true;
    return false;
}

/*
 * TACHE : Determine si un point (x,y) est situe a l'interieur d'un demi-anneau elliptique gauche Ag forme par deux ellupses E1 et E2 concentriques
 *         de centre (x0,y0) et de rayon respectifs a1,b1 et a2,b2
 *
 * DONNEE: les coordonnees (x,y) du point , les coordonnees du centre des deux ellipses et leurs deux rayons respectifs
 *
 * RESULTAT: renvoie vrai si le point apppartient a l'interieur de Ag et dans le cas contraire renvoie
 */

inline bool appartientAnneauG(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2) {
    if (appartientAnneau(x,y,x0,y0,a1,b1,a2,b2) && (x <= x0)) return true;
    return false;
}

/*
 * TACHE : Determine si un point (x,y) est situe a l'interieur d'un demi-anneau elliptique droite Ad forme par deux ellupses E1 et E2 concentriques
 *         de centre (x0,y0) et de rayon respectifs a1,b1 et a2,b2
 *
 * DONNEE: les coordonnees (x,y) du point , les coordonnees du centre des deux ellipses et leurs deux rayons respectifs
 *
 * RESULTAT: renvoie vrai si le point apppartient a l'interieur de Ad et dans le cas contraire renvoie
 */

inline bool appartientAnneauD(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2) {
    if (appartientAnneau(x,y,x0,y0,a1,b1,a2,b2) && (x >= x0)) return true;
    return false;
}

/*
 * TACHE : Calcul |f(x,y)|
 *
 * DONNEE: les coordonnes (x,y) du point P , le centre de l'ellipse (x0,y0) et les rayons de l'ellipse a et b
 *
 * RESULTAT: Calcul |f(x,y)|
 */

double calculDef(const int x, const int y , const double x0, const double y0, const double a , const double b) {
    double f;
    f =  abs(pow((x-x0)/a,2) + pow((y-y0)/b,2) - 1);
    return f;
}

/*
 *  TACHE : Determine les points d'intersection (xp1,yp1) et (xp2,yp2) d'un ellipse de centre (x0,y0) et de rayons a et b
 *          et d'une droite (D) passant par le centre de l'ellipse et d'un point P(x,y)
 *
 *  DONNEE: le point P(x,y) , le centre (x0,yo) et les rayons a et b de l'ellipse
 *
 *  DONNEE/RESULTAT : les points d'intersections (xp1,yp1) et (xp2,yp2)
 *
 */
void pointDintersectionDeEllipseEtDroite(const double x,const double y, const double x0 , const double y0, const double a
    , const double b, double *xp1, double *yp1, double *xp2 , double *yp2) {
    double dx, dy;
    dx = x-x0;
    dy = y-y0;
    double k ;
    k = (pow(dx,2)/a + pow(dy,2)/b);

    double t1, t2;
    t1 = sqrt(1/k);
    t2 = -sqrt(1/k);

    *xp1 = x0 + t1 *dx;
    *yp1 = y0 + t1*dy;
    *xp2 = x0 + t2*dx;
    *yp2 = y0 + t2*dy;
}
inline double Fxy(const double x, const double y, const double x0 , const double y0, const double a, const double b, double p, double q ) {
   double dx,dy,u,v;
   dx = x-x0;
   dy = y-y0;
   u = p * dx + q * dy;
   v = p * dy - q * dx;
   return (pow(u/a,2) + pow(v/b,2) -1 );
}

/*
 * TACHE : determine si un pixel (x,y) appartient a un ellipse inclinee
 *
 * DONNEE: les coordonnees du pixel (x,y) le centre le l'ellipse (x0,y0) , le grand et le petit rayon de l'ellipse a et b et l'inclinaison de l'ellipse p et q
 *
 * RESULTAT: renvoie vrai si le pixel appartient a l'ellipse sinon faux
 *
 */
inline bool appartientEllipseInclinee(const double x, const double y, const double x0 , const double y0, const double a, const double b, double p, double q ) {
   double f = Fxy(x,y,x0,y0,a,b,p,q);
   return (f <= 0);
}

inline bool appartientanneauSuperieur(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2) {
    if (appartientAnneau(x,y,x0,y0,a1,b1,a2,b2) && (y >= y0)) return true;
    else return false ;
}

inline bool appartientanneauInferieur(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2) {
    if (appartientAnneau(x,y,x0,y0,a1,b1,a2,b2) && (y < y0)) return true;
    else return false;
}

/*
 * TACHE: Determiner si un pixel appartient a l'anneau inclinee
 *
 * DONNEE: coordonnee du pixel (x,y) ,coordonne du centre de l'anneau (x0,y0) , leurs rayons respectifs et les parametres d'inclinaisons

 * RESULTAT: Renvoie vrai si le pixel appartient a l'anneau inclinee , sinon renvoie faux
 *
 */

inline bool appartientanneauInclinee(const int x, const int y, const int x0, const int y0, const double a1, const double b1, const double a2, const double b2,const double a, const double b ) {
    if (appartientEllipseInclinee(x,y,x0,y0,a2,b2,a,b) && !appartientEllipseInclinee(x,y,x0,y0,a1,b1,a,b)) return true;
    return false;
}


/*
 * TACHE: Determiner si un pixel appartient a la partie superieur de l'anneau inclinee
 *
 * DONNEE: coordonnee du pixel (x,y) ,coordonne du centre de l'anneau (x0,y0) , leurs rayons respectifs et les parametres d'inclinaisons

 * RESULTAT: Renvoie vrai si le pixel appartient  , sinon renvoie faux
 *
 */
inline bool appartientanneauSuperieurIncline(const int x, const int y,double x0,double y0, double a1,double b1,double a2, double b2,  const double a,const double b) {
    /*
     * La droite D passant par le centre de l'ellipse est de coordonne (a,b) , donc les coordonnes de n son vecteur normale est (-b,a)
     */
    double a_droite = b;   // Coefficient de la droite (basé sur l'inclinaison)
    double b_droite = -a;  // Coefficient de la droite (basé sur l'inclinaison)
    double c_droite = -(a_droite * x0 + b_droite * y0); // Ordonnée à l'origine pour passer par (xc, yc)
    double position = a_droite * x + b_droite * y + c_droite;

    return (position>=0 && appartientanneauInclinee(x,y,x0,y0,a1,b1,a2,b2,a,b));
}
/*
 * Deuxieme solution : utiliser la formule de la rotation d'un point dans un repere
 */
inline bool appartientanneauSuperieurIncline2(const int x, const int y, double x0, double y0, double a1, double b1, double a2, double b2, const double angle) {
    // Calcul de la position du point par rapport à la droite horizontale inclinée
    double dx = x - x0;
    double dy = y - y0;
    double cosAngle = cos(angle);
    double sinAngle = sin(angle);
    // Formule de la rotation d'un point dans un repere
    double xRot = dx * cosAngle + dy * sinAngle;
    double yRot = -dx * sinAngle + dy * cosAngle;

    // Vérifie si le point est au-dessus de la droite horizontale inclinée et appartient à l'anneau incliné
    return (yRot >= 0 && appartientanneauInclinee(x, y, x0, y0, a1, b1, a2, b2, cosAngle, sinAngle));
}







#endif //GEOMETRIE_H
