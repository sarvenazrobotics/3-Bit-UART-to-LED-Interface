# 3-Bit UART-to-LED Controller

![ATmega328P UART-to-LED Schematic](image.png)

A lightweight embedded system that receives 3-bit binary input via UART and controls three LEDs in real time using an ATmega328P microcontroller.

## 📌 Overview

This project demonstrates serial communication and GPIO control on the ATmega328P. The user sends a 3-character sequence of `'0'`s and `'1'`s through a serial terminal. Upon pressing **Enter**, the microcontroller updates the states of three LEDs connected to **Port D pins 2, 3, and 4** (PD2–PD4).

- **Input**: ASCII `'0'`/`'1'` via UART (9600 baud, 8N1)
- **Output**: Three LEDs representing a 3-bit binary pattern
- **Target**: Educational use in embedded systems labs or microcontroller prototyping

## 🧪 Features

- Real-time LED state update after valid input
- Input validation (only `'0'` and `'1'` accepted)
- Safe bit masking to prevent unintended port changes
- Terminal feedback for user confirmation
- Compatible with Proteus simulation or real hardware (e.g., Arduino Uno)

## 🔧 Hardware Setup

| Component        | Connection              |
|------------------|-------------------------|
| Microcontroller  | ATmega328P              |
| LED 1 (Bit 0)    | PD2 → Resistor → GND    |
| LED 2 (Bit 1)    | PD3 → Resistor → GND    |
| LED 3 (Bit 2)    | PD4 → Resistor → GND    |
| UART (Debug I/O) | TX → Pin D1, RX → Pin D0|

> 💡 **Note**: LEDs are active-HIGH (turn on when pin = `1`).

## 💻 Software

### Dependencies
- AVR-GCC toolchain
- `mega328p.h`, `delay.h`, `alcd.h` (or compatible headers)
- UART terminal (e.g., Tera Term, PuTTY, Arduino Serial Monitor, Proteus Virtual Terminal)

### Example Usage

1. Flash the firmware to an ATmega328P.
2. Open a serial terminal at **9600 baud**.
3. Send a 3-bit pattern followed by **Enter**:

```text
101

Expected result:

LED on PD2 → ON
LED on PD3 → OFF
LED on PD4 → ON
The terminal will respond:

Buffer Updated: 101

