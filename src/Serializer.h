#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TCompactProtocol.h>
#include <nan.h>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

class Serializer : public Nan::ObjectWrap {
public:
  static NAN_MODULE_INIT(Init);
  static NAN_METHOD(New);
  static NAN_METHOD(Flush);
  static NAN_METHOD(WriteStructBegin);
  static NAN_METHOD(WriteStructEnd);
  static NAN_METHOD(WriteFieldBegin);
  static NAN_METHOD(WriteFieldEnd);
  static NAN_METHOD(WriteFieldStop);
  static NAN_METHOD(WriteMessageBegin);
  static NAN_METHOD(WriteMessageEnd);
  static NAN_METHOD(WriteListBegin);
  static NAN_METHOD(WriteListEnd);
  static NAN_METHOD(WriteSetBegin);
  static NAN_METHOD(WriteSetEnd);
  static NAN_METHOD(WriteMapBegin);
  static NAN_METHOD(WriteMapEnd);
  static NAN_METHOD(WriteString);
  static NAN_METHOD(WriteByte);
  static NAN_METHOD(WriteBinary);
  static NAN_METHOD(WriteI16);
  static NAN_METHOD(WriteI32);
  static NAN_METHOD(WriteI64);
  static NAN_METHOD(WriteDouble);
  static NAN_METHOD(WriteBool);

  static Nan::Persistent<v8::FunctionTemplate> constructor;

protected:
  boost::shared_ptr<TMemoryBuffer> buffer;
  boost::shared_ptr<TCompactProtocol> protocol;
};
