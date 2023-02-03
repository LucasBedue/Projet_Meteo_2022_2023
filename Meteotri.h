#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Le chainon pour avl et abr.
typedef struct chainon{
    int station;
    int date;
    int heure;
    double pressionmer;
    double anglevent;
    double forcevent;
    int humidite;
    double pression;
    double varpression;
    double precipitation;
    double coordx;
    double coordy;
    double temperature;
    double temperaturemin;
    double temperaturemax;
    double altitude;
    int commune;
    int equilibre;
    struct chainon* fd;
    struct chainon* fg;
}Chainon;

//Les fonctions a usage global.
Chainon* creerArbre(int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
int estVide(Chainon* pA);
int estFeuille(Chainon* pAr);
int existeFilsGauche(Chainon* pA);
int existeFilsDroit(Chainon* pA);
void ajouterFilsGauche(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
void ajouterFilsDroit(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
Chainon* modifierRacine(Chainon* a,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
void supprimerFilsDroit(Chainon* pAr);
void supprimerFilsGauche(Chainon* pAr);
int nmbfeuille(Chainon* pAr);
void tailleArbre(Chainon* pAr,int* valu);
void hauteurarbre(Chainon* pAr,int* hautmax,int hautactu);
int max(int a,int b);
int min(int a,int b);
Chainon* rotationGauche(Chainon* pAr);
Chainon* rotationDroite(Chainon* pAr);
Chainon* doubleRotationGauche(Chainon* pAr);
Chainon* doubleRotationDroit(Chainon* pAr);
Chainon* equilibrerAVL(Chainon* pAr);

//Fonctions pour le tri -m.
Chainon* insertionAVLH(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeH(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
void traiterH2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
Chainon* insertionABRH(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);

//Fonctions pour le tri -h.
Chainon* insertionAVLAlt(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeAlt(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
void traiterAlt2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
Chainon* insertionABRAlt(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);

//Fonctions pour le tri -w.
Chainon* insertionAVLV(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeV(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio);
void traiterV2(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio);

//Fonctions pour le tri -t1.
Chainon* insertionAVLT1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeT1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio);
void traiterT12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio);

//Fonctions pour le tri -p1.
Chainon* insertionAVLP1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeP1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio);
void traiterP12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio);

//Fonctions pour le tri -t2.
Chainon* insertionAVLT2(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeT2(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat);
void traiterT22(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat);

//Fonctions pour le tri -p2.
Chainon* insertionAVLP2(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeP2(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double pressmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat);
void traiterP22(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double pressmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat);
