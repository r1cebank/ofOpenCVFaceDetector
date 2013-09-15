#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    frameNumber = 0;
    //ofSetFrameRate(30);
	vidGrabber.initGrabber(_WIDTH, _HEIGHT, true);
	finder.setup("haarcascade_frontalface_default.xml");
    processImg.setUseTexture(false);
    processImg.allocate(_WIDTH, _HEIGHT);
    colorImg.allocate(_WIDTH, _HEIGHT);
	grayImg.allocate(_WIDTH, _HEIGHT);
}

//--------------------------------------------------------------
void testApp::update(){
    double begin, after;
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
        frameNumber++;
        colorImg.setFromPixels(vidGrabber.getPixels(), _WIDTH, _HEIGHT);
        grayImg = colorImg;
        processImg = colorImg;
        if(frameNumber % _MAXFRAME == 0) {
            frameNumber = 0;
            begin =  ofGetElapsedTimeMillis();
            finder.findHaarObjects(processImg);
            after =  ofGetElapsedTimeMillis();
            findTime = after - begin;
        }
    }
    //ofLog(OF_LOG_NOTICE) << "Elapsed time (ms): " << after-begin << endl;
}

//--------------------------------------------------------------
void testApp::draw(){
	grayImg.draw(200, 0);
    colorImg.draw(520, 0);
    ofSetColor(ofColor::white);
    ofFill();
    ofRect(0, 0, 200, 240);
    ofSetColor(ofColor::seaGreen);
    ofDrawBitmapString("framerate: " + ofToString((int)ofGetFrameRate())+"fps", 10, 15);
    ofDrawBitmapString("findtime: " + ofToString(findTime) + "ms", 10, 30);
    ofDrawBitmapString("faces: " + ofToString(finder.blobs.size()), 10, 45);
    ofSetColor(ofColor::white);
    ofNoFill();
	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x + 520, cur.y, cur.width, cur.height);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
