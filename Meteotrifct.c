#include "Meteotri.h"

//Créer un chainon.
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


//Verifie si le chainon est vide.
int estVide(Chainon* pA){
    if (pA==NULL){
        printf("L'arbre est vide!\n");
        return 1;
    }
    else{
        return 0;
    };
}




//vérifie si le chainon est une feuille.
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


//Vérifie si il y a un fils gauche.
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

//Vérifie si il y a un fils droit.
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

//Ajoute un fils gauche.
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

//Ajoute un fils droit.
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

//On modifie la racine de l'arbre.
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


//On supprime le fils droit.
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

//On supprime le fils gauche
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

//On compte le nombre de feuille.
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

//On compte la taille de l'arbre.
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

//On compte la hauteur de l'arbre.
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

//Retourne le maximum de deux nombres.
int max(int a,int b){
    if(a>b){return a;}
    else{return b;};
}

//Retourne le minimum de deux nombres.
int min(int a,int b){
    if(a<b){return a;}
    else{return b;};
}

//Rotation gauche d'un avl.
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

//Rotation droite d'un avl.
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

//Double rotation gauche d'un avl.
Chainon* doubleRotationGauche(Chainon* pAr){
    
    pAr->fd=rotationDroite(pAr->fd);
    pAr=rotationGauche(pAr);
    
    return pAr;
}

//Double rotation droite d'un avl.
Chainon* doubleRotationDroit(Chainon* pAr){
    
    pAr->fg=rotationGauche(pAr->fg);
    pAr=rotationDroite(pAr);
    
    return pAr;
}

//Equilibre un AVL en appellant rotation gauche et droite.
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

}

///////////////////////////////////////////////////////////////////////////////////Tri -m
//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterH2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
    
    int bool=0;
    if(pAr!=NULL){
        if(pAr->humidite==0.0){

        }
        else{
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
}

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeH(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeH(pAr->fd,fsorti,tabu,nmbstatio);
        parcoursInfixeH(pAr->fg,fsorti,tabu,nmbstatio);
        traiterH2(pAr,fsorti,tabu,nmbstatio);
    }


}

//Insertion AVL selon l'humidité.
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

///////////////////////////////////////////////////////////////////////////////////Tri -h
//Insertion AVL selon l'altitude.
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

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeAlt(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeAlt(pAr->fd,fsorti,tabu,nmbstatio);
        parcoursInfixeAlt(pAr->fg,fsorti,tabu,nmbstatio);
        traiterAlt2(pAr,fsorti,tabu,nmbstatio);
    }
}


//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterAlt2(Chainon* pAr,FILE* fsorti,Chainon* tabu,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if((*nmbstatio)==0){
            tabu[0].station=pAr->station;
                            tabu[0].date=pAr->date;
                            tabu[0].heure=pAr->heure;
                            tabu[0].pressionmer=pAr->pressionmer;
                            tabu[0].anglevent=pAr->anglevent;
                            tabu[0].forcevent=pAr->forcevent;
                            tabu[0].humidite=pAr->humidite;
                            tabu[0].varpression=pAr->varpression;
                            tabu[0].pression=pAr->pression;
                            tabu[0].precipitation=pAr->precipitation;
                            tabu[0].coordx=pAr->coordx;
                            tabu[0].coordy=pAr->coordy;
                            tabu[0].temperature=pAr->temperature;
                            tabu[0].temperaturemin=pAr->temperaturemin;
                            tabu[0].temperaturemax=pAr->temperaturemax;
                            tabu[0].altitude=pAr->altitude;
                            tabu[0].commune=pAr->commune;
                            tabu[0].equilibre=0;
                            tabu[0].fd=NULL;
                            tabu[0].fg=NULL;
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


///////////////////////////////////////////////////////////////////////////////////Tri -w
//Insertion AVL selon la station.
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


//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeV(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeV(pAr->fg,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
        parcoursInfixeV(pAr->fd,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
        traiterV2(pAr,fsorti,tabu,vitessemoyex,vitessemoyey,anglemoyex,anglemoyey,nmbstationpourleven,nmbstatio);
    }

}


