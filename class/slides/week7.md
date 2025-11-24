---
title: Technical Basics II
description: Week 7
class: 
_class:
  - lead
footer: 25.11.25 | Qianxun Chen | Technical Basics II
_footer: ""
paginate: false
_paginate: false
theme: uncover
size: 16:9
marp: true
style: |
  .columns {
  display:grid;
  grid-template-columns: repeat(2, minmax(0,1fr));
  gap:1rem;
  }
  .columns div {
  vertical-align: center;
  }
  .caption {
    font-size:24px;
    color:grey;
    letter-spacing:0.05em;
  }
  .image_cap {
    z-index:100;
    position: absolute;
    top: 500px;
    left:600px;
  }
  table {
  font-size:28px;
  }
  li {
  font-size:36px;
  }
---

## Technical Basics II
####  Week 7
<br>
<br>
Lecturer: Qianxun Chen

---

### Soldering Basics: Tools
* Soldering Iron
* Solder
* Helping hand
* (Soldering Paste)
* (Desoldering pump/wig)
---

##### Soldering Tutorial for Beginners: Five Easy Steps
https://www.youtube.com/watch?v=Qps9woUGkvI

<!-- 350 celsius -->
---

![bg width:700px](images/solder.jpg)

---

#### Each group takes
- A soldering station
- A helping hand
- Some solder

---
#### Exercise 1 Solder the DC Motor
Steps
1. Take two wires, one in red, one in black
1. Cut off the pins from one side
1. Expose 3mm of cooper and twist the cooper together
1. Put solder onto the wires and the soldering points
1. Solder things together
1. Check connections

---

![width:600px](images/motor_soldered.jpg)
<!-- try to expose as little wire as possible -->

[Intro to Soldering](https://www.instructables.com/Intro-to-Soldering/)

---

### DC Motors
- Usages: toy cars, robotics, fans...
- If you missed the class this week, you can solder your dc motor in the digital media lab

![width:300px](images/dc.jpg)

---
### Motor Comparison

|  | Servos | Stepper Motors| DC Motors|
| ------ | ------ | ------ | ------ |
| Control System | no feedback| high precision | precise control
| Speed and Torque |  High torque at low speeds | good at dynamic tasks with speed changes | High speed
|Applications | Low-speed, high-precision tasks |Dynamic, high-performance tasks | High-speed applications

---
<div class="columns">

<div>

### Diode
![ width:400px](images/diode.png)

* We put a diode between the + and the - of a DC motor to protect the control electronics from voltage spikes  

<!-- When the motor's power is suddenly switched off, the collapsing magnetic field in the motor's coils generates a high voltage that would normally be absorbed by the control components like transistors, potentially damaging them. -->
</div>

<div>

![width:500px](images/diode_meme.jpg)
<p class="caption">From Cil's gist contribution</p>

</div>
</div>

---
### Transistor
- A semiconductor device used to switch or amplify electrical signals and power
- NPN/PNP: direction of current flow is different

![width:700px](images/pnp-npn.jpg)

<!-- npn is more common, emitterisconnected to ground-->
---
#### Transistor
- <b>Collector (C)</b> collects the majority of the charge carriers that are emitted from the emitter.
- <b>Base (B)</b>This is the control terminal. A small current or voltage at the base can control a larger current flow between the collector and emitter.
- <b>Emitter (E)</b> emits the charge carriers (electrons in an NPN transistor) into the base

---
#### Exercise 2 DC Motor Transistor + Diode
- NPN transistor: 2N2222

<br><br><br><br><br><br><br><br><br>

![bg width:620px](images/motor_image.png)
![bg width:500px](images/motor_s.png)

- Fallback: use 5v on arduino instead

---
- Try to control the DC motor with `digitalWrite()` 
* Then try to control it with `analogWrite()`
* The DC Motor needs around 100/255 duty cycle for minimum requirement to rotate
* If it has a hard time to start rotating in low speed, a short kick at full duty cycle would help
```cpp
analogWrite(pin, 255);
delay(100);
analogWrite(pin, 128);
```

---
<!-- analogWrite 100 -->
<!-- digital high/low -->
<!-- break -->
#### Break

---

#### Exercise 3 Button as a Toggle Switch
1. Add a potentiometer to control the DC motor speed.
Use `map()` to convert the potentiometer’s analog value to the speed range required by the motor

2. Add a button that toggles the motor state:
– If the motor is running, pressing the button stops it
– If the motor is stopped, pressing the button starts it
Hint: seperate button and on/off state
<!-- previous  -->
---

![bg width:900px](images/e3.png)

---

### Gear Motors
slower but more powerful

<br><br><br><br><br><br><br><br><br>

![bg width:500px](images/gear_dc.jpg)

![bg width:300px](images/n20.jpg)

---

#### DC Motor Controllers
- Dual H-Bridge motor controller
- L293D (Elegoo Starter Kit)
https://www.youtube.com/watch?v=fPLEncYrl4Q
- Other popular controllers: L298N, TB6612fng
<!-- usually we control a dc motor with a controller -->

---
### Mosfet

![width:600px](images/mosfet.jpg)

<!-- 
In general you can replace the resistor in our control circuit with a mosfet, the legs will be a bit different

Gate, Source, and Drain: A MOSFET has at least three terminals: the gate (G), source (S), and drain (D).
Voltage Control: A voltage is applied between the gate and source terminals. This voltage controls the conductivity, or "resistance," between the drain and source terminals. 

how much voltage you give to the gate is the most important factor
-->
---
#### How mofet/transistor works?
https://www.youtube.com/shorts/FdYaVhaLNVE

---

#### Relay
![width:200px](images/relay.jpg)
![width:300px](images/relay_module.png)

![bg right width:500px](images/relay_intro.png)

<!-- relay module 
using arduino to control the coil-->

---

##### Demo

![width:800px](images/relay_demo.webp)

---

### Switches

|  | Transistors | Mosfets| Relay|
| ------ | ------ | ------ | ------ |
| Mechanism | current controlled | voltage controlled | electromechanical
| Connections | no guarantee of a complete shutoff || Completely disconnected
| Speed |  fast | fast | Slow
|Common Applications | Low-power DC | High-power DC | AC

---
### Final Project

Sign up for initial presentation slots: [sheet](https://leuphanalg-my.sharepoint.com/:x:/r/personal/qianxun_chen_leuphana_de/Documents/2025_26%20WiSe/Technical%20Basics%20II_2025_26.xlsx?d=w5ecffadd71d543a785a077e473ea42bd&csf=1&web=1&e=LzYRWF)