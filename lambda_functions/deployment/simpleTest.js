var aws = require('aws-sdk');
var R = require('ramda');

export.myHandler = function(event, context, callback){
  if(event.num = 10){
    callback(null, {number: 10} );
  }
  else{
    callback(null, {number: -1} );
  }
}

