---
title: Technical Basics II
description: Week 13
class: 
_class:
  - lead
footer: 20.01.26 | Qianxun Chen | Technical Basics II
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
#### Exercise 1: 1-digit 
- 5161AS(Common Cathode)
- Library: [SevSeg](https://docs.arduino.cc/libraries/sevseg/)
- [Code]()
![bg right width:300px](images/seg_pin.png)

---
<!-- need to edit the image, the order of d1-d4 is reversed -->
![bg right width:600px](images/4_digit_7_seg.png)
- 4-digit 7-segent display
- 3461BS (Common Annode)

---

#### Exercise 2: 4-digit

---

<!-- Break -->



---

#### Exercise 3:  7-segent display with 74HC595
- Add 74HC595
- Add a sensor
- Display sensor reading on the display

<!-- 
#### Reference
https://www.circuitbasics.com/arduino-7-segment-display-tutorial/ -->
---
#### Project Checkups