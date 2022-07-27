function time (Velocity,High,Angle) { 
  var time=(Velocity * sin(Angle) + sqrt(pow((Velocity)*sin(Angle), 2) + 2 * 9.8 + High) / 9.8)
  return time
}
function length(Velocity,High,Angle) {
var distance=(Velocity * cos(Angle) * time(Velocity,Angle,High));
return distance;
}
function velocity(Velocity,High,Angle) {
var MotionTime = time(Velocity, Angle,High)
var Vx = Velocity * cos(Angle)
var Vy = Velocity * sin(Angle) - 9.8* MotionTime
var finalvelocity=sqrt(pow(Vx, 2) + pow(Vy, 2))
return finalvelocity
}
function hitAngle(Velocity,High,Angle) {
var MotionTime = time(velocity, Angle,High);
var hitangle=((Velocity * cos(Angle)) / ((Velocity * sin(Angle)) - (9.8 * MotionTime)));
return hitangle;
}

const Velocity = document.getElementById("velocity");
const High = document.getElementById("high");
const angle = document.getElementById("angle");

function all(Velocity,High,Angle){
document.write("The final velocity is:");
document.write(velocity(Velocity,High,Angle));
document.write("km/h <br><br>");
document.write("The hit angle is:");
document.write(hitAngle(Velocity,High,Angle));
document.write("Rad <br>");
document.write("The distance between start poin and hit point is:");
document.write(length(Velocity,High,Angle));
document.write("km <br>");
}
