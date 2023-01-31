#include "Meteotri.h"

Chainon* creerArbre(int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun){

    Chainon* pA=malloc(sizeof(Chainon));
    pA->station=statio;
    pA->date=dat;
    pA->heure=heur;
    pA->pressionmer=pressionme;
    pA->varpression=varpressio;
    pA->precipitation=precipitatio;
    pA->temperature=temperatur;
    pA->temperaturemin=temperaturmin;
    pA->temperaturemax=temperaturmax;
    pA->commune=commun;
    pA->pression=pressio;
    pA->humidite=humidit;
    pA->forcevent=forceven;
    pA->anglevent=angleven;
    pA->altitude=altitud;
    pA->coordx=coorx;
    pA->coordy=coory;
    pA->equilibre=0;
    pA->fd=NULL;
    pA->fg=NULL;

    return pA;
}



int estVide(Chainon* pA){
    if (pA==NULL){
        printf("L'arbre est vide!\n");
        return 1;
    }
    else{
        return 0;
    };
}





int estFeuille(Chainon* pAr){
    if(estVide(pAr)==1){
        return(0);
    }
    else{
        if((pAr->fg==NULL)&&(pAr->fd==NULL)){
            return 1;
        }
        else{return 0;};
    };
}


/*
int element(Chainon* pAr){
    if(estVide(pAr)==1){
        return(0);
    }
    else{
        return (pAr->val);
    };
}
*/

int existeFilsGauche(Chainon* pA){
    if(estVide(pA)==1){
        return(0);
    }
    else{
        if(pA->fg==NULL){
            return 0;
        }
        else{
            return 1;
        };
    };

}


int existeFilsDroit(Chainon* pA){
    if(estVide(pA)==1){
        return(0);
    }
    else{
        if(pA->fd==NULL){
            return 0;
        }
        else{
            return 1;
        };
    };


    
}

void ajouterFilsGauche(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun){
    if(estVide(pAr)==1){
        pAr=creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
    }
    else{
        if(pAr->fg!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fg=creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
        };
    };

}

void ajouterFilsDroit(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun){
    if(estVide(pAr)==1){
        pAr=creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
    }
    else{
        if(pAr->fd!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fd=creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
        };
    };

}
/*
void traiter(Chainon* pA){//a changer
    printf("%d equi= %d\n",element(pA),pA->equilibre);
}


void parcoursPrefixe(Chainon* pAr){
    if(pAr!=NULL){
        traiter(pAr);
        parcoursPrefixe(pAr->fg);
        parcoursPrefixe(pAr->fd);
    }
}

void parcoursPostfixe(Chainon* pAr){
    if(pAr!=NULL){
        parcoursPostfixe(pAr->fg);
        parcoursPostfixe(pAr->fd);
        traiter(pAr);
    }
}

void parcoursInfixe(Chainon* pAr){
    if(pAr!=NULL){
        parcoursInfixe(pAr->fg);
        traiter(pAr);
        parcoursInfixe(pAr->fd);
    }
}
*/

