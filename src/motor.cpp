#include <ros/ros.h>
#include "keyboard.h"
#include <geometry_msgs/Twist.h>

class TeleopDrive{
	public:
	void joyCallBack(const keyboard::Key& tus);
		TeleopDrive();
	private:
		
		ros::NodeHandle nh_;
		ros::Subscriber key_sub_;
		ros::Publisher cmd_pub_;
};

TeleopDrive::TeleopDrive(){
	key_sub_=nh_.subscribe("keyboard/keydown",10,&TeleopDrive::joyCallBack,this);
	cmd_pub_=nh_.advertise<geometry_msgs::Twist>("/cmd_vel",1);

};
void TeleopDrive::joyCallBack(const keyboard::Key& tus){
	geometry_msgs::Twist cmd_vel;
if(tus.code== 273){
	cmd_vel.linear.x=1;
	cmd_vel.linear.y=0;
	cmd_vel.linear.z=0;
	cmd_vel.angular.x=0;
	cmd_vel.angular.y=0;
	cmd_vel.angular.z=0;}
else if(tus.code==274){
	cmd_vel.linear.x=-1;
	cmd_vel.linear.y=0;
	cmd_vel.linear.z=0;
	cmd_vel.angular.x=0;
	cmd_vel.angular.y=0;
	cmd_vel.angular.z=0;
}
else if (tus.code==275){
	cmd_vel.linear.x=0;
	cmd_vel.linear.y=0;
	cmd_vel.linear.z=0;
	cmd_vel.angular.x=0;
	cmd_vel.angular.y=0;
	cmd_vel.angular.z=-1;
}
else if (tus.code==276){
	cmd_vel.linear.x=0;
	cmd_vel.linear.y=0;
	cmd_vel.linear.z=0;
	cmd_vel.angular.x=0;
	cmd_vel.angular.y=0;
	cmd_vel.angular.z=1;
}
else {
	cmd_vel.linear.x=0;
	cmd_vel.linear.y=0;
	cmd_vel.linear.z=0;
	cmd_vel.angular.x=0;
	cmd_vel.angular.y=0;
	cmd_vel.angular.z=0;
}
	
cmd_pub_.publish(cmd_vel);

};
int main(int argc,char** argv){
	ros::init(argc,argv,"teleop_drive");
	TeleopDrive teleop_drive;
	ros::spin();
}
