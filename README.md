# Line Follower & Obstacle Avoidance Robot

Arduino-based car using Infrared sensors for line detection and an Ultrasonic sensor for obstacle avoidance.

This project implements an autonomous robotic car capable of following a track line and avoiding obstacles in its path. Using IR sensors for line detection and an ultrasonic sensor for distance measurement, the robot makes real-time decisions to navigate safely and smoothly.

---

## Features

### Line Following
- IR sensors detect black/white contrast.
- The robot adjusts motor movement to stay aligned with the track.

### Obstacle Avoidance
- The ultrasonic sensor measures distance ahead.
- The robot stops and reacts when an object is detected.

---

## Hardware Used

### Uno R3 (Microcontroller)
Executes the control algorithms and processes sensor inputs/outputs.

### L298 Dual H-Bridge Motor Driver
Amplifies Arduino logic signals to supply the higher current required to drive DC motors.

### Ultrasonic Sensor Module
Calculates distance using time-of-flight of ultrasonic waves for obstacle detection.

### Infrared Line/Obstacle Sensors
Detect black track lines and nearby objects using infrared reflection.

### Breadboard
A solderless prototyping board for connecting circuits.

### Jumper Wires
Used to connect sensors, modules, and the motor driver to the Arduino.

### Robot Chassis with DC Gear Motors
Provides movement and differential steering capability.

### 18650 Li-Ion Batteries
High-energy-density cells that power the entire system.

### Battery Holder
Holds and connects the 18650 batteries in series to provide the required voltage.


