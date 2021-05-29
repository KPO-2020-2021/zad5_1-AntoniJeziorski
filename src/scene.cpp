#include "scene.hh"

Scene::Scene(Drone drone1, Drone drone2) {

    arrayOfDrones[0] = drone1;
    arrayOfDrones[1] = drone2;

}

Drone& Scene::UseDrone(int droneNumber) {

    return arrayOfDrones[droneNumber];

}

Drone Scene::GetDrone(int droneNumber) const {
    
    return arrayOfDrones[droneNumber];

}
