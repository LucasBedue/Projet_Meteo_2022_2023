#include "Meteotri.h"

Chainon* creerArbre(int valeur){

    Chainon* pA=malloc(sizeof(Chainon));
    pA->val=valeur;
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



int element(Chainon* pAr){
    if(estVide(pAr)==1){
        return(0);
    }
    else{
        return (pAr->val);
    };
}


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

void ajouterFilsGauche(Chainon* pAr,int e){
    if(estVide(pAr)==1){
        pAr=creerArbre(e);
    }
    else{
        if(pAr->fg!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fg=creerArbre(e);
        };
    };

}

void ajouterFilsDroit(Chainon* pAr,int e){
    if(estVide(pAr)==1){
        pAr=creerArbre(e);
    }
    else{
        if(pAr->fd!=NULL){
            printf("On ne peut pas créer de noeud ici!\n");
        }
        else{
            pAr->fd=creerArbre(e);
        };
    };

}

void traiter(Chainon* pA){
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

//////////////////////////////////////////////////////////////////////////////////////////

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
    Fifo* pFile =  malloc(sizeof(Fifo));
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

////////////////////////////////////////////////////////////////////////////////////////

Chainon* modifierRacine(Chainon* a,int e){
    if(estVide(a)==0){
        a->val=e;
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

int filiformeTest(Chainon* pAr,int q){

    if(pAr==NULL){
        return q;
    }
    else{
        if((existeFilsGauche(pAr)==1)&&(existeFilsDroit(pAr)==1)){
            return 0;
        }
        else if(existeFilsGauche(pAr)==1){
            return filiformeTest(pAr->fg,1);
        }
        else if(existeFilsDroit(pAr)==1){
            return filiformeTest(pAr->fd,1);
        }
        else{
            return 1;
        };
    };

}

int peigneGauche(Chainon* pAr,int q){
if(pAr==NULL){
    return q;
}
else{
    if(existeFilsDroit(pAr)==1){
        return 0;
    }
    else if(existeFilsGauche(pAr)==1){
        return peigneGauche(pAr->fg,-1);
    }
    else{
        return 1;
    };
    
};
}

Chainon* constrPeigneGauche(int h){
    if(h<=0){
        return NULL;
    }
    else{
        Chainon* tmp=creerArbre(rand()%11);
        h--;
        Chainon* tmp2=tmp;
        while(h>0){
            tmp->fg=creerArbre(rand()%11);
            h--;
            tmp=tmp->fg;
        };
        return tmp2;
    };
}
///////////////////////////////////////////////////////////////////////

int recherche(Chainon* pAr,int e){
    if(pAr==NULL){
        return -1;
    }
    else{
        if(e==(pAr->val)){return 1;}
        else if((e<(pAr->val))&&(existeFilsGauche(pAr))){
            return recherche(pAr->fg,e);
        }
        else if((e>(pAr->val))&&(existeFilsDroit(pAr))){
            return recherche(pAr->fd,e);
        }
        else{return 0;};
    };

}

Chainon* recinsertABR(Chainon* pAr,int e){
    if(pAr==NULL){
        return creerArbre(e);
    }
    else if(e<pAr->val){
        pAr->fg=recinsertABR(pAr->fg,e);
    }
    else if(e>pAr->val){
        pAr->fd=recinsertABR(pAr->fd,e);
    }
    return pAr;

}

Chainon* iteinsertABR(Chainon* pAr,int e){
    Chainon* tmp=pAr;
    while(tmp!=NULL){
        printf("%d\n",tmp->val);
        if((e<tmp->val)&&(tmp->fg!=NULL)){
            tmp=tmp->fg;

        }
        else if((e>tmp->val)&&(tmp->fd!=NULL)){
            tmp=tmp->fd;

        }
        else if((e<tmp->val)&&(tmp->fg==NULL)){
                tmp->fg=creerArbre(e);
                return pAr;
        }
        else if((e>tmp->val)&&(tmp->fd==NULL)){
                tmp->fd=creerArbre(e);
                return pAr;
        }
        else {
            return pAr;
        };
    };
    tmp=creerArbre(e);
    return pAr;

}

Chainon* suppMax(Chainon* pAr,int* pe){
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





Chainon* suppression(Chainon* pAr,int e){
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

int verifABR(Chainon* pAr,int *pPrev){
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


Chainon* insertionAVL(Chainon* pAr,int e,int* h){

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


Chainon* suppMinAVL(Chainon* pAr,int* h,int* pe){

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



Chainon* suppressionAVL(Chainon* pAr,int e,int* h){

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
