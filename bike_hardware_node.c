/
Bike Sense - IoT Hardware Node Draft (C / Arduino Style)
This C code represents the physical microcontroller (e.g., ESP32, Arduino)
that would be installed on the motorcycle. It reads the physical
ignition and stand sensors and transmits the state to the web server.
*/
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
// --- Physical Pin Definitions (Mock Setup) ---
#define IGNITION_PIN 4  // GPIO pin connected to the ignition relay/sensor
#define STAND_PIN 5     // GPIO pin connected to the side stand switch
// --- Global State Variables ---
bool isIgnitionOn = false;
bool isStandDown = false;
bool previousIgnitionState = false;
bool previousStandState = false;
// --- Mock Hardware Functions ---
// In a real ESP32/Arduino, you would use digitalRead(PIN)
bool readSensor(int pin) {
// Simulating physical hardware read
// For this draft, we will just return false, but normally this reads voltage HIGH/LOW
return false;
}
// Function to simulate sending an HTTP POST or MQTT payload to your web app API
void sendDataToServer(bool ignition, bool stand) {
printf("[NETWORK] Transmitting sensor data to Bike Sense API...\n");
printf("          { "ignition_on": %s, "stand_down": %s }\n",
ignition ? "true" : "false",
stand ? "true" : "false");
// Code here would typically look like:
// HTTPClient http;
// http.begin("https://your-bikesense-api.com/update");
// http.addHeader("Content-Type", "application/json");
// http.POST("{"ignition_on": true, "stand_down": true}");
// http.end();
}
// --- Initialization ---
void setup() {
printf("Initializing Bike Sense IoT Hardware...\n");
// In Arduino, you would configure pins:
// pinMode(IGNITION_PIN, INPUT_PULLDOWN);
// pinMode(STAND_PIN, INPUT_PULLUP);
printf("Hardware initialized. Listening for sensor changes...\n\n");
}
// --- Main execution loop ---
void loop() {
// 1. Read the physical sensors
isIgnitionOn = readSensor(IGNITION_PIN);
isStandDown = readSensor(STAND_PIN);
// 2. Check if the state has changed since our last read
if (isIgnitionOn != previousIgnitionState || isStandDown != previousStandState) {
printf("[SENSOR EVENT] State Change Detected!\n");
// 3. Send the updated data to the web server
sendDataToServer(isIgnitionOn, isStandDown);
// 4. Update the stored state
previousIgnitionState = isIgnitionOn;
previousStandState = isStandDown;
}
// Sleep for a short duration to prevent CPU thrashing (e.g., delay(500) in Arduino)
sleep(1);
}
// Standard C entry point (if not using Arduino IDE)
int main() {
setup();
// Infinite loop acting as the microcontroller lifecycle
while(1) {
loop();
// For testing purposes in this C draft, let's artificially trigger a state change
printf("--- Simulating rider turning on the bike while on the stand ---\n");
isIgnitionOn = true;
isStandDown = true;
if (isIgnitionOn != previousIgnitionState || isStandDown != previousStandState) {
sendDataToServer(isIgnitionOn, isStandDown);
previousIgnitionState = isIgnitionOn;
previousStandState = isStandDown;
}
// Break out of the infinite loop just for the sake of the script ending
break;
}
return 0;
}