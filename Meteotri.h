#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Pour gerer l'arbre
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



//Pour gerer le tri en largeur
typedef struct chainonfile{
    Chainon* arbre;
    struct chainonfile* suivant;
}ChainonFile;

typedef struct {
    ChainonFile* pHead;
    ChainonFile* pTail;
}Fifo;


Chainon* creerArbre(int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
int estVide(Chainon* pA);
int estFeuille(Chainon* pAr);
//int element(Chainon* pAr);
int existeFilsGauche(Chainon* pA);
int existeFilsDroit(Chainon* pA);
void ajouterFilsGauche(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
void ajouterFilsDroit(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
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
Chainon* modifierRacine(Chainon* a,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun);
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

////////////Humidite

//void parcoursPrefixeH(Chainon* pAr,Chainon* listestatio,int* nmbstation);
//void traiterH(Chainon* pAr,Chainon* listestatio,int* nmbstation);
//Chainon* iteinsertABRH(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory);
Chainon* insertionAVLH(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeH(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
void traiterH2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);

///////////Altitude
Chainon* insertionAVLAlt(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeAlt(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);
void traiterAlt2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio);

///////////Vent
Chainon* insertionAVLV(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeV(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio);
void traiterV2(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio);

//////////Températuret1

Chainon* insertionAVLT1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeT1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio);
void traiterT12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio);

/////////Pressionp1

Chainon* insertionAVLP1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeP1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio);
void traiterP12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio);

//////////Températuret2
Chainon* insertionAVLT2(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h);
void parcoursInfixeT2(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[500],int* nmbdat);
void traiterT22(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[500],int* nmbdat);
