## 2 ways PWM Generator between 7 to 25V using an Attiny 85 and power mosfets

#### Part list :
- 1 Attiny 85
- 1 7805 (and maybe some capacitors to go with it, i haven't include them in the schematic)
- 2 mosfets (IRF3205 in my case)(They are not logic level so it's not a good choice)
- 2 potentiometer
- 1 push button (optional)
- 2 diodes (to prevent reverse voltage when driving DC motors)
- Some connectors
- Something to program the Attiny (I use an Arduino uno as ISP)

#### Schematic
![schematic](/schematic/PWMGenerator.png)

#### How to build and install
Build only :
```
make
```

Build and install :
```
make install
```
