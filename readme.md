This is a test case for HTTP POST in openframeworks

Tested as of commit 6b3b320fd2e8f21cde059df7a31dd4a9cf830e1e

The response should be method = POST but its method = PUT

I think libcurl is being too clever, but I'm not sure where

```cpp
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
```

returns

```json
 {
  "args": {},
  "data": "{ \"test\": \"post\" }",
  "files": {},
  "form": {},
  "headers": {
    "Accept": "*/*",
    "Connection": "close",
    "Content-Length": "18",
    "Expect": "100-continue",
    "Host": "httpbin.org"
  },
  "json": {
    "test": "post"
  },
  "method": "PUT",
  "origin": "100.37.162.147",
  "url": "http://httpbin.org/anything"
}
```
