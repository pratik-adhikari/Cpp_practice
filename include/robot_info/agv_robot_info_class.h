#ifndef AGV_ROBOT_INFO_CLASS_H
#define AGV_ROBOT_INFO_CLASS_H

#include "hydraulic_system_monitor.h"
#include "robot_info/robot_info_class.h"
#include <string>

class AGVRobotInfo : public RobotInfo {
public:
  AGVRobotInfo(ros::NodeHandle *nh, const std::string &description,
               const std::string &serial, const std::string &ip,
               const std::string &firmware, const std::string &payload,
               const std::string &temperature, const std::string &fillLevel,
               const std::string &pressure);

  void publish_data() override; // Override the base class method

private:
  HydraulicSystemMonitor hydraulicSystem;
  std::string maximum_payload;
};

#endif // AGV_ROBOT_INFO_CLASS_H
