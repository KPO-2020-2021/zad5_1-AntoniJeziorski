#pragma once

#include "matrix3D.hh"
#include "solid.hh"

/*!
 *
 * \file cuboid.hh
 * 
 * \brief Plik zawierajacy definicje klasy Cuboid
 */

/*!
 *
 * \brief Definicja klasy Cuboid reprezentujaca prostopadloscian jako bryle geometryczna\n w trojwymiarowym ukladzie wspolrzednych
 */

class Cuboid: public Solid {

    /*!
     *
     * \brief Jednowymiarowa tablica wektorow reprezentujacych wspolrzedne lokalne wierzcholkow
     */

    Vector3D localCorners[8];

    /*!
     *
     * \brief Jednowymiarowa tablica wektorow reprezentujacych wspolrzedne globalne wierzcholkow
     */

    Vector3D globalCorners[8];

    /*!
     *
     * \brief Wektor przetrzymujacy wspolrzedne srodka prostopadloscianu
     */

    Vector3D location;

    /*!
     *
     * \brief Zmienna typu double przetrzymujaca calkowity kat obrotu prostopadloscianu
     */

    double rotationAngle;

    public:

        /*!
         *
         * \brief Konstruktor bezparametryczny klasy Cuboid
         * Tworzy prostopadloscian o dlugosciach bokow 1 i przekazuje wspolrzedne do lokalnego ukladu wspolrzednych
         */

        Cuboid();

        /*!
         *
         * \brief Metoda obliczajaca wspolrzedne globalne wierzcholkow prostopadloscianu
         * 
         * \param Translation - wektor polozenia srodka prostopadloscianu w ukladzie rodzica
         */

        void ToGlobal(Vector3D& Translation);
    
        /*!
         *
         * \brief Przeciazenie operatora funkcyjnego () dla zapisu
         * 
         * \param index - indeks wierzcholka prostopadloscianu
         * 
         * \return Wektor reprezentujacy wspolrzedne wierzcholka
         */

        Vector3D &operator () (int index);

        /*!
         *
         * \brief Przeciazenie operatora indeksujacego
         * 
         * \param index - indeks wierzcholka
         * 
         * \return Wektor reprezentujacy wspolrzedne lokalne wierzcholka
         */

        Vector3D &operator [] (int index);

        /*!
         *
         * \brief Metoda zwracajaca wspolrzedne srodka prostopadloscianu
         * 
         * \return Wektor reprezentujacy wspolrzedne srodka prostopadloscianu
         */

        Vector3D GetLocation();

        /*!
         *
         * \brief Metoda aktualizujaca kat obrotu prostopadloscianu
         * 
         * \param angle - kat o jaki chcemy zaktualizowac wartosc kata obrotu
         */

        void Rotate(double angle);

        /*!
         *
         * \brief Metoda zwracajaca calkowity kat obrotu prostopadloscianu
         * 
         * \return Calkowity kat obrotu prostopadloscianiu jako zmienna typu double
         */

        double GetRotationAngle();

};

