//
//  particle.cpp
//  opticalFlowApp1
//
//  Created by aa_debdeb on 2015/11/15.
//
//

#include "particle.h"

Particle::Particle(){
    position = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    velocity = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    force = ofVec2f(0, 0);
    radious = 10;
    maxSpeed = 10;
    
}

void Particle::update(){
    velocity *= 0.99;
    velocity += force;
    velocity.limit(maxSpeed);
    position += velocity;
    borders();
    force *= 0;
}

void Particle::borders(){
    if(position.x < radious){
        position.x = radious;
        velocity.x *= -1;
    }
    if(position.x > ofGetWidth() - radious){
        position.x = ofGetWidth() - radious;
        velocity *= -1;
    }
    if(position.y < radious){
        position.y = radious;
        velocity.y *= -1;
    }
    if(position.y > ofGetHeight() - radious){
        position.y = ofGetHeight() - radious;
        velocity.y *= -1;
    }
}

void Particle::draw(){
    ofSetColor(255, 255, 0, 100);
    ofDrawCircle(position.x, position.y, radious);
}

void Particle::serForce(ofVec2f _force){
    force = _force;
}