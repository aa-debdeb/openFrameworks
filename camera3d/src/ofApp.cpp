#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    videoGrabber.setup(80, 60);
    xInterval = float(ofGetWidth()) / videoGrabber.getWidth();
    yInterval = float(ofGetHeight()) / videoGrabber.getHeight();
    
    ofEnableDepthTest();
    ofEnableSmoothing();
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    mesh.enableColors();
    mesh.enableIndices();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();
    
    if(videoGrabber.isFrameNew()){
        unsigned char * pixels = videoGrabber.getPixels();
        
        mesh.clearVertices();
        mesh.clearColors();
        mesh.clearIndices();
        for(int h = 0; h < videoGrabber.getHeight(); h++){
            for(int w = 0; w < videoGrabber.getWidth(); w++){
                float r = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3] / 256.0;
                float g = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 1] / 256.0;
                float b = (float)pixels[int(h * videoGrabber.getWidth() + w) * 3 + 2] / 256.0;
                ofFloatColor color = ofFloatColor(r, g, b);
                float z = ofMap(color.getBrightness(), 0, 1, 300, -300);
                mesh.addColor(color);
                mesh.addVertex(ofVec3f(w * xInterval, h * yInterval, z));
            }
        }
        for(int h = 0; h < videoGrabber.getHeight() - 1; h++){
            for(int w = 0; w < videoGrabber.getWidth() - 1; w++){
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex(h * videoGrabber.getWidth() + w + 1);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
                mesh.addIndex(h * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w);
                mesh.addIndex((h + 1) * videoGrabber.getWidth() + w + 1);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    mesh.draw();
//    mesh.drawWireframe();
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
