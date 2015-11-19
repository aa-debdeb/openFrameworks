#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(mode_id.set("mode", 0, 0, 2));
    gui.add(startColor.set("start color", ofColor(54, 230, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(endColor.set("end color", ofColor(255, 140, 0), ofColor(0, 0), ofColor(255, 255)));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofGradientMode mode;
    switch(mode_id){
        case 0:
            mode = OF_GRADIENT_CIRCULAR;
            break;
        case 1:
            mode = OF_GRADIENT_LINEAR;
            break;
        case 2:
            mode = OF_GRADIENT_BAR;
            break;
    }
    ofBackgroundGradient(startColor, endColor, mode);
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
