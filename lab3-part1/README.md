Authors: Laura Camp, Ryan Nyborg, Megan Lubbers
NetIDs: lauracamp, rnyborg, meglubbers
Date: 3/3/2017
Project Name: lab3-part1

# Description
In this lab, you will work in a **team** of four people. Since this is the case, the code given to you is extremely minimal. You will work together to create an alarm that goes off when an accelerometer sense an acceleration that is too large. This alarm can be turned off by the press and release of a switch.

## Expected Outcome
[![lab3-part1-outcome](https://storage.googleapis.com/ece-gitlab/lab3-part1-outcome.png)](https://onedrive.live.com/embed?cid=09B553F15839C65B&resid=9B553F15839C65B%2195003&authkey=AEgE_M8N9Y2MRNI)

# Instructions

## Alarm
First, to create an alarm you will need to use PWM in a unique way. An alarm sounds like a "chirp" which is a signal that sweeps linearly in frequency between a low and high frequency. Your alarm is required to sweep roughly from 24 kHz to 2 kHz in 100 milliseconds. The alarm will sweep repeatedly from 24 kHz to 2 kHz while starting over at 24 kHz each time.

## Accelerometer
Second, you need to be able to determine the acceleration detected by the accelerometer on 3 axes. This will require using the ADC to sample three analog signals and interpreting their meaning in the digital domain. You are required to sample the analog values coming from the accelerometer once every millisecond.

## All Together Now
Lastly, the alarm should by default be "off." When the accelerometer reaches a defined threshold, the alarm will turn on. The threshold should be such that when the accelerometer is lightly dropped as in the video, the alarm goes off. When the alarm is on, pressing and release the switch should turn off the alarm.

# Rubric
![Lab 3 Part 1](https://storage.googleapis.com/ece-gitlab/lab3-part1-rubric.png)
