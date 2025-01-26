/*********************************************************************************
 *  MIT License
 *  
 *  Copyright (c) 2020-2024 Gregg E. Berman
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 ********************************************************************************/
 
////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 6: One working on/off LED and one working     //
//            dimmable LED, both based on the LightBulb   //
//            Service                                     //
//                                                        //
////////////////////////////////////////////////////////////


#include "HomeSpan.h"
#include "LedConfig.h"

// Homekit setup code 466-37-726

#define LED_PIN 32
#define LED_PIN_TWO 33
#define LED_PIN_THREE 16
#define LED_PIN_FOUR 17
#define CONTROL_PIN 5
#define STATUS_LED_PIN 19

void setup() {
  
  Serial.begin(115200);
  homeSpan.setControlPin(CONTROL_PIN, PushButton::TRIGGER_ON_HIGH);
  homeSpan.setStatusPin(STATUS_LED_PIN);
  homeSpan.setStatusAutoOff(60);
  homeSpan.begin(Category::Bridges,"Koral Bridge");

  new SpanAccessory();                            // This first Accessory is the new "Bridge" Accessory.  It contains no functional Services, just the Accessory Information Service
    new Service::AccessoryInformation();
      new Characteristic::Identify();     
      new Characteristic::Name("Koral Bridge");

  new SpanAccessory(); 
    new Service::AccessoryInformation();    
      new Characteristic::Identify();
      new Characteristic::Name("Front");
  
    new DimmableLED(LED_PIN);        
  
  new SpanAccessory(); 
    new Service::AccessoryInformation();    
      new Characteristic::Identify();
      new Characteristic::Name("Right");

    new DimmableLED(LED_PIN_TWO);

  new SpanAccessory(); 
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Left");

    new DimmableLED(LED_PIN_THREE);

  new SpanAccessory(); 
    new Service::AccessoryInformation();    
      new Characteristic::Identify();
      new Characteristic::Name("Back");

    new DimmableLED(LED_PIN_FOUR);

} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();
  
} // end of loop()
