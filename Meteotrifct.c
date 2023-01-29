#include "Meteotri.h"

Chainon* creerArbre(int statio,float temperatur,float pressio,float humidit,float angleven,float forceven,float altitud,float coorx,float coory){

    Chainon* pA=malloc(sizeof(Chainon));
    pA->station=statio;
    pA->temperature=temperatur;
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

void ajouterFilsGauche(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory){
    if(estVide(pAr)==1){
        pAr=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
    }
    else{
        if(pAr->fg!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fg=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
        };
    };

}

void ajouterFilsDroit(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory){
    if(estVide(pAr)==1){
        pAr=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
    }
    else{
        if(pAr->fd!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fd=creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
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

Chainon* modifierRacine(Chainon* a,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory){
    if(estVide(a)==0){
        a->station=statio;
        a->temperature=temperatur;
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

    if(pAr->equilibre>=2){
        if(pAr->fd->equilibre>=0){
            return rotationGauche(pAr);
        }
        else{
            return doubleRotationGauche(pAr);
        };

    }
    else if(pAr->equilibre<=-2){
        if(pAr->fg->equilibre<=0){
            return rotationDroite(pAr);
        }
        else{
            return doubleRotationDroit(pAr);
        };
    };
    return pAr;


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
void traiterH2(Chainon* pAr,FILE* fsorti){
    char str1[10];
    char str2[30];
    char str3[30];
    char str4[30];
    int err=0;
    int p=0;
    err=sprintf(str1,"%d",pAr->station);
    err=sprintf(str2,"%f",pAr->humidite);
    err=sprintf(str3,"%f",pAr->coordx);
    err=sprintf(str4,"%f",pAr->coordy);
    while(str1[p]!='\0'){
        if(fputc(str1[p],fsorti)==str1[p]){
            p++;
        }
            else{
                printf("Erreur dans l'écriture de fsortie");
                exit(3);
                };
    }
    if(fputc(' ',fsorti)==' '){}
    else{
        printf("Erreur dans l'écriture de fsortie");
        exit(3);
    };
    p=0;
    while(str2[p]!='\0'){
        if(fputc(str2[p],fsorti)==str2[p]){
            p++;
        }
            else{
                printf("Erreur dans l'écriture de fsortie");
                exit(3);
                };
    }
    if(fputc(' ',fsorti)==' '){}
    else{
        printf("Erreur dans l'écriture de fsortie");
        exit(3);
    };
    p=0;
    while(str3[p]!='\0'){
        if(fputc(str3[p],fsorti)==str3[p]){
            p++;
        }
            else{
                printf("Erreur dans l'écriture de fsortie");
                exit(3);
                };
    }
    if(fputc(' ',fsorti)==' '){}
    else{
        printf("Erreur dans l'écriture de fsortie");
        exit(3);
    };
    p=0;
    while(str4[p]!='\0'){
        if(fputc(str4[p],fsorti)==str4[p]){
            p++;
        }
            else{
                printf("Erreur dans l'écriture de fsortie");
                exit(3);
                };
    }
    if(fputc('\n',fsorti)=='\n'){}
    else{
        printf("Erreur dans l'écriture de fsortie");
        exit(3);
    };
    p=0;
}

void parcoursInfixeH(Chainon* pAr,FILE* fsorti){
if(pAr!=NULL){
        
        parcoursInfixeH(pAr->fd,fsorti);
        parcoursInfixeH(pAr->fg,fsorti);
        traiterH2(pAr,fsorti);
    }


}

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


Chainon* insertionAVLH(Chainon* pAr,int statio,float temperatur,float pressio,float humidit,float forceven,float angleven,float altitud,float coorx,float coory,int* h){

if(pAr==NULL){
    *h=1;
    return creerArbre(statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory);
}
else if(humidit<pAr->humidite){
    pAr->fg=insertionAVLH(pAr->fg,statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory,h);
    *h=-(*h);
}
else if(humidit>pAr->humidite){
    pAr->fd=insertionAVLH(pAr->fd,statio,temperatur,pressio,humidit,forceven,angleven,altitud,coorx,coory,h);
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

















