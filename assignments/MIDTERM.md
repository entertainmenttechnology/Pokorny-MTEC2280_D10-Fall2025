# MIDTERM PROJECT: "Integrating Systems"

## WORK-IN-PROGRESS DUE 3/12

## MIDTERM DUE 3/19

Create a physical computing system that accepts user input, is processed on the MCU, and provides output to the user via actuators and indicators. 

Focus on human interaction:
- How do I use changes in the physical world as input?
- What gestures am I trying to measure?
- How do I measure them so they can be stored and processsed by the MCU?
- How do I control the current state of the system?
	- What is my "algorithm" or "recipe" for processing input into output?
		- What do I need the software to keep track of at any given moment?
		- What is my intended order of events?
		- How do I implement that in C/C++ for Arduino?    
- What electronic components do I need in my circuit?
- What is my intended output. What is the "result" of this process?

	
**Must include at least one instance of the following:**   
**HARDWARE:**          
-  At least one analog sensor:
    - potentiometer
	- LDR / photocell
- At least one digital input:
    - button
- At least one analog output:
    - LED PWM
    - Piezo Buzzer
    - Servo Motor
- At least one digital output:
    - LED         
    
**SOFTWARE:**
- digitalRead()
- digitalWrite()
- analogRead()
- analogWrite()
- use of declared variables
- use of array[]
- conditional statement [IF/ELSE]
- logical operators [AND, OR, NOT, etc]
- timer using millis() instead of delay()
- For Loop implementation

NOTE: this is the minimum that must be included in final version of Midterm Project. I highly encourage you to push yourself (both technically & creatively) and include more if time allows.

Reccomendations:
- Scope the project appropriately for alloted time.     
- Prioritize compelling concepts and choices over volume.      
- Focus on the user experience. Test the device with this in mind.       
- Save often and a lot! Back up your work! Use GitHub repo and push to origin at regular intervals.      
- Serial.print() is your friend. Use it to debug your code and gain insights.       
	

## DUE DATES:

**NOTE: You must be in class to present on these dates in order to gain full credit.**

### Wednesday 3/12 - MIDTERM WIP DUE
- The project at least should compile without errors, and circuits should be tested. 
- If you are having technical issues, these should be well documented and presented so they can be addressed before the midterm final version due date.
- We will playtest in class, so you should integrate that feedback into next iteration.
- WIP should show around 4-5 hours of work at minimum.
- Save as "MIDTERM-WIP_YourName" and push to your GitHub repo before start of class
	
### Wednesday 3/19 - MIDTERM DUE
- Save your completed midterm project as "MIDTERM_YourName" and push to your GitHub repo before start of class.
