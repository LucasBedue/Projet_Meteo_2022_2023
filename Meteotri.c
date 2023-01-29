#include "Meteotri.h"

/////////////////////////////////////////////////////////////////////
int main(int argc,char **argv){/*-f "./Meteotmpfilesfolder/secondfile" -o "./Meteotmpfilesfolder/ordereddata--" "$argtri" -r*/
    srand(0);
    FILE* fentree=fopen(argv[2],"r");
    if(fentree==NULL){
        printf("Error with the file to open, the file to filter\n");
        exit (2);
    };
    FILE* fsortie=fopen(argv[4],"w");
    if(fsortie==NULL){
        printf("Error with the file to create, the file filtered\n");
        exit (2);
    };





    int value=-1;//le nombre de noeud
    int* pvalue=&value;
    int hauteur=-1;//pour la hauteur de l'arbre
    int* phauteur=&hauteur;
    int* h=malloc(sizeof(int));//sert à l'équilirage
    Chainon* pArbre=NULL;

    printf("%s",argv[4]);

    if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat1")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat2")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat3")==0){


    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap1")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap2")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap3")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddataw")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatah")==0){
        

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatam")==0){
        rewind(fentree);
        printf("%s",argv[5]);
        printf("ok1");
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            printf(" ok2 ");
            char station[10];
            char humiditee[30];
            char coordx[30];
            char coordy[30];
            printf(" ok3 ");
            int c=getc(fentree);
            printf("%c",c);
            int i=0;
            while(c!=EOF){
                i=0;
                memset(station,0,10);
                memset(humiditee,0,30);
                memset(coordx,0,30);
                memset(coordy,0,30);
                printf("%s",station);
                printf("%s",humiditee);
                printf("%s",coordx);
                printf("%s",coordy);
                printf(" ok4 ");
                while((c!='\n')||(c!=';')){
                    station[i]=c;
                    i++;
                }
                printf("%s",station);
                i=0;
                while((c!='\n')||(c!=';')){//date1
                }
                while((c!='\n')||(c!=';')){//date2
                }
                while((c!='\n')||(c!=';')){//pression
                }
                while((c!='\n')||(c!=';')){//angle vent
                }
                while((c!='\n')||(c!=';')){//vitesse vent
                }
                while((c!='\n')||(c!=';')){//humidité
                    humiditee[i]=c;
                    i++;
                }
                printf("%s",humiditee);
                i=0;
                while((c!='\n')||(c!=';')){//pression station
                }
                while((c!='\n')||(c!=';')){//variation de pression
                }
                while((c!='\n')||(c!=';')){//précipitation
                }
                while((c!='\n')||(c!=';')){//coordx
                    coordx[i]=c;
                    i++;
                }
                printf("%s",coordx);
                i=0;
                while((c!='\n')||(c!=';')){//coordy
                    coordy[i]=c;
                    i++;
                }
                printf("%s",coordy);
                while((c!='\n')||(c!=';')){//temperature
                }
                while((c!='\n')||(c!=';')){//temperature min
                }
                while((c!='\n')||(c!=';')){//temperaturemax
                }
                while((c!='\n')||(c!=';')){//altitude
                }
                while((c!='\n')||(c!=';')){//commune
                }

                //insertion en fonction de l'humidité
                pArbre=insertionAVLH(pArbre,atoi(station),2000,2000,atof(humiditee),2000,2000,2000,atof(coordx),atof(coordy),h);


            }
            //on dresse une liste des stations, avec leur humidité max et leurs coordonnées
            Chainon listestation[100];
            int* nmbstation=malloc(sizeof(int));
            *nmbstation=0;
            parcoursPrefixeH(pArbre,listestation,nmbstation);
            Chainon* pArbre2;
            *h=0;
            for(int k=0;k<*nmbstation;k++){
                pArbre2=insertionAVLH(pArbre2,listestation[k].station,listestation[k].temperature,listestation[k].pression,listestation[k].humidite,listestation[k].forcevent,listestation[k].anglevent,listestation[k].altitude,listestation[k].coordx,listestation[k].coordy,h);
            }
            rewind(fsortie);

            parcoursInfixeH(pArbre2,fsortie);



        }
        else if((argv[5]=="--abl")){

        }
        else if(argv[5]=="--tab"){

        }



        


    }












    int errfclose=fclose(fentree);
    if(errfclose==EOF){
        printf("Error with the closing of the fentree file\n");
        exit (3);
    };
    errfclose=fclose(fsortie);
    if(errfclose==EOF){
        printf("Error with the closing of the fsortie file\n");
        exit (3);
    };


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