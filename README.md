# 🚗 Line Follower & Obstacle Avoidance Robot

An **Arduino-based autonomous robotic car** that follows a line using **infrared sensors** and avoids obstacles using an **ultrasonic sensor**.  
The robot processes sensor data in real time to make movement decisions such as moving forward, turning left/right, or stopping.

---

## 📌 Project Overview

This project implements a smart robotic car capable of:

- Following a black line on a contrasting surface
- Detecting obstacles ahead
- Stopping safely when an object is too close
- Making smooth directional corrections using differential motor control

The system combines **IR line detection** with **distance averaging** from an ultrasonic sensor to reduce noise and improve stability.

---

## ✨ Features

### 🔹 Line Following
- Uses **two IR sensors** (left & right)
- Detects black/white contrast using a configurable threshold
- Adjusts motor movement to stay aligned with the track

### 🔹 Obstacle Avoidance
- Uses an **ultrasonic sensor** to measure distance
- Applies a moving average filter to ultrasonic readings
- Stops the robot when an obstacle is detected within a safe range

### 🔹 Motor Control
- Controlled via an **L298 Dual H-Bridge** motor driver
- Independent control of left and right motors
- PWM speed control using Arduino pins

---

## 🧠 Control Logic

| Left IR | Right IR | UV (Ultrasonic) | Action |
|--------|----------|------------------|--------|
| Black  | Black    | Safe (> 50 cm)   | Move Forward |
| Black  | White    | Safe (> 50 cm)   | Turn Left |
| White  | Black    | Safe (> 50 cm)   | Turn Right |
| White  | White    | Safe (> 50 cm)   | Stop |
| —      | —        | Obstacle < 50 cm | Stop |


---

## 🔌 Pin Configuration

### 🛞 Motor Driver (L298)

| Function | Arduino Pin |
|--------|-------------|
| IN1 | 7 |
| IN2 | 4 |
| IN3 | 5 |
| IN4 | 6 |
| ENA | 9 |
| ENB | 8 |

### 📡 Ultrasonic Sensor

| Function | Arduino Pin |
|--------|-------------|
| Trig | 3 |
| Echo | 2 |

### 👁️ IR Sensors

| Sensor | Arduino Pin |
|------|-------------|
| Left IR | A5 |
| Right IR | A0 |

---

## ⚙️ Constants Used

```cpp
const int NUM_READINGS      = 5;     // Ultrasonic averaging
const int MOTOR_SPEED       = 255;   // Max motor speed
const int IR_THRESHOLD      = 150;   // Black/white threshold
const int OBSTACLE_DISTANCE = 50;    // Stop distance (cm)
```

## 🧩 Hardware Components

Arduino Uno R3 – Main microcontroller

L298 Dual H-Bridge Motor Driver – Drives DC motors

Ultrasonic Sensor (HC-SR04) – Obstacle detection

Infrared Line Sensors (2x) – Line tracking

Robot Chassis with DC Gear Motors

Breadboard & Jumper Wires

18650 Li-Ion Batteries + Holder

## 🚀 How It Works

IR sensors continuously read surface color values.
<p align="center">
  <img src="/Images/image1.png" alt="Image 1" width="250" style="margin-right:10px;"/>
  <img src="/Images/image2.png" alt="Image 2" width="240"/>
</p>

Ultrasonic sensor measures distance ahead.

Distance values are averaged to reduce noise.

If an obstacle is closer than 50 cm, the robot stops.

Otherwise, IR sensor states determine movement direction.
