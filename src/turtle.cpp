#include <ros/ros.h>
#include "keyboard.h"
#include <geometry_msgs/Twist.h>
ros::Publisher pub1;
geometry_msgs::Twist t;
void okTuslariCallback(const keyboard::Key tus){
ROS_INFO("kod: %d",tus.code);
if(tus.code== 116){
t.linear.x=2;
t.angular.z=0;}
else if(tus.code==103){
t.linear.x=-2;
t.angular.z=0;
}
else if (tus.code==104){
t.linear.x=0;
t.angular.z=-2;
}
else if (tus.code==102){
t.linear.x=0;
t.angular.z=2;
}
else {
t.linear.x=0;
t.angular.z=0;}
pub1.publish(t);
}
int main(int argc, char** argv){

	ros::init(argc,argv,"turtle");
	ros::NodeHandle nh;
	pub1=nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 1000);
	ros::Subscriber sub = nh.subscribe("keyboard/keydown",1000,okTuslariCallback);
	ros::Rate loop_rate(50);
while(ros::ok()){
	ros::spinOnce();
	loop_rate.sleep();
}
	return 0;

}
