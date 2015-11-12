#include "ofApp.h"

#define X_NUM 300
#define Y_NUM 300
#define CELL_SIZE 2

int states[X_NUM][Y_NUM];

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
//    ofSetFrameRate(60);
    initializeStates();
}

void ofApp::initializeStates(){
    for(int x = 0; x < X_NUM; x++){
        for(int y = 0; y < Y_NUM; y++){
            states[x][y] = ofRandom(1) < 0.5 ? 1 : 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    int nextStates[X_NUM][Y_NUM];
    for(int x = 0; x < X_NUM; x++){
        for(int y = 0; y < Y_NUM; y++){
            int up = y != 0 ? y - 1: Y_NUM - 1;
            int down = y != Y_NUM - 1 ? y + 1: 0;
            int left = x != 0 ? x - 1: X_NUM - 1;
            int right = x != X_NUM - 1 ? x + 1: 0;
            int sum = states[left][up] + states[x][up] + states[right][up]
                    + states[left][y] + states[right][y]
                    + states[left][down] + states[x][down] + states[right][down];
            if((states[x][y] == 1 && (sum == 2 || sum == 3)) || (states[x][y] == 0 && sum == 3)){
                nextStates[x][y] = 1;
            } else {
                nextStates[x][y] = 0;
            }
        }
    }
    for(int x = 0; x < X_NUM; x++){
        for(int y = 0; y < Y_NUM; y++){
            states[x][y] = nextStates[x][y];
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for(int x = 0; x < X_NUM; x++){
        for(int y = 0; y < Y_NUM; y++){
            if(states[x][y] == 1){
                ofSetColor(0, 255, 0);
            } else {
                ofSetColor(0);
            }
            ofRect(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
        }
    }
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
    initializeStates();
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
