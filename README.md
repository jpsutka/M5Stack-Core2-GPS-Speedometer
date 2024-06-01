# GPS Integration with M5Stack

This project demonstrates how to integrate the Beitian BN-220 GPS module with a M5Stack. The image below shows the connection setup.

## Components

- **Beitian BN-220 GPS Module**
- **M5Stack Core 2**

## Connections

The following table lists the connections between the GPS module and the M5Stack:

| GPS Module Pin | M5Stack Core 2 Pin  |
| -------------- | ------------------- |
| TX             | T                   |
| RX             | R                   |
| VCC            | VCC                 |
| GND            | GND                 |

### Connection Diagram

![Connection Diagram](./image.jpg)

In the image above, you can see the connections highlighted:
- **Green wire** (TX) connects to the **T** pin of the microcontroller.
- **White wire** (RX) connects to the **R** pin of the microcontroller.
- **Red wire** (VCC) connects to the **VCC** pin of the microcontroller.
- **Black wire** (GND) connects to the **GND** pin of the microcontroller.

## Setup Instructions

1. Connect the GPS module to the microcontroller as shown in the image.
2. Power on the microcontroller.
3. Ensure that the GPS module has a clear view of the sky for optimal signal reception.