//////////////////////////////////////////////////////////////////////////////////////////
/*
int Verifil(Fifo* filou){
    if(filou==NULL){
        return (-1);
    }
    else if((filou->pHead==NULL && filou->pTail!=NULL)||(filou->pHead!=NULL && filou->pTail==NULL)){
        return (-2);
    }
    else if(filou->pTail!=NULL){
     if(filou->pTail->suivant!=NULL){
        return (-3);
    }else{return -1;};
    }
}

Fifo* CreerFile(){
    Fifo* pFile = malloc(sizeof(Fifo));
    if(pFile==NULL){
    exit(89);
}
pFile->pHead = NULL;
pFile->pTail = NULL;
return pFile;

}

ChainonFile* creerChainon(Chainon* Ar){
    ChainonFile* pChainon = malloc(sizeof(ChainonFile));
    if(pChainon==NULL){
        exit(10);
    }
    pChainon->arbre=Ar;
    pChainon->suivant=NULL;
    return pChainon;
}


int enfilerDyn(Fifo* Fil,Chainon* Ar){
    int q=0;
    q=Verifil(Fil);
    if(q>=-1){
            ChainonFile* nouveau = creerChainon(Ar);
            nouveau->arbre=Ar;
            if(Fil->pTail==NULL){
                Fil->pTail=nouveau;
                Fil->pHead=nouveau;
            }
            else{
                Fil->pTail->suivant=nouveau;
                Fil->pTail=nouveau;
            };
    }
return q;

}

ChainonFile* defilerDyn(Fifo* Fil){
    if(Verifil(Fil)>=-1){
        if((Fil->pTail==Fil->pHead) && (Fil->pTail!=NULL)){
            ChainonFile* areti=Fil->pHead;
            Fil->pHead=NULL;
            Fil->pTail=NULL;
            areti->suivant=NULL;
            return areti;
        }
        else{
        ChainonFile* aretu=Fil->pHead;
        Fil->pHead=Fil->pHead->suivant;
        aretu->suivant=NULL;
        
        return aretu;
        };
    }
    else{
        exit(5);
    };
}

void AfficherFile(Fifo* Filou){
     if(Filou==NULL){
       exit(3);
    }
    ChainonFile* cursed=Filou->pHead;

    while (cursed!=NULL){
        printf("%d-",cursed->arbre->val);
        cursed=cursed->suivant;
    }
    printf("\n");

}
*/
/*
void parcoursLargeur(Chainon* pAr){
    if(pAr!=NULL){
        int err=0;
        Fifo* ffile=CreerFile();
        ChainonFile* noeud=NULL;
        err=enfilerDyn(ffile,pAr);
        if (err<-1){exit(6);};
        while((ffile->pHead!=NULL) && (ffile->pTail!=NULL)){
            noeud=defilerDyn(ffile);
            traiter(noeud->arbre);
            if(existeFilsGauche(noeud->arbre)==1){
                err=enfilerDyn(ffile,noeud->arbre->fg);};
                if (err<-1){exit(7);};
            if(existeFilsDroit(noeud->arbre)==1){
                err=enfilerDyn(ffile,noeud->arbre->fd);};
                if (err<-1){exit(8);};
        };

    };
    

}
*/
////////////////////////////////////////////////////////////////////////////////////////

Chainon* modifierRacine(Chainon* a,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun){
    if(estVide(a)==0){
    a->station=statio;
    a->date=dat;
    a->heure=heur;
    a->pressionmer=pressionme;
    a->varpression=varpressio;
    a->precipitation=precipitatio;
    a->temperature=temperatur;
    a->temperaturemin=temperaturmin;
    a->temperaturemax=temperaturmax;
    a->commune=commun;
    a->pression=pressio;
    a->humidite=humidit;
    a->forcevent=forceven;
    a->anglevent=angleven;
    a->altitude=altitud;
    a->coordx=coorx;
    a->coordy=coory;
        return a;
    }
    else{
        printf("Rien à remplacer!\n");
        return a;
    };
}



void supprimerFilsDroit(Chainon* pAr){
    if(pAr==NULL){}
    else{
if(pAr->fd!=NULL){
    if(existeFilsDroit(pAr->fd)==1){supprimerFilsDroit(pAr->fd->fd);}
    if(existeFilsGauche(pAr->fd)==1){supprimerFilsGauche(pAr->fd->fg);}
    free(pAr->fd);
    pAr->fd=NULL;
};
    };
    
}



void supprimerFilsGauche(Chainon* pAr){
    if(pAr==NULL){}
    else{
if(pAr->fg!=NULL){
    if(existeFilsGauche(pAr->fg)==1){supprimerFilsGauche(pAr->fg->fg);}
    if(existeFilsDroit(pAr->fg)==1){supprimerFilsDroit(pAr->fg->fd);}
    free(pAr->fg);
    pAr->fg=NULL;
};
    }
    
}
//////////////////////////////////////////////////////////////////////////////
int nmbfeuille(Chainon* pAr){

    if(pAr!=NULL){
        if((pAr->fg==NULL)&&(pAr->fd==NULL)){
            return 1;
        }
        else{
                return nmbfeuille(pAr->fg)+nmbfeuille(pAr->fd);

        };
    }
    else{return 0;};

}

