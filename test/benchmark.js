const thrift = require('thrift');
const { Serializer } = require('./');
const Benchmark = require('benchmark');
const { ListingLocationUpdate, Neighborhood } = require('./codegen/listings_types');

const neighborhoods = Array.from({ length: 10 }, (_, i) => new Neighborhood({ neighborhoodId: i, name: `name-${i}` }));

const listingUpdate = new ListingLocationUpdate({
  listingId: 1,
  offsetLat: 123.1347,
  offsetLng: 1298.590288,
  locationUpdateTimestamp: 111,
  cityId: 222,
  canonicalNeighborhoodId: 333,
  neighborhoods,
});

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
    var serializer = new Serializer();
    listingUpdate.write(serializer);
    serializer.flush();
  })
  .on('cycle', function(event) {
    console.log(String(event.target));
  })
  .on('complete', function() {
    console.log('Fastest is ' + this.filter('fastest').map('name'));
  })
  .run();
