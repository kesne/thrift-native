# thrift-native

Node.js bindings to Thrift's C++ library. Designed primarily for manually serializing / deserializing payloads with thrift. Currently only supports writing, and a minimal version of the Compact protocol.

## Write methods not yet implemented

- writeMessageBegin
- writeMessageEnd
- writeMapBegin
- writeMapEnd
- writeByte
- writeBinary

## Read methods not yet implemented

- readMessageBegin
- readMessageEnd
- readStructBegin
- readStructEnd
- readFieldBegin
- readFieldEnd
- readMapBegin
- readMapEnd
- readListBegin
- readListEnd
- readSetBegin
- readSetEnd
- readBool
- readByte
- readI16
- readI32
- readI64
- readDouble
- readBinary
- readString
- skip