void tailleArbre(Chainon* pAr,int* valu){
if(pAr!=NULL){
        if((existeFilsGauche(pAr)==1)||(existeFilsDroit(pAr)==1)){
            *valu =*valu+1;
            if(existeFilsGauche(pAr)==1){
                tailleArbre(pAr->fg,valu);
            };
            if(existeFilsDroit(pAr)==1){
                tailleArbre(pAr->fd,valu);
            };
        };

    }
    else{ 
        if((*valu)==(-1)){
        *valu=0;
    };
    };
}

void hauteurarbre(Chainon* pAr,int* hautmax,int hautactu){
if(pAr!=NULL){
    if((*hautmax)==-1){(*hautmax)=0;};
    if(existeFilsGauche(pAr)==1){
        hauteurarbre(pAr->fg,hautmax,(hautactu+1));
 
   };
    if(existeFilsDroit(pAr)==1){
        hauteurarbre(pAr->fd,hautmax,(hautactu+1));
  
   };

};
if((*hautmax)<=hautactu){
        (*hautmax)=hautactu;
}
else{};

}

///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////

/*
Chainon* recinsertABR(Chainon* pAr,int e,int statio,float temperatur,float pressio,float humidit,float ven,float altitud,float coorx,float coory){
    //a changer
    if(pAr==NULL){
        return creerArbre(e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory);
    }
    else if(e<pAr->val){
        pAr->fg=recinsertABR(pAr->fg,e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory);
    }
    else if(e>pAr->val){
        pAr->fd=recinsertABR(pAr->fd,e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory);
    }
    return pAr;

}

Chainon* iteinsertABR(Chainon* pAr,int e,int statio,float temperatur,float pressio,float humidit,float ven,float altitud,float coorx,float coory){
    // a changer
    Chainon* tmp=pAr;
    while(tmp!=NULL){
        if((e<tmp->val)&&(tmp->fg!=NULL)){
            tmp=tmp->fg;

        }
        else if((e>tmp->val)&&(tmp->fd!=NULL)){
            tmp=tmp->fd;

        }
        else if((e<tmp->val)&&(tmp->fg==NULL)){
                tmp->fg=creerArbre(e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory;
                return pAr;
        }
        else if((e>tmp->val)&&(tmp->fd==NULL)){
                tmp->fd=creerArbre(e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory);
                return pAr;
        }
        else {
            return pAr;
        };
    };
    tmp=creerArbre(e,statio,temperatur,pressio,humidit,ven,altitud,coorx,coory);
    return pAr;

}

Chainon* suppMax(Chainon* pAr,int* pe){//a changer
if(existeFilsDroit(pAr)==1){
    pAr->fd=suppMax(pAr->fd,pe);
}
else{
    Chainon* tmp=pAr;
    *pe=pAr->val;
    pAr=pAr->fg;
    free(tmp);
};
return pAr;

}





Chainon* suppression(Chainon* pAr,int e){//a changer
if(pAr==NULL){
    return pAr;
}
else if(e>pAr->val){
    pAr->fd=suppression(pAr->fd,e);
}
else if(e<pAr->val){
    pAr->fg=suppression(pAr->fg,e);
}
else if(existeFilsGauche(pAr)==0){
    Chainon* tmp=pAr;
    pAr=pAr->fd;
    free(tmp);
}
else{
    pAr->fg=suppMax(pAr->fg,&(pAr->val));
};
return pAr;


}

*/
/*
int verifABR(Chainon* pAr,int *pPrev){// a changer
    int* tmp=pPrev;
    if(pAr!=NULL){
        if(verifABR(pAr->fg,pPrev)==0){
            return 0;
        };
        if(pPrev!=NULL){
            if(pAr->val<=*pPrev){
                return 0;
            };
        }
        else{
            pPrev=malloc(sizeof(int));
            if(pPrev==NULL){
                exit (2);
                }
        };
        *pPrev=pAr->val;

        if(verifABR(pAr->fd,pPrev)==0){
            if(tmp==NULL){free(pPrev);}
            return 0;
        };


    };
    if(tmp==NULL){free(pPrev);}
    return 1;

}
*/
/////////////////////////////////////////////////////////////

