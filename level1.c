#define _CRTÉÉ_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define g 9.8 
//In this program we want to analyz projectile motion.The user supposed to enetr the intial velocity, high and launch angle. The calculate will return the final velocity, hit angle and the distance between the start point and the hit point.

double time(double velocity, double angle,double high) {
	return ((velocity * sin(angle) + sqrt(pow((velocity)*sin(angle), 2) + 2 * g + high) / g));
}
//this function calculates the time until the Zvovon hit the ground.We need this calculation for further calculations.

double lenth(double velocity, double high, double angle) {
	return (velocity * cos(angle) * time(velocity,angle,high));
}
//this function calculates the distance between the start point and the hit point.

double FinalVelocitySize(double velocity, double high, double angle) {
	double MotionTime = time(velocity, angle,high);
	double Vx = velocity * cos(angle);
	double Vy = velocity * sin(angle) - g * MotionTime;
	return sqrt(pow(Vx, 2) + pow(Vy, 2));
}
//this function calculates the absulot value of the final velocity.

double HitAngle(double velocity, double high, double angle) {
	double MotionTime = time(velocity, angle,high);
	return atan((velocity * cos(angle)) / ((velocity * sin(angle)) - (g * MotionTime)));

}
//this function calculates the Hit Angle.We wont divide in zero because g*motiontime>velocity*sin(angle) 

double InputCheck() {
	double Value = -1;
	while (scanf("%lf", &Value) != 1 || Value < 0) {
		printf("Theres a problam with this value. please check again the roles.");
		fseek(stdin, 0, SEEK_END);
	}
	return Value;
}
//this function is getting the input and checking that the input is legal.in theory,when scanf is getting an ilegal tab it get into the loop and printing error massege.
//pracricly,when scanf getting ilegal tab it stop scanning, which means that the illegal tab is staying in the buffer memory. fseek is helping us to "clean" the buffer and avoid infinity loop

int main()
{
	double IntialVelocity = 0;
	double IntialAngle = 0;
	double IntialHige = 0;
		printf("Welcome to Zvovo.net \n");
		printf("Please eneter the absolute value of the intial velocity in km/h \n");
		IntialVelocity = InputCheck();
		printf("Please eneter the intial high in units of km \n");
		IntialHige = InputCheck();
		printf("Please eneter the intial angle  in units of rad \n");
		IntialAngle = InputCheck();
		double Finaldistance = lenth(IntialVelocity, IntialHige, IntialAngle);
		printf ("The Zvovon will land %f km away from the launch spot \n", Finaldistance);
		double FinalVelocity= FinalVelocitySize(IntialVelocity, IntialHige, IntialAngle);
		printf("The Zvovons velocity when it hits the ground is %f km/h \n", FinalVelocity);
		double FinalAngle = HitAngle(IntialVelocity, IntialHige, IntialAngle);
		printf("The Zvovons angle when it hits the ground is %f rad \n", FinalAngle);
}
