#include "../gen/V8Box2.h"

#include "../impl/Box2.h"
#include <nan.h>

namespace three {

NAN_METHOD(V8Box2::Constructor) {
  v8::Isolate* isolate = info.GetIsolate();

  if (info.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "2 arguments required")));
    return;
  }

  int min = info[0]->Uint32Value();
  int max = info[1]->Uint32Value();

  Box2* impl = Box2::Create(min, max);
  V8Box2 * obj = new V8Box2(impl);
  obj->Wrap(info.This());
  info.GetReturnValue().Set(info.This());
}

NAN_METHOD(V8Box2::setMethod) {
  v8::Isolate* isolate = info.GetIsolate();

  if (info.Length() < 2) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "2 arguments required")));
    return;
  }

  Box2* impl = V8Box2::toImpl(ObjectWrap::Unwrap<V8Box2>(info.Holder()));

  int min = info[0]->Uint32Value();
  int max = info[1]->Uint32Value();

  impl->set(min, max);

  info.GetReturnValue().Set(info.This());
}


NAN_METHOD(V8Box2::isEmptyMethod) {
  v8::Isolate* isolate = info.GetIsolate();

  if (info.Length() > 0) {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "0 argument required")));
    return;
  }

  Box2* impl = V8Box2::toImpl(ObjectWrap::Unwrap<V8Box2>(info.Holder()));

  int min = info[0]->Uint32Value();
  int max = info[1]->Uint32Value();
  bool empty = impl->isEmpty();

  v8::Local<v8::Boolean> result = Nan::New(empty);
  info.GetReturnValue().Set(result);
}

NAN_MODULE_INIT(V8Box2::Init) {
  v8::Local<v8::String> cname = Nan::New("Box2").ToLocalChecked();
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(Constructor);
  v8::Local<v8::ObjectTemplate> objTpl = tpl->InstanceTemplate();
  tpl->SetClassName(cname);
  objTpl->SetInternalFieldCount(1);

  Nan::SetPrototypeMethod(tpl, "set", setMethod);
  Nan::SetPrototypeMethod(tpl, "isEmpty", isEmptyMethod);

  Nan::Set(target, cname, Nan::GetFunction(tpl).ToLocalChecked());
}

}; // namespace three