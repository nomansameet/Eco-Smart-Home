# Eco-Smart-Home
-> Project Description:
This project is a smart home automation system built using IoT (Internet of Things) technology. It helps control basic household appliances like fans, lights, and garden watering using a smartphone app. The system is designed to save energy and water, making homes more efficient and eco-friendly.
We used the ESP32 microcontroller, which connects to Wi-Fi and controls the devices through a relay module. The garden is watered automatically using a moisture sensor, which checks the soil and waters only when needed. Everything can also be controlled manually via the Blynk app on a mobile phone.

-> Working (Step-by-Step):

1.Wi-Fi Connection:
The ESP32 connects to your home Wi-Fi so it can communicate with your smartphone app(Change the credentials
 according to the code).

2.Mobile Control:
Using the Blynk app, you can turn ON/OFF devices like fans and lights from anywhere using your phone.

3.Relay Module:
A 4-channel relay acts like a switch. When ESP32 gets a signal from the app, it tells the relay to turn the device ON or OFF.

4.Smart Garden Watering:
A moisture sensor is placed in the soil. It checks the moisture level:

- If the soil is dry → the ESP32 turns ON the motor to water the plants.
- If the soil is wet → it keeps the motor OFF to save water.

5.Power Supply:
The whole system is powered using a battery, making it portable and safe during power cuts.
