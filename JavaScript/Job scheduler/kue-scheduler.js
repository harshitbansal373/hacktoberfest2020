const http = require('http');

const port = 3000;
http.createServer().listen(port, () => {
    console.warn(`Server running at http://localhost:${port}/`);
});

// kue-scheculer demo

const kue = require('kue-scheduler');
var Queue = kue.createQueue();

let data = { name: 'send email' }; 

let job = Queue
            .createJob('schedule', data)
            .attempts(3)
            .priority('normal');

Queue.schedule('10 seconds from now', job);

Queue.process('schedule', function(job, done) {
    console.log('job is running....')
    done()
})