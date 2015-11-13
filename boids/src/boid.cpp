//
//  boid.cpp
//  boids
//
//  Created by aa_debdeb on 2015/11/12.
//
//

#include "boid.h"

Boid::Boid(float x, float y){
    acceleration = ofVec2f(0, 0);
    float angle = ofRandom(TWO_PI);
    velocity = ofVec2f(cos(angle), sin(angle));
    location = ofVec2f(x, y);
    r = 3.0;
    maxForce = 0.03;
}

void Boid::run(vector<Boid> boids, float separateForce, float alignForce, float cohesionForce,
                                   float separateRadious, float alignRadious, float cohesionRadious, float maxSpeed){
    this->separateForce = separateForce;
    this->alignForce = alignForce;
    this->cohesionForce = cohesionForce;
    this->separateRadious = separateRadious;
    this->alignRadious = alignRadious;
    this->cohesionRadious = cohesionRadious;
    this->maxSpeed = maxSpeed;
    flock(boids);
    update();
    borders();
}

void Boid::applyForce(ofVec2f force){
    acceleration += force;
}

void Boid::flock(vector<Boid> boids){
    ofVec2f sep = separate(boids);
    ofVec2f ali = align(boids);
    ofVec2f coh = cohesion(boids);
    sep = sep * separateForce;
    ali = ali * alignForce;
    coh = coh * cohesionForce;
    applyForce(sep);
    applyForce(ali);
    applyForce(coh);
}

void Boid::update(){
    velocity += acceleration;
    velocity.limit(maxSpeed);
    location += velocity;
    acceleration *= 0;
}

ofVec2f Boid::seek(ofVec2f target){
    ofVec2f desired = target - location;
    desired.normalize();
    desired *= maxSpeed;
    ofVec2f steer = desired - velocity;
    steer.limit(maxForce);
    return steer;
}

void Boid::render(){
    ofVec2f origin = ofVec2f(1.0, 0.0);
    float theta = origin.angle(velocity) + 90;
    ofSetColor(200, 100);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotate(theta);
    ofBeginShape();
    ofVertex(0, -r * 2);
    ofVertex(-r, r * 2);
    ofVertex(r, r * 2);
    ofEndShape();
    ofPopMatrix();
}

void Boid::borders(){
    if(location.x < -r) location.x = ofGetWidth() + r;
    if(location.y < -r) location.y = ofGetHeight() + r;
    if(location.x > ofGetWidth() + r) location.x = -r;
    if(location.y > ofGetHeight() + r) location.y = -r;
}

ofVec2f Boid::separate(vector<Boid> boids){
    float desiredSeparation = separateRadious;
    ofVec2f steer = ofVec2f(0, 0);
    int count = 0;
    for(int i = 0; i < boids.size(); i++){
        Boid other = boids[i];
        float d = location.distance(other.location);
        if((d > 0) && (d < desiredSeparation)){
            ofVec2f diff = location - other.location;
            diff.normalize();
            diff /= d;
            steer += diff;
            count++;
        }
    }
    if(count > 0){
        steer /= (float(count));
    }
    
    if(steer.length() > 0){
        steer.normalize();
        steer *= maxSpeed;
        steer -= velocity;
        steer.limit(maxForce);
    }
    return steer;
    
}

ofVec2f Boid::align(vector<Boid> boids){
    float neighbordist = alignRadious;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    for(int i = 0; i < boids.size(); i++){
        Boid other = boids[i];
        float d = location.distance(other.location);
        if((d > 0) && (d < neighbordist)){
            sum += other.velocity;
            count++;
        }
    }
    if(count > 0){
        sum /= (float(count));
        sum.normalize();
        sum *= maxSpeed;
        ofVec2f steer = sum - velocity;
        steer.limit(maxForce);
        return steer;
    } else {
        return ofVec2f(0, 0);
    }
}

ofVec2f Boid::cohesion(vector<Boid> boids){
    float neighbordist = cohesionRadious;
    ofVec2f sum = ofVec2f(0, 0);
    int count = 0;
    for(int i = 0; i < boids.size(); i++){
        Boid other = boids[i];
        float d = location.distance(other.location);
        if((d > 0) && (d < neighbordist)){
            sum += other.location;
            count++;
        }
    }
    if(count > 0){
        sum /= (float(count));
        return seek(sum);
    } else {
        return ofVec2f(0, 0);
    }
}


