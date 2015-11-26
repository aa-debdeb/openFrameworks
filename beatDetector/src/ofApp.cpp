#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(30);
    ofEnableSmoothing();
    ofSetCircleResolution(64);
    
    ofSoundStreamSetup(0, 1, this, 44100, beat.getBufferSize(), 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    beat.update(ofGetElapsedTimeMillis());
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 139, 139);
    float kick = beat.kick();
    float kickRadious = ofMap(kick, 0, 1, 0, 100);
    ofDrawCircle(150, 200, kickRadious);
    ofDrawBitmapString("kick", 150 - 20, 50);
    float snare = beat.snare();
    float snareRadious = ofMap(snare, 0, 1, 0, 100);
    ofDrawCircle(400, 200, snareRadious);
    ofDrawBitmapString("snare", 400 - 20, 50);
    float hihat = beat.hihat();
    float hihatRadious = ofMap(hihat, 0, 1, 0, 100);
    ofDrawCircle(650, 200, hihatRadious);
    ofDrawBitmapString("hihat", 650 - 20, 50);

    ofDrawBitmapString("fft", 100, 330);
    for(int i = 0; i < 32; i++){
        float band = beat.getBand(i);
        float height = band * 100 < 300 ? band * 100: 300;
        ofDrawRectangle(80 + i * 20, 650 - height, 20, height);
    }
}

void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    beat.audioReceived(input, bufferSize, nChannels);
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
