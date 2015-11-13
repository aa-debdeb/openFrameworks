//
//  flock.cpp
//  boids
//
//  Created by aa_debdeb on 2015/11/13.
//
//

#include "flock.h"

Flock::Flock(){
    boids = vector<Boid>();
}

void Flock::run(float separateForce, float alignForce, float cohesionForce,
                float separateRadious, float alignRadious, float cohesionRadious, float maxSpeed){
    for(int i = 0; i < boids.size(); i++){
        boids[i].run(boids, separateForce, alignForce, cohesionForce, separateRadious, alignRadious, cohesionRadious, maxSpeed);
    }
}

void Flock::render(){
    for(int i = 0; i < boids.size(); i++){
        boids[i].render();
    }
}

void Flock::addBoid(Boid b){
    boids.push_back(b);
}

