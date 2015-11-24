#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetVerticalSync(true);
    
    box2d.init();
    box2d.setGravity(0, 0);
    box2d.setFPS(30.0);
    box2d.registerGrabbing();
    
    int interval = 50;
    int x_num = ofGetWidth() / interval + 1;
    int y_num = ofGetHeight() / interval + 1;
    
    
    for(int y = 0; y < y_num; y++){
        for(int x = 0; x < x_num; x++){
            shared_ptr<ofxBox2dCircle> circle = shared_ptr<ofxBox2dCircle>(new ofxBox2dCircle);
            if(!(x == 0 || x == x_num - 1 || y == 0 || y == y_num - 1)){
                circle.get()->setPhysics(3.0, 0.53, 0.1);
            }
            circle.get()->setup(box2d.getWorld(), x * interval, y * interval, 10);
            circles.push_back(circle);
        }
    }
    
    for(int y = 0; y < y_num; y++){
        for(int x = 0; x < x_num; x++){
            if(x != x_num - 1){
                shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
                joint.get()->setup(box2d.getWorld(), circles[y * x_num + x].get()->body, circles[y * x_num + x + 1].get()->body);
                joint.get()->setLength(interval);
                joints.push_back(joint);
            }
            if(y != y_num - 1){
                shared_ptr<ofxBox2dJoint> joint = shared_ptr<ofxBox2dJoint>(new ofxBox2dJoint);
                joint.get()->setup(box2d.getWorld(), circles[y * x_num + x].get()->body, circles[(y + 1) * x_num + x].get()->body);
                joint.get()->setLength(interval);
                joints.push_back(joint);
            }
        }
    }
    
    camera.setup(320, 240);
    fbFlow.setPyramidScale(0.5);
    fbFlow.setNumLevels(4);
    fbFlow.setWindowSize(32);
    fbFlow.setNumIterations(2);
    fbFlow.setPolyN(7);
}

//--------------------------------------------------------------
void ofApp::update(){
    box2d.update();
    camera.update();
    fbFlow.calcOpticalFlow(camera);
    
    for(int i = 0; i < circles.size(); i++){
        ofVec2f position = circles[i].get()->getPosition();
        float camX = position.x * float(camera.getWidth()) / ofGetWidth();
        float camY = position.y * float(camera.getHeight()) / ofGetHeight();
        circles[i].get()->addForce(fbFlow.getFlowOffset(camX, camY), 10.0);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    camera.draw(0, 0, ofGetWidth(), ofGetHeight());

    ofSetColor(255, 128);
    for(int i = 0; i < circles.size(); i++){
        ofSetColor(255, 128);
        circles[i].get()->draw();
    }
    
    for(int i = 0; i < joints.size(); i++){
        joints[i].get()->draw();
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
