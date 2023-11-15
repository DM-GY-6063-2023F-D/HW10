# HW10

Display number of seconds, alternating between two representations every minute: binary and decimal.

### Wall-Second Logic

The logic I implemented for transforming ```millis()``` into wall-seconds is this:

```ellapsedSeconds = millis() / 1000;```

```wallSeconds = ellapsedSeconds % 60;```

This turns ```ellapsedSeconds``` from an unbound sequence that grows to infinity, into a sequence that cycles between 0 and 59.


### Binary

Let's look at the binary representation of some numbers between 0 and 59:

<div class="row">
  <div class="column" markdown=1>
| decimal | binary |
| --- | --- |
|  0 | 000000 |
|  1 | 000001 |
|  2 | 000010 |
|  3 | 000011 |
|  4 | 000100 |
|  5 | 000101 |
|  6 | 000110 |
|  7 | 000111 |
|  8 | 001000 |
|  9 | 001001 |
| 10 | 001010 |
| 11 | 001011 |
| 12 | 001100 |
| 13 | 001101 |
| 14 | 001110 |
| 15 | 001111 |
| ... | ... |
  
  </div>
  <div class="column" markdown=1>
  | decimal | binary |
| --- | --- |
|  0 | 000000 |
|  1 | 000001 |
|  2 | 000010 |
|  3 | 000011 |
|  4 | 000100 |
|  5 | 000101 |
|  6 | 000110 |
|  7 | 000111 |
|  8 | 001000 |
|  9 | 001001 |
| 10 | 001010 |
| 11 | 001011 |
| 12 | 001100 |
| 13 | 001101 |
| 14 | 001110 |
| 15 | 001111 |
| ... | ... |

  </div>
</div>

There's a pattern ! The right-most binary bit toggles every second, the second bit toggles every 2 seconds, the third every 4 seconds, then 8, then 16, then 32.




### Decimal

Each LED represents 10 seconds.

Those 10 seconds are mapped into analog values between 0 and 255.

For example, after 5 seconds, the first LED is half-lit; after 37 seconds, the first 3 LEDs are fully lit and the fourth is 66% lit.


### Issues, Challenges & Difficulties

One issue I faced with the *Decimal* representation is that this Arduino board only allows for 5 active PWM pins at a time. Took me a while to figure that out.

Another issue was that switching between *Decimal* and *Binary* representations required some pins to switch between being an analog output to a digital output. Apparently the Arduino doesn't like that very much and some pins would get stuck with previous values.

This was fixed by just running the ```setup()``` function every loop and resetting the ```pinMode()``` for all used pins.

### Schematic

![](./imgs/wk10-hw10-01_sch.png)

### Board

![](./imgs/wk10-hw10-01_bb.png)

Board looks different in video because I had to use a separate board to keep HW and class circuits separate :p

### Video

