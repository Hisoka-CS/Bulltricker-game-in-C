
#include <stdio.h>
#include <stdlib.h>
#define pion_blanc 1
#define dame_blanc 2
#define pion_noir -1
#define dame_noir -2
#define roi_blanc 3
#define roi_noir -3
#define case_vide 0
//**************************************les structures a travailler avec **************************************************




typedef struct {
    int lig,col ;
} Case ;

typedef struct {
    Case case_i,case_f ;
} deplacement ;
typedef struct element *listeCases ;
typedef struct {
    char *nom ;
    int couleur ;
} joueur ;
typedef struct {
    int plateau[15][15] ;
    int nb_pion_noir ;
    int nb_pion_blanc ;
    int nb_dame_noir ;
    int nb_dame_blanc ;
} tricker ;
//*****************************************************conception et initialisation du plateau*********************************
void affiche_ligne(int i,int tricker[15][15]) {
    int j ;
    printf(" %2d ",i+1) ;
    for(j=0 ;j<15 ;j++) {
        switch(tricker[i][j]) {
            case pion_blanc :
            printf("| O ") ;
            break ;
            case  pion_noir :
            printf("| X ") ;
            break ;
            case  dame_noir :
            printf("| [X] ") ;
            break ;
            case  dame_blanc :
            printf("| [O] ") ;
            break ;
            case roi_blanc :
            printf("| Q ");
            break ;
            case  roi_noir :
            printf("| Z ");
            break ;
            default :
            printf("| ") ;
            break ;
            }
    printf("| %2d\n",i+1) ;
    printf(" |-------------------------------------------|\n") ;
}
}
void affiche_tricker(int tricker[15][15]) {
    int i ;
    printf(" a b c d e f g h i j \n") ;
    printf(" |----------------------------------------|\n") ;
    for(i=0 ;i<15 ;i++)
        affiche_ligne(i,tricker) ;
    printf(" a b c d e f g h i j \n") ;
}
void init_tricker(tricker * jeu) {
    jeu->nb_pion_noir = 15 ;
    jeu->nb_pion_blanc = 15 ;
    jeu->nb_dame_blanc = 8 ;
    jeu->nb_dame_noir = 8 ;
    int i,j ;
    //On initialise le tableau
    for(i=0 ;i<15 ;i++)
        for(j=0 ;j<15 ;j++)
        jeu->plateau[i][j] = 0 ;
        //On remplie la partie haute du damier par des pions noirs
    for (i=0;i<15;i++) {
    if (i=1) {
        for(j=0;j<15;j++){
            if (j=7) jeu->plateau[i][j]=roi_noir ;
            if(j%2==0) jeu->plateau[i][j]=dame_noir ;
            }
    }
    if (i=2) {
        for(j=0;j<15;j++){
            if(j%2==1) jeu->plateau[i][j]=pion_noir ;
            }
    }
    if (i=3) {
        for(j=0;j<15;j++){
            if(j%2==0) jeu->plateau[i][j]=pion_noir ;
            }
    }
    //On remplie la partie basse du damier par des pions blancs
    if (i=13) {
        for(j=0;j<15;j++){
            if( j=7) jeu->plateau[i][j]=roi_blanc;
            if(j%2==0) jeu->plateau[i][j]=dame_blanc ;
            }
    }
    if (i=12) {
        for(j=0;j<15;j++){
            if(j%2==1) jeu->plateau[i][j]=pion_blanc ;
            }
    }
    if (i=11) {
        for(j=0;j<15;j++){
            if(j%2==0) jeu->plateau[i][j]=pion_blanc ;
            }
    }
}
}
//*****************************************************deplacement***********************************************************
int deplace_roi(int couleur,deplacement d,tricker* jeu){
    jeu->plateau[d.case_i.lig][d.case_i.col] =couleur;
    jeu->plateau[d.case_f.lig][d.case_f.col] = case_vide;
    if (abs(d.case_f.lig - d.case_i.lig > 2)||abs(d.case_f.col - d.case_i.col > 2)){
            printf("impossible");
          }
      if((d.case_f.lig%2==0 || d.case_f.col%2==0)){
            printf("impossible");
         }
       if(jeu->plateau[d.case_f.lig][d.case_f.col] = jeu->plateau[d.case_i.lig][d.case_i.col-2]){
            if (jeu->plateau[d.case_i.lig][d.case_i.col-1]!= case_vide){
                printf("error");
        }}

      if(jeu->plateau[d.case_f.lig][d.case_f.col] = jeu->plateau[d.case_i.lig-2][d.case_i.col]){
            if (jeu->plateau[d.case_i.lig-1][d.case_i.col]!= case_vide ){
                printf("error");
         }
       }
       if ((jeu->plateau[d.case_f.lig][d.case_f.col] = jeu->plateau[d.case_i.lig][d.case_i.col+2])){
            if (jeu->plateau[d.case_i.lig][d.case_i.col+1]!= case_vide){
                printf("error");
           }}
      if ((jeu->plateau[d.case_f.lig][d.case_f.col] = jeu->plateau[d.case_i.lig+2][d.case_i.col])){
            if (jeu->plateau[d.case_i.lig+1][d.case_i.col]!= case_vide){
                printf("error");
          }}
        jeu->plateau[d.case_f.lig][d.case_f.col]== jeu->plateau[d.case_i.lig][d.case_i.col];
        jeu->plateau[d.case_i.lig][d.case_f.col]=case_vide;//il faut ajouter checker if the surroundings are all full if not boolen=false else boolen=true and print("end game")  whil(boolen!=true) continue ... et reatrancher nb de dame ou de pion

}
void deplace_dame(int couleur,deplacement d,tricker* jeu)
{
   int c,v;//c=1 deplacement ou prise va être faitê et c=0 deplacement ou prise impossible
   jeu->plateau[d.case_i.lig][d.case_i.col] =couleur;
   jeu->plateau[d.case_f.lig][d.case_f.col] = case_vide;

   if(jeu->plateau[d.case_f.lig][d.case_f.col]!=case_vide ) printf("error");
   if((jeu->plateau[d.case_i.lig+1][d.case_i.col]!=case_vide)&&(jeu->plateau[d.case_i.lig+1][d.case_i.col]!=couleur)&& (jeu->plateau[d.case_i.lig+2][d.case_i.col]==case_vide))////Deplacement obligatoire
   {
    c=1;
    jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig+2][d.case_i.col];
    jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
    jeu->plateau[d.case_i.lig+1][d.case_i.col]=case_vide;//prise de la pièce

      if((jeu->plateau[d.case_i.lig+1][d.case_i.col]!=case_vide)&&(jeu->plateau[d.case_i.lig+1][d.case_i.col]!=couleur) &&(jeu->plateau[d.case_i.lig+2][d.case_i.col]==case_vide)) //double prise
    {
        jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig+2][d.case_i.col];
        jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
    }
   }
   if((jeu->plateau[d.case_i.lig][d.case_i.col+1]!=case_vide)&& (jeu->plateau[d.case_i.lig][d.case_i.col+1]!=couleur)&& (jeu->plateau[d.case_i.lig][d.case_i.col+2]==case_vide))////Deplacement obligatoire
   {
    v=1;
    jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig][d.case_i.col+2];
    jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
    jeu->plateau[d.case_i.lig][d.case_i.col+1]=case_vide;
      if((jeu->plateau[d.case_i.lig+1][d.case_i.col]!=case_vide)&& (jeu->plateau[d.case_i.lig+1][d.case_i.col]!=couleur)&&(jeu->plateau[d.case_i.lig+2][d.case_i.col]==case_vide)) //double prise
    {
        jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig][d.case_i.col+2];
        jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
        jeu->plateau[d.case_i.lig+1][d.case_i.col]=case_vide;
    }
   }
   if((jeu->plateau[d.case_i.lig][d.case_i.col-1]!=case_vide)&& (jeu->plateau[d.case_i.lig][d.case_i.col-1]!=couleur)&&(jeu->plateau[d.case_i.lig][d.case_i.col-2]==case_vide))////Deplacement obligatoire
   {
    v=1;
    jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig][d.case_i.col-2];
    jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
    jeu->plateau[d.case_i.lig][d.case_i.col-1]=case_vide;

      if((jeu->plateau[d.case_i.lig][d.case_i.col-1]!=case_vide)&& (jeu->plateau[d.case_i.lig][d.case_i.col-1]!=couleur)&&(jeu->plateau[d.case_i.lig][d.case_i.col-2]==case_vide)) //double prise
    {
        jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig][d.case_i.col-2];
        jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
        jeu->plateau[d.case_i.lig][d.case_i.col-1]=case_vide;
    }
    }
    if((jeu->plateau[d.case_i.lig-1][d.case_i.col]!=case_vide)&&(jeu->plateau[d.case_i.lig-1][d.case_i.col]!=couleur)&&(jeu->plateau[d.case_i.lig-22][d.case_i.col]==case_vide))////Deplacement obligatoire
    {
      c=1;
      jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig-2][d.case_i.col];
      jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
      jeu->plateau[d.case_i.lig-1][d.case_i.col]=case_vide;

      if((jeu->plateau[d.case_i.lig-1][d.case_i.col]!=case_vide)&& (jeu->plateau[d.case_i.lig-1][d.case_i.col]!=couleur)&&(jeu->plateau[d.case_i.lig-2][d.case_i.col]==case_vide)) //double prise
    {
        jeu->plateau[d.case_f.lig][d.case_f.col]=jeu->plateau[d.case_i.lig-2][d.case_i.col];
        jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
        jeu->plateau[d.case_i.lig-1][d.case_i.col]!=couleur;
    }
    }
    if(c==1 && v==1) printf("priorité a la prise par rangée");
    jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide;
    jeu->plateau[d.case_f.lig][d.case_f.col] = couleur;
  }




