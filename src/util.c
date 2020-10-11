#include "util.h"


////////////////////////////////////////////////////////////////////////////////
// Affichage

/**
Affiche la matrice a
@param m : hauteur
@param n : largeur
@param a : matrice, vu comme un tableau contenant les colonnes de manière continue
@param lda : leading dimension (si a est une sous-matrice d'une matrice M, lda est la hauteur de M (car on stocke par colonne))
@param flux : flux de sortie
*/
void affiche(int m, int n, double *a, int lda, FILE * flux){
  // ligne
  for (int i = 0; i < m; i++){
    // colonne
    for (int j = 0; j < n; j++){
      fprintf(flux, "%f  ", a[i + j * lda]);
    }
    // fin de la ligne
    fprintf(flux, "\n");
  }
}

/**
Affiche le vecteur v
@param n : taille
@param v : vecteur
@param lda : leading dimension (si v est un vecteur d'une ligne matrice M, lda est la hauteur de M (car on stocke par colonne))
@param flux : flux de sortie
*/
void affiche_vecteur(int n, double *v, int lda, FILE * flux){
  for (int i = 0; i < n; i++){
    fprintf(flux, "%f", v[i * lda]);
    fprintf(flux, "\n");
  }
}


////////////////////////////////////////////////////////////////////////////////
// Allocation et libération des matrices et des vecteurs

/**
Alloue la mémoire pour une matrice de dim m*n, et renvoie un pointeur vers cette matrice
@param m : hauteur
@param n : largeur
@return Un pointeur sur la matrice
*/
double * matrice(int m, int n){
  double * mat = malloc(m * n * sizeof(double));
  return mat;
}

/**
Alloue la mémoire pour un vecteur de dim n, et renvoie un pointeur vers ce vecteur
@param m : hauteur
@return Un pointeur sur le vecteur
*/
double * vecteur(int n){
  double * vec = malloc(n * sizeof(double));
  return vec;
}

/**
Libère la mémoire pour la matrice "a"
@param a La matrice
*/
void free_matrice(double *a){
  free(a);
}

/**
Libère la mémoire pour le vecteur "a"
@param a La matrice
*/
void free_vecteur(double *v){
  free(v);
}


////////////////////////////////////////////////////////////////////////////////
// Initialisation et modification des matrices et des vecteurs

/**
Fixe la valeur de l'élément en position (m, n) à "val"
@param m : ligne
@param n : colonne
@param a : matrice
@param val : nouvel valeur de l'élément en position (m, n)
*/
void fixer_elt_matrice(int m, int n, int lda, double *a, double val){
  a[m + n * lda] = val;
}

/**
Fixe la valeur de l'élément en position "n" à "val"
@param n : numéro de l'élément à modifier
@param v : matrice
@param val : nouvel valeur de l'élément en position (m, n)
*/
void fixer_elt_vecteur(int n, int lda, double *v, double val){
  v[n * lda] = val;
}

/**
initialise la matrice en allant de 1.0 à m*n, de gauche à droite puis de haut en bas
@param m : hauteur
@param n : largeur
@param a : matrice
*/
void init_matrice(int m, int n, int lda, double *a){
  double val = 1.0;
  // ligne
  for (int i = 0; i < m; i++){
    // colonne
    for (int j = 0; j < n; j++){
      a[i + j * lda] = val;
      val++;
    }
  }
}

/**
initialise le vecteur en allant de 1.0 à n, de haut en bas
@param n : taille
@param v : vecteur
*/
void init_vecteur(int n, int lda, double *v){
  double val = 1.0;
  for (int i = 0; i < n; i++){
    v[i * lda] = val;
    val++;
  }
}


////////////////////////////////////////////////////////////////////////////////
// Opération sur les matrices et les vecteurs

/**
Effectue le produit scalaire entre les vecteurs "X" et "Y"
@param N Nombre d'éléments des vecteurs "X" et "Y"
@param X Vecteur "X"
@param incX Incrément entre chaque élément de "X"
@param Y Vecteur "Y"
@param incX Incrément entre chaque élément de "Y"
@return Le résultat du produit scalaire
*/
double my_ddot(const int N, const double *X, const int incX, const double *Y, const int incY){
  int res = 0;

  for (int i = 0; i < N; i++){
    res += X[i*incX] * Y[i*incY];
  }

  return res;
}