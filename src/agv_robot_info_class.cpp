#include "robot_info/agv_robot_info_class.h"
#include "robotinfo_msgs/RobotInfo10Fields.h"

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh, const std::string &description,
                           const std::string &serial, const std::string &ip,
                           const std::string &firmware,
                           const std::string &payload,
                           const std::string &temperature,
                           const std::string &fillLevel,
                           const std::string &pressure)
    : RobotInfo(nh, description, serial, ip, firmware),
      hydraulicSystem(temperature, fillLevel, pressure),
      maximum_payload(payload) {}

void AGVRobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

  //   RobotInfo::publish_data();
  msg.data_field_01 = "robot_description: " + robot_description;
  msg.data_field_02 = "serial_number: " + serial_number;
  msg.data_field_03 = "ip_address: " + ip_address;
  msg.data_field_04 = "firmware_version: " + firmware_version;
  msg.data_field_05 = "maximum_payload: " + maximum_payload + " Kg";
  msg.data_field_06 =
      "hydraulic_oil_temperature: " + hydraulicSystem.getTemperature() + "C";
  msg.data_field_07 =
      "hydraulic_oil_tank_fill_level: " + hydraulicSystem.getFillLevel() + "%";
  msg.data_field_08 =
      "hydraulic_oil_pressure: " + hydraulicSystem.getPressure() + " bar";

  //   msg.data_field_09 = "";
  //   msg.data_field_10 = "";

  pub_.publish(msg);
}
