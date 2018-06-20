const { Protocol } = require('./');
const { Basic } = require('./codegen/basic_types');

const protocol = new Protocol();

const basic = new Basic({ message: 'testing123' });

basic.write(protocol);
console.log(protocol.flush());

basic.write(protocol);
console.log(protocol.flush());