//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterV2(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* vitessemoyex,double* vitessemoyey,double* anglemoyex,double* anglemoyey,int* nmbstationpourleven,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if(pAr->anglevent==400){}
        else{
        if((*nmbstatio)==0){
            tabu[0].station=pAr->station;
                            tabu[0].date=pAr->date;
                            tabu[0].heure=pAr->heure;
                            tabu[0].pressionmer=pAr->pressionmer;
                            tabu[0].anglevent=pAr->anglevent;
                            tabu[0].forcevent=pAr->forcevent;
                            tabu[0].humidite=pAr->humidite;
                            tabu[0].varpression=pAr->varpression;
                            tabu[0].pression=pAr->pression;
                            tabu[0].precipitation=pAr->precipitation;
                            tabu[0].coordx=pAr->coordx;
                            tabu[0].coordy=pAr->coordy;
                            tabu[0].temperature=pAr->temperature;
                            tabu[0].temperaturemin=pAr->temperaturemin;
                            tabu[0].temperaturemax=pAr->temperaturemax;
                            tabu[0].altitude=pAr->altitude;
                            tabu[0].commune=pAr->commune;
                            tabu[0].equilibre=0;
                            tabu[0].fd=NULL;
                            tabu[0].fg=NULL;
                            nmbstationpourleven[0]++;
                            vitessemoyex[0]=(cos(pAr->anglevent))*(pAr->forcevent);
                            vitessemoyey[0]=(sin(pAr->anglevent))*(pAr->forcevent);
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

                            vitessemoyex[u]=(vitessemoyex[u]+((cos(pAr->anglevent))*(pAr->forcevent)));
                            vitessemoyey[u]=(vitessemoyey[u]+((sin(pAr->anglevent))*(pAr->forcevent)));
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

                            vitessemoyex[(*nmbstatio)]=(cos(pAr->anglevent)*(pAr->forcevent));
                            vitessemoyey[(*nmbstatio)]=(sin(pAr->anglevent)*(pAr->forcevent));
                            nmbstationpourleven[(*nmbstatio)]++;
                (*nmbstatio)++;
            }
        }

    }
    }
    

///////////////////////////////////////////////////////////////////////////////////Tri -t1
//Insertion AVL selon la station.
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

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeT1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeT1(pAr->fg,fsorti,tabu,tempmoy,temmax,temmin,nmbstationpourletem,nmbstatio);
        parcoursInfixeT1(pAr->fd,fsorti,tabu,tempmoy,temmax,temmin,nmbstationpourletem,nmbstatio);
        traiterT12(pAr,fsorti,tabu,tempmoy,temmax,temmin,nmbstationpourletem,nmbstatio);
    }


}

//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterT12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* tempmoy,double* temmax,double* temmin,int* nmbstationpourletem,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if(pAr->temperature==2000){}
        else{
        if((*nmbstatio)==0){
            
            tabu[0].station=pAr->station;
                            tabu[0].date=pAr->date;
                            tabu[0].heure=pAr->heure;
                            tabu[0].pressionmer=pAr->pressionmer;
                            tabu[0].anglevent=pAr->anglevent;
                            tabu[0].forcevent=pAr->forcevent;
                            tabu[0].humidite=pAr->humidite;
                            tabu[0].varpression=pAr->varpression;
                            tabu[0].pression=pAr->pression;
                            tabu[0].precipitation=pAr->precipitation;
                            tabu[0].coordx=pAr->coordx;
                            tabu[0].coordy=pAr->coordy;
                            tabu[0].temperature=pAr->temperature;
                            tabu[0].temperaturemin=pAr->temperaturemin;
                            tabu[0].temperaturemax=pAr->temperaturemax;
                            tabu[0].altitude=pAr->altitude;
                            tabu[0].commune=pAr->commune;
                            tabu[0].equilibre=0;
                            tabu[0].fd=NULL;
                            tabu[0].fg=NULL;
                            tempmoy[0]=(pAr->temperature);
                            nmbstationpourletem[0]++;
                temmax[0]=pAr->temperature;       
                temmin[0]=pAr->temperature;

                
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

                            tempmoy[u]=tempmoy[u]+(pAr->temperature);
                            if((pAr->temperature)>=temmax[u]){
                                temmax[u]=pAr->temperature;
                            }
                            if((pAr->temperature)<=temmin[u]){
                                temmin[u]=pAr->temperature;
                            }
                            
                            nmbstationpourletem[u]++;

                        
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
                

                tempmoy[(*nmbstatio)]=tempmoy[(*nmbstatio)]+(pAr->temperature);       
                temmax[(*nmbstatio)]=pAr->temperature;       
                temmin[(*nmbstatio)]=pAr->temperature;
                if(temmax[(*nmbstatio)]<=pAr->temperature){
                    temmax[(*nmbstatio)]=pAr->temperature;
                }
                if(temmin[(*nmbstatio)]>=pAr->temperature){
                    temmin[(*nmbstatio)]=pAr->temperature;
                }
                nmbstationpourletem[(*nmbstatio)]++;
                (*nmbstatio)++;
                
            }
        }

        
    }
    }
    


}

