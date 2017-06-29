const net = require('net');
const express = require('express');
const app = express();
const path = require('path');
var bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({ extended: true }));
var urlencodedParser = bodyParser.urlencoded({ extended: false })



var client = {};
function defaultDataCallback(data){
    console.log('This is from Xpress:', data.toString());
}
client = net.createConnection({host: "192.168.0.2",port: 1337}, () => {
  //'connect' listener
  console.log('connected to Xpress!');

  client.write('\n');
  client.write("relay enable\r\n");
});
client.on('data', defaultDataCallback);
client.on('end', () => {
  console.log('disconnected from Xpress');
});


app.use(express.static('public'));
/*
// Manual Value *******
app.post('/form', function(req, res) {
    reply = {msg: ""}; 
    reply.msg = 'You sent the value: ' + req.body.name ;
    res.send(reply);
});


//********

app.post('/Manual', function(req, res) {
    reply = {msg: ""}; 
    reply.msg = "You are in Manual Mode"; 

    res.send(reply); 
});

app.post('/DayMode', function(req, res) {
    reply = {msg: ""}; 
    reply.msg = "You are in DayMode"; 

    res.send(reply); 
});


app.post('/NightMode', function(req, res) {
    reply = {msg: ""}; 
    reply.msg = "You are in NightMode"; 

    res.send(reply); 
});
*/

app.post('/', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.value); 
    var reply = {msg: ""};
    if (req.body.value == 1) {
        console.log('In value == 1'); 
        client.write('DayMode\r\n');
        reply.msg = "Enabled..."; 
    }
    else if (req.body.value == 0) {
        console.log('In value == 0'); 
        client.write('NightMode\r\n');
        reply.msg = "Disabled...";
    }
    
});

app.post('/DayMode', urlencodedParser, function(req, res) {
    var reply = {msg: ""};
    client.write('DayMode\r\n');
    reply.msg = "Enabled..."; 
    
}); 

app.post('/NightMode', urlencodedParser, function(req, res) {
    var reply = {msg: ""};
    client.write('NightMode\r\n');
    reply.msg = "Disabled..."; 
    
}); 

app.post('/ColorSlider', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.rating); 
    var reply = {msg: ""};
    var value = req.body.rating;
    var red = value.toString(); 
    var result = "R=" + red + '\r\n'; // R=127
    reply.msg = result; 
    client.write(result); 
    
});
app.post('/ColorSlider2', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.rating2); 
    var reply = {msg: ""};
    var value = req.body.rating2;
    var green = value.toString(); 
    var result = "G=" + green + '\r\n'; // G=127
    reply.msg = result; 
    client.write(result); 
    
});
app.post('/ColorSlider3', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.rating3); 
    var reply = {msg: ""};
    var value = req.body.rating3;
    var blue = value.toString(); 
    var result = "B=" + blue + '\r\n'; // B=127
    reply.msg = result; 
    client.write(result); 
    
});
app.post('/Temperature', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.rating4); 
    var reply = {msg: ""};
    var value = req.body.rating4;
    var temp = value.toString(); 
    var result = "T=" + temp + '\r\n'; // T=127
    reply.msg = result; 
    client.write(result); 
    
});
app.post('/Brightness', urlencodedParser, function(req, res) {
    console.log('You have entered: ' + req.body.rating5); 
    var reply = {msg: ""};
    var value = req.body.rating5;
    var bright = value.toString(); 
    var result = "N=" + bright + '\r\n'; // N=127
    reply.msg = result; 
    client.write(result); 
    
});






app
    .get('/', function(req, res){
       res.sendFile(path.join(__dirname+'/public/home.html'));
    })
    .get('/relay/:relayCommand', function (req, res) {
        var reply = {msg: ""};
        
        if(req.params.relayCommand == "enable"){
            client.write('relay enable\r\n');
            reply.msg = "Shields online..."; 
        } else if(req.params.relayCommand == "disable"){
            client.write('relay disable\r\n');
            reply.msg = "Tractor beam disabled...";
        } else {
            reply.msg = "What?!?!";
        }

        res.send(reply);
    })
    .get('/adcc', function(req, res){
        var adcc_callback;
        adcc_callback = (data) => {
            matches = data.toString('utf-8').match('ADC=(\\d+)');
            if(matches){
                res.send({msg: "Don't move that dial...or do...or whatever...", value: +matches[1]})
            } else {
                res.send({msg: 'No dice!', value: undefined});
            }
            client.removeListener('data', adcc_callback);
        };
        client.write('pot value\r\n');
        client.addListener('data', adcc_callback);
    })
    .get('/killMe', function (req, res) {
        res.send({msg: "You have so much to live for!!"});
    })
    .get('/killMe/:really', function (req, res) {
        if(req.params.really == "now"){
            client.end();
            throw '(╯°□°)–︻╦╤─ – – – -(*_*)';
        }
    })
    .listen(1337, function(){
        console.log("Pulling into port");
    });