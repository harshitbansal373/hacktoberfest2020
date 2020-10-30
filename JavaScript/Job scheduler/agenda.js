const Agenda = require('agenda');
const express = require('express');
var Agendash = require('agendash');
var app = express();

/* const users = await User.doSomethingReallyIntensive();
processUserData(users); */

const mongoConnectionString = 'mongodb://127.0.0.1/agenda';
const agenda = new Agenda({db: {address: mongoConnectionString, options: { useUnifiedTopology: true }}});

app.use('/dash', Agendash(agenda));

agenda.define('printAnalyticsReport', job => {
    console.log('I print a report!');
});


agenda.on('ready', function () {
    agenda.every('20 seconds', 'printAnalyticsReport');
    agenda.start();
});

app.listen(3001);