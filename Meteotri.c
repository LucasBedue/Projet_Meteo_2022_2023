#include "Meteotri.h"

/*
Ce programme ouvre le fichier 'secondfile' et l'emplacement d'arrivé des données ordonnées.
Il regarde les arguments, tri avec un avl,abr ou tableau, at imprime tout dans le fichier de la forme 'ordereddate--'.
*/

int main(int argc,char **argv){
//On ouvre les fichiers d'entrées et de sorties.
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
    srand(0);
    int* h=malloc(sizeof(int));//Sert à l'équilirage.
    Chainon* pArbre=NULL;//L'arbre.


    if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat1")==0){//On regarde le nom du fichier d'entrée. C'est le tri t1.
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){//On regarde l'argument de tri.
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;

            while(c!=EOF){//On lis les caractères un par un,on enregistre tout dans carac[], et on insere le chainon que la ligne représente.
                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if(c==':'){
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
                    if(carac[12][0]=='\0'){
                        carac[12][0]='2';
                        carac[12][1]='0';
                        carac[12][2]='0';
                        carac[12][3]='0';
                    }
                    pArbre=insertionAVLT1(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);//On insère.
                    for(int k=0;k<17;k++){//On libère le tableau qui représente la ligne.
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);

                }
                else if(c==EOF){}
            }

            //On retient les valeurs qui nous permettent de faire la moyenne des températues et de les enregistrer.
            Chainon tab[100];
            double tempmoyen[100]={0};
            double tempmax[100]={0};
            double tempmin[100]={0};
            int nmbstationpourlatemp[100]={0};
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            
            //On parcours l'arbre, retient les dates et heures nécessaires et les températures.
            parcoursInfixeT1(pArbre,fsortie,tab,tempmoyen,tempmax,tempmin,nmbstationpourlatemp,nmbstation);

            //On vérifie la véracité de la variable et on l'affiche.
            int o=0;
            for(o=0;o<(*nmbstation);o++){
                tempmoyen[o]=(tempmoyen[o])/(nmbstationpourlatemp[o]);
            }
            o=0;
            for(o=0;o<(*nmbstation);o++){
               fprintf(fsortie,"%d %d %lf %lf %lf\n",((o)*50),tab[o].station,tempmoyen[o],tempmax[o],tempmin[o]);//Le *50 aide juste a l'affichage.
            }
            free(nmbstation);
        }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    
    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat2")==0){//C'est le tri t2.
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;
            while(c!=EOF){

                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if((c=='+')||(c==':')||((c=='-')&&(i==1))){
                        c=getc(fentree);
                    }
                    else if((i==2)&&(f>1)&&(f<10)){
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
                    pArbre=insertionAVLT2(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);

                }
                else if(c==EOF){}
                
            }
            int* nmbdate=malloc(sizeof(int));//Nombre de jour max
            *nmbdate=0;
            int tabdate[5000]={0};//Contient les dates
            int tabheure[5000][24]={0};//Contient les heures par dates
            double tempmoyen[5000][24]={0};//Contient la somme des temperature par date. On fera la division plus tard avec nmbstationmaxheure
            short nmbstationmaxheure[5000][24]={0};//Nombre de mesure associé à chaque heure.
            int nmbstationmaxjour[5000]={0};//Nombre de mesure par jour.
            //Ces variables servent a afficher la date sous forme YYYY-MM-JJ.
            char datepart1[5];
            char datepart2[3];
            char datepart3[3];
            char datentier[8];
            bzero(datepart1,5);
            bzero(datepart2,3);
            bzero(datepart3,3);
            bzero(datentier,8);

            //Parcours pour stocker toutes les variables.
            parcoursInfixeT2(pArbre,tabdate,tabheure,tempmoyen,nmbstationmaxheure,nmbstationmaxjour,nmbdate);

            //Affichage
            for(int o=0;o<(*nmbdate);o++){
                if((nmbstationmaxjour[o])==0){}
                else{
                    
                for(int g=0;g<24;g++){
                    if((tempmoyen[o][g]==0)&&(nmbstationmaxheure[o][g]==0)){}
                    else{
                        sprintf(datentier,"%d",tabdate[o]);
                        datepart1[0]=datentier[0];
                        datepart1[1]=datentier[1];
                        datepart1[2]=datentier[2];
                        datepart1[3]=datentier[3];
                        datepart2[0]=datentier[4];
                        datepart2[1]=datentier[5];
                        datepart3[0]=datentier[6];
                        datepart3[1]=datentier[7];


                        fprintf(fsortie,"%s-%s-%s %d %lf\n",datepart1,datepart2,datepart3,g,(tempmoyen[o][g]/(nmbstationmaxheure[o][g])));
                        
                    }
                }
            }
            }
            free(nmbdate);
        }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
     

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatat3")==0){//C'est le tri t3 (indisponible).
       
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){//Indiscponible

        }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap1")==0){//C'est le tri p1.
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
                    pArbre=insertionAVLP1(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);
                }
                else if(c==EOF){
                }
                
            }

            //On stocke les pression et le nombre de mesures pour pouvoir en faire la moyenne.
            Chainon tab[100];
            double pressmoyen[100]={0};
            double pressmax[100]={0};
            double pressmin[100]={0};
            int nmbstationpourlapress[100]={0};
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            
            //Le parcours enregistre tout dans les tableaux.
            parcoursInfixeP1(pArbre,fsortie,tab,pressmoyen,pressmax,pressmin,nmbstationpourlapress,nmbstation);

            //On affiche.
            int o=0;
            for(o=0;o<(*nmbstation);o++){
                pressmoyen[o]=(pressmoyen[o])/(nmbstationpourlapress[o]);
            }
            o=0;
            for(o=0;o<(*nmbstation);o++){
               fprintf(fsortie,"%d %d %lf %lf %lf\n",((o+1)*50),tab[o].station,pressmoyen[o],pressmax[o],pressmin[o]);
            }
            free(nmbstation);
        }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap2")==0){//C'est le tri p2
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;
            while(c!=EOF){

                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if((c=='+')||(c==':')||((c=='-')&&(i==1))){
                        c=getc(fentree);
                    }
                    else if((i==2)&&(f>1)&&(f<10)){
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
                    pArbre=insertionAVLP2(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);
                }
                else if(c==EOF){}
                
            }

            //On initialise des tableaux.
            int* nmbdate=malloc(sizeof(int));//Nombre de jour max
            *nmbdate=0;
            int tabdate[5000]={0};//Contient les dates
            int tabheure[5000][24]={0};//Contient les heures
            double pressmoyen[5000][24]={0};//Contient la somme des temperature. On la divisera par nmbstationmaxheure plus tard.
            short nmbstationmaxheure[5000][24]={0};//Nombre de mesure par heure.
            int nmbstationmaxjour[5000]={0};//Nombre de mesure par jour
            //Ces variables servent à l'affichage
            char datepart1[5];
            char datepart2[3];
            char datepart3[3];
            char datentier[8];
            bzero(datepart1,5);
            bzero(datepart2,3);
            bzero(datepart3,3);
            bzero(datentier,8);

            //On enregistre le valeurs.
            parcoursInfixeP2(pArbre,tabdate,tabheure,pressmoyen,nmbstationmaxheure,nmbstationmaxjour,nmbdate);

            //On les affiches
            for(int o=0;o<(*nmbdate);o++){
                if((nmbstationmaxjour[o])==0){}
                else{
                    
                for(int g=0;g<24;g++){
                    if((pressmoyen[o][g]==0)&&(nmbstationmaxheure[o][g]==0)){}
                    else{
                        sprintf(datentier,"%d",tabdate[o]);
                        datepart1[0]=datentier[0];
                        datepart1[1]=datentier[1];
                        datepart1[2]=datentier[2];
                        datepart1[3]=datentier[3];
                        datepart2[0]=datentier[4];
                        datepart2[1]=datentier[5];
                        datepart3[0]=datentier[6];
                        datepart3[1]=datentier[7];
                        fprintf(fsortie,"%s-%s-%s %d %lf\n",datepart1,datepart2,datepart3,g,(pressmoyen[o][g]/(nmbstationmaxheure[o][g])));
                        
                    }
                }
            }
        }
        free(nmbdate);
    }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatap3")==0){//C'est le tri p3 (indisponible).
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){//Indisponible.

        }
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.

        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddataw")==0){//C'est le tri w.
        rewind(fentree);
        if((strcmp(argv[5],"--avl")==0)||(strcmp(argv[5],"_")==0)){
            int f=0;
            char carac[17][30]={'\0'};
            int c=getc(fentree);
            int i=0;
            f=0;
            while(c!=EOF){
                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if(c==':'){
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
                    if((carac[4][0]=='\0')||(carac[5][0]=='\0')){
                        bzero(carac[4],30);
                        carac[4][0]='4';
                        carac[4][1]='0';
                        carac[4][2]='0';
                    }
                    pArbre=insertionAVLV(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]),h);
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);
                }
                else if(c==EOF){
                }
            }
            //On enregistre la sommes des moyennes d'angle et de vitesse de vent dedans.
            Chainon tab[100];
            double vitessemoyenx[100]={0};
            double vitessemoyeny[100]={0};
            double anglemoyenx[100]={0};
            double anglemoyeny[100]={0};
            int nmbstationpourlevent[100]={0};
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            
            //On parcourt pour stocker les valeurs.
            parcoursInfixeV(pArbre,fsortie,tab,vitessemoyenx,vitessemoyeny,anglemoyenx,anglemoyeny,nmbstationpourlevent,nmbstation);

            //On fait la moyenne des vitesse et on affiche.
            int o=0;
            for(o=0;o<(*nmbstation);o++){
                vitessemoyenx[o]=(vitessemoyenx[o])/(nmbstationpourlevent[o]);
            }
            o=0;
            for(o=0;o<(*nmbstation);o++){
                vitessemoyeny[o]=((vitessemoyeny[o])/(nmbstationpourlevent[o]));
            }
            o=0;
            for(o=0;o<(*nmbstation);o++){
               fprintf(fsortie,"%lf %lf %lf %lf\n",tab[o].coordx,tab[o].coordy,vitessemoyenx[o],vitessemoyeny[o]);
            }
            free(nmbstation);
        }
    
        else if(strcmp(argv[5],"--abr")==0){//Indisponible.
            
        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatah")==0){//C'est le tri h.
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
                }
            }

            //On retient le nombre de station et leurs altitude. Ces stations sont enregistrés dans tab[].
            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            //On parcoure l'arbre pour enregistrer les valeurs d'altitude des stations, le numéro des station ainsi que leurs coordonnées.
            parcoursInfixeAlt(pArbre,fsortie,tab,nmbstation);

            //On affiche.
            for(int k=0;k<(*nmbstation);k++){
               fprintf(fsortie,"%d %lf %lf %lf\n",tab[k].station,tab[k].altitude,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);
        }
        else if((strcmp(argv[5],"--abr")==0)){
        int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;

            while(c!=EOF){

                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if(c==':'){
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
                    pArbre=insertionABRAlt(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]));
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);
                }
                else if(c==EOF){
                }
            }

            //On retient le nombre de station et leurs altitude. Ces stations sont enregistrés dans tab[].
            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            //On parcoure l'arbre pour enregistrer les valeurs d'altitude des stations, le numéro des station ainsi que leurs coordonnées.
            parcoursInfixeAlt(pArbre,fsortie,tab,nmbstation);

            //On affiche.
            for(int k=0;k<(*nmbstation);k++){
               fprintf(fsortie,"%d %lf %lf %lf\n",tab[k].station,tab[k].altitude,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);
        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }

    }
    else if(strcmp(argv[4], "./Meteotmpfilesfolder/ordereddatam")==0){//C'est le tri -m.
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
                }
            }

            //On enregitre les numéros de stations, leur humidité et leurs coordonnées.
            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            parcoursInfixeH(pArbre,fsortie,tab,nmbstation);
            
            //On affiche.
            for(int k=0;k<(*nmbstation);k++){
                fprintf(fsortie,"%d %d %lf %lf\n",tab[k].station,tab[k].humidite,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);
        }
        else if(strcmp(argv[5],"--abr")==0){
            int f=0;
            char carac[17][30];
            int c=getc(fentree);
            int i=0;
            f=0;
            while(c!=EOF){
                if((c!='\n')&&(c!=';')&&(c!=EOF)){
                    if(c==':'){
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
                    pArbre=insertionABRH(pArbre,atoi(carac[0]),atoi(carac[1]),atoi(carac[2]),atof(carac[3]),atof(carac[4]),atof(carac[5]),atoi(carac[6]),atof(carac[7]),atof(carac[8]),atof(carac[9]),atof(carac[10]),atof(carac[11]),atof(carac[12]),atof(carac[13]),atof(carac[14]),atof(carac[15]),atoi(carac[16]));
                    for(int k=0;k<17;k++){
                        bzero(carac[k],30);
                    }
                    c=getc(fentree);
                }
                else if(c==EOF){
                }
            }

            //On enregitre les numéros de stations, leur humidité et leurs coordonnées.
            Chainon tab[100];
            int* nmbstation=malloc(sizeof(int));
            (*nmbstation)=0;
            parcoursInfixeH(pArbre,fsortie,tab,nmbstation);
            
            //On affiche.
            for(int k=0;k<(*nmbstation);k++){
                fprintf(fsortie,"%d %d %lf %lf\n",tab[k].station,tab[k].humidite,tab[k].coordx,tab[k].coordy);
            }
            free(nmbstation);
        }
        else if(strcmp(argv[5],"--tab")==0){//Indisponible.

        }
    }

    //On ferme les fichiers.
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

    return 0;
}