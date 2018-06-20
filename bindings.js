const thrift = require('thrift');
const { Serializer } = require('./build/Release/thrift-native.node');

function Deserializer(encodedByteArray) {
  var transport = new thrift.TFramedTransport(Buffer.from(encodedByteArray));
  var protocol = new thrift.TCompactProtocol(transport);
  return protocol;
}

module.exports = {
  Serializer,
  Deserializer,
};
