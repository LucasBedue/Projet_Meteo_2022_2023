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
        
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;

            while(c!=EOF){

                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if((c=='-')||(c==':')){
                        f++;
                        c=getc(fentree);
                    }
                    else{
                        carac[i][f]=c;
                    f++;
                    c=getc(fentree);
                    }
                    
                }
                else if(c==';'){
                    i++;
                    f=0;
                    c=getc(fentree);
                }
                else if(c=='\n'){
                    i=0;
                    f=0;
                    //Chainon* pArbre=creerArbre(atoi(carac[1]),atoi(carac[2]),atoi(carac[3]),atof(carac[4]),atof(carac[5]),atof(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atof(carac[16]),atoi(carac[17]));
                    //printf("%d %d %d %f %f %f %f %f %f %f %f %f %f %f %f %f %d",pArbre->station,pArbre->date,pArbre->heure,pArbre->pressionmer,pArbre->anglevent,pArbre->forcevent,pArbre->humidite,pArbre->pression,pArbre->varpression,pArbre->precipitation,pArbre->coordx,pArbre->coordy,pArbre->temperature,pArbre->temperaturemin,pArbre->temperaturemax,pArbre->altitude,pArbre->commune);
                    pArbre=insertionAVLH(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    
                    //free(pArbre);
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);

                }
                else if(c==EOF){
                    pArbre=insertionAVLH(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);

                }
                
                

            }
            

            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            parcoursInfixeH(pArbre,fsortie,tab,nmbstation);
            printf("%d",(*nmbstation));
            for(int k=0;k<(*nmbstation);k++){
                printf("%d %d %lf %lf\n",tab[k].station,tab[k].humidite,tab[k].coordx,tab[k].coordy);
                fprintf(fsortie,"%d %d %lf %lf\n",tab[k].station,tab[k].humidite,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);

            

            
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