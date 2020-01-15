#include <ros/ros.h>
#include "keyboard.h"
#include <std_msgs/Time.h>
#include <std_msgs/Float64.h>
double start;
ros::Publisher pub;

void callback(const keyboard::Key tus){
 	start= ros::Time::now().toSec();
}

void callback2(const keyboard::Key tus){
	std_msgs::Float64 msg;
	msg.data =ros::Time::now().toSec()-start;
	ROS_INFO("code: %d",tus.code);
	ROS_INFO("Time: %lf",msg.data);
	pub.publish(msg);
}

int main(int argc, char** argv){
	ros::init(argc,argv,"duration");
	ros::NodeHandle nh;
	pub=nh.advertise<std_msgs::Float64>("time", 1000);
	ros::Subscriber sub = nh.subscribe("keyboard/keydown",1000,callback);
	ros::Subscriber sub2 = nh.subscribe("keyboard/keyup",1000,callback2);

	ros::Rate loop_rate(50);
	while(ros::ok()){
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;

}
