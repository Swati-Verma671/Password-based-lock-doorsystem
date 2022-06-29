# Password-based-lock-doorsystem

## Introduction
This project was created using C language with Keil as the compiler and AT89C51 simulation as the microprocessor. This door system can detect the wrong and correct password and switch the motor off or on. This project was created using a calculator keypad instead as the desired letter keypad wasn't available in this version of proteus. However, there isn't much difference in the design and the code for both the design systems.

## Objective
The objective of this project was to create a more robust, time-saving, safe and better solution to the traditional door locks(the keys and lock maneuver) that have high chances of burglary and therefore put the safety of the residents and people at risk.

## Working Principle
The user enters the password through the keypad and the number pressed is stored and displayed number is kept hidden for privacy. The stored pin would be compared to the correct pin and see if the pin entered is correct or not and respond by switching the motor on or off. If the pin enterd is correct it displays the message "Correct Pin" and opens the door by switching on the motor and again displaying "Door Opened". And if the pin entered is wrong, the message displayed would be "Wrong pin".

## Circuit
![Image](password.png)
