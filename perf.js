const thrift = require('thrift');
const { Protocol } = require('./');
const Benchmark = require('benchmark');
const { Basic } = require('./codegen/basic_types');
const { ListingLocationUpdate, Neighborhood } = require('./codegen/listings_types');

var suite = new Benchmark.Suite();

const listingUpdate = new Basic({ message: 'This is a test message!' });
const encodedJSON = JSON.stringify(listingUpdate);
const encodedByteArray = Buffer.from('GBdUaGlzIGlzIGEgdGVzdCBtZXNzYWdlIQA=', 'base64');

// const neighborhoods = Array.from({ length: 10 }, (_, i) => new Neighborhood({ neighborhoodId: i, name: `name-${i}` }));

// const listingUpdate = new ListingLocationUpdate({
//   listingId: 1,
//   offsetLat: 123.1347,
//   offsetLng: 1298.590288,
//   locationUpdateTimestamp: 111,
//   cityId: 222,
//   canonicalNeighborhoodId: 333,
//   neighborhoods,
// });

console.log();
console.log('Running Suite: Read');
new Benchmark.Suite('read')
  .add('neighborhood -> json', () => {
    const json = JSON.parse(encodedJSON);
    return new Basic(json);
  })
  .add('neighborhood -> thrift', () => {
    var transport = new thrift.TFramedTransport(encodedByteArray);
    var protocol = new thrift.TCompactProtocol(transport);
    var basic = new Basic();
    basic.read(protocol);
    return basic;
  })
  .on('cycle', function(event) {
    console.log(String(event.target));
  })
  .on('complete', function() {
    console.log('Fastest is ' + this.filter('fastest').map('name'));
  })
  .run();

console.log();
console.log('Running Suite: Write');
new Benchmark.Suite('write')
  .add('neighborhood -> json', function() {
    JSON.stringify(listingUpdate);
  })
  .add('neighborhood -> thrift', function() {
    var transport = new thrift.TFramedTransport();
    var protocol = new thrift.TCompactProtocol(transport);
    listingUpdate.write(protocol);
    transport.flush();
  })
  .add('neighborhood -> thrift-native', function() {
    var protocol = new Protocol();
    listingUpdate.write(protocol);
    protocol.flush();
  })
  .on('cycle', function(event) {
    console.log(String(event.target));
  })
  .on('complete', function() {
    console.log('Fastest is ' + this.filter('fastest').map('name'));
  })
  .run();
