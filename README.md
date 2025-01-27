This repo implements a service to connect an ESP32 to Apple HomeKit using the [HomeSpan](https://github.com/HomeSpan/HomeSpan) library.

The code can be built using [Platform.io](platform.io) from inside [Visual Studio Code](https://code.visualstudio.com)

# Flashing
- Pull latest code from github branch `main` 
- Use platform.io to "Upload" code to ESP32
# Device Config Mode
- Hold control button for 3 seconds to to enter device configuration mode
- Status LED will blink quickly when entering config mode and then a single blink to indicate option 1 in the config
- Press the control button two times to get to the wifi setup option. The light should blink three times to indicate wifi setup is selected
- Press and hold the control button for 3 seconds to activate the wifi setup
# Wifi setup
- Go to wifi settings on your mobile device and select the "Homespan-Setup" network with the password "homespan".
- When the wifi network portal opens, select the wifi network to use and enter the password. 
- Once successfully connected the portal will show the option to enter a new setup code. Changing this code is necessary if you are setting up more than one device on the same wifi network.
# Config Setup Code
- Multiple ESP32s will need separate setup codes
- They can be configured from this menu or changed in device config mode. 
- To keep the default setup code do not enter a code and press continue
- The ESP32 will restart and be connected to the wifi
# Pairing with Apple Home
- Open Apple Home and press "Add Accessory"
- Enter the proper Setup Code and assign the bridge and connected lights to their correct zone and name them appropriately.


# Troubleshooting
## Erasing Pairing
- Pairing problem can occur if the bridge(ESP32) is removed from Apple home when not connected to wifi. The bridge may still think its paired with Apple Home and cannot be readded. 
- - Option 4 in the Device Config mode will unpair the bridge from Apple Home and allow it to be readded.
## Wifi Connectivity
- Wifi credentials can be removed from the bridge by using Option 4 in Device Config mode
## Advanced
- Using platformIO to "Monitor" the ESP32 can be used to inspect and control the ESP32 (bridge) and run configuration options as well as debug any issues with connectivity.


# Relevant Docs
[Device Configuration Mode](https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md#device-configuration-mode)

[Wifi Credentials and Setup Code](https://github.com/HomeSpan/HomeSpan/blob/master/docs/UserGuide.md#setting-homespans-wifi-credentials-and-setup-code)

[Getting Started](https://github.com/HomeSpan/HomeSpan/blob/master/docs/GettingStarted.md)