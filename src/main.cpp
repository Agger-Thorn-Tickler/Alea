#include "ofMain.h"
#include "ofApp.h"
#include "PreferenceApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.width = 1000;
	settings.height = 1000;
	settings.setPosition(ofVec2f(500,0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);

	settings.width = 500;
	settings.height = 1000;
	settings.setPosition(ofVec2f(0,0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	shared_ptr<ofApp> mainApp(new ofApp);
	shared_ptr<PreferenceApp> guiApp(new PreferenceApp);
	mainApp->gui = guiApp;

	ofRunApp(guiWindow, guiApp);
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
