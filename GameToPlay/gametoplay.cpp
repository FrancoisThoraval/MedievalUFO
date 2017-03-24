#include "gametolay.hpp"

void GameToPlay(Map *map){
/********* VARIABLE *********/
struct timeval debut,fin;                // variable temps
float tempspasse;
float tempsJeux = 60;
/***************************/
  /** INIT MAP ICI **/                                  //<------ FRANCOIS


    // Creé fenetre Demander nom joueur 1
  Player J1(NOM_A_METTRE);
   // Crée fenetre Demander nom joueur 2
  Player J2(NOM_A_METTRE);
  int tours = 1;
  bool TourSuivant = false;
  gettimeofday(&debut,NULL);
  while((J2.getLost()!=true) || (J1.getLost()!= true )){  // boucle principale qui arrete le jeux quand il est fini
    if(tour == 1){                                        // tour du joueur 1
      TourSuivant = false;
      while(!(TourSuivant)){                              // FIN DE TOURS




        //********************************************************//
        //                     JEUX ICI                           //
        //********************************************************//



        tempspasse = (((fin.tv_sec - debut.tv_sec)*1000000L+fin.tv_usec) - debut.tv_usec);
        tempspasse = (tempspasse/1000)/1000;
        gettimeofday(&fin,NULL);
        if((tempspasse > tempsJeux) || (PASSER_SON_TOUR_EST_APPUYE )) {             //<-------------- FRANCOIS
          tours = 2;
          J1.EndOfTurn(map);
          TourSuivant = true;
        }

      }
    } else {                                              // tour du joueur 2
      TourSuivant = false;
      while(!(TourSuivant)){                              // FIN DE TOURS




        //********************************************************//
        //                     JEUX ICI                           //
        //********************************************************//


        tempspasse = (((fin.tv_sec - debut.tv_sec)*1000000L+fin.tv_usec) - debut.tv_usec);
        tempspasse = (tempspasse/1000)/1000;
        gettimeofday(&fin,NULL);
        if((tempspasse > tempsJeux) || (PASSER_SON_TOUR_EST_APPUYE )) {             //<-------------- FRANCOIS
          tours = 1;
          J2.EndOfTurn(map);
          TourSuivant = true;
        }

      }
    }
  }

}
