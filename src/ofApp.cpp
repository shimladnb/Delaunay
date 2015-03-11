#include "ofApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing();

    ofBackground(0);

    
    camWidth 		= 1680;
    camHeight 		= 1050;

    ofSetWindowShape(camWidth, camHeight);
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(camWidth,camHeight);
    
    colorImg.allocate(camWidth,camHeight);
    grayImage.allocate(camWidth,camHeight);
    grayBg.allocate(camWidth,camHeight);
    grayDiff.allocate(camWidth,camHeight);

    //gui!!
    parameters.setName("parameters");
    parameters.add(size.set("BLOBS",3,1,10));
    parameters.add(reset.set("ResetShit",100,1,2000));
    parameters.add(number.set("50SHADES",10,1,300));
 	parameters.add(check.set("Draw blobs",false));


    gui.setup(parameters);
    // by now needs to pass the gui parameter groups since the panel internally creates it's own group
    

    sync.setup((ofParameterGroup&)gui.getParameter(),6667,"localhost",6666);
    send.setup("localhost",6667);
    ofSetVerticalSync(true);
    
    

    
    
    
}

//-------------------------------- ------------------------------
void testApp::update(){
    vidGrabber.update();
    if (vidGrabber.isFrameNew()){
        colorImg.setFromPixels(vidGrabber.getPixelsRef());
        grayImage = colorImg; // convert our color image to a grayscale image
        if (bLearnBackground == true) {
            grayBg = grayImage; // update the background image
            bLearnBackground = true;
        }
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(number);
        contourFinder.findContours(grayDiff, 5, (camWidth*camHeight)/4, size, true, true);
    }
    
    sync.update();
    send.sendParameter((ofParameterGroup&)gui.getParameter());
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(ofColor_<unsigned char>::black); //Bground color
    ofSetColor(ofColor_<unsigned char>::white); //Fground color

    
    triangulation.draw();
    if (DrawGUI  ==  false)
    {
        grayDiff.draw(camWidth-320, 0, 320, 240);
        ofRect(camWidth-321, 0, 321, 241);
    }
    if (DrawGUI == false)
    {
        gui.draw();
    }
              
    ofNoFill();
    

   // ofDrawBitmapString("'r' to reset", ofPoint(10,20));
    if(check == true)
    {
        contourFinder.draw(0, 0, camWidth, camHeight);
    }
 //   ofSetHexColor(0xffffff);
 //   colorImg.draw(0, 240, 320, 240);


//    ofColor c(255, 255, 255);
 //   for(int i = 0; i < contourFinder.nBlobs; i++) {
 //       ofRectangle r = contourFinder.blobs.at(i).boundingRect;
 //       r.x += 320; r.y += 240;
 //       c.setHsb(i * 64, 255, 255);
 //       ofSetColor(c);
 //       ofRect(r);
 //   }
    for(int i = 0; i < contourFinder.nBlobs; i++) {
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
        
        ofPoint  s  =  contourFinder.blobs.at(i).centroid;
        s.x ; s.y ;
        
        triangulation.addPoint(ofPoint(s.x ,s.y ));
        triangulation.triangulate();

//reset triangles
        Npoints = triangulation.getNumTriangles();
        if (Npoints > reset){
            triangulation.reset();
        }
        
        
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    if(key == 'r'){
        
        DrawGUI = true;
    }
    else {
        DrawGUI = false;
    }
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
//        triangulation.addPoint(ofPoint(x,y));
//        triangulation.triangulate();
    
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