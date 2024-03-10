#include "agv_robot_info_class.cpp"
#include "ros/node_handle.h"
#include "ros/ros.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "agv_robot_info_node");
  ros::NodeHandle nh;

  AGVRobotInfo robot_info(&nh, "Mir100", "567A359", "169.254.5.180", "3.5.8",
                          100);

  ros::Rate loop_rate(1); // 1 Hz

  while (ros::ok()) {
    robot_info.publish_data();
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
};