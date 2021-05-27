#include "drone.hh"

bool Drone::ZapisWspolrzednychDoPliku( const char *sNazwaPliku) {

    Vector3D X, Y, tmp1 = body(0), tmp2 = body(7), tmp3 = body(2), tmp4 = body(5);

    std::ofstream  StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if (!StrmPlikowy.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return false;
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    StrmPlikowy << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << body(1) << std::endl << body(3) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << body(0) << std::endl << body(2) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << body(6) << std::endl << body(4) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    StrmPlikowy << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl;

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}