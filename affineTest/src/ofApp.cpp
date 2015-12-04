#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(64);

    srcImg.load("lena.png");
    srcMat =toCv(srcImg);
    
    srcPt[0] = Point2f(100, 100);
    srcPt[1] = Point2f(100, 400);
    srcPt[2] = Point2f(400, 100);
    dstPt[0] = Point2f(200, 200);
    dstPt[1] = Point2f(200, 500);
    dstPt[2] = Point2f(500, 200);
    
    isHolding = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    Mat affineMat = getAffineTransform(srcPt, dstPt);
    warpAffine(srcMat, dstMat, affineMat, srcMat.size() * 2);
    
    toOf(dstMat, dstImg);
    dstImg.update();
    
    ofSetColor(255);
    srcImg.draw(0, 0);
    dstImg.draw(srcImg.getWidth(), 0);

    
    ofSetColor(128);
    ofDrawLine(srcPt[0].x, srcPt[0].y, dstPt[0].x, dstPt[0].y);
    ofDrawLine(srcPt[1].x, srcPt[1].y, dstPt[1].x, dstPt[1].y);
    ofDrawLine(srcPt[2].x, srcPt[2].y, dstPt[2].x, dstPt[2].y);

    
    ofSetColor(255, 0, 0);
    ofNoFill();
    ofDrawTriangle(srcPt[0].x, srcPt[0].y, srcPt[1].x, srcPt[1].y, srcPt[2].x, srcPt[2].y);
    for(int i = 0; i < 3; i++){
        ofDrawEllipse(srcPt[i].x, srcPt[i].y, 20, 20);
    }
    ofSetColor(0, 0, 255);
    ofNoFill();
    ofDrawTriangle(dstPt[0].x, dstPt[0].y, dstPt[1].x, dstPt[1].y, dstPt[2].x, dstPt[2].y);
    for(int i = 0; i < 3; i++){
        ofDrawEllipse(dstPt[i].x, dstPt[i].y, 20, 20);
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
    if(isHolding){
        heldPt->x = mouseX;
        heldPt->y = mouseY;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    for(int i = 0; i < 3; i++){
        if(ofDist(mouseX, mouseY, srcPt[i].x, srcPt[i].y) < 20){
            isHolding = true;
            heldPt = &srcPt[i];
            return;
        }
    }
    for(int i = 0; i < 3; i++){
        if(ofDist(mouseX, mouseY, dstPt[i].x, dstPt[i].y) < 20){
            isHolding = true;
            heldPt = &dstPt[i];
            return;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    isHolding = false;
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
