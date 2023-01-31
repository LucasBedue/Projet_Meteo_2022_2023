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
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatah")==0){//Tri de hauteur
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
                    
                    pArbre=insertionAVLAlt(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    
                    
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);

                }
                else if(c==EOF){
                    pArbre=insertionAVLAlt(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);

                }
                
                

            }
            

            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            parcoursInfixeAlt(pArbre,fsortie,tab,nmbstation);
            
            for(int k=0;k<(*nmbstation);k++){
                
               fprintf(fsortie,"%d %lf %lf %lf\n",tab[k].station,tab[k].altitude,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);

            

            
        }
        else if((argv[5]=="--abl")){

        }
        else if(argv[5]=="--tab"){

        }

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatam")==0){//Tri d'humidité
        rewind(fentree);
        
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;

            while(c!=EOF){

                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if(c==':'){
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
                    
                    pArbre=insertionAVLH(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    
                    
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
            
            for(int k=0;k<(*nmbstation);k++){
                
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



}