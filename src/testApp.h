#pragma once

#include "ofMain.h"
#include "ofxCvHaarFinder.h"

#define _WIDTH 320
#define _HEIGHT 240
#define _MAXFRAME 5

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
    
    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage processImg;
    ofxCvHaarFinder finder;
    ofVideoGrabber vidGrabber;
    
    double findTime;
    int frameNumber;
};
