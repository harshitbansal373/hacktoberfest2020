let canvas = document.getElementById("myCanvas");
let ctx = canvas.getContext("2d");

let mouse = {
    x : 0,
    y : 0,
}

window.addEventListener('mousemove',(event) => {
  mouse.x = event.pageX;
  mouse.y = event.pageY;
})

const draw = () =>{
    canvas.height = window.innerHeight;
    canvas.width = window.innerWidth;
    
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    
    let green = 180-(mouse.y*(180/window.innerHeight));
    let blue = 255-(mouse.y*(180/window.innerHeight));
    ctx.fillStyle = `rgb(0, ${green}, ${blue})`;
    ctx.fillRect(0, 0, canvas.width, canvas.height);
    
    ctx.beginPath();
    ctx.arc(mouse.x,mouse.y,30,0,Math.PI*2);
    ctx.strokeStyle="#FF5511";
    ctx.stroke();
    ctx.fillStyle="#FFFF00";
    ctx.fill();
    
    lightLine();
}

const lightLine = () =>{
    ctx.strokeStyle="#FF5511";
    
    let moveLength = 40
    let lineLength = 60
    
    for(let i=-1;i<=1;i+=2){
        ctx.beginPath();
        ctx.moveTo(mouse.x+(moveLength*i),mouse.y);
        ctx.lineTo(mouse.x+(lineLength*i),mouse.y);
        ctx.stroke();
   
        ctx.beginPath();
        ctx.moveTo(mouse.x,mouse.y+(moveLength*i));
        ctx.lineTo(mouse.x,mouse.y+(lineLength*i));
        ctx.stroke();
    }
    
    ctx.beginPath();
    ctx.moveTo(mouse.x+30,mouse.y+30);
    ctx.lineTo(mouse.x+(30+15),mouse.y+(30+15));
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(mouse.x-30,mouse.y+30);
    ctx.lineTo(mouse.x-(30+15),mouse.y+(30+15));
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(mouse.x+30,mouse.y-30);
    ctx.lineTo(mouse.x+(30+15),mouse.y-(30+15));
    ctx.stroke();
    
    ctx.beginPath();
    ctx.moveTo(mouse.x-30,mouse.y-30);
    ctx.lineTo(mouse.x-(30+15),mouse.y-(30+15));
    ctx.stroke();
}

setInterval('draw()',50)