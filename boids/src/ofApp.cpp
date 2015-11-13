#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(50);
    flock = Flock();
    for(int i = 0; i < 300; i++){
        flock.addBoid(Boid(ofGetWidth() / 2.0, ofGetHeight() / 2.0));
    }
    
    gui.setup();
    gui.add(separateForce.setup("separation force", 1.5, 0, 3));
    gui.add(alignForce.setup("alignment force", 1, 0, 3));
    gui.add(cohesionForce.setup("cohesion force", 1, 0, 3));
    gui.add(separateRadious.setup("separation radious", 25, 0, 300));
    gui.add(alignRadious.setup("alignment radious", 50, 0, 300));
    gui.add(cohesionRadious.setup("cohesion radious", 50, 0, 300));
    gui.add(maxSpeed.setup("max speed", 2, 0, 4));
}


//--------------------------------------------------------------
void ofApp::update(){
    flock.run(separateForce, alignForce, cohesionForce,
              separateRadious, alignRadious, cohesionRadious, maxSpeed);
}

//--------------------------------------------------------------
void ofApp::draw(){
    flock.render();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case 'f':
            ofToggleFullscreen();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
