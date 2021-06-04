#pragma once

#include "vector3D.hh"
#include "size.hh"
#include <iostream>
#include <string>

/*!
 *
 * \file solid.hh
 * \brief Plik zawierający definicję klasy Solid\
 */

/*!
 *
 * \brief Definicja klasy Solid
 * 
 * Klasa Solid modelujaca bryle geometryczna w trojwymiarowym ukladzie wspolrzednych
 */

class Solid {

    public:
        
        /*!
         *
         * \brief Vector3D przetrzymujacy wartosci skali w osiach X Y Z
         */

        Vector3D scaleVector;

        /*!
         *
         * \brief std::string przetrzymujacy nazwe pliku bryly
         */

        std::string filename;

        /*!
         *
         * \brief konstruktor bezparametryczny klasy Solid
         * 
         * Kostruktor tworzacy bryle geometryczna ze skala [1,1,1]
         */

        Solid();

        /*!
         *
         * \brief Metoda aktualizujaca wartosc skali
         * 
         * \param s - wektor zawierajacy wartosci skali o jakie chcemy zmienic wartosc skali w klasie
         */

        void Scale(const Vector3D& s);

        /*!
         *
         * \brief Metoda zwracajaca nazwe pliku
         * 
         * \return Nazwa pliku bryly jako std::string
         */

        std::string GetFilename();

};