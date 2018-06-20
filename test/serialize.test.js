const thrift = require('thrift');
const { Serializer } = require('../');
const { SharedStruct } = require('./codegen/shared_types');
const { Work, FirstName, LastName, Name, Everything } = require('./codegen/test_types');

function serializeWithThrift(struct) {
  let value = null;
  const transport = new thrift.TFramedTransport(null, byteArray => {
    value = byteArray.slice(4).toString();
  });
  const protocol = new thrift.TCompactProtocol(transport);
  struct.write(protocol);
  transport.flush();
  return value;
}

function performTest(struct) {
  const serializer = new Serializer();
  struct.write(serializer);
  const serialized = serializer.flush();
  const normalSerialized = serializeWithThrift(struct);
  expect(serialized).toEqual(normalSerialized);
}

test.each([
  new SharedStruct({ code: 123, value: 'foobar' }),
  new Work({ num2: 99 }),
  new Work({ num1: 33, num2: 42 }),
  new Work({ num2: 66, comment: 'foobar' }),
  new Work({ num1: 33, num2: 42, comment: 'cmt' }),
  new FirstName({ name: 'Jordan' }),
  new LastName({ name: 'Jordan' }),
  new Name({
    first_name: new FirstName({ name: 'Jordan' }),
    last_name: new LastName({ name: 'Gensler' }),
  }),
  new Everything({
    byte_val: 127,
    i16_val: 32767,
    i32_val: 2147483647,
    i64_val: '9223372036854775807',
    set_val: new Set(['foo', 'bar']),
    list_val: ['foo', 'bar'],
    map_val: { 'foo': 'bar' },
    string_val: 'some string',
    bool_val: false,
    double_val: 3.14195,
  }),
])('should serialize to an identical value', struct => {
  performTest(struct);
});
