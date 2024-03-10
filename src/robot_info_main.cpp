#include "robot_info_class.cpp"
#include "ros/node_handle.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;

  RobotInfo robot_info(&nh, "Model X", "123ABC", "192.169.1.0", "v1");

  ros::Rate loop_rate(1); // 1 Hz

  while (ros::ok()) {
    robot_info.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}