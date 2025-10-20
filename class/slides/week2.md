---
title: Technical Basics II
description: Week 2
class: 
_class:
  - lead
footer: 21.10.25 | Qianxun Chen | Technical Basics II
_footer: ""
paginate: true
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
---

## Technical Basics II
####  Week 2
<br>
<br>
Lecturer: Qianxun Chen

---

#### Reminder: Registration for Exam
Deadline: 27 October 2025 (23:59)

---

### Catch up from last week
<!-- let's write the code together from scratch -->

---
### LED
* Light Emitting Diode
* long leg is +
 ![bg right width:400px](images/img-d2.png)

<!-- smd led on your arduino -->
---

#### High-power LED
- Super bright, but consumes a lot of energy

 ![bg right width:400px](images/highpower_led.jpg)
 
---
### Exercise 1
- Conect a LED to pin 13 of Arduino
- What is happening?

 ![bg right width:400px](images/led_on_arduino.jpg)

<!-- it's blinking but it's not the best way to connect a led -->

---

<div class="columns">
<div>
<br>

### Resistors


 ![width:300px](images/symbol-r.png)

 ![width:300px](images/r_inside.jpg)
</div>

<div>

 ![width:200px](images/img-r.jpg) 

 <div class="caption"> THT <br>
Through Hole Technology
</div>

 ![width:200px](images/img-r-smd.jpg)



<div class="caption"> SMD <br>
Surface Mount Devices
</div>
</div>
<!--  -->

---
### Resistor Color Code

![](images/r-farbcode.png)

<!-- 
The colours on a resistor follow a particular set of rules. There can be 4-band/5-band resisotrs. But they all have multiplier & thetolerance.If you takea look at your resistor bag, you will find they are 5-band resistors and they all have colour brown on one side and that's the tolerance.

you also have this on this paper in your starter kit. take a 1k resistor.

according to this color code how should a 1k 5-band resisotr look like? (brown, black, black, brown + tolerance)
-->
---

### Breadboard

![width:700px](images/Breadboard.jpg)

<!-- power rails, in the middle is the component area -->

---
#### How to place a component on a breadboard

![width:800px](images/resistors-on-breadboard.png)

<!-- you shouldn't put different legs of one component along the connected holes, the green area are places where you can put other components that shall be connected to this leg -->

---
### Wires
- Jumper Wires
- Types: M/M, M/F, F/F
- Good habits: red wire for +, black wire for -

![bg right width:600px](images/wires.jpg)

<!-- easier to debug! -->
---
#### What you should NEVER do
- Directly connecting the + and - 
-> short circuit (potentially break baords/components)

---
#### Exercise 2: 
220Ω Resistor
![width:600px](images/Arduino-LED.png)

<!-- if we connect the orange line to 5v from arduino, led is always on -->

---

![width:600px](images/Arduino-Blink-LED-schematic.png)

---

### GND
- The circuit's common ground, acting as a zero-volt reference and a return path for current.
- In a direct current (DC) circuit, the negative (-) terminal is often designated as the "ground"

---

### How to power your breadboard
- Arduino
- Power supply module
- Battery / power source

---

![](images/power_supply.jpg)

<!-- 
Break, later Theory -->

---

|  | Symbol | Unit | 
| ------ | ------ | ------ |
| Voltage |    V | Volt, V |
| Current  |  I | Amp, A |
| Resistance  |  R | Ohm, Ω |

![bg right width:500px](images/ohms-law-meme.jpg)

<!-- If we take water as an metaphor for electricity, Voltage is like water preasure, resistance related to the size of the tube, while current is the amount of water that actually flows in the tube.-->

---
![width:600px](images/ohms-triangle.jpg)

<!-- power is useful if you need to use a battery and wants to decide the battery you needs to use  -->
---
Why do we use a 220 Ohm resistor earlier?
* For current limiting
* 5 = I * 220
* 0.02A(20mA) is a safe current for common LEDs
<!-- feel free to change it to 330, the light will become dimmer,200-500 range is good -->
---
### Direct Current vs Alternating Current

![width:1000px](images/dc_ac.jpeg)

<!--
DC: Smaller devices, stable, simple to design circuits
AC: More practical in long distance power transmission, easier to change voltage -->

---
### Common Voltages for DC
- For Microcontrollers: 5v, 3.3v
- 9v 
- 12v

<!--  
In arduino we are dealing mostly with 5v, older technologies, more robust but more power consumption
3.3V for modern microcontrollers, lower power consumption 

If sth is supposed to work with 12v, a lower voltage of 9v might be able to still make it work, but the other way around will be dangerous
-->
---


![width:900px](images/svp.png)
<!-- series: shared current, devided voltage
parallel: shared voltage: devided current -->
---
<!-- 
No arduino,
vcc stands for voltage common collector
It is the positive supply voltage for an electronic circuit

-->
#### Exercise 3
- Power your breadboard with the power supply module
- Set it on 5v
- Practice parralel/series circuit with two LEDs on breadboard

![bg right width:600px](images/series_parralel.svg)


---

#### Exercise 4
- Connect one red, one yellow, and one green LED to pin 2,3,4 on your Arduino
- Coding: Write a program to make the LEDs shine simultaneously and then in sequence.


<!-- Break -->

---
### RGB LED
![width:150px](images/rgbled.gif)

---
![width:600px](images/RGB_types.png)

---
### In our case: Common Cathode
![width:600px](images/RGB_cathode_inside.png)

---
#### Exercise 5
- How will you connect this RGB LED to arduino?
- How many resistors do you need?
- First use the same code as Exercise 4
---
<!-- we can't share one led among them. because led in different colors requires different amount of voltage -->
![width:700px](images/RGB_schematic_arduino.png)

---

![width:700px](images/RGB_Arduino.png)

---
#### Challenge 
- Write a  `setRGB()` function that accepts RGB values to change color freely
- Use it to modify the RGB LED to different colors

```cpp
void setRGB(int redValue, int greenValue, int blueValue) {

}
```
