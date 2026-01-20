---
title: Technical Basics II
description: Week 13
class: 
_class:
  - lead
footer: 20.01.26 | Qianxun Chen | Technical Basics II
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
  h4 {
  padding-bottom:0px;
  margin-bottom:4px;
  }
  table {
  font-size:28px;
  }
  li {
  font-size:34px;
  }
---

## Technical Basics II
####  Week 13
<br>
<br>
Lecturer: Qianxun Chen

---
#### Seven Segment Displays
<br><br><br><br><br><br><br>
![bg width:500px](images/7_segments.jpg)
![bg width:400px](images/microwave.webp)

---
#### How it works
![bg right width:200px](images/how_7_segment_works.webp)

- Seven segment displays consist of 7 LEDs(A-G), called segments, arranged in the shape of an “8”
- \+ 8th segment: DP for the decimal point
- Each segment on the display can be controlled individually, just like a regular LED.
---
#### Two Types
<br><br><br><br><br><br><br><br><br>

![bg width:600px](images/common_cath_display.webp)
![bg width:600px](images/common_an_display.webp)

<!-- similar as RGB LED, the 7-segment displays also have two types 
Cathod - A
Anode - B
-->

---
#### Exercise 1: One-digit Seven-segment Display
- 5161AS(Common Cathode)
- Library: [SevSeg](https://docs.arduino.cc/libraries/sevseg/)
- [Code](https://github.com/cqx931/techBasics2/blob/main/Week13/1_SevSeg_one_digit/1_SevSeg_one_digit.ino)

<br><br><br><br><br><br><br><br>

![bg width:190px](images/seg_pin2.png)
![bg width:600px](images/seven_segment.png)


---

#### Four-digit seven-segment display
- Miuzei: 3461BS (Common Annode)
- Elegoo: 5641AS (Common Cathode)
- [Code](https://github.com/cqx931/techBasics2/blob/main/Week13/2_SevSeg_four_digit/2_SevSeg_four_digit.ino)
![bg right width:500px](images/4_digit_how.avif)

---

#### Exercise 2: 3461BS 
The order of D1-D4 is reversed on 5641AS 

<br><br><br><br><br><br><br><br>
![bg width:800px](images/4_digit_7_seg_34.png)
![bg width:650px](images/4_digit_7_seg_34_connection.png)

<!-- Break -->
---

#### Exercise 3: 7-segent display with 74HC595
- Add 74HC595 
- A-G, DP to Q0-Q7
- Arduino: DS to pin8, STCP to pin7, SHCP to pin6
- OE to GND, CLEAR to 5V
- Library: [SevSegShift](https://github.com/bridystone/SevSegShift)
- [Code](https://github.com/cqx931/techBasics2/blob/main/Week13/3_SevSeg_shift_register/3_SevSeg_shift_register.ino)

![bg right width:700px](images/74HC595-pinout.jpg)

---

#### DHT Sensors
- DHT: Digital Humidity and Temperature (DHT11)
- Library:[DHTstable](https://github.com/RobTillaart/DHTstable/tree/master)
- Other models: DHT22, AM2302...
![bg right width:500px](images/dhts.jpg)
- Data pin to pin 5 [one can also use pin 14(A0) or other analog pins]
- [Code](https://github.com/cqx931/techBasics2/blob/main/Week13/4_DHT/4_DHT.ino)
---

#### Exercise 3: Challenge
Display sensor reading on the display

<!-- 
#### Reference
https://www.circuitbasics.com/arduino-7-segment-display-tutorial/ -->
---
#### Project Documentation and Evaluation
<!-- 3d printer is there, when to install? (next wednesday?) -->