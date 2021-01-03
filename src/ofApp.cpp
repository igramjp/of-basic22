#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /*
    ofSetLogLevel(OF_LOG_VERBOSE);
    grabber.setVerbose(true);
    grabber.listDevices();
    */
    grabber.setDeviceID(1);
    grabber.initGrabber(320, 240);
    
    ofBackground(0, 0, 0);
    colorImage.allocate(320, 240);
    grayImage.allocate(320, 240);
    grayBackground.allocate(320, 240);
    grayDiff.allocate(320, 240);
    bLearnBackground = true;
    threshold = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    bool bNewFrame = false;
    
    grabber.update();
    bNewFrame = grabber.isFrameNew();
    
    if (bNewFrame) {
        colorImage.setFromPixels(grabber.getPixels());
        grayImage = colorImage;
        
        if (bLearnBackground == true) {
            grayBackground = grayImage;
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBackground, grayImage);
        grayDiff.threshold(threshold);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    colorImage.draw(10, 10);
    grayImage.draw(340, 10);
    grayBackground.draw(10, 260);
    grayDiff.draw(340, 260);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bLearnBackground = true;
            break;
        case '+':
            threshold++;
            if (threshold > 255) {
                threshold = 255;
            }
            break;
        case '-':
            threshold--;
            if (threshold < 0) {
                threshold = 0;
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
