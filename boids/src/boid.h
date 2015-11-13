//
//  boid.h
//  boids
//
//  Created by aa_debdeb on 2015/11/12.
//
//

#ifndef __boids__boid__
#define __boids__boid__

#include <stdio.h>
#include "ofMain.h"

class Boid {
public:
    Boid(float x, float y);
    void run(vector<Boid> boids, float separateForce, float alignForce, float cohesionForce,
                                 float separateRadious, float alignRadious, float cohesionRadious, float maxSpeed);
    void render();
    
private:
    void applyForce(ofVec2f force);
    void flock(vector<Boid> boids);
    void borders();
    void update();
    ofVec2f seek(ofVec2f target);
    ofVec2f separate(vector<Boid> boids);
    ofVec2f align(vector<Boid> boids);
    ofVec2f cohesion(vector<Boid> boids);
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    
    float separateForce;
    float alignForce;
    float cohesionForce;
    float separateRadious;
    float alignRadious;
    float cohesionRadious;
};

#endif /* defined(__boids__boid__) */
