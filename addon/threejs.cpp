#include <nan.h>

#include "gen/V8Box2.h"

namespace three {

void InitAll(v8::Handle<v8::Object> exports) {
  V8Box2::Init(exports);
}

NODE_MODULE(threejs, InitAll)

}; // namespace three