int max(int a,int b){
    if(a>b){return a;}
    else{return b;};
}

int min(int a,int b){
    if(a<b){return a;}
    else{return b;};
}


Chainon* rotationGauche(Chainon* pAr){
    Chainon* pivot=pAr->fd;
    pAr->fd=pivot->fg;
    pivot->fg=pAr;
    int eq_a=pAr->equilibre;
    int eq_p=pivot->equilibre;
    pAr->equilibre=eq_a-max(eq_p,0)-1;
    pivot->equilibre=min(min(eq_a-2,eq_a+eq_p-2),eq_p-1);
    pAr=pivot;
    return pAr;

}

Chainon* rotationDroite(Chainon* pAr){

    Chainon* pivot=pAr->fg;
    pAr->fg=pivot->fd;
    pivot->fd=pAr;
    int eq_a=pAr->equilibre;
    int eq_p=pivot->equilibre;
    pAr->equilibre=eq_a-min(eq_p,0)+1;
    pivot->equilibre=max(max(eq_a+2,eq_a+eq_p+2),eq_p+1);
    pAr=pivot;
    return pAr;  
}

Chainon* doubleRotationGauche(Chainon* pAr){
    
    pAr->fd=rotationDroite(pAr->fd);
    pAr=rotationGauche(pAr);
    
    return pAr;
}

Chainon* doubleRotationDroit(Chainon* pAr){
    
    pAr->fg=rotationGauche(pAr->fg);
    pAr=rotationDroite(pAr);
    
    return pAr;
}

/*
Chainon* insertionAVL(Chainon* pAr,int e,int* h){//a changer

if(pAr==NULL){
    *h=1;
    return creerArbre(e);
}
else if(e<pAr->val){
    pAr->fg=insertionAVL(pAr->fg,e,h);
    *h=-(*h);
}
else if(e>pAr->val){
    pAr->fd=insertionAVL(pAr->fd,e,h);
}
else{
    *h=0;
    return pAr;
};

if(*h!=0){
    pAr->equilibre=pAr->equilibre+(*h);
    pAr=equilibrerAVL(pAr);
    if(pAr->equilibre==0){
        *h=0;
    }
    else{
        *h=1;
    };
};

return pAr;


}


*/
Chainon* equilibrerAVL(Chainon* pAr){

    if(pAr!=NULL){
        if(pAr->equilibre>=2){
            if(pAr->fd->equilibre>=0){
                return rotationGauche(pAr);
            }
            else{
                return doubleRotationGauche(pAr);
            }
        }
        else if(pAr->equilibre<=-2){
            if(pAr->fg->equilibre<=0){
                return rotationDroite(pAr);
            }
            else{
                return doubleRotationDroit(pAr);
            }

        }
        return pAr;
    }

return pAr;

/*
if(pAr!=NULL){


    if(pAr->equilibre>=2){
        if(pAr->fd->equilibre>=0){
            return rotationGauche(pAr);
        }
        else{
            return doubleRotationGauche(pAr);
        }

    }
    if(pAr->equilibre<=-2){
        if(pAr->fg->equilibre<=0){
            return rotationDroite(pAr);
        }
        else{
            return doubleRotationDroit(pAr);
        }
    }
    return pAr;
}
    return pAr;

*/
}

/*
Chainon* suppMinAVL(Chainon* pAr,int* h,int* pe){//a changer

    if(pAr->fg==NULL){
        *pe=pAr->val;
        *h=-1;
        Chainon* tmp=pAr;
        pAr=pAr->fd;
        free(tmp);
        return pAr;
    }
    else{
        pAr->fg=suppMinAVL(pAr->fg,h,pe);
        *h=-(*h);
    };
    if(*h!=0){
        pAr->equilibre=(pAr->equilibre+(*h));
        if(pAr->equilibre==0){
            *h=-1;
        }
        else{
            *h=0;
        };
    }
    return pAr;

}

*/
/*
Chainon* suppressionAVL(Chainon* pAr,int e,int* h){//a changer

    if(pAr==NULL){
        *h=1;
        return pAr;
    }
    else if(e>pAr->val){
        pAr->fd=suppressionAVL(pAr->fd,e,h);
    }
    else if(e<pAr->val){
        pAr->fg=suppressionAVL(pAr->fg,e,h);
        *h=-(*h);
    }
    else if(existeFilsDroit(pAr)==1){
        pAr->fd=suppMinAVL(pAr->fd,h,&(pAr->val));
    }
    else{
        Chainon* tmp=pAr;
        pAr=pAr->fg;
        free(tmp);
        *h=-1;
        return pAr;
    };
    
    if(*h!=0){
        pAr->equilibre=(pAr->equilibre)+(*h);
        if(pAr->equilibre==0){
            *h=1;
        }
        else{
            *h=0;
        };
    };
    return pAr;

}
*/



