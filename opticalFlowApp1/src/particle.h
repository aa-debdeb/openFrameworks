//
//  particle.h
//  opticalFlowApp1
//
//  Created by aa_debdeb on 2015/11/15.
//
//

#ifndef __opticalFlowApp1__particle__
#define __opticalFlowApp1__particle__

#include <stdio.h>
#include "ofMain.h"

class Particle {

public:
    
    Particle();
    void update();
    void draw();
    void borders();
    void serForce(ofVec2f _force);
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f force;
    float radious;
    float maxSpeed;
    
};

#endif /* defined(__opticalFlowApp1__particle__) */
