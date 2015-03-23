#include "ofApp.h"

#include "Poco/Base64Decoder.h"
#include "lenna.h"

//--------------------------------------------------------------
void ofApp::setup(){

	setting.width  = 512;
	setting.height = 512;

	original.allocate(setting);

	//ksmrFX setup
	fx.setup(&original, setting);


	//make image for sample
	stringstream ss;
	ss << lenna;
	Poco::Base64Decoder b64in(ss);

	ofBuffer buffer;
	b64in >> buffer;

	image.loadImage(buffer);
}

//--------------------------------------------------------------
void ofApp::update(){

	//fx switch with key bind
	fx.getfxUnit(KSMR_FRAGFX_NOISE)->bEnable		= ofGetKeyPressed('1');
	fx.getfxUnit(KSMR_FRAGFX_EDGEONTOP)->bEnable	= ofGetKeyPressed('2');
	fx.getfxUnit(KSMR_FRAGFX_FRINGE)->bEnable		= ofGetKeyPressed('3');
	fx.getfxUnit(KSMR_FRAGFX_INVERT)->bEnable		= ofGetKeyPressed('4');
	fx.getfxUnit(KSMR_FRAGFX_SLANTSHIFT)->bEnable	= ofGetKeyPressed('5');
	fx.getfxUnit(KSMR_FRAGFX_TEXCHIP)->bEnable		= ofGetKeyPressed('6');
	fx.getfxUnit(KSMR_FRAGFX_VERTNOISE)->bEnable	= ofGetKeyPressed('7');
	fx.getfxUnit(KSMR_FRAGFX_VERTSLIDE)->bEnable	= ofGetKeyPressed('8');

	//change uniform parameter
	fx.getfxUnit(KSMR_FRAGFX_VERTSLIDE)->u_Volume = ofNoise(ofGetElapsedTimef())*5000.0;
}

//--------------------------------------------------------------
void ofApp::draw(){

	//draw src buffer
	original.begin();{
		ofClear(0, 0, 0, 255);

		ofSetColor(255);
		image.draw(0, 0);
	}original.end();


	ofSetColor(255);
	//draw original buffer
	original.draw(0, 0);

	//apply active Effects
	fx.applyFx();

	//draw applied buffer
	original.draw(512, 0);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
