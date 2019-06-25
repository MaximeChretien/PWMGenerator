## 2 ways PWM Generator between 7 to 25V using an attiny 85 and power mosfets
<br>

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
(+12v can be replaced with any voltage between 7 and 25v)
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
