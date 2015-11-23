#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableDepthTest();
    ofEnableSmoothing();
    gui.setup();
    gui.add(is_box.set("box", false));
    gui.add(specular_light.set("specular", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(diffuse_light.set("diffuse", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(ambient_light.set("ambient", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(specular_material.set("specular", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(diffuse_material.set("diffuse", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(ambient_material.set("ambient", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(emmisive_material.set("emmisive", ofFloatColor(0.5, 0.5, 0.5), ofFloatColor(0, 0, 0), ofFloatColor(1, 1, 1)));
    gui.add(shiness_material.set("shiness", 0, -128, 128));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    material.setShininess(shiness_material);
    material.setEmissiveColor(emmisive_material);
    material.setAmbientColor(ambient_material);
    material.setDiffuseColor(diffuse_material);
    material.setSpecularColor(specular_material);

    cam.begin();
    
    light.enable();
    light.setSpotlight();
    light.setPosition(-100, 100, 100);
    light.setAmbientColor(ambient_light);
    light.setDiffuseColor(diffuse_light);
    light.setSpecularColor(specular_light);
    
    if(is_box){
        ofBoxPrimitive box;
        box.set(150);
        box.setPosition(0, 0, 0);
        material.begin();
        box.draw();
        material.end();
    } else {
        ofSpherePrimitive sphere;
        sphere.set(100, 90);
        sphere.setPosition(0, 0, 0);
        material.begin();
        sphere.draw();
        material.end();
    }
    light.disable();
    
    cam.end();
 
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
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
