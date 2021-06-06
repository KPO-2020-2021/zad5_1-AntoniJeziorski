#pragma once

#include "lacze_do_gnuplota.hh"
#include "cuboid.hh"
#include "hexagonal_prism.hh"
#include <unistd.h>
#include <fstream>

/*!
 *
 * \file drone.hh
 * 
 * \brief Plik zawierajacy definicje klasy Drone
 */

/*!
 *
 * \brief Definicja klasy Drone modelujacej drona w trojwymiarowych ukladzie wspolrzednych
 */

class Drone {

    /*!
     *
     * \brief Pole typu double zawierajace wartość kata obrotu brona
     */

    double rotationAngle;

    /*!
     *
     * \brief Pole typu Cuboid reprezentujace koprus drona
     */

    Cuboid body;

    /*!
     *
     * \brief Pole typu Vector3D zawierajace wpsolrzedne polozenia drona
     */

    Vector3D location;

    /*!
     *
     * \brief Jednowymiarowa tablica typu HexPrism reprezentujaca rotory drona
     */

    HexPrism rotor[4];

    public:

        /*!
         *
         * \brief Konstruktor bezparametryczny klasy Drone, tworzy pusty obiekt
         */

        Drone();

        /*!
         *
         * \brief Konstruktor parametryczny klasy Drone
         * 
         * \param scale - skala korpusu
         * 
         * \param rotorScale - skala rotora
         * 
         * \param loc - wspolrzedne poczatkowe drona
         */

        Drone(Vector3D& scale, Vector3D& rotorScale, Vector3D& loc);

        /*!
         *
         * \brief Metoda zapisujaca korpus drona do pliku
         * 
         * \param droneNumber - numer drona
         * 
         * \return true jesli operacja sie powiedzie\n false jesli operacja sie nie powiedzie
         */

        bool SaveBody(int droneNumber);

        /*!
         *
         * \brief Metoda zapisuja rotor do pliku
         * 
         * \param droneNumber - numer drona
         * 
         * \param rotorNumber - numer rotora
         * 
         * \param Translation - wektor przesuniecia rotora wzgledem ukaldu rodzica
         * 
         * \return true jesli operacja sie powiedzie\n false jesli operacja sie nie powiedzie
         */

        bool SaveRotor(int droneNumber, int rotorNumber, Vector3D& Translation);

        /*!
         *
         * \brief Metoda zapisujaca drona do plikow\n Wywoluje funkcje SaveBody i SaveDrone
         * 
         * \param droneNumber - numer drona
         */

        void SaveDrone(int droneNumber);

        /*!
         *
         * \brief Metoda realizujaca lot pionowy drona
         * 
         * \param translation - wektor o jaki trzeba przesunac drona
         * 
         * \param Link - lacze do gnuplota
         * 
         * \param droneNumber - numer drona
         */

        void VerticalFlight(Vector3D& translation, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        /*!
         *
         * \brief Metoda realizujaca lot poziomy drona
         * 
         * \param distance - dlugosc lotu
         * 
         * \param angle - kat obrotu drona
         * 
         * \param Link - lacze do gnuplota
         * 
         * \param droneNumber - numer drona
         */

        void HorizontalFlight(double distance, double angle, PzG::LaczeDoGNUPlota& Link, int droneNumber);

        /*!
         *
         * \brief Metoda wyznaczajaca sciezke przelotu drona
         * 
         * \param angle - kat obrotu drona
         * 
         * \param distance - dlugosc lotu
         */

        void PlanPath(double angle, double distance); 

        /*!
         *
         * \brief Metoda obliczajaca wspolrzedne globalne rotora
         * 
         * \param rotorNumber - numer rotora
         * 
         * \param Translation - przesuniecie rotora wzgledem ukladu korpusu
         */

        void RotorToGlobal(int rotorNumber, Vector3D& Translation);

        /*!
         *
         * \brief Metoda realizujaca zwiad drona
         * 
         * \param droneNumber - numer drona
         * 
         * \param link - lacze do gnuplota
         */

        void Recce(int droneNumber,  PzG::LaczeDoGNUPlota& Link);

        /*!
         *
         * \brief Przeciazenie operatora indeksowania dla zapisu rotora
         * 
         * \param index - indeks rotora
         * 
         * \return rotor jako obiekt klasy HexPrism o podanym indeksie
         */

        HexPrism &operator [] (int index);

        /*!
         *
         * \brief Metoda zwracajaca polozenie drona
         * 
         * \return Polozenie drona jako const Vector3D
         */

        Vector3D GetLocation() const;

};