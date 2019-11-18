#include "Bosch_Humidity_Sensor.h"

bosch_humidity sensor_101; 
void read_sensor_data()
{
	sensor_101.f_current = read_current; 
	sensor_101.f_voltage = read_voltage;
}


float read_current () 
{
	float read_current;
	read_current = READ_PIN_23 & 0x1111;
	return read_current; 
}

float read_voltage () 
{
	float read_voltage;
	read_voltage= READ_PIN_23 & 0x1111;
	return read_voltage;
}

void calculate_humidity()
{
	sensor_101.f_humidity = (float) ((2.0f / 3.0f * sensor_101.f_current << 2) * (sensor_101.f_voltage / 2.0f));
}

