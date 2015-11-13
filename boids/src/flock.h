//
//  flock.h
//  boids
//
//  Created by aa_debdeb on 2015/11/13.
//
//

#ifndef __boids__flock__
#define __boids__flock__

#include <stdio.h>
#include "ofMain.h"
#include "boid.h"

class Flock{
public:
    Flock();
    void run(float separateForce, float alignForce, float cohesionForce,
             float separateRadious, float alignRadious, float cohesionRadious, float maxSpeed);
    void render();
    void addBoid(Boid b);
private:
    vector<Boid> boids;
};


#endif /* defined(__boids__flock__) */
