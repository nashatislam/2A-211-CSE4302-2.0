#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TASK 01
class SmartDevice{
protected:

    string deviceID;
    string brandName;
    float powerRating;

public:

    SmartDevice(string a, string b, float c) : deviceID(a), brandName(b), powerRating(c)
    {}

    virtual void diagnose() const = 0;

    float getPowerRating() const{

        return powerRating;
    }

    void displayInfo() const {
        cout << "Device ID: " << deviceID << "\nBrand: " << brandName << "\nPower Rating: " << powerRating << " watts\n";
    }
};

// TASK 02
class ThermostatDevice : public SmartDevice{
protected:

    float minTemprange;
    float maxTemprange;
    string mode;

public:
    ThermostatDevice(string a, string b, float c, float d, float e, string f) : SmartDevice(a, b, c), minTemprange(d), maxTemprange(e), mode(f)
    {}

    virtual float calculatePowerConsumption(float hours) const{

        return powerRating * hours;
    }

    void diagnose() const override{

        cout << "Temperature Range: " << minTemprange << " C - " << maxTemprange << " C\nMode: " << mode << endl;
    }
};

class SecurityCameraDevice : public SmartDevice{
protected:

    string resolution;
    float recordingHours;
    const float dataperHour = 5.00; //GB

public:

    SecurityCameraDevice(string a, string b, float c, string d, float e) : SmartDevice(a, b, c), resolution(d), recordingHours(e)
    {}

    float calculateDataUsage(float days) const
    {
        return recordingHours * days * dataperHour;
    }

    void diagnose() const override{

        cout << "Resolution: " << resolution << "\nRecording Hours: " << recordingHours << " per day" << endl;
    }
};

// TASK 03
class SmartThermostat : public virtual ThermostatDevice{
private:

    bool remoteControlEnabled;

public:
    SmartThermostat(string a, string b, float c, float d, float e, string f, bool g) : ThermostatDevice(a, b, c, d, e, f), remoteControlEnabled(g)
    {}

    float calculatePowerConsumption(float hours) const override {
        float reducedto = 0.8;

        if(remoteControlEnabled){
            return powerRating * hours * reducedto;
        }
        return powerRating * hours;
    }

    void diagnose() const override {

        ThermostatDevice::diagnose();
        if(remoteControlEnabled){
            cout << "Remote-control enabled" << endl;
        }
        else{
            cout << "Not remote-control enabled" << endl;
        }

    }
};

class HybridThermostat : public virtual ThermostatDevice, public virtual SecurityCameraDevice{
private:

    float energySavingEfficiency;
    float powerRating;

public:

    HybridThermostat(string a, string b, float c, float d, float e, string f, string g, float h, float i) : ThermostatDevice(a, b, c, d, e, f),
          SecurityCameraDevice(a, b, c, g, h), powerRating(c),
          energySavingEfficiency(i)
          {}

    float calculatePowerConsumption(float hours) const override {
        float (1 - (energySavingEfficiency / 100.0)) * powerRating * hours;
    }

    float calculateDataUsage(float days) const{

        return SecurityCameraDevice::calculateDataUsage(days) + days * 2.00; // Additional data usage for temperature control
    }

    void diagnose() const override{

        ThermostatDevice::diagnose();
        SecurityCameraDevice::diagnose();
        cout << "Energy Saving Efficiency: " << energySavingEfficiency << endl;
    }
};

// TASK 04
void sort_devices_by_power(vector <SmartDevice*> &devices){

    sort(devices.begin(), devices.end(), [](SmartDevice* a, SmartDevice* b) {
        return a->getPowerRating() > b->getPowerRating();
    });
}


int main(){
    SmartThermostat smartThermo("ST3401", "Breeze", 150, 18, 30, "cooling", true);
    HybridThermostat hybridThermo("HT8738", "EcoSmart", 200, 15, 28, "heating", "4K", 12, 25);
    SecurityCameraDevice cam("SC9762", "SecureView", 100, "1080p", 24);


    vector<SmartDevice*> devices = {&smartThermo, &cam};

    sort_devices_by_power(devices);

    cout << "Devices sorted by power rating:\n";
    for (const auto& device : devices) {
        device->displayInfo();
        cout << "\n";
    }


    return 0;

}
