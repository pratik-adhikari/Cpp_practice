#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include "ros/ros.h"
#include <string>

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle *nh, std::string description, std::string serial,
            std::string ip, std::string firmware)
      : robot_description(description), serial_number(serial), ip_address(ip),
        firmware_version(firmware) {
    // publisher
    pub_ = nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
  }

  virtual void publish_data() {
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;
    msg.data_field_05 = "";
    msg.data_field_06 = "";
    msg.data_field_07 = "";
    msg.data_field_08 = "";
    msg.data_field_09 = "";
    msg.data_field_10 = "";
    pub_.publish(msg);
  }

protected:
  ros::Publisher pub_;
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;
};