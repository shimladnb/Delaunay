#include "ofApp.h"
#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
int main(){
    
    
    ofAppGlutWindow window;// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
    ofSetupOpenGL(1680, 1050, OF_WINDOW);

    ofRunApp(new testApp()); // start the app
}
