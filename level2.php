<?php
 $Velocity=0;
 $IntialHigh=0;
 $Angle=1;
function motiontime($Velocity,$Angle)
{
    echo $Velocity * sin($Angle)*9.8;
    return 0;
}
function distance($Velocity,$Angle,$IntialHigh){
    echo $Velocity*cos($Angle)*sqrt((2*$IntialHigh)/9.8);
    return 0;
}
function Vx($Velocity,$Angle){
    echo $Velocity*cos($Angle);
    return 0;
}
function Vy($Velocity,$Angle){
   echo ($Velocity*sin($Angle))-(motiontime($Velocity,$Angle)*9.8);
   return 0;
}
function finalvelocity($Velocity,$Angle,$IntialHigh){
   echo sqrt(pow(Vx($Velocity,$Angle),2)+pow(Vy($Velocity,$Angle),2));
   return 0;
}
function finalangle($Velocity,$Angle,$IntialHigh){
    if(Vy($Velocity,$Angle)>0){
        echo atan(Vx($Velocity,$Angle)/Vy($Velocity,$Angle));
        return 0; 
    }
    else{
        return 1;
    }
}
$Velocity=$_POST["Velocity"];
$IntialHigh=$_POST["High"];
$Angle=$_POST["Angle"];
?>

<p>
       The velocity is:
        <?php finalvelocity($Velocity,$Angle,$IntialHigh); ?> km/h <br />
       The hit angle is:
        <?php finalangle($Velocity,$Angle,$IntialHigh); ?> Rad <br />
        The distance between start point and hit point is:
        <?php distance($Velocity,$Angle,$IntialHigh) ?> km <br />
</p>
