#include "ofMain.h"
#include "ofApp.h"

#include "ofxLivePP.h"

//========================================================================
int main( ){
	ofLogToConsole();

	if (!ofxLivePP::setup()) {
		return 1;
	}

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

	// destroy the Live++ agent
	ofxLivePP::destroy();
}
