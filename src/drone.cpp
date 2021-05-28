#include "drone.hh"

Drone::Drone(Vector3D scale, Vector3D loc) {
    
    location = loc;
    body.Scale(scale);
    body.ToGlobal(location);
}

bool Drone::SaveBody( const char *sFileName) {

    Vector3D X, Y, tmp1 = body(0), tmp2 = body(7), tmp3 = body(2), tmp4 = body(5);

    std::ofstream  FileStream;

    FileStream.open(sFileName);
    if (!FileStream.is_open())  {
        throw std::runtime_error("Operacja otwarcia pliku do zapisu nie powiodla sie");
        return false;
    }

    X = (tmp1 + tmp2) / 2;
    Y = (tmp3 + tmp4) / 2;

    FileStream << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(1) << std::endl << body(3) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(0) << std::endl << body(2) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(6) << std::endl << body(4) << std::endl << Y << std::endl << '#' << std::endl << std::endl;
    FileStream << X << std::endl << body(7) << std::endl << body(5) << std::endl << Y << std::endl << '#' << std::endl;

    FileStream.close();
    return !FileStream.fail();
}

void Drone::VerticalFlight(Vector3D translation, PzG::LaczeDoGNUPlota& Link) {

    for (int i = 0; i < FLOPS; i++)
    {
        location = location + translation/FLOPS;
        body.ToGlobal(location);
        SaveBody("../datasets/body.dat");
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);
    }

}

void Drone::HorizontalFlight(double distance, PzG::LaczeDoGNUPlota& Link) {

    Vector3D BodyCenter, tmp, end;

    end[0] = distance;

    BodyCenter = body(0) + body(5);
    BodyCenter = BodyCenter/2;

    end = RotationMatrix_Z(rotationAngle) * end + BodyCenter;

    tmp = end - BodyCenter;
    tmp[2] = 0;

    for (int i = 0; i < 200; ++i)
    {
        body.Rotate(rotationAngle/200);
        body.ToGlobal(location);
        SaveBody("../datasets/body.dat");
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);
    }

    for (int i = 0; i < FLOPS; i++)
    {
        location = location + tmp/FLOPS;
        body.ToGlobal(location);
        SaveBody("../datasets/body.dat");
        Link.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
        usleep(10000);
    }

} 

void Drone::PlanPath(double angle, double distance) {

    rotationAngle = angle;

    std::ofstream FileStream;    
    FileStream.open("../datasets/path.dat");

    Vector3D tmp, BodyCenter;
    tmp[0] = distance;

    BodyCenter = body(0) + body(5);
    BodyCenter = BodyCenter/2;

    FileStream << BodyCenter << std::endl;

    BodyCenter[2] += 80;

    FileStream << BodyCenter << std::endl;

    tmp = RotationMatrix_Z(rotationAngle) * tmp + BodyCenter;

    FileStream << tmp << std::endl;

    tmp[2] = tmp[2] - 80;
    
    FileStream << tmp << std::endl;

    FileStream.close();

}