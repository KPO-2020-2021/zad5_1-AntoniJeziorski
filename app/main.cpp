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
#include "scene.hh"
#include "../inc/lacze_do_gnuplota.hh"

int main() {

    double tab[3] = {10,8,6}, tab2[3] = {0,0,80}, l1[3] = {20,20,3}, l2[3] = {50,20,3}, t[3] = {0,0,-80}, h[3] = {79, 80, 0}, r[3] = {7,7,2}, angle, distance;
    Vector3D v(tab), tr(tab2), loc1(l1), tr2(t), hor(h), loc2(l2), rot(r);

    Drone d1(v,rot, loc1), d2(v, rot, loc2);
    int droneNumber = 1;

    Scene scene(d1,d2);

    char option = '0';

    PzG::LaczeDoGNUPlota  Link;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
   
    PzG::InfoPlikuDoRysowania *body1Info = &Link.DodajNazwePliku("../datasets/body1.dat");
    body1Info->ZmienKolor(1);
    body1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor1_1Info = &Link.DodajNazwePliku("../datasets/rotor0_1.dat");
    rotor1_1Info->ZmienKolor(1);
    rotor1_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor2_1Info = &Link.DodajNazwePliku("../datasets/rotor1_1.dat");
    rotor2_1Info->ZmienKolor(1);
    rotor2_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor3_1Info = &Link.DodajNazwePliku("../datasets/rotor2_1.dat");
    rotor3_1Info->ZmienKolor(1);
    rotor3_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor4_1Info = &Link.DodajNazwePliku("../datasets/rotor3_1.dat");
    rotor4_1Info->ZmienKolor(1);
    rotor4_1Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor1_2Info = &Link.DodajNazwePliku("../datasets/rotor0_2.dat");
    rotor1_2Info->ZmienKolor(1);
    rotor1_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor2_2Info = &Link.DodajNazwePliku("../datasets/rotor1_2.dat");
    rotor2_2Info->ZmienKolor(1);
    rotor2_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor3_2Info = &Link.DodajNazwePliku("../datasets/rotor2_2.dat");
    rotor3_2Info->ZmienKolor(1);
    rotor3_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *rotor4_2Info = &Link.DodajNazwePliku("../datasets/rotor3_2.dat");
    rotor4_2Info->ZmienKolor(1);
    rotor4_2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *body2Info = &Link.DodajNazwePliku("../datasets/body2.dat");
    body2Info->ZmienKolor(1);
    body2Info->ZmienSzerokosc(3);

    PzG::InfoPlikuDoRysowania *bedInfo = &Link.DodajNazwePliku("../datasets/bed.dat");
    bedInfo->ZmienKolor(2);
    bedInfo->ZmienSzerokosc(1);
    
    

   //
   //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy tylko x,y.
   //
    Link.ZmienTrybRys(PzG::TR_3D);

    Link.UstawZakresY(0,200);
    Link.UstawZakresX(0,200);
    Link.UstawZakresZ(0,150);


    scene.GetDrone(0).SaveDrone(1);
    scene.GetDrone(1).SaveDrone(2);
  
    Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku

    while(option != 'k') { // Dopoki nie zostanie podane k

        if(option == '0') { 
        
            std::cout << "a - wybierz aktywnego drona" << std::endl;
            std::cout << "p - zadaj parametry przelotu" << std::endl;
            std::cout << "z - wykonaj zwiad" << std::endl;
            std::cout << "m - wyswietl menu" << std::endl;
            std::cout << std::endl;
            std::cout << "k - koniec dzialania programu" << std::endl;
            
        }

        std::cout << "Twoj wybor: " << std::endl;
        std::cin >> option;

        switch(option) {
            case 'k':

                option = 'k'; break;

            case 'p':

                std::cout << "Podaj kierunek lotu (kat w stopniach)" << std::endl;
                std::cin >> angle;
                std::cout << "Podaj dlugosc lotu" << std::endl;
                std::cin >> distance;

                Link.DodajNazwePliku("../datasets/path.dat");
                scene.UseDrone(droneNumber-1).PlanPath(angle, distance);
                std::cout << "Planuje sciezke..." << std::endl;
                usleep(1000000);
                Link.Rysuj();
                
                std::cout << "Wznoszenie..." << std::endl;
                scene.UseDrone(droneNumber-1).VerticalFlight(tr, Link, droneNumber);
                std::cout << "Lot..." << std::endl;
                scene.UseDrone(droneNumber-1).HorizontalFlight(distance, angle, Link, droneNumber);
                scene.UseDrone(droneNumber-1).VerticalFlight(tr2, Link, droneNumber);
                std::cout << "Dron wyladowal..." << std::endl;

                Link.UsunNazwePliku("../datasets/path.dat");
                Link.Rysuj();

                break;

            case 'm':

                option = '0';

                break;
            case 'a':

                std::cout << "Podaj numer drona" << std::endl;
                std::cin >> droneNumber;

                break;

            case 'z':
                Link.DodajNazwePliku("../datasets/path.dat");
                scene.UseDrone(droneNumber-1).Recce(droneNumber, Link);
                Link.UsunNazwePliku("../datasets/path.dat"); 
                Link.Rysuj();
                break;

            default:
                option = '0';
                std::cerr << "!!! NIEPOPRAWNA OPCJA !!!" << std::endl; break;
        }
    }

    return 0;

}
