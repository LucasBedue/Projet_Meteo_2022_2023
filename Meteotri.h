#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pour gerer l'arbre
typedef struct chainon {
    int val;
    int equilibre;
    struct chainon* fd;
    struct chainon* fg;
} Chainon;

//Pour gerer le tri en largeur
typedef struct chainonfile{
    Chainon* arbre;
    struct chainonfile* suivant;
}ChainonFile;

typedef struct {
    ChainonFile* pHead;
    ChainonFile* pTail;
}Fifo;


Chainon* creerArbre(int valeur);
int estVide(Chainon* pA);
int estFeuille(Chainon* pAr);
int element(Chainon* pAr);
int existeFilsGauche(Chainon* pA);
int existeFilsDroit(Chainon* pA);
void ajouterFilsGauche(Chainon* pAr,int e);
void ajouterFilsDroit(Chainon* pAr,int e);
void traiter(Chainon* pA);
void parcoursPrefixe(Chainon* pAr);
void parcoursPostfixe(Chainon* pAr);
void parcoursInfixe(Chainon* pAr);
int Verifil(Fifo* filou);
Fifo* CreerFile();
ChainonFile* creerChainon(Chainon* Ar);
int enfilerDyn(Fifo* Fil,Chainon* Ar);
ChainonFile* defilerDyn(Fifo* Fil);
void AfficherFile(Fifo* Filou);
void parcoursLargeur(Chainon* pAr);
Chainon* modifierRacine(Chainon* a,int e);
void supprimerFilsDroit(Chainon* pAr);
void supprimerFilsGauche(Chainon* pAr);
int nmbfeuille(Chainon* pAr);
void tailleArbre(Chainon* pAr,int* valu);
void hauteurarbre(Chainon* pAr,int* hautmax,int hautactu);
int filiformeTest(Chainon* pAr,int q);
int peigneGauche(Chainon* pAr,int q);
Chainon* constrPeigneGauche(int h);
int recherche(Chainon* pAr,int e);
Chainon* recinsertABR(Chainon* pAr,int e);
Chainon* iteinsertABR(Chainon* pAr,int e);
Chainon* suppression(Chainon* pAr,int e);
Chainon* suppMax(Chainon* pAr,int* pe);
int verifABR(Chainon* pAr,int *pPrev);
int max(int a,int b);
int min(int a,int b);
Chainon* rotationGauche(Chainon* pAr);
Chainon* rotationDroite(Chainon* pAr);
Chainon* insertionAVL(Chainon* pAr,int e,int* h);
Chainon* doubleRotationGauche(Chainon* pAr);
Chainon* doubleRotationDroit(Chainon* pAr);
Chainon* equilibrerAVL(Chainon* pAr);
Chainon* suppMinAVL(Chainon* pAr,int* h,int* pe);
Chainon* suppressionAVL(Chainon* pAr,int e,int* h);