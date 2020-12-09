/* const http = require('http'); */

// const port = 3001;
/* http.createServer().listen(port, () => {
    console.warn(`Server running at http://localhost:${port}/`);
});
 */
var express = require('express');
var kueUiExpress = require('kue-ui-express');
var app = express();

const nodemailer = require("nodemailer");

let transporter = nodemailer.createTransport({
    host: "smtp.gmail.com",
    port: 465,
    secure: true, // true for 465, false for other ports
    auth: {
      user: 'user',
      pass: 'pass'
    }
  });

var kue = require('kue');
var queue = kue.createQueue();

/* Creating a job */
var job = queue.create('email', {
    to: "sanjaysinh@yopmail.com"
}).removeOnComplete(true).delay(20000).attempts(5).backoff( {type:'exponential'} ).save();


queue.process('email', function(job, done) {
    email(job.data.to, done);
    job.log()
});


job.on('complete', function(result){
    console.log('Job completed with data ', result);
  
  }).on('failed attempt', function(errorMessage, doneAttempts){
    console.log('Job attempt' + doneAttempts + 'failed');
  
  }).on('failed', function(errorMessage){
    console.log('Job failed');
  
  }).on('progress', function(progress, data){
    console.log('\r  job #' + job.id + ' ' + progress + '% complete with data ', data );
  });

async function email(address, done) {
    if(!isValidEmail(address)) {
        return done(new Error('invalid email address'));
    }

    let info = await transporter.sendMail({
        from: 'talibany@gmail.com',
        to: address,
        subject: "Hello ✔",
        text: "Hello world?",
        html: "<b>Hello world?</b>"
    }, (err, info) => {
        if(!err) {
            done();
        } else {
            console.log("Error : %s", err);
            done( new Error(JSON.stringify(err)));
        }
    });
}

function isValidEmail (email) {
    console.log('sending mail to : ', email);
    return true;
}


kueUiExpress(app, '/kue/', '/kue-api');
app.use('/kue-api/', kue.app);
app.listen(3000);