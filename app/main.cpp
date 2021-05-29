// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h.in"
#include "solid.hh"
#include "cuboid.hh"
#include "drone.hh"
#include "example.h"
#include "vector3D.hh"
#include "matrix3D.hh"
#include "../inc/lacze_do_gnuplota.hh"

int main() {

    double tab[3] = {10,8,6}, tab2[3] = {0,0,80}, l[3] = {20,20,3}, t[3] = {0,0,-80}, h[3] = {79, 80, 0} ;
    Vector3D v(tab), tr(tab2), loc(l), tr2(t), hor(h);

    Drone dron(v,loc);


    

    PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
    Lacze.DodajNazwePliku("../datasets/body.dat",PzG::SR_Ciagly);
    PzG::InfoPlikuDoRysowania *bodyInfo = &Lacze.DodajNazwePliku("../datasets/body.dat");
    bodyInfo->ZmienKolor(1);
    bodyInfo->ZmienSzerokosc(3);

    Lacze.DodajNazwePliku("../datasets/bed.dat",PzG::SR_Ciagly);
    PzG::InfoPlikuDoRysowania *bedInfo = &Lacze.DodajNazwePliku("../datasets/bed.dat");
    bedInfo->ZmienKolor(2);
    bedInfo->ZmienSzerokosc(1);
    
    

   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
    Lacze.ZmienTrybRys(PzG::TR_3D);

    Lacze.UstawZakresY(0,200);
    Lacze.UstawZakresX(0,200);
    Lacze.UstawZakresZ(0,150);

    dron.SaveBody("../datasets/body.dat");
  
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');

    Lacze.DodajNazwePliku("../datasets/path.dat", PzG::SR_Ciagly);
    PzG::InfoPlikuDoRysowania *pathInfo = &Lacze.DodajNazwePliku("../datasets/path.dat");
    pathInfo->ZmienKolor(4);
    pathInfo->ZmienSzerokosc(1);

    dron.PlanPath(45, 100);
    Lacze.Rysuj();
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');

    dron.VerticalFlight(tr, Lacze);
    
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');

    dron.HorizontalFlight(100 ,Lacze);

    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');

    dron.VerticalFlight(tr2, Lacze);
    
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');



    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000,'\n');

    return 0;

}
