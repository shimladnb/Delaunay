#pragma once

#include "ofMain.h"
#include "ofxDelaunay.h"
#include "ofxOpenCv.h"
#include "ofxGui.h"
#include "ofxOsc.h"
#include "ofxOscParameterSync.h"


class testApp : public ofBaseApp , public ofxGuiGroup{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofParameter<int> size;
    ofParameter<int> reset;
    ofParameter<int> number;
    ofParameter<bool> check;
    ofParameterGroup parameters;
    ofParameter<ofColor> color;

    ofxPanel gui;    ofxDelaunay triangulation;
    ofVideoGrabber 		vidGrabber;
    ofxPanel panel;
    

    ofxOscSender send;
    ofxOscParameterSync sync;
    
    bool bLearnBackground;

    ofxCvColorImage colorImg;
    ofxCvGrayscaleImage grayImage, grayBg, grayDiff;
    ofxCvContourFinder contourFinder;

    

    int 				camWidth;
    int 				camHeight;
    int somepoint;
    int Npoints;
    bool DrawGUI;
    
};
