# ofxLivePP

Live++ for openFrameworks

## Usage

- put LivePP folder as libs/LivePP/LivePP
- main.cpp:

```cpp
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
```

## Visual Studio Project Settings

(Planning to create easy utility script for this.)

https://liveplusplus.tech/docs/documentation.html#linker_settings

> MSVC/Visual Studio
> These linker settings must be enabled in the configuration properties of each project that uses Live++:
> 
> Linker -> General -> Create Hotpatchable Image must be set to Enabled (/FUNCTIONPADMIN)
> 
> Linker -> Optimization -> References must be set to No (/OPT:NOREF)
> 
> Linker -> Optimization -> Enable COMDAT Folding must be set to No (/OPT:NOICF)
> 

> Linker -> Debugging -> Generate Debug Info must be set to Generate Debug Information optimized for sharing and publishing (/DEBUG:FULL)

## License

0BSD or WTFPL
