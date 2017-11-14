Author: Ryan Nyborg<br>
NetID: rnyborg<br>
Date: 1/23/2017<br>
Project Name: lab0-part1

# Description
In this lab, you will familiarize yourself with using platformIO, digital output, and a simple LED circuit. You will be connecting three LEDs of different colors to the microcontroller and turning them on and off using the correct special function registers. A testLED function has been written for you so that the code you write described in led.cpp is correct, the LEDs will light up in succession.

## Expected Outcome
![Demo CountPages alpha](https://storage.googleapis.com/ece-gitlab/lab0p0.gif)

# Instructions
Examine comments in led.cpp and main.cpp in this repository and complete the described functions. You will need to create a circuit using your breadboard, jumper wires, LEDs, and resistors to control the LEDs using the microcontroller. To get started you can start with the "Hello World" projects that are linked under the Piazza resources.

## LED circuit
A standard LED connection requires that an LED be connected in series with a resistor with the anode (longer lead) connected to the power (Vdd) and one side of the resistor connected to ground. *However, we will be controlling the LEDs with the output of our pins. Therefore, replace the power connection with a connection to the pins specified below.*

## Required Connections
White LED 	-- 	RB4 <br>
Red LED		--	RB5 <br>
Yellow LED	--	RB6

*It is up to you to figure out which pin number on the microcontroller corresponds to RB4, RB5, and RB6*

# Rubric
![Lab 0 Part 1](https://storage.googleapis.com/ece-gitlab/lab0p0)
