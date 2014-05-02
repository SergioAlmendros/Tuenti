#!/usr/sbin node

if ((process.version.split('.')[1]|0) < 10) {
	console.log('Please, upgrade your node version to 0.10+');
	process.exit();
}

var net = require('net');
var util = require('util');
var crypto = require('crypto');

var options = {
	'port': 6969,
	'host': '54.83.207.90',
}


var dh, secret, state = 0;

var socket = net.connect(options, function() {
	state++;
});

socket.on('data', function(data) {

	data = data.toString().trim().split('|');

	console.log(data);

});