///////////////////////////////////////////////////////////////////////////////////Tri -p1
//Insertion AVL selon la station.
Chainon* insertionAVLP1(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(statio<pAr->station){
pAr->fg=insertionAVLP1(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(statio>=pAr->station){
    pAr->fd=insertionAVLP1(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
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

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeP1(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio){
if(pAr!=NULL){
        
        parcoursInfixeP1(pAr->fg,fsorti,tabu,pressmoy,pressmax,pressmin,nmbstationpourlapress,nmbstatio);
        parcoursInfixeP1(pAr->fd,fsorti,tabu,pressmoy,pressmax,pressmin,nmbstationpourlapress,nmbstatio);
        traiterP12(pAr,fsorti,tabu,pressmoy,pressmax,pressmin,nmbstationpourlapress,nmbstatio);
    }

}

//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterP12(Chainon* pAr,FILE* fsorti,Chainon* tabu,double* pressmoy,double* pressmax,double* pressmin,int* nmbstationpourlapress,int* nmbstatio){

    int bool=0;
    if(pAr!=NULL){
        if(pAr->pression==0.0){

        }
        else{
        if((*nmbstatio)==0){

            tabu[0].station=pAr->station;
                            tabu[0].date=pAr->date;
                            tabu[0].heure=pAr->heure;
                            tabu[0].pressionmer=pAr->pressionmer;
                            tabu[0].anglevent=pAr->anglevent;
                            tabu[0].forcevent=pAr->forcevent;
                            tabu[0].humidite=pAr->humidite;
                            tabu[0].varpression=pAr->varpression;
                            tabu[0].pression=pAr->pression;
                            tabu[0].precipitation=pAr->precipitation;
                            tabu[0].coordx=pAr->coordx;
                            tabu[0].coordy=pAr->coordy;
                            tabu[0].temperature=pAr->temperature;
                            tabu[0].temperaturemin=pAr->temperaturemin;
                            tabu[0].temperaturemax=pAr->temperaturemax;
                            tabu[0].altitude=pAr->altitude;
                            tabu[0].commune=pAr->commune;
                            tabu[0].equilibre=0;
                            tabu[0].fd=NULL;
                            tabu[0].fg=NULL;
                            pressmoy[0]=(pAr->pression);
                            nmbstationpourlapress[0]++;
                pressmax[0]=pAr->pression;       
                pressmin[0]=pAr->pression;
                
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

                            pressmoy[u]=pressmoy[u]+(pAr->pression);
                            if((pAr->pression)>=pressmax[u]){
                                pressmax[u]=pAr->pression;
                            }
                            if(((pAr->pression)<=pressmin[u])&&(pAr->pression!=0.0)){
                                pressmin[u]=pAr->pression;
                            }
                            
                            nmbstationpourlapress[u]++;

                        
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
                

                pressmoy[(*nmbstatio)]=(pAr->pression);       
                pressmax[(*nmbstatio)]=(pAr->pression);       
                pressmin[(*nmbstatio)]=(pAr->pression);
                
                nmbstationpourlapress[(*nmbstatio)]++;
                (*nmbstatio)++;
            }
        }

        
    }
    }


}


///////////////////////////////////////////////////////////////////////////////////Tri -t2
//Insertion AVL selon la date.
Chainon* insertionAVLT2(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(dat<pAr->date){
pAr->fg=insertionAVLT2(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(dat>=pAr->date){
    pAr->fd=insertionAVLT2(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
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

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeT2(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat){
    if(pAr!=NULL){
        
        parcoursInfixeT2(pAr->fg,tabdat,tabheur,tmpmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
        parcoursInfixeT2(pAr->fd,tabdat,tabheur,tmpmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
        traiterT22(pAr,tabdat,tabheur,tmpmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
    }


}

//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterT22(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double tmpmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat){

    int bool1=0;
    int u=0;
    int x=0;
    if(pAr!=NULL){
        if(pAr->temperature!=2000){
            if((*nmbdat)==0){
                tabdat[0]=pAr->date;
                tabheur[0][0]=pAr->heure;
                tmpmoye[0][0]=pAr->temperature;
                nmbstationmaxheur[0][0]++;
                nmbstationmaxjou[0]++;
                (*nmbdat)++;
            }
            else{
                
                for(u=0;u<(*nmbdat);u++){
                    if(bool1==1){}
                    else{
                    if(pAr->date==tabdat[u]){
                        for(x=0;x<24;x++){
                            if(pAr->heure==x){
                                nmbstationmaxheur[u][x]++;
                                nmbstationmaxjou[u]++;
                                tmpmoye[u][x]=tmpmoye[u][x]+pAr->temperature;
                                bool1=1;

                            }
                        }
                    }
                }
                }
                if(bool1==0){
                    tabdat[(*nmbdat)]=pAr->date;
                    tabheur[(*nmbdat)][0]=pAr->heure;
                    tmpmoye[(*nmbdat)][0]=pAr->temperature;
                    nmbstationmaxheur[(*nmbdat)][0]++;
                    nmbstationmaxjou[(*nmbdat)]++;
                    (*nmbdat)++;
                }
                

            }
        
        





        }   
        else{}
    }

}

///////////////////////////////////////////////////////////////////////////////////Tri -p2
//Insertion AVL selon la date.
Chainon* insertionAVLP2(Chainon* pAr,int statio,int dat,int heur,double pressionme,double angleven,double forceven,int humidit,double pressio,double varpressio,double precipitatio,double coorx,double coory,double temperatur,double temperaturmin,double temperaturmax,double altitud,int commun,int* h){
if(pAr==NULL){
    *h=1;
    return creerArbre(statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun);
}
else if(dat<pAr->date){
pAr->fg=insertionAVLP2(pAr->fg,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
    *h=-(*h);
}
else if(dat>=pAr->date){
    pAr->fd=insertionAVLP2(pAr->fd,statio,dat,heur,pressionme,angleven,forceven,humidit,pressio,varpressio,precipitatio,coorx,coory,temperatur,temperaturmin,temperaturmax,altitud,commun,h);
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

//Parcours l'arbre et appelle le programme de traitement pour enregistrer les valeurs.
void parcoursInfixeP2(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double pressmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat){
  if(pAr!=NULL){
        parcoursInfixeP2(pAr->fg,tabdat,tabheur,pressmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
        parcoursInfixeP2(pAr->fd,tabdat,tabheur,pressmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
        traiterP22(pAr,tabdat,tabheur,pressmoye,nmbstationmaxheur,nmbstationmaxjou,nmbdat);
    }

}

//On regarde le chainon actuel et on enregistre ces valeurs au bons endroits si il est lisible.
void traiterP22(Chainon* pAr,int tabdat[5000],int tabheur[5000][24],double pressmoye[5000][24],short nmbstationmaxheur[5000][24],int nmbstationmaxjou[5000],int* nmbdat){

    int bool1=0;
    int u=0;
    int x=0;
    if(pAr!=NULL){
        if(pAr->pression!=2000){
            if((*nmbdat)==0){
                tabdat[0]=pAr->date;
                tabheur[0][pAr->heure]=pAr->heure;
                pressmoye[0][pAr->heure]=pAr->pression;
                nmbstationmaxheur[0][pAr->heure]++;
                nmbstationmaxjou[0]++;
                (*nmbdat)++;
            }
            else{
                
                for(u=0;u<(*nmbdat);u++){
                    if(bool1==1){}
                    else{
                    if(pAr->date==tabdat[u]){
                        for(x=0;x<24;x++){
                            if(pAr->heure==x){
                                nmbstationmaxheur[u][x]++;
                                nmbstationmaxjou[u]++;
                                pressmoye[u][x]=pressmoye[u][x]+pAr->pression;
                                bool1=1;

                            }
                        }
                    }
                }
                }
                if(bool1==0){
                    tabdat[(*nmbdat)]=pAr->date;
                    tabheur[(*nmbdat)][pAr->heure]=pAr->heure;
                    pressmoye[(*nmbdat)][pAr->heure]=pAr->pression;
                    nmbstationmaxheur[(*nmbdat)][pAr->heure]++;
                    nmbstationmaxjou[(*nmbdat)]++;
                    (*nmbdat)++;
                }
            }
        }   
        else{}
    }



}


///////////////////////////////////////////////////////////////////////////////////

