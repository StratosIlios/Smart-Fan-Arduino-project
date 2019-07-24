# Smart-Fan
The Smart Fan is an Arduino project. The Fan is working as long as the ultrasonic sensor is not blocked by an obstacle. In case that the sensor is blocked by an obstacle the motor is turned off and the sensor tries to avoid it. When free space is being found by the sensor, the motor is turned on again. In case that there are a lot of obstacles around the sensor, it scans continuously around the area searching for free space. The scanning covers a 180 degrees angle because the use of servo motor. 

Components that have been used:
1. 1X Arduino Uno R3 Controller Board
2. 1X Servo Motor (SG90)
3. 1X L293D
4. 1X Fan Blade and 3V DC Motor(with wire)
5. 1X Ultrasonic Sensor
6. 1X Red Led
7. 1X Green Led
8. 2X Resistors 220 Ohm
9. 4X Female-to-male Dupont wires
10. 13X 65 Jumper Wires
