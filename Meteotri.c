#include "Meteotri.h"

/////////////////////////////////////////////////////////////////////
int main(int argc,char **argv){
    srand(0);
    FILE* f=NULL;

    if(strcmp(argv[1],"-t1")==0){
            char* pathfiletmp="./Meteotmpfilesfolder/filet1";
            f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-t2")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filet2";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-t3")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filet3";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-p1")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filep1";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-p2")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filep2";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-p3")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filep3";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-w")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filew";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-h")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/fileh";
        f=fopen(pathfiletmp,"w");
    }
    else if(strcmp(argv[1],"-m")==0){
        char* pathfiletmp="./Meteotmpfilesfolder/filem";
        f=fopen(pathfiletmp,"w");
    }
    else{
        printf("We entered in the programm without any sorting parameter.\n");
        return 0;
    };


    if(f==NULL){
    printf("Cannot open the tmpfile\n");
    exit(1);
    }

    FILE* fcsv=fopen(argv[2],"r");
    if(fcsv==NULL){
    printf("Cannot open the csv file\n");
    exit(1);
    }

    int value=-1;//le nombre de noeud
    int* pvalue=&value;
    int hauteur=-1;//pour la hauteur de l'arbre
    int* phauteur=&hauteur;
    int compt=1;//pour génerer l'arbre
    int* h=malloc(sizeof(int));//sert à l'équilirage
    Chainon* pArbre=NULL;




    int errfclose=fclose(fcsv);
    if(errfclose==EOF){
        printf("Error in the closing of the csv file.\n");
        exit(2);
    }
    errfclose=fclose(f);
    if(errfclose==EOF){
        printf("Error in the closing of the tmp file.\n");
        exit(2);
    }

    printf("On est passé dans le programme .c !\n");

    return 0;

    /*exo2

parcoursInfixe(pArbre);

printf("Il y a %d feuilles! \n",nmbfeuille(pArbre));

tailleArbre(pArbre,pvalue);
printf("Il y a %d noeuds! \n",value);

hauteurarbre(pArbre,phauteur,0);
if(hauteur==-1){
printf("L'arbre est vide, et n'a pas de hauteur!\n");
}
else{
    printf("L'arbre à une hauteur de %d\n",hauteur);
};

*/


//Ex3

/*
pArbre=insertionAVL(pArbre,10,h);
pArbre=insertionAVL(pArbre,3,h);
pArbre=insertionAVL(pArbre,5,h);
pArbre=insertionAVL(pArbre,15,h);
pArbre=insertionAVL(pArbre,20,h);
pArbre=insertionAVL(pArbre,12,h);
pArbre=insertionAVL(pArbre,7,h);
pArbre=insertionAVL(pArbre,45,h);
pArbre=insertionAVL(pArbre,9,h);
*/
/*
pArbre=insertionAVL(pArbre,10,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,5,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,20,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,15,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,13,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,17,h);
parcoursLargeur(pArbre);
printf("\n");
pArbre=insertionAVL(pArbre,26,h);
parcoursLargeur(pArbre);
printf("\n");
printf("\n");




pArbre=suppressionAVL(pArbre,26,h);

parcoursLargeur(pArbre);

pArbre=suppressionAVL(pArbre,17,h);

parcoursLargeur(pArbre);
*/
//pArbre=suppressionAVL(pArbre,20,h);

//parcoursLargeur(pArbre);


/*
printf("%d\n",pArbre->equilibre);
printf("%d\n",pArbre->fg->equilibre);
printf("%d\n",pArbre->fg->fd->equilibre);
printf("%d\n",pArbre->fd->equilibre);
printf("%d\n",pArbre->fd->fd->equilibre);
printf("%d\n",pArbre->fd->fg->equilibre);
printf("%d\n",pArbre->fg->fd->fd->equilibre);
printf("%d\n",pArbre->fd->fd->fd->equilibre);
printf("%d\n",pArbre->fg->fd->fd->fd->equilibre);
*/



/*
printf("\n");

int* pPrevtmp;



switch (verifABR(pArbre,pPrevtmp)){
    case -1:{
        printf("L'arbre est vide\n");
    };
    break;
    case 0:{
    printf("L'arbre n'est pas un ABR\n");
    };
    break;
    case 1:{
    printf("L'arbre est un ABR\n");
    };
    break;

};
*/



/*
switch (recherche(pArbre,6)){
    case -1:{
        printf("L'arbre est vide\n");
    };
    break;
    case 0:{
    printf("L'arbre ne contient pas la valeur\n");
    };
    break;
    case 1:{
    printf("L'arbre contient la valeur\n");
    };
    break;

};
*/

/*

switch (filiformeTest(pArbre,-1)){
    case -1:{
        printf("L'arbre est vide\n");
    };
    break;
    case 0:{
    printf("L'arbre n'est pas filiforme\n");
    };
    break;
    case 1:{
    printf("L'arbre est filiforme\n");
    };
    break;

};

switch (peigneGauche(pArbre,-1)){
    case -1:{
        printf("L'arbre est vide\n");
    };
    break;
    case 0:{
    printf("L'arbre n'est pas peigne gauche\n");
    };
    break;
    case 1:{
    printf("L'arbre est peigne gauche\n");
    };
    break;

};

*/


}