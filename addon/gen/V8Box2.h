#ifndef GEN_V8BOX2_H
#define GEN_V8BOX2_H

#include "../impl/Box2.h"
#include <nan.h>

namespace three {

class V8Box2 : public Nan::ObjectWrap {
public:
  static Box2* toImpl(const V8Box2* wrapper) {
    return wrapper->ptr_;
  }

  static NAN_MODULE_INIT(Init);

private:
  static NAN_METHOD(Constructor);
  static NAN_METHOD(setMethod);
  static NAN_METHOD(isEmptyMethod);

  V8Box2(Box2* ptr) {
    ptr_ = ptr;
  };
  Box2* ptr_;
};

}; // namespace three

#endif // GEN_V8BOX2_H
