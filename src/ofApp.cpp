#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	//font.load("DelaGothicOne-Regular.ttf", 40);
	fbo.allocate(ofGetWidth(), ofGetHeight()/2, GL_RGBA);
	fbo.begin();
	ofClear(0, 0, 0, 0);
	fbo.end();

	fbo2.allocate(ofGetWidth(), ofGetHeight()/2, GL_RGBA);
	fbo2.begin();
	ofClear(0, 0, 0, 0);
	fbo2.end();

	//load cp and u font
	ofTrueTypeFontSettings settings("CP and U-Fo.ttf", 185);
	settings.addRanges(ofAlphabet::Japanese);
	settings.contours = true;
	settings.antialiased = true;
	settings.dpi = 72;
	settings.direction = OF_TTF_LEFT_TO_RIGHT;
	font.load(settings);

	//import the japanese characters
	auto bufferLines = ofBufferFromFile("text.txt").getText();
	for (int i = 0; i < bufferLines.size(); i++) {
		str += bufferLines[i];
	}
	//load noto sans
	english.load("NotoSansJP-Black.otf", 95, true, true, true);

	ofBackground(244, 244, 244);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//draw upper half
	fbo.begin();
	font.setLetterSpacing(0.8);
	ofSetColor(0, 0, 0, 191);
	for (int i = 25; i <= 105; i++) {
		ofNoFill();
		font.drawStringAsShapes(str, 20, 660 - 0.4 * pow(1.07, i));
	}
	fbo.end();
	ofSetColor(250, 250, 250, 50);
	fbo.draw(0, 0);
	ofSetColor(0, 0, 0, 255);
	font.drawString(str, 20, 160);
	
	//draw second half of MORISAWA
	fbo2.begin();
	english.setLetterSpacing(0.8);
	ofSetColor(0, 0, 0, 191);
	for (int i = 25; i <= 105; i++) {
		ofNoFill();
		english.drawStringAsShapes("MORISAWA", 20, 660 - 0.4 * pow(1.07, i));
	}
	fbo2.end();
	
	//flip fbo upside down
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetWidth()/2, 0);
	ofRotate(180.0);
	ofSetColor(250, 250, 250, 50);
	fbo2.draw(-357, -659);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
