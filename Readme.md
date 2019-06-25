## 2 ways PWM Generator between 7 to 25V using an attiny 85 and power mosfets
<br>

#### Description :
The attiny is used to generate two pwm output connected to the gate of each mosfets.
The charges are connected between the input voltage and the drain of the mosfets.
Each potentiometer are used to control the duty cycle of each output.

#### Caracteristics :
- Ouput : 2 with separate duty cycles
- Input / Output voltage : 7 to 25V
- Max curent : depend on the mosfet used (around 30A for me)
- PWM Frequency : ~31 KHz
- Duty cycle : controlled by the potentiometers

#### Part list :
- 1 attiny 85
- 1 7805 (and maybe some capacitors to go with it, i haven't included them in the schematic)
- 2 mosfets (IRF3205 in my case)(They are not logic level so it's not a good choice)
- 2 potentiometer
- 1 push button (optional)
- 2 diodes (to prevent reverse voltage when driving DC motors)
- 1 100nF capacitor
- Some connectors
- Something to program the Attiny (I use an Arduino uno as ISP)
<br>

#### Schematic :
![schematic](/schematic/PWMGenerator.png)
(+12v can be replaced with any voltage between 7 and 25V)
<br>

#### How to build and flash on attiny 85 :
Go to **src** subfolder
<br>
Build only :
```
make
```

Build and flash :
<br>
Verify programmer settings in makefile and :
```
make install
```
