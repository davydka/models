#include "ofApp.h"

int _w = 320;
int _h = 320;
int counter = 0;
int frameCounter = 0;

bool bRecording;
string fileName;
string fileExt;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetWindowPosition(0, 0);
	ofSetWindowShape(_w, _h);
	ofSetVerticalSync(true);
	ofSetFrameRate(30);

	// ofDisableArbTex();
	// ofEnableDepthTest();

	cam.setDistance(300);
	ofSetCircleResolution(64);

	model.loadModel("box.obj", false);
	// model.setPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.75 , 0);
	
	fbo.allocate(_w, _h);
	fbo.begin();
		ofClear(255,255,255, 0);
	fbo.end();

	bRecording = false;
}

//--------------------------------------------------------------
void ofApp::update(){
	counter++;
	model.update();

	if(bRecording){
		// cout << "recording" << endl;
		ofPixels pixels;
		fbo.readToPixels(pixels);
		ofSaveImage(pixels, "sequence/"+ofToString(frameCounter, 4, '0')+".png");
		frameCounter++;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);

	ofSetColor(255, 255, 255);

	fbo.begin();
	ofClear(0,0,0,0);
	ofBackground(0, 0, 0);
	cam.begin();
	ofRotateX(ofRadToDeg(.5));
	// ofRotateY(ofRadToDeg(-.5));

	// ofRotateY(ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, 90));
	ofRotateY(counter);

	// ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableDepthTest();
	
	ofSetColor(255, 0, 255, 255);
	// model.setPosition(ofGetWidth()/2, (float)ofGetHeight() * 0.75 , 0);
	// model.setPosition(ofGetWidth()/2, (float)ofGetHeight() /2, 0);
	// model.draw(OF_MESH_FILL); //same as model.drawFaces();
	// model.draw(OF_MESH_POINTS); // same as model.drawVertices();
	model.draw(OF_MESH_WIREFRAME); // same as model.drawWireframe();

	cam.end();
	fbo.end();

	fbo.draw(0,0);

	stringstream ss;
	ss << "FPS: " << ofGetFrameRate() << endl
	<< (bRecording?"stop":"start") << " recording: r" << endl;
	ofSetColor(0, 255, 0);
	ofDrawBitmapString(ss.str(),15,15);
}

//--------------------------------------------------------------
void ofApp::exit(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(key=='r'){
		if(!bRecording) {
			ofDirectory dir("");
			dir.removeDirectory("sequence/", true);
			// cout << dir.listDir() << endl;
			bRecording = true;
			return;
		}
		
		if(bRecording) {
			bRecording = false;
			return;
		}
	}
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
