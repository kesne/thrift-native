var myModule;

if (process.env.DEBUG) {
  myModule = require('./build/Debug/thrift-native.node');
} else {
  myModule = require('./build/Release/thrift-native.node');
}

module.exports = myModule;
