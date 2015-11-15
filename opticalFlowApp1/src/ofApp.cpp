#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    camera.setup(320, 240);
    
    gui.setup();
    gui.add(fbPyrScale.set("fbPyrScale", .5, 0, .99));
    gui.add(fbLevels.set("fbLevels", 4, 1, 8));
    gui.add(fbIterations.set("fbIterations", 2, 1, 8));
    gui.add(fbPolyN.set("fbPolyN", 7, 5, 10));
    gui.add(fbPolySigma.set("fbPolySigma", 1.5, 1.1, 2));
    gui.add(fbUseGaussian.set("fbUseGaussian", false));
    gui.add(fbWinSize.set("winSize", 32, 4, 64));
    
    particles = vector<Particle>();
    for(int i = 0; i < 1000; i++){
        particles.push_back(Particle());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    fbFlow.setPyramidScale(fbPyrScale);
    fbFlow.setNumLevels(fbLevels);
    fbFlow.setWindowSize(fbWinSize);
    fbFlow.setNumIterations(fbIterations);
    fbFlow.setPolyN(fbPolyN);
    fbFlow.setPolySigma(fbPolySigma);
    fbFlow.setUseGaussian(fbUseGaussian);
    fbFlow.calcOpticalFlow(camera);
    
    for(int i = 0; i < particles.size(); i++){
        float adjustedX = particles[i].position.x * float(camera.getWidth()) / ofGetWidth();
        float adjustedY = particles[i].position.y * float(camera.getHeight()) / ofGetHeight();
        ofVec2f force = fbFlow.getFlowOffset(adjustedX, adjustedY) * 3;
        particles[i].serForce(force);
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    camera.draw(0, 0, ofGetWidth(), ofGetHeight());
    fbFlow.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    for(int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
    
    gui.draw();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
