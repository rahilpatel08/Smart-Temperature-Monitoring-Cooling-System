# 🌡️ CoolSense
### Arduino-Based Smart Temperature Monitoring & Cooling System

An intelligent temperature-based automatic cooling system built using **Arduino Uno** and simulated on **Tinkercad**.  
The system reads real-time temperature data, displays it on an LCD, and automatically controls fan speed using PWM — all based on predefined temperature thresholds.

---

## 📌 Project Overview

This is my second Arduino project, built as a natural progression from my first — the Temperature Monitoring System.  
While the first project focused on alerts, this one adds **automatic control** — the system doesn't just warn you, it actually responds by adjusting fan speed.  
Adding an LCD display, a transistor-driven DC motor, and PWM control made this significantly more complex — and significantly more rewarding.

---

## 🛠️ Components Used

| Component | Quantity |
|---|---|
| Arduino Uno | 1 |
| TMP36 Temperature Sensor | 1 |
| 16x2 LCD Display | 1 |
| DC Motor (Fan) | 1 |
| NPN Transistor (Motor Driver) | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Resistors (LEDs + Transistor Base) | As required |
| Breadboard | 1 |
| Jumper Wires | As required |
| USB Power Supply (via Arduino) | 1 |

---

## ⚙️ How It Works

The Arduino continuously reads the analog output of the TMP36 sensor and converts it to temperature in °C.  
The current temperature and fan status are displayed live on the 16x2 LCD.  
The fan is controlled through an NPN transistor using PWM output from **Arduino Pin 5**.  
Fan speed is controlled via **PWM (Pulse Width Modulation)** through a transistor-driven DC motor circuit.

Based on the temperature reading, the system responds as follows:

| Temperature Range | LED | Fan Speed | PWM Value | LCD Display |
|---|---|---|---|---|
| Below 30°C | 🟢 Green ON | OFF | 0 | Fan: OFF |
| 30°C – 35°C | 🟡 Yellow ON | LOW | 80 | Fan: SLOW |
| 35°C – 40°C | 🔴 Red ON | MEDIUM | 170 | Fan: MEDIUM |
| Above 40°C | 🔴 Red ON | MAXIMUM | 255 | Fan: MAX |

I tested all four states by manually adjusting the TMP36 temperature value inside Tinkercad's simulation panel and verifying the LCD output, LED response, and motor behavior in real time.

---

## 🖼️ Circuit Diagram

![Circuit Diagram](circuit.PNG)

---

## 📷 System Operation

### Normal Temperature (<30°C)
![Normal](normal-operation.PNG)

### Moderate Temperature (30°C – 35°C)
![Slow Fan](slow-fan.PNG)

### High Temperature (35°C – 40°C)
![Medium Fan](medium-fan.PNG)

### Critical Temperature (>40°C)
![Max Fan](max-fan.PNG)

---

## 📂 Project Files

- `smart_fan_controller.ino` → Arduino source code
- `README.md` → Project documentation
- `circuit.png` → Circuit diagram
- `normal-operation.png` → Normal temperature state
- `slow-fan.png` → Low speed fan state
- `medium-fan.png` → Medium speed fan state
- `max-fan.png` → Maximum speed fan state

---

## 🐛 Challenges Faced & Debugging Journey

This project was more complex than the first — more components, more wiring, more things that could go wrong.  
Here's what I ran into and how I solved it.

---

### ❌ Issue 1 — Understanding Transistor Pin Connections

The NPN transistor (used to drive the DC motor) has three terminals: Collector, Base, and Emitter.  
I initially struggled to understand which terminal connects where and how the transistor actually controls the motor current.

After studying the circuit more carefully, it clicked:
- The **Base** receives the PWM signal from the Arduino (through a resistor)
- The **Collector** connects to the motor
- The **Emitter** connects to ground
- The Arduino signal at the Base controls how much current flows through the Collector → motor circuit

**Fix:** Once the terminal roles were clear, the motor started responding correctly to PWM signals.

---

### ❌ Issue 2 — LCD Showing Blank Display

After wiring the 16x2 LCD, the display remained completely blank despite the code running correctly.

The issue was incorrect wiring of the LCD's data and control pins. The `LiquidCrystal` library expects pins to be connected in a specific order, and a single misplaced wire caused the entire display to fail.

**Fix:** Re-verified every pin connection against the LCD datasheet and corrected the wiring. Display worked immediately after.

---

### ❌ Issue 3 — Flyback Diode Placement Confusion

DC motors generate voltage spikes when they turn off (back EMF). A flyback diode is placed across the motor to protect the circuit from these spikes.

Understanding where exactly to place the diode — and in which direction — was confusing during simulation.

**Fix:** Researched the concept of back EMF and flyback protection. Placing the diode in reverse bias across the motor terminals (cathode to positive, anode to negative) resolved the confusion.

> **Key lesson:** Every component in a motor circuit has a reason. The flyback diode isn't optional — it protects the transistor and Arduino from voltage spikes that could damage the circuit.

---

### ❌ Issue 4 — Inconsistent Motor Speed in Tinkercad Simulation

While testing PWM control, the Tinkercad motor simulation sometimes showed inconsistent speed behavior — the motor didn't always respond predictably to different PWM values.

**Fix:** This was a Tinkercad simulation limitation rather than a code or wiring error. I verified the PWM values through Serial Monitor output and confirmed the logic was correct. The behavior would be more consistent on real hardware.

> **Key lesson:** Simulation tools have limitations. Always verify logic through Serial Monitor or additional debugging, not just visual behavior.

---

## 💡 What I Learned

This project taught me how multiple hardware components can work together in an embedded system.

I learned how to read analog sensor values, control output devices like LEDs, LCDs, and motors, and use PWM for variable speed control.

I also gained practical experience with transistor-based motor driving, LCD interfacing, flyback diode protection, and systematic debugging of both hardware and software issues.

Most importantly — I learned to think about the **purpose of each connection** instead of simply following a circuit diagram.  
That shift in thinking made the entire debugging process faster and more intuitive.

---

## 📝 A Personal Note

Coming from my first project, I thought this one would feel easier.  
It didn't — it introduced entirely new concepts: transistors, PWM, LCD interfacing, motor protection.  
But that's exactly what made it valuable.  
Every new component came with a new question, and every question led to a deeper understanding of how embedded systems actually work beneath the surface.

---

## 🚀 Future Improvements

- Replace the NPN transistor with an L293D motor driver IC for better motor control
- Add a potentiometer to let the user manually set temperature thresholds
- Include a buzzer alert when temperature exceeds a critical limit
- Build the physical circuit on actual hardware instead of simulation
- Add data logging to track temperature and fan speed over time

---

## 🔧 Simulation Tool

Built and tested on **[Tinkercad](https://www.tinkercad.com/)** — a free browser-based electronics simulation platform.  
No physical hardware required to run this project.

---

## 👤 Author

**Rahil Patel**  
ENC '29 — Thapar Institute of Engineering & Technology  
[LinkedIn](https://www.linkedin.com/in/) | [GitHub](https://github.com/)

---

*Second Arduino project. Each one teaches something the last one didn't.*