void traiterH2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
    
    int bool=0;
    if(pAr!=NULL){
        if((*nmbstatio)==0){
            tabu[0]=(*pAr);
            (*nmbstatio)++;
            
        }
        else{
            
            if(bool==0){
                for(int u=0;u<(*nmbstatio);u++){
                    if(bool==0){
                        if((tabu[u].station)==(pAr->station)){

                        bool=1;
                        if((tabu[u].humidite)<(pAr->humidite)){
                            
                            tabu[u].station=pAr->station;
                            tabu[u].date=pAr->date;
                            tabu[u].heure=pAr->heure;
                            tabu[u].pressionmer=pAr->pressionmer;
                            tabu[u].anglevent=pAr->anglevent;
                            tabu[u].forcevent=pAr->forcevent;
                            tabu[u].humidite=pAr->humidite;
                            tabu[u].varpression=pAr->varpression;
                            tabu[u].pression=pAr->pression;
                            tabu[u].precipitation=pAr->precipitation;
                            tabu[u].coordx=pAr->coordx;
                            tabu[u].coordy=pAr->coordy;
                            tabu[u].temperature=pAr->temperature;
                            tabu[u].temperaturemin=pAr->temperaturemin;
                            tabu[u].temperaturemax=pAr->temperaturemax;
                            tabu[u].altitude=pAr->altitude;
                            tabu[u].commune=pAr->commune;
                            tabu[u].equilibre=0;
                            tabu[u].fd=NULL;
                            tabu[u].fg=NULL;

                        }
                        else{bool=1;}
                    }
                    }
                } 
            }
            if(bool==0){
                tabu[(*nmbstatio)].station=pAr->station;
                tabu[(*nmbstatio)].date=pAr->date;
                tabu[(*nmbstatio)].heure=pAr->heure;
                tabu[(*nmbstatio)].pressionmer=pAr->pressionmer;
                tabu[(*nmbstatio)].anglevent=pAr->anglevent;
                tabu[(*nmbstatio)].forcevent=pAr->forcevent;
                tabu[(*nmbstatio)].humidite=pAr->humidite;
                tabu[(*nmbstatio)].varpression=pAr->varpression;
                tabu[(*nmbstatio)].pression=pAr->pression;
                tabu[(*nmbstatio)].precipitation=pAr->precipitation;
                tabu[(*nmbstatio)].coordx=pAr->coordx;
                tabu[(*nmbstatio)].coordy=pAr->coordy;
                tabu[(*nmbstatio)].temperature=pAr->temperature;
                tabu[(*nmbstatio)].temperaturemin=pAr->temperaturemin;
                tabu[(*nmbstatio)].temperaturemax=pAr->temperaturemax;
                tabu[(*nmbstatio)].altitude=pAr->altitude;
                tabu[(*nmbstatio)].commune=pAr->commune;
                tabu[(*nmbstatio)].equilibre=0;
                tabu[(*nmbstatio)].fd=NULL;
                tabu[(*nmbstatio)].fg=NULL;
                (*nmbstatio)++;
            }
        }

        
    }
    
}


