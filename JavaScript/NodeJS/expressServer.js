/**
 * Created by Shafeen M. on 7/8/2015.
 */


var app = require('express')();
var http = require('http').Server(app);

var filelist = ["index.html"];

filelist.forEach(function(filename) {
    app.get('/'+filename, function (req, res) {
        res.sendFile('/'+filename, { root : './'});
    });
});

http.listen(3000, function(){
    console.log('listening on *:3000');
});