void deplace_pion (int couleur,deplacement d,tricker* jeu) {
    jeu->plateau[d.case_i.lig][d.case_i.col] =couleur;
    if (jeu->plateau[d.case_i.lig][d.case_i.col] = pion_blanc)
            if(jeu->plateau[d.case_f.lig][d.case_f.col] == pion_blanc )
                printf("error");
            if (jeu->plateau[d.case_f.lig][d.case_f.col] == pion_noir )
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_blanc;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
                jeu->nb_pion_noir--;
            if (jeu->plateau[d.case_f.lig][d.case_f.col] == dame_noir )
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_blanc;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
                jeu->nb_dame_noir--;
            if(jeu->plateau[d.case_f.lig][d.case_f.col] = case_vide)
                jeu->plateau[d.case_f.lig][d.case_f.col] = couleur ;
                jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide ;
            if(d.case_f.lig%2==0 && d.case_f.col%2==0)
                printf("error");
            if((d.case_i.lig - d.case_f.lig > 2)||abs(d.case_i.col - d.case_f.col > 2))
                printf("error");
            else
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_blanc;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
    if (jeu->plateau[d.case_i.lig][d.case_i.col] = pion_noir)
            if(jeu->plateau[d.case_f.lig][d.case_f.col] == pion_noir )
                printf("error");
            if (jeu->plateau[d.case_f.lig][d.case_f.col] == pion_blanc )
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_noir;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
                jeu->nb_pion_blanc--;
            if (jeu->plateau[d.case_f.lig][d.case_f.col] == dame_blanc )
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_noir;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
                jeu->nb_dame_blanc--;
            if(jeu->plateau[d.case_f.lig][d.case_f.col] = case_vide)
                jeu->plateau[d.case_f.lig][d.case_f.col] = couleur ;
                jeu->plateau[d.case_i.lig][d.case_i.col] =case_vide ;
            if(d.case_f.lig%2==0 && d.case_f.col%2==0)
                printf("error");
            if(d.case_f.lig - d.case_i.lig > 2 || d.case_f.col - d.case_i.col > 2)
                printf("error");
            else
                jeu->plateau[d.case_f.lig][d.case_f.col] = pion_noir;
                jeu->plateau[d.case_i.lig][d.case_i.col] = case_vide ;
}


    int checkmate(tricker * jeu)
    {
     int lig,col,a,b,c,d;
     int checkmatestatus=0;
     a=jeu->plateau[lig+1][col];
     b=jeu->plateau[lig-1][col];
     c=jeu->plateau[lig][col+1];
     d=jeu->plateau[lig][col-1];
     for(lig=0;lig<15;lig++) {
        for(col=0;col<15;col++){
            if(jeu->plateau[lig][col]=roi_noir){
               if ((a!=case_vide)&&(b!=case_vide)&&(c!=case_vide)&&(d!=case_vide)){
                   if((a!=pion_noir && a!=dame_noir)||(b!=pion_noir && b!=dame_noir)||(c!=pion_noir && c!=dame_noir)||(d!=pion_noir && d!=dame_noir)) {
                        checkmatestatus=1;
       }}}
            if(jeu->plateau[lig][col]=roi_blanc){
               if ((a!=case_vide)&&(b!=case_vide)&&(c!=case_vide)&&(d!=case_vide)){
                   if((a!=pion_blanc && a!=dame_blanc)||(b!=pion_blanc && b!=dame_blanc)||(c!=pion_blanc && c!=dame_blanc)||(d!=pion_blanc && d!=dame_blanc)) {
                    checkmatestatus=1;
       }}}
    return checkmatestatus;
}}}








  void menu(){
 	printf("\t Menu : \n");
 	printf("\t1 : afficher tricker \n");
 	printf("\t2 :afficher ligne \n");
 	printf("\t3 : deplacer ROI \n");
 	printf("\t4 : deplacer DAME \n");
 	printf("\t5 : deplacer PION\n");
  }


