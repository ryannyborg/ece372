Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
NetIDs: lauracamp, rnyborg, meglubbers
Date: 4/9/17
Project Name: final


# Description
In this lab, you will work in a ** team ** of four people. Since this is the case, the code given to you is extremely minimal. You will work together to control two motors using the L293D amplifier supplied in every kit. Using the potentiometer, the speed of the motors will be controlled.

## Expected Outcome
To be posted.

# Instructions
First, you will need to be able to capture an analog voltage from a potentiometer that can swing from 5V to 0V.
The digital value captured from the potentiometer will control the duty cycle of several PWM signals that control the motors. These PWMs will be connected to the L293D amplifier and this amplifier will connect to either side of the motors.

You will use two motors. The motor is controlled by a difference in voltage between its two terminals. Therefore, to get it to spin forward at full speed, it is only necessary to apply a 5V signal to one side of the motor and 0V to the other side. The reverse the direction, these voltages are switched to opposite terminals.

When the potentiometer is at its lowest point (~ 0V), only one motor will be on at full power. When the potentiometer is at its highest point (~ 5V), the other motor will be on at full power and the other one will be off. When the potentiometer is in the middle (~ 2.5V), both motors will be on at full power. This behavior emulates that of wheels turning in a car with the potentiometer being the steering wheel and the motors being the wheels.

The motors will operate in three modes: forward, reverse, and idle. You will need to connect an external switch that switches between these modes after a press and release.

# Rubric
![Lab 2](https://storage.googleapis.com/ece-gitlab/lab2_rubric.png)
