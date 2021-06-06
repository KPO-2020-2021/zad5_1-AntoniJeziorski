#include "drone.hh"

/*!
 *
 * \file scene.hh
 * 
 * \brief Plik zawierajacy definicje klasy Scene
 */

/*!
 *
 * \brief Definicja klasy Scene reprezentujacej scene z dronami
 */

class Scene {

    /*!
     *
     * \brief Jednowymiarowa tablica typu Drone preztrzymuajca informacje na temat dronow na scene
     */

    Drone arrayOfDrones[2];

    /*!
     *
     * \brief Zmienna typu PzG::LaczeDoGNUPlota bedaca laczem do programu gnuplot
     */

    PzG::LaczeDoGNUPlota Link;

    public:

        /*!
         *
         * \brief Konstruktor parametryczny klasy Scene\n Tworzy scene z dwoma dronami podanymi jako parametry
         * 
         * \param drone1 - dron nr 1
         * 
         * \param drone2 - dron nr 2
         */

        Scene(Drone drone1, Drone drone2);

        /*!
         *
         * \brief Metoda zwracajaca referencje do drona ktorego chcemy uzyc
         * 
         * \param droneNumber - numer drona
         * 
         * \return Referencje do drona o zadanym numerze
         */

        Drone& UseDrone(int droneNumber);

        /*!
         *
         * \brief Metoda zwracajaca drona tylko do odczytu
         * 
         * \param droneNumber - numer drona
         * 
         * \return const Drone o zadanym numerze
         */

        Drone GetDrone(int droneNumber) const;

};


