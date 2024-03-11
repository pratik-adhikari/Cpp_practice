#ifndef HYDRAULIC_SYSTEM_MONITOR_H
#define HYDRAULIC_SYSTEM_MONITOR_H
 
#include <string>

class HydraulicSystemMonitor {
public:
  HydraulicSystemMonitor(const std::string &temperature,
                         const std::string &fillLevel,
                         const std::string &pressure);

  std::string getTemperature() const;
  std::string getFillLevel() const;
  std::string getPressure() const;

private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;
};

#endif // HYDRAULIC_SYSTEM_MONITOR_H
