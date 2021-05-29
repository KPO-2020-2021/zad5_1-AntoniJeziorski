#include "drone.hh"

class Scene {

    Drone arrayOfDrones[2];

    PzG::LaczeDoGNUPlota Link;

    public:

        Scene(Drone drone1, Drone drone2);

        Drone& UseDrone(int droneNumber);

        Drone GetDrone(int droneNumber) const;

};
