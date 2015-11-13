#pragma once

#include "ofMain.h"
#include "boid.h"
#include "flock.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    private:
        Flock flock;
    
        ofxPanel gui;
        ofxFloatSlider separateForce;
        ofxFloatSlider alignForce;
        ofxFloatSlider cohesionForce;
        ofxFloatSlider separateRadious;
        ofxFloatSlider alignRadious;
        ofxFloatSlider cohesionRadious;
        ofxFloatSlider maxSpeed;
    
};
