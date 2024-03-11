#ifndef ROBOT_INFO_CLASS_H
#define ROBOT_INFO_CLASS_H

#include "robotinfo_msgs/RobotInfo10Fields.h"
#include "ros/node_handle.h"
#include <string>

class RobotInfo {
public:
  RobotInfo(ros::NodeHandle *nh, const std::string &description,
            const std::string &serial, const std::string &ip,
            const std::string &firmware);

  virtual ~RobotInfo();

  virtual void publish_data();

protected:
  ros::Publisher pub_;
  std::string robot_description;
  std::string serial_number;
  std::string ip_address;
  std::string firmware_version;
};

#endif // ROBOT_INFO_CLASS_H
