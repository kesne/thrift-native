#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TCompactProtocol.h>
#include "Protocol.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

Nan::Persistent<v8::FunctionTemplate> Protocol::constructor;

NAN_MODULE_INIT(Protocol::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(Protocol::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Protocol").ToLocalChecked());

  Nan::SetPrototypeMethod(ctor, "flush", Flush);
  Nan::SetPrototypeMethod(ctor, "writeStructBegin", WriteStructBegin);
  Nan::SetPrototypeMethod(ctor, "writeStructEnd", WriteStructEnd);
  Nan::SetPrototypeMethod(ctor, "writeFieldBegin", WriteFieldBegin);
  Nan::SetPrototypeMethod(ctor, "writeFieldEnd", WriteFieldEnd);
  Nan::SetPrototypeMethod(ctor, "writeFieldStop", WriteFieldStop);
  Nan::SetPrototypeMethod(ctor, "writeListBegin", WriteListBegin);
  Nan::SetPrototypeMethod(ctor, "writeListEnd", WriteListEnd);
  Nan::SetPrototypeMethod(ctor, "writeString", WriteString);
  Nan::SetPrototypeMethod(ctor, "writeI16", WriteI16);
  Nan::SetPrototypeMethod(ctor, "writeI32", WriteI32);
  Nan::SetPrototypeMethod(ctor, "writeI64", WriteI64);
  Nan::SetPrototypeMethod(ctor, "writeDouble", WriteDouble);

  target->Set(Nan::New("Protocol").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Protocol::New) {
  // throw an error if constructor is called without new keyword
  if(!info.IsConstructCall()) {
    return Nan::ThrowError(Nan::New("Protocol::New - called without new keyword").ToLocalChecked());
  }

  // create a new instance and wrap our javascript instance
  Protocol* vec = new Protocol();

  boost::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
  boost::shared_ptr<TCompactProtocol> compactProtocol(new TCompactProtocol(buffer));

  vec->buffer = buffer;
  vec->protocol = compactProtocol;

  vec->Wrap(info.Holder());

  // return the wrapped javascript instance
  info.GetReturnValue().Set(info.Holder());
}

NAN_METHOD(Protocol::Flush) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  std::string serialized = self->buffer->getBufferAsString();
  self->buffer->resetBuffer();
  info.GetReturnValue().Set(Nan::New<v8::String>(serialized).ToLocalChecked());
}

NAN_METHOD(Protocol::WriteStructBegin) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  const char* name = *Nan::Utf8String(info[0]->ToString());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeStructBegin(name);
}

NAN_METHOD(Protocol::WriteStructEnd) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeStructEnd();
}

NAN_METHOD(Protocol::WriteFieldBegin) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  const char* name = *Nan::Utf8String(info[0]->ToString());
  TType fieldType = static_cast<TType>(info[1]->NumberValue());
  int fieldId = info[2]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldBegin(name, fieldType, fieldId);
}

NAN_METHOD(Protocol::WriteFieldEnd) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldEnd();
}

NAN_METHOD(Protocol::WriteFieldStop) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldStop();
}


NAN_METHOD(Protocol::WriteString) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  const char* str = *Nan::Utf8String(info[0]->ToString());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeString(str);
}

NAN_METHOD(Protocol::WriteI64) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  int64_t num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI64(num);
}

NAN_METHOD(Protocol::WriteI16) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  int16_t num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI16(num);
}

NAN_METHOD(Protocol::WriteI32) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  int32_t num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI32(num);
}

NAN_METHOD(Protocol::WriteDouble) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  double num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeDouble(num);
}

NAN_METHOD(Protocol::WriteListBegin) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());
  TType listType = static_cast<TType>(info[0]->NumberValue());
  int listSize = info[1]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeListBegin(listType, listSize);
}

NAN_METHOD(Protocol::WriteListEnd) {
  Protocol * self = Nan::ObjectWrap::Unwrap<Protocol>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeListEnd();
}
