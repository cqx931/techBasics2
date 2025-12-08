---
title: Technical Basics II
description: Week 9
class: 
_class:
  - lead
footer: 09.12.25 | Qianxun Chen | Technical Basics II
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
  gap:.5rem;
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
  font-size:34px;
  }
---

## Technical Basics II
####  Week 9
<br>
<br>
Lecturer: Qianxun Chen

---

#### Project Idea Presentations

---

#### CD40106
- Schmitt Trigger Inverter
- 6 Not Logic Gates
- Usage: generate Square-wave, creating oscillators
![width:200px](images/not_gate.png)

![bg right width:400px](images/cd40106_inside.png)

<!-- "CD" is the family and/or manufacturer prefix -->
---
### Intergrated Circuit (IC)
![ width:400px](images/ic_notch.png)
- A tiny electronic device combining many components onto a single chip to perform complex functions
- Direction: Notch -> Face Up, on the leftside of it is pin 1
- Pin numbers increase sequentially as you move counter-clockwise away from pin 1.



---
#### Capacitor
- A temporary energy storage tank that can be charged and discharged quickly 
- Unit: F(farad) pF->nF->uF
![bg right width:600px](images/cap_symbol.png)
![ width:400px](images/capacitor_s.png)
<!-- symbol, polarized, non-polarized,unit, voltage -->
---
##### Most Common Capacitor Types

Aluminum Electrolytic Capacitors & Ceramic Capacitors 
     
<br><br><br>
![bg width:500px](images/cap_alu.webp)
Polarized...................................Non-polirized 
- Voltage Rating: the maximum voltage a capacitor can safely handle (Usually twice the working voltage)
![bg width:400px](images/cap_cera.webp)



<!-- there are many types.... -->
---
#### Exercise 1: Blinking LED with CD40106
- List of components:
  - 1 Red LED
  - 2 10k resistors
  - 1 Capacitor (100uF or 47uF)
  - 1 IC: CD40106
<!-- capacitor and IC they receive from me, 47uF is faster

a resistor and capacitor to form an oscillator. The capacitor charges and discharges in a loop, creating a square wave signal that toggles the LED on and off. This setup is simple but highlights how the CD40106 can be applied to create timing circuits. Once built, it’s easy to adjust the blinking speed by changing the values of the resistor or capacitor.
 -->
---
#### Exercise 1
Power from Arduino 5V <br> is also okay 
<br><br><br><br><br><br><br>

![bg width:560px](images/cd40106_schematic.png)
![bg width:700px](images/cd40106_breadboard.png)

<!-- break -->


---
#### Exercise 3: Perfboarding

![ bg width:500px](images/perfboard.png)
![ bg width:500px](images/perf.jpg)
<br><br><br>
Perfboards
- One sided / double sided(Front and back are connected)
- (Don't heat the pads for too long, the cooper might come off)
---
##### Components
- IC Socket: easier replacement and to prevent heat damage to the chip during soldering
- Screw Terminal: More stable connection

![bg right width:300px](images/ic_socket.png)
![bg right width:300px](images/screw_terminals.png)

---
#### Perfboarding: General Principles
- Transfer from breadboard to perfboard: <br> IC -> flat components(resistors) -> higher components(capacitors, LEDs, screw terminals)...
* Place the coomponent -> solder component to the pads -> make connections
* Three ways to make a connection: 
  - use components leg (metal wire)
  - neighboring pads can be joined by solder
  - extra wires 
<!-- need some good planning with component legs -->
---
##### Step 1: Solder the IC Socket
<br><br><br><br><br><br><br><br><br><br><br><br>

![bg width:400px](images/step1.jpg)
![bg width:400px](images/step2.jpg)
<!-- place it first, the terminal is larger than the IC,so the lower two points are not used -->

---
##### Step 2: Solder Resistors

<br><br><br><br><br><br><br><br><br><br><br><br>
![bg width:400px](images/step3.jpg)
![bg width:400px](images/step4.jpg)

---
##### Step 3: Add LED and Capacitor
<br><br><br><br><br><br><br><br><br><br><br><br>
![bg width:400px](images/step5.jpg)
![bg width:400px](images/step6.jpg)

---
##### Step 4: Add connections for power
<br><br><br><br><br><br><br><br><br><br><br><br>
<!-- sample result -->
![bg width:500px](images/step7.jpg)

---

#### Challenge: Blinking 2 LEDs
- How to blink a red LED and a green LED alternately using a CD40106?
* Hint: Feed the output signal of the red LED to the input signal of the green LED

---
##### Solution
<br><br><br><br>
![bg width:600px](images/2leds_s.png)
![bg width:450px](images/2leds_c.png)
Use a 1 kΩ resistor for the green LED to match the brightness level of the red LED.

---

#### Solder Two Wires Together
If you need to solder two wires together, check this out:
https://www.youtube.com/watch?v=4xUBRMgcVhc