void parcoursInfixeH(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeH(pAr->fd,fsorti,tabu,nmbstatio);
        parcoursInfixeH(pAr->fg,fsorti,tabu,nmbstatio);
        traiterH2(pAr,fsorti,tabu,nmbstatio);
    }


}
/*
void parcoursPrefixeH(Chainon* pAr,Chainon* listestatio,int* nmbstation){
if(pAr!=NULL){
        traiterH(pAr,listestatio,nmbstation);
        parcoursPrefixeH(pAr->fg,listestatio,nmbstation);
        parcoursPrefixeH(pAr->fd,listestatio,nmbstation);
    }

}

void traiterH(Chainon* pAr,Chainon* listestatio,int* nmbstation){
    if(pAr!=NULL){
        if(*nmbstation==0){
            listestatio[*nmbstation].station=pAr->station;
            listestatio[*nmbstation].temperature=pAr->temperature;
            listestatio[*nmbstation].pression=pAr->pression;
            listestatio[*nmbstation].humidite=pAr->humidite;
            listestatio[*nmbstation].anglevent=pAr->anglevent;
            listestatio[*nmbstation].forcevent=pAr->forcevent;
            listestatio[*nmbstation].coordx=pAr->coordx;
            listestatio[*nmbstation].coordy=pAr->coordy;
            listestatio[*nmbstation].fd=NULL;
            listestatio[*nmbstation].fg=NULL;
            *nmbstation++;

        }
        else{
            int bool=0;
            for(int q=0;q<*nmbstation;q++){
                if(pAr->station==listestatio[q].station){
                    if(pAr->humidite>listestatio[q].humidite){
                        listestatio[q].station=pAr->station;
                        listestatio[q].temperature=pAr->temperature;
                        listestatio[q].pression=pAr->pression;
                        listestatio[q].humidite=pAr->humidite;
                        listestatio[q].anglevent=pAr->anglevent;
                        listestatio[q].forcevent=pAr->forcevent;
                        listestatio[q].coordx=pAr->coordx;
                        listestatio[q].coordy=pAr->coordy;
                        listestatio[q].fd=NULL;
                        listestatio[q].fg=NULL;
                        bool=1;
                    };
                };
            };
            if(bool==0){
                listestatio[*nmbstation].station=pAr->station;
                listestatio[*nmbstation].temperature=pAr->temperature;
                listestatio[*nmbstation].pression=pAr->pression;
                listestatio[*nmbstation].humidite=pAr->humidite;
                listestatio[*nmbstation].anglevent=pAr->anglevent;
                listestatio[*nmbstation].forcevent=pAr->forcevent;
                listestatio[*nmbstation].coordx=pAr->coordx;
                listestatio[*nmbstation].coordy=pAr->coordy;
                listestatio[*nmbstation].fd=NULL;
                listestatio[*nmbstation].fg=NULL;
                *nmbstation++;
            };
        };
    };
    
}

Chainon* iteinsertABRH(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory){
Chainon* tmp=pAr;
    while(tmp!=NULL){
        if((humidit<tmp->humidite)&&(tmp->fg!=NULL)){
            tmp=tmp->fg;

        }
        else if((humidit>tmp->humidite)&&(tmp->fd!=NULL)){
            tmp=tmp->fd;

        }
        else if((humidit<tmp->humidite)&&(tmp->fg==NULL)){
                tmp->fg=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
                return pAr;
        }
        else if((humidit>tmp->humidite)&&(tmp->fd==NULL)){
                tmp->fd=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
                return pAr;
        }
        else {
            return pAr;
        };
    };
    tmp=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
    return pAr;



}

*/


Chainon* insertionAVLH(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){

if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(humidit<pAr->humidite){
    pAr->fg=insertionAVLH(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(humidit>=pAr->humidite){
    pAr->fd=insertionAVLH(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
}


if(*h!=0){
    pAr->equilibre=pAr->equilibre+(*h);
    pAr=equilibrerAVL(pAr);
    if(pAr->equilibre==0){
        *h=0;
    }
    else{
        *h=1;
    };
};

return pAr;



}

////////////////////////////////////
Chainon* insertionAVLAlt(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(altitud<pAr->altitude){
pAr->fg=insertionAVLAlt(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(altitud>=pAr->altitude){
    pAr->fd=insertionAVLAlt(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
}


if(*h!=0){
    pAr->equilibre=pAr->equilibre+(*h);
    pAr=equilibrerAVL(pAr);
    if(pAr->equilibre==0){
        *h=0;
    }
    else{
        *h=1;
    };
};

return pAr;


}


void parcoursInfixeAlt(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeAlt(pAr->fd,fsorti,tabu,nmbstatio);
        parcoursInfixeAlt(pAr->fg,fsorti,tabu,nmbstatio);
        traiterAlt2(pAr,fsorti,tabu,nmbstatio);
    }
}



void traiterAlt2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if((*nmbstatio)==0){
            tabu[0]=(*pAr);
            (*nmbstatio)++;
            
        }
        else{
            
            if(bool==0){
                for(int u=0;u<(*nmbstatio);u++){
                    if(bool==0){
                        if((tabu[u].station)==(pAr->station)){

                        bool=1;
                        if((tabu[u].altitude)<(pAr->altitude)){
                            
                            tabu[u].station=pAr->station;
                            tabu[u].date=pAr->date;
                            tabu[u].heure=pAr->heure;
                            tabu[u].pressionmer=pAr->pressionmer;
                            tabu[u].anglevent=pAr->anglevent;
                            tabu[u].forcevent=pAr->forcevent;
                            tabu[u].humidite=pAr->humidite;
                            tabu[u].varpression=pAr->varpression;
                            tabu[u].pression=pAr->pression;
                            tabu[u].precipitation=pAr->precipitation;
                            tabu[u].coordx=pAr->coordx;
                            tabu[u].coordy=pAr->coordy;
                            tabu[u].temperature=pAr->temperature;
                            tabu[u].temperaturemin=pAr->temperaturemin;
                            tabu[u].temperaturemax=pAr->temperaturemax;
                            tabu[u].altitude=pAr->altitude;
                            tabu[u].commune=pAr->commune;
                            tabu[u].equilibre=0;
                            tabu[u].fd=NULL;
                            tabu[u].fg=NULL;

                        }
                        else{bool=1;}
                    }
                    }
                } 
            }
            if(bool==0){
                tabu[(*nmbstatio)].station=pAr->station;
                tabu[(*nmbstatio)].date=pAr->date;
                tabu[(*nmbstatio)].heure=pAr->heure;
                tabu[(*nmbstatio)].pressionmer=pAr->pressionmer;
                tabu[(*nmbstatio)].anglevent=pAr->anglevent;
                tabu[(*nmbstatio)].forcevent=pAr->forcevent;
                tabu[(*nmbstatio)].humidite=pAr->humidite;
                tabu[(*nmbstatio)].varpression=pAr->varpression;
                tabu[(*nmbstatio)].pression=pAr->pression;
                tabu[(*nmbstatio)].precipitation=pAr->precipitation;
                tabu[(*nmbstatio)].coordx=pAr->coordx;
                tabu[(*nmbstatio)].coordy=pAr->coordy;
                tabu[(*nmbstatio)].temperature=pAr->temperature;
                tabu[(*nmbstatio)].temperaturemin=pAr->temperaturemin;
                tabu[(*nmbstatio)].temperaturemax=pAr->temperaturemax;
                tabu[(*nmbstatio)].altitude=pAr->altitude;
                tabu[(*nmbstatio)].commune=pAr->commune;
                tabu[(*nmbstatio)].equilibre=0;
                tabu[(*nmbstatio)].fd=NULL;
                tabu[(*nmbstatio)].fg=NULL;
                (*nmbstatio)++;
            }
        }

        
    }
    
}


////////////////////////////////////////
Chainon* insertionAVLV(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(statio<pAr->station){
pAr->fg=insertionAVLV(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(statio>=pAr->station){
    pAr->fd=insertionAVLV(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
}


if(*h!=0){
    pAr->equilibre=pAr->equilibre+(*h);
    pAr=equilibrerAVL(pAr);
    if(pAr->equilibre==0){
        *h=0;
    }
    else{
        *h=1;
    };
};

return pAr;

}



void parcoursInfixeV(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeV(pAr->fg,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
        parcoursInfixeV(pAr->fd,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
        traiterV2(pAr,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
    }

}



void traiterV2(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if((*nmbstatio)==0){
            tabu[0]=(*pAr);
            (*nmbstatio)++;
            
        }
        else{
            
            if(bool==0){
                for(int u=0;u<(*nmbstatio);u++){
                    if(bool==0){
                        if((tabu[u].station)==(pAr->station)){
                            bool=1;
                            tabu[u].station=pAr->station;
                            tabu[u].date=pAr->date;
                            tabu[u].heure=pAr->heure;
                            tabu[u].pressionmer=pAr->pressionmer;
                            tabu[u].anglevent=pAr->anglevent;
                            tabu[u].forcevent=pAr->forcevent;
                            tabu[u].humidite=pAr->humidite;
                            tabu[u].varpression=pAr->varpression;
                            tabu[u].pression=pAr->pression;
                            tabu[u].precipitation=pAr->precipitation;
                            tabu[u].coordx=pAr->coordx;
                            tabu[u].coordy=pAr->coordy;
                            tabu[u].temperature=pAr->temperature;
                            tabu[u].temperaturemin=pAr->temperaturemin;
                            tabu[u].temperaturemax=pAr->temperaturemax;
                            tabu[u].altitude=pAr->altitude;
                            tabu[u].commune=pAr->commune;
                            tabu[u].equilibre=0;
                            tabu[u].fd=NULL;
                            tabu[u].fg=NULL;

                            vitessemoyex[u]=vitessemoyex[u]+(pAr->forcevent);
                            vitessemoyey[u]=vitessemoyey[u]+(pAr->forcevent);
                            anglemoyex[u]=anglemoyex[u]+(pAr->anglevent);
                            anglemoyey[u]=anglemoyey[u]+(pAr->anglevent);
                            nmbstationpourleven[u]++;
                        }
                        
                    }
                    }
                } 
            }
            if(bool==0){
                tabu[(*nmbstatio)].station=pAr->station;
                            tabu[(*nmbstatio)].date=pAr->date;
                            tabu[(*nmbstatio)].heure=pAr->heure;
                            tabu[(*nmbstatio)].pressionmer=pAr->pressionmer;
                            tabu[(*nmbstatio)].anglevent=pAr->anglevent;
                            tabu[(*nmbstatio)].forcevent=pAr->forcevent;
                            tabu[(*nmbstatio)].humidite=pAr->humidite;
                            tabu[(*nmbstatio)].varpression=pAr->varpression;
                            tabu[(*nmbstatio)].pression=pAr->pression;
                            tabu[(*nmbstatio)].precipitation=pAr->precipitation;
                            tabu[(*nmbstatio)].coordx=pAr->coordx;
                            tabu[(*nmbstatio)].coordy=pAr->coordy;
                            tabu[(*nmbstatio)].temperature=pAr->temperature;
                            tabu[(*nmbstatio)].temperaturemin=pAr->temperaturemin;
                            tabu[(*nmbstatio)].temperaturemax=pAr->temperaturemax;
                            tabu[(*nmbstatio)].altitude=pAr->altitude;
                            tabu[(*nmbstatio)].commune=pAr->commune;
                            tabu[(*nmbstatio)].equilibre=0;
                            tabu[(*nmbstatio)].fd=NULL;
                            tabu[(*nmbstatio)].fg=NULL;

                            vitessemoyex[(*nmbstatio)]=vitessemoyex[(*nmbstatio)]+(pAr->forcevent);
                            vitessemoyey[(*nmbstatio)]=vitessemoyey[(*nmbstatio)]+(pAr->forcevent);
                            anglemoyex[(*nmbstatio)]=anglemoyex[(*nmbstatio)]+(pAr->anglevent);
                            anglemoyey[(*nmbstatio)]=anglemoyey[(*nmbstatio)]+(pAr->anglevent);
                            nmbstationpourleven[(*nmbstatio)]++;
                (*nmbstatio)++;
            }
        }

        
    }
    

//////////////////////////////
/*
Chainon* insertionAVLT1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(statio<pAr->station){
pAr->fg=insertionAVLT1(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(statio>=pAr->station){
    pAr->fd=insertionAVLT1(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
}


if(*h!=0){
    pAr->equilibre=pAr->equilibre+(*h);
    pAr=equilibrerAVL(pAr);
    if(pAr->equilibre==0){
        *h=0;
    }
    else{
        *h=1;
    };
};

return pAr;


}
void parcoursInfixeT1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){


}
void traiterT12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){



}
*/











