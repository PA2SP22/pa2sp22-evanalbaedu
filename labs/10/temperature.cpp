#include "temperature.h"

// CLASS FUNCTION DEFINITIONS GO HERE
void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
    kelvin_ = ((5.0 * (fahrenheit - 32.0)) / 9.0) + 273.15;
}

double Temperature::GetTempAsKelvin() const {
    return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
    return kelvin_ - 273.15;
}

double Temperature::GetTempAsFahrenheit() const {
    return ((GetTempAsCelsius() * 9.0) / 5.0) + 32.0;
}

string Temperature::ToString(char unit) const {
    stringstream s;
    unit = toupper(unit);
    if (unit == 'K') {
        s << std::fixed << std::setprecision(2) << GetTempAsKelvin() << " Kelvin";
    } else if (unit == 'C') {
        s << std::fixed << std::setprecision(2) << GetTempAsCelsius() << " Celsius";
    } else if (unit == 'F') {
        s << std::fixed << std::setprecision(2) << GetTempAsFahrenheit() << " Fahrenheit";   
    } else {
        s << "Invalid Unit";
    } 
    
    return s.str();
}