//**********************************************************************************************main*******************************************************************************************


 int main()
 {
    tricker * jeu;
    deplacement d;
    int couleur;
    int tricker[15][15];
    init_tricker(jeu);
	int n=0;
    int ch=0;
    int i,j,x,y,checkmatestatus;
    checkmatestatus=0;



        while(checkmatestatus!=1)
        {
        do{//while not checkmate
           menu();
           printf("saisir un choix : ");
           scanf("%d",&ch);
           switch(ch){
       	   case 1 :
              affiche_tricker( tricker[15][15]);
               checkmatestatus=checkmate(jeu);
              break;
           case 2 :
               printf("donner la ligne");
               scanf("%d",&i);
               affiche_ligne(i, tricker[15][15]);
                checkmatestatus=checkmate(jeu);
              break;
           case 3:
              printf("donner une couleur");
              scanf("%s",couleur);
              printf("donner la case a deplacer ");
              scanf("%d%d",&i,&j);
              d.case_i.lig=i;
              d.case_i.col=j;
              printf("donner la case ou deplacer ");
              scanf("%d%d",&x,&y);
              d.case_f.lig=x;
              d.case_f.col=y;
              deplace_roi(couleur,d,jeu);
               checkmatestatus=checkmate(jeu);
           case 4:
              printf("donner une couleur");
              scanf("%s",couleur);
              printf("donner la case a deplacer ");
              scanf("%d%d",&i,&j);
              d.case_i.lig=i;
              d.case_i.col=j;
              printf("donner la case ou deplacer ");
              scanf("%d%d",&x,&y);
              d.case_f.lig=x;
              d.case_f.col=y;
              deplace_dame(couleur,d,jeu);
               checkmatestatus=checkmate(jeu);
           case 5:
              printf("donner une couleur");
              scanf("%s",couleur);
              printf("donner la case a deplacer ");
              scanf("%d%d",&i,&j);
              d.case_i.lig=i;
              d.case_i.col=j;
              printf("donner la case ou deplacer ");
              scanf("%d%d",&x,&y);
              d.case_f.lig=x;
              d.case_f.col=y;
              deplace_pion(couleur, d, jeu);
               checkmatestatus=checkmate(jeu);
    }
    }while(checkmatestatus!=1);
        }
     return 0;
}








