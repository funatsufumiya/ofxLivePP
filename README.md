# ofxLivePP

[Live++](https://liveplusplus.tech) for openFrameworks

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

	if (!ofxLivePP::setup()) { // if you use ofxLivePP as local addon, please call ofxLivePP::setup(true) instead.
		return 1;
	}


	// Start of as your like -----------------------------------

	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

	// End of as your like -----------------------------------


	// destroy the Live++ agent
	ofxLivePP::destroy();
}
```

## Visual Studio Project Settings

### Recommended way

Add [`settings.props`](./settings.props) file from addon to your project (via the "Property Manager" window in Visual Studio)

### Manually

https://liveplusplus.tech/docs/documentation.html#compiler_settings_MSVC

> MSVC/Visual Studio
> These compiler settings must be enabled in the configuration properties of each project which uses Live++:
> 
> C/C++ -> General -> Debug Information Format must be set to either C7 compatible (/Z7) or Program Database (/Zi)
> 
> C/C++ -> Code Generation -> Enable Minimal Rebuild must be set to No (/Gm-)
> 
> x86/Win32 projects additionally require the following compiler settings:
> 
> C/C++ -> Code Generation -> Create Hotpatchable Image must be set to Yes (/hotpatch)

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



