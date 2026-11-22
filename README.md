# Photoresistor LED Controller

## Description

This Arduino project uses a **photoresistor (LDR)** to detect the amount of light around the sensor and control the blinking speed of the Arduino's built-in LED.
![Uploading image.png…]()


The Arduino continuously reads the light level and adjusts the LED delay dynamically. The current light value and calculated delay are also displayed through the Serial Monitor.

## Components

* Arduino board
* Photoresistor (LDR)
* Resistor
* Jumper wires
* Built-in LED

## Pin Connections

| Component     | Arduino Pin   |
| ------------- | ------------- |
| Photoresistor | A0            |
| Built-in LED  | `LED_BUILTIN` |

## How It Works

1. The photoresistor is connected to **A0**.
2. The Arduino reads the sensor using `analogRead()`.
3. The program keeps track of the minimum and maximum light readings.
4. The `map()` function converts the light reading into a delay between:

   * **50 ms** minimum delay
   * **500 ms** maximum delay
5. The built-in LED turns ON for the calculated delay.
6. The LED turns OFF for the same delay.
7. The process repeats continuously.

This makes the LED's blinking speed respond to changes in the surrounding light.

## Serial Monitor

The program uses a baud rate of **9600**.

Example output:

```text
Light Value:523 Delay Value:250
Light Value:600 Delay Value:210
Light Value:300 Delay Value:400
```

* **Light Value** — The value read from the photoresistor.
* **Delay Value** — The calculated LED delay in milliseconds.

## Important Variables

```cpp
const byte Photo_Resistor = A0;
unsigned const int Max_Delay = 500;
unsigned const int Mini_Delay = 50;
```

* `Photo_Resistor` — Defines the sensor input pin.
* `Max_Delay` — Sets the longest LED delay.
* `Mini_Delay` — Sets the shortest LED delay.

## Main Functions

* `analogRead()` — Reads the photoresistor's analog value.
* `map()` — Converts the sensor value into a delay range.
* `digitalWrite()` — Turns the built-in LED ON or OFF.
* `Serial.print()` — Displays sensor information.
* `delay()` — Controls how long the LED stays ON and OFF.

## Purpose

The project demonstrates how an Arduino can use a **light sensor as an input** and use that information to control an **LED as an output**. It also demonstrates analog input, variable mapping, serial communication, and dynamic timing.
