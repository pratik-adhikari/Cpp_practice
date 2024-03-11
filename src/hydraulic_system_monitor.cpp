#include "robot_info/hydraulic_system_monitor.h"

HydraulicSystemMonitor::HydraulicSystemMonitor(const std::string &temperature,
                                               const std::string &fillLevel,
                                               const std::string &pressure)
    : hydraulic_oil_temperature(temperature),
      hydraulic_oil_tank_fill_level(fillLevel),
      hydraulic_oil_pressure(pressure) {}

std::string HydraulicSystemMonitor::getTemperature() const {
  return hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::getFillLevel() const {
  return hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::getPressure() const {
  return hydraulic_oil_pressure;
}
