#include "solid.hh"
#include "matrix3D.hh"

/*!
 *
 * \file hexagonal_prism.hh
 * 
 * \brief Plik zawierajacy definicje klasy HexPrism
 */

/*!
 *
 * \brief Definicja klasy HexPrism dziedziczacej po klasie Solid modelujaca prostopadloscian szesciokatny w trojwymiarowym ukladzie wspolrzednych
 */

class HexPrism: public Solid {

    /*!
     *
     * \brief Jendowymiarowa tablica typu Vector3D reprezentujaca lokalne wspolrzedne wierzcholkow
     */

    Vector3D localCorners[12];

    /*!
     *
     * \brief Jednowymiarowa tablica typu Vector3D reprezentujaca wspolrzedne wierzcholkow w ukladzie rodzica
     */

    Vector3D cuboidSystemCorners[12];

    /*!
     *
     * \brief Jednowymiarowa tablica typu Vector3D reprezentujaca globalne wspolrzedne wierzcholkow
     */

    Vector3D globalCorners[12];

    /*!
     *
     * \brief Wektor reprezentujacy polozenie w ukladzie rodzica
     */

    Vector3D location;

    /*!
     *
     * \brief Zmienna typu double przetrzymujaca wartosc kata calkowitego obrotu rotora
     */

    double rotationAngle;

    public:

        /*!
         *
         * \brief Konstruktor bezparametryczny klasy HexPrism\n Tworzy prostopadloscian szesciokatny o dlugosci krawedzi 1
         */

        HexPrism();

        /*!
         *
         * \brief Metoda obliczajaca wspolrzedne prostopadloscianu szesciokatnego w ukladzie wpsolrzednym rodzica
         */

        void  ToCubeSystem(Vector3D& Translation);

        /*!
         *
         * \brief Przeciazenie operatora funkcyjnego dla zapisu wartosci lokalnych wierzcholkow
         * 
         * \param index - indeks wierzcholka
         * 
         * \return Wektor reprezentujacy wspolrzedne lokalne wierzcholka
         */

        Vector3D &operator () (int index);

        /*!
         *
         * \brief Przeciazenie operatora indeksowania dla zapisu wspolrzednych globalnych wierzcholkow
         * 
         * \param index - index wierzcholka
         * 
         * \return Wektor reprezentujacy globalne wspolrzedne wierzcholka
         */

        Vector3D &operator [] (int index);

        /*!
         *
         * \brief Metoda aktualizujaca wartosc calkowitego kata obrotu
         * 
         * \param angle - wartosc kata o jaki chcemy obrocic prostopadloscian
         * 
         */

        void Rotate(double angle); 

        /*!
         *
         * \brief Metoda zwracajaca wartosc kata calkowitego obrotu
         * 
         * \return Kat calkowitego obrotu jako zmienna typu double
         */

        double GetAngle();

        /*!
         *
         * \brief Metoda zwracajaca tablice localCorners
         * 
         * \return Wskaznik na pierwszy element tablicy localCorners
         */

        Vector3D* GetLocalCorners();

};
