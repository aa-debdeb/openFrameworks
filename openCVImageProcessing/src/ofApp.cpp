#include "ofApp.h"

#define MAX_STATE 11

ofVideoGrabber videoGrabber;
ofxCvColorImage originalImage;
ofxCvGrayscaleImage grayImage;
ofxCvGrayscaleImage binaryImage;
ofxCvColorImage blurImage;
ofxCvGrayscaleImage contrastImage;
ofxCvGrayscaleImage cannyImage;
ofxCvColorImage invertImage;
ofxCvColorImage dilateImage;
ofxCvColorImage erodeImage;
ofxCvContourFinder contourFinder;
ofxCvGrayscaleImage absDiffImage;

int currentState = 0;
std::string stateNames[] = {"1. original", "2. gray", "3. binary", "4. contour", "5: blur",
                            "6: contrast", "7. canny", "8. invert", "9. dilate", "10. erode",
                            "11: absDiff"};
int binaryTheshold = 80;
int blurValue = 9;
ofxCvGrayscaleImage pGrayImage;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(200);
    videoGrabber.initGrabber(ofGetWidth(), ofGetHeight());
    originalImage.allocate(ofGetWidth(), ofGetHeight());
    grayImage.allocate(ofGetWidth(), ofGetHeight());
    binaryImage.allocate(ofGetWidth(), ofGetHeight());
    blurImage.allocate(ofGetWidth(), ofGetHeight());
    contrastImage.allocate(ofGetWidth(), ofGetHeight());
    cannyImage.allocate(ofGetWidth(), ofGetHeight());
    invertImage.allocate(ofGetWidth(), ofGetHeight());
    dilateImage.allocate(ofGetWidth(), ofGetHeight());
    erodeImage.allocate(ofGetWidth(), ofGetHeight());
    absDiffImage.allocate(ofGetWidth(), ofGetHeight());
    
    currentState = 0;
    pGrayImage.allocate(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetColor(255);
    videoGrabber.update();
    if(videoGrabber.isFrameNew()){
        originalImage.setFromPixels(videoGrabber.getPixels(), ofGetWidth(), ofGetHeight());
        grayImage = originalImage;
        // binary image
        binaryImage = originalImage;
        binaryImage.threshold(binaryTheshold);
        switch(currentState){
            case 3:
                ofSetColor(255, 0, 0);
                contourFinder.findContours(binaryImage, 20, 500, 100, true);
                break;
            case 4: // blur image
                blurImage = originalImage;
                blurImage.blur(blurValue);
                break;
            case 5: // contrast image
                contrastImage = originalImage;
                contrastImage.contrastStretch();
                break;
            case 6: // canny image
                cvCanny(grayImage.getCvImage(), cannyImage.getCvImage(), 60, 150);
                cannyImage.flagImageChanged();
                break;
            case 7: // invert image
                invertImage = originalImage;
                invertImage.invert();
                break;
            case 8: // dilate image
                dilateImage = originalImage;
                dilateImage.dilate();
                break;
            case 9: // erode image
                erodeImage = originalImage;
                erodeImage.erode();
                break;
            case 10:
                absDiffImage.absDiff(pGrayImage, grayImage);
                break;
        }
    }
    pGrayImage = grayImage;
}

//--------------------------------------------------------------
void ofApp::draw(){
    switch (currentState) {
        case 0:
            originalImage.draw(0, 0);
            break;
        case 1:
            grayImage.draw(0, 0);
            break;
        case 2:
            binaryImage.draw(0, 0);
            break;
        case 3:
            ofSetColor(30);
            ofRect(0, 0, ofGetWidth(), ofGetHeight());
            contourFinder.draw(0, 0);
            break;
        case 4:
            blurImage.draw(0, 0);
            break;
        case 5:
            contrastImage.draw(0, 0);
            break;
        case 6:
            cannyImage.draw(0, 0);
            break;
        case 7:
            invertImage.draw(0, 0);
            break;
        case 8:
            dilateImage.draw(0, 0);
            break;
        case 9:
            erodeImage.draw(0, 0);
            break;
        case 10:
            absDiffImage.draw(0, 0);
            break;
    }

    int previousState = currentState > 0 ? currentState - 1 : MAX_STATE - 1;
    int nextState = currentState < MAX_STATE - 1 ? currentState + 1 : 0;
    std::string navigator = stateNames[previousState] +
                                  " < " + stateNames[currentState] +
                                  " > " + stateNames[nextState];
    
    ofSetColor(128);
    ofDrawBitmapString(navigator, 50, 50);
    switch(currentState){
        case 2:
        case 3:
            ofDrawBitmapString("threshold(-/+): " + ofToString(binaryTheshold), 50, 70);
            break;
        case 4:
            ofDrawBitmapString("blur value(-/+): " + ofToString(blurValue), 50, 70);
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case OF_KEY_LEFT:
            currentState = currentState > 0 ? currentState - 1 : MAX_STATE - 1;
            break;
        case OF_KEY_RIGHT:
            currentState = currentState < MAX_STATE - 1 ? currentState + 1 : 0;
            break;
        case '+':
            switch(currentState){
                case 2:
                case 3:
                    binaryTheshold = binaryTheshold < 255 ? binaryTheshold + 1 : 255;
                    break;
                case 4:
                    blurValue = blurValue < 99 ? blurValue + 2: 99;
                    break;
            }
            break;
        case '-':
            switch(currentState){
                case 2:
                case 3:
                    binaryTheshold = binaryTheshold > 0 ? binaryTheshold - 1 : 0;
                    break;
                case 4:
                    blurValue = blurValue > 1 ? blurValue - 2: 1;
            }
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
