#include "robot_info_class.cpp"
#include "ros/node_handle.h"

class AGVRobotInfo : public RobotInfo {

public:
  AGVRobotInfo(ros::NodeHandle *nh, std::string description, std::string serial,
               std::string ip, std::string firmware, double payload)
      : RobotInfo(nh, description, serial, ip, firmware),
        maximum_payload(payload) {}

  void publish_data() override {
    robotinfo_msgs::RobotInfo10Fields msg;
    msg.data_field_01 = "robot_description: " + robot_description;
    msg.data_field_02 = "serial_number: " + serial_number;
    msg.data_field_03 = "ip_address: " + ip_address;
    msg.data_field_04 = "firmware_version: " + firmware_version;

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << maximum_payload;
    msg.data_field_05 = "maximum_payload: " + stream.str() + " Kg";

    msg.data_field_06 = "";
    msg.data_field_07 = "";
    msg.data_field_08 = "";
    msg.data_field_09 = "";
    msg.data_field_10 = "";
    pub_.publish(msg);
  }

private:
  double maximum_payload;
};
