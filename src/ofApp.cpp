#include "ofApp.h"

void ofApp::setup(){
  ofHttpRequest request;
  request.method = ofHttpRequest::POST;
  request.url = "http://httpbin.org/anything";
  request.body = "{ \"test\": \"post\" }";
  ofURLFileLoader http;
  auto response = http.handleRequest(request);
  ofLogNotice() << response.status << std::endl;
  ofLogNotice() << response.data.getText() << std::endl;
  ofExit(0);
}
