#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TCompactProtocol.h>
#include "Serializer.h"

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

Nan::Persistent<v8::FunctionTemplate> Serializer::constructor;

NAN_MODULE_INIT(Serializer::Init) {
  v8::Local<v8::FunctionTemplate> ctor = Nan::New<v8::FunctionTemplate>(Serializer::New);
  constructor.Reset(ctor);
  ctor->InstanceTemplate()->SetInternalFieldCount(1);
  ctor->SetClassName(Nan::New("Serializer").ToLocalChecked());

  Nan::SetPrototypeMethod(ctor, "flush", Flush);
  Nan::SetPrototypeMethod(ctor, "writeStructBegin", WriteStructBegin);
  Nan::SetPrototypeMethod(ctor, "writeStructEnd", WriteStructEnd);
  Nan::SetPrototypeMethod(ctor, "writeFieldBegin", WriteFieldBegin);
  Nan::SetPrototypeMethod(ctor, "writeFieldEnd", WriteFieldEnd);
  Nan::SetPrototypeMethod(ctor, "writeFieldStop", WriteFieldStop);
  Nan::SetPrototypeMethod(ctor, "writeListBegin", WriteListBegin);
  Nan::SetPrototypeMethod(ctor, "writeListEnd", WriteListEnd);
  Nan::SetPrototypeMethod(ctor, "writeSetBegin", WriteSetBegin);
  Nan::SetPrototypeMethod(ctor, "writeSetEnd", WriteSetEnd);
  Nan::SetPrototypeMethod(ctor, "writeString", WriteString);
  Nan::SetPrototypeMethod(ctor, "writeI16", WriteI16);
  Nan::SetPrototypeMethod(ctor, "writeI32", WriteI32);
  Nan::SetPrototypeMethod(ctor, "writeI64", WriteI64);
  Nan::SetPrototypeMethod(ctor, "writeBool", WriteBool);
  Nan::SetPrototypeMethod(ctor, "writeDouble", WriteDouble);

  target->Set(Nan::New("Serializer").ToLocalChecked(), ctor->GetFunction());
}

NAN_METHOD(Serializer::New) {
  // throw an error if constructor is called without new keyword
  if(!info.IsConstructCall()) {
    return Nan::ThrowError(Nan::New("Serializer::New - called without new keyword").ToLocalChecked());
  }

  // create a new instance and wrap our javascript instance
  Serializer* vec = new Serializer();

  boost::shared_ptr<TMemoryBuffer> buffer(new TMemoryBuffer());
  boost::shared_ptr<TCompactProtocol> compactProtocol(new TCompactProtocol(buffer));

  vec->buffer = buffer;
  vec->protocol = compactProtocol;

  vec->Wrap(info.Holder());

  // return the wrapped javascript instance
  info.GetReturnValue().Set(info.Holder());
}

NAN_METHOD(Serializer::Flush) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  std::string serialized = self->buffer->getBufferAsString();
  self->buffer->resetBuffer();
  info.GetReturnValue().Set(Nan::New<v8::String>(serialized).ToLocalChecked());
}

NAN_METHOD(Serializer::WriteStructBegin) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  const char* name = *Nan::Utf8String(info[0]->ToString());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeStructBegin(name);
}

NAN_METHOD(Serializer::WriteStructEnd) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeStructEnd();
}

NAN_METHOD(Serializer::WriteFieldBegin) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  const char* name = *Nan::Utf8String(info[0]->ToString());
  TType fieldType = static_cast<TType>(info[1]->NumberValue());
  int fieldId = info[2]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldBegin(name, fieldType, fieldId);
}

NAN_METHOD(Serializer::WriteFieldEnd) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldEnd();
}

NAN_METHOD(Serializer::WriteFieldStop) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeFieldStop();
}


NAN_METHOD(Serializer::WriteString) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  const char* str = *Nan::Utf8String(info[0]->ToString());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeString(str);
}

NAN_METHOD(Serializer::WriteI64) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  int64_t num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI64(num);
}

NAN_METHOD(Serializer::WriteI16) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  int16_t num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI16(num);
}

NAN_METHOD(Serializer::WriteI32) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  int32_t num = info[0]->Int32Value();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeI32(num);
}

NAN_METHOD(Serializer::WriteDouble) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  double num = info[0]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeDouble(num);
}

NAN_METHOD(Serializer::WriteBool) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  bool val = info[0]->BooleanValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeBool(val);
}

NAN_METHOD(Serializer::WriteListBegin) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  TType listType = static_cast<TType>(info[0]->NumberValue());
  int listSize = info[1]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeListBegin(listType, listSize);
}

NAN_METHOD(Serializer::WriteListEnd) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeListEnd();
}

NAN_METHOD(Serializer::WriteSetBegin) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());
  TType setType = static_cast<TType>(info[0]->NumberValue());
  int setSize = info[1]->NumberValue();

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeSetBegin(setType, setSize);
}

NAN_METHOD(Serializer::WriteSetEnd) {
  Serializer * self = Nan::ObjectWrap::Unwrap<Serializer>(info.This());

  TCompactProtocol * protocol = self->protocol.get();
  protocol->writeSetEnd();
}
