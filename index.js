const { Serializer, Deserializer } = require('./');
const { Basic } = require('./codegen/basic_types');

const protocol = new Serializer();

const basic = new Basic({ message: 'testing123' });

basic.write(protocol);

const deserializer = new Deserializer(protocol.flush());

const basic2 = new Basic();
basic2.read(deserializer);

console.log(basic2);
