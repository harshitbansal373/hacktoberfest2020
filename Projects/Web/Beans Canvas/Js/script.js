var canvas= document.querySelector('canvas');
canvas.width = window.innerWidth;
canvas.height=window.innerHeight;

var c = canvas.getContext('2d');

var mouse = {
    x:undefined,
    y:undefined
}

window.addEventListener('mousemove' , function(event){
    mouse.x=event.x;
    mouse.y=event.y;
    
});
window.addEventListener('resize', function(){
    canvas.width = window.innerWidth;
    canvas.height=window.innerHeight;

    init();
});

function Circle( x , y , dx , dy , rad) {
    this.x = x;
    this.y=y;
    this.dx = dx;
    this.dy = dy;
    this.rad =  rad;
    this.color = 'grey';
    this.draw = function () {
        c.beginPath();
        c.arc(this.x,this.y,this.rad,0,Math.PI*2,false);
        c.fillStyle = '#DEA407';
        c.fill();
        for(var i=0;i<circleArray.length;i++)
        {
            var x1=this.x;
            var y1=this.y;
            var x2=circleArray[i].x;
            var y2=circleArray[i].y;
            lineMaker(x1,y1,x2,y2);
        }
    };

var lineMaker = function(x1,y1,x2,y2){
    if(x1!=x2 && y1!=y2)
            {
                c.beginPath();
                c.moveTo(x1,y1);
                c.lineTo(x2,y2);
                c.strokeStyle = "#DEA407";
                c.stroke();
            }
}

    this.update  = function() {
        if(this.x+this.rad>innerWidth||this.x-this.rad<0)
        this.dx= -this.dx;
        if(this.y+this.rad>innerHeight||this.y-this.rad<0)
        this.dy= -this.dy;
        this.x+=this.dx;
        this.y+=this.dy;
        //interactivity
        var x1=this.x;
        var y1=this.y;
        var x2=mouse.x;
        var y2=mouse.y;
        if(distance(x1,x2,y1,y2)<800){
                    lineMaker(x1,y1,x2,y2);
        }
        this.draw();
    };
}

var distance = function (p,q,r,s){
    var d1=p-q;
    var d2=r-s;
    d1 = Math.pow(d1,2);
    d2 = Math.pow(d2,2);
    var d3=d1+d2;
    var d4 = Math.pow(d3,0.5);
    return d4;
}

var circleArray = [];

function init(){
    circleArray=[];
    for(var i=0;i<10;i++){
        var rad=20;
        var x=Math.random() * (innerWidth - rad*2) + rad;
        var y=Math.random() * (innerHeight - rad*2)+rad;
        var dy=( Math.random() - 0.5);
        var dx =( Math.random() - 0.5);
        circleArray.push(new Circle(x,y,dx,dy,rad));
    }
    
}

function animate() {
    requestAnimationFrame(animate);
    c.clearRect(0,0,innerWidth,innerHeight);
    for (let i = 0; i < circleArray.length; i++) {
        circleArray[i].update();
        
    }
}
animate();
init();