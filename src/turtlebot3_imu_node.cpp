#include <ros/ros.h>
#include <sensor_msgs/Imu.h>

void msgCallback(const sensor_msgs::Imu::ConstPtr& msg){
    ROS_INFO(" ");
    printf("orientation [x:%f, y:%f, z:%f, w:%f]\n", msg->orientation.x, msg->orientation.y, msg->orientation.z, msg->orientation.w);
    printf("angular_velocity [x:%f, y:%f, z:%f]\n", msg->angular_velocity.x, msg->angular_velocity.y, msg->angular_velocity.z);
    printf("linear_acceleration [x:%f, y:%f, z:%f]\n", msg->linear_acceleration.x, msg->linear_acceleration.y, msg->linear_acceleration.z);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "turtlebot3_imu");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/imu", 100, msgCallback);
    ros::spin();

    return 0;
}