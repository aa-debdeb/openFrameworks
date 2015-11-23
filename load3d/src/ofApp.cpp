#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(50, 50, 50, 0);
    ofEnableDepthTest();
    ofEnableSmoothing();
    model.loadModel("tsubomi.obj");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    light.enable();
    ofEnableSeparateSpecularLight();
    ofEnableLighting();
    
    cam.begin();
    ofSetColor(255, 255, 255, 255);
    
    model.setScale(0.75, 0.75, 0.75);
    model.setPosition(0, 0, 0);
    model.drawFaces();
    cam.end();
    
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
