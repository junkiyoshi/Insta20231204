#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);

	for (int z = 500; z > -500; z -= 20) {

		auto location = glm::vec3(0, 0, z);

		ofPushMatrix();
		ofTranslate(location);
		
		ofRotateZ(z * 0.5 + ofGetFrameNum() * 4);

		ofFill();
		ofSetColor(0);
		ofDrawBox(450, 20, 5);

		ofNoFill();
		ofSetColor(255);
		ofDrawBox(450, 20, 5);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}