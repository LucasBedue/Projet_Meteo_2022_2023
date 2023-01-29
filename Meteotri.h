#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pour gerer l'arbre
typedef struct chainon{
    int station;
    float temperature;
    float pression;
    float humidite;
    float anglevent;
    float forcevent;
    float altitude;
    float coordx;
    float coordy;
    int equilibre;
    struct chainon* fd;
    struct chainon* fg;
}Chainon;



//Pour gerer le tri en largeur
typedef struct chainonfile{
    Chainon* arbre;
    struct chainonfile* suivant;
}ChainonFile;

typedef struct {
    ChainonFile* pHead;
    ChainonFile* pTail;
}Fifo;


Chainon* creerArbre(int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
int estVide(Chainon* pA);
int estFeuille(Chainon* pAr);
//int element(Chainon* pAr);
int existeFilsGauche(Chainon* pA);
int existeFilsDroit(Chainon* pA);
void ajouterFilsGauche(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
void ajouterFilsDroit(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
//void traiter(Chainon* pA);
//void parcoursPrefixe(Chainon* pAr);
//void parcoursPostfixe(Chainon* pAr);
//void parcoursInfixe(Chainon* pAr);
//int Verifil(Fifo* filou);
//Fifo* CreerFile();
//ChainonFile* creerChainon(Chainon* Ar);
//int enfilerDyn(Fifo* Fil,Chainon* Ar);
//ChainonFile* defilerDyn(Fifo* Fil);
//void AfficherFile(Fifo* Filou);
//void parcoursLargeur(Chainon* pAr);
Chainon* modifierRacine(Chainon* a,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
void supprimerFilsDroit(Chainon* pAr);
void supprimerFilsGauche(Chainon* pAr);
int nmbfeuille(Chainon* pAr);
void tailleArbre(Chainon* pAr,int* valu);
void hauteurarbre(Chainon* pAr,int* hautmax,int hautactu);
//Chainon* recinsertABR(Chainon* pAr,int e,int statio,float temperatur,float pressio,float humidit,float ven,float altitud,float coorx,float coory);
//Chainon* iteinsertABR(Chainon* pAr,int e,int statio,float temperatur,float pressio,float humidit,float ven,float altitud,float coorx,float coory);
//Chainon* suppression(Chainon* pAr,int e);
//Chainon* suppMax(Chainon* pAr,int* pe);
//int verifABR(Chainon* pAr,int *pPrev);
int max(int a,int b);
int min(int a,int b);
Chainon* rotationGauche(Chainon* pAr);
Chainon* rotationDroite(Chainon* pAr);
//Chainon* insertionAVL(Chainon* pAr,int e,int* h);
Chainon* doubleRotationGauche(Chainon* pAr);
Chainon* doubleRotationDroit(Chainon* pAr);
Chainon* equilibrerAVL(Chainon* pAr);
//Chainon* suppMinAVL(Chainon* pAr,int* h,int* pe);
//Chainon* suppressionAVL(Chainon* pAr,int e,int* h);

////////////H

void parcoursPrefixeH(Chainon* pAr,Chainon* listestatio,int* nmbstation);
void traiterH(Chainon* pAr,Chainon* listestatio,int* nmbstation);
Chainon* iteinsertABRH(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
Chainon* insertionAVLH(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory,int* h);
void parcoursInfixeH(Chainon* pAr,FILE* fsorti);
void traiterH2(Chainon* pAr,FILE* fsorti);
///////////