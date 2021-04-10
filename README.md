# 3D_printed_manipulator-Arduino

This repo is a part of 3D printed manipulator project. Manipulator is controlled via Arduino and Android OS mobile device depending on accelerometer readings of the mobile.


There are three individual repos:
1) 3D_printed_manipulator-electronics_Eagle (with schematic and PCB project files). Link: https://github.com/Corrlie/3D_printed_manipulator-electronics_Eagle
2) 3D_printed_manipulator-Arduino (used to control microcontroller). Link: https://github.com/Corrlie/3D_printed_manipulator-Arduino
3) 3D_printed_manipulator-Android (app which reads data from accelerometter and depending on its readings sends appropirate signals to microcontroller via Bluetooth). Link: https://github.com/Corrlie/3D_printed_manipulator-Android

Description:

1) 3D_printed_manipulator-electronics_Eagle - it contains schematic and boards files. Hardware consists of several electronics components: Arduino Nano microcontroller, HC-05 Bluetooth Module, five servomechanisms (parameters of each one depend on its tasks), dc/dc converter XL4016. On the board file there are also names of all elements in polish language and author's description. 
The schematic file:


![eagle_schem](https://user-images.githubusercontent.com/63510085/110690989-dcb04c00-81e4-11eb-9b4a-f193760422bf.png)


The board file:


![eagle_brd](https://user-images.githubusercontent.com/63510085/110691061-f05bb280-81e4-11eb-9929-6754425dc542.png)


2) 3D_printed_manipulator-Arduino - with Arduino file. It controls Arduino Nano microcontroller and other electronics components used in the project. It assigns appropriate microcontrollers outputs, sets servos in initial positions, reads data via Bluetooth module and according to them - moves servomechanisms.  

3) 3D_printed_manipulator-Android - which contains files for Android OS app.

After the starting activity, there is a activity which is used to connect with the HC-05 Bluetooth module. It is shown on the picture below:


![android_turnon](https://user-images.githubusercontent.com/63510085/110690503-4d0a9d80-81e4-11eb-820e-bc8c5249210c.png)


First the app checks the availability of Bluetooth on current device. If it is available, one can turn the BT on via clicking the button "TURN BT ON". Underneath list of paired devices is shown. It is possible to connect with the HC-05 paired device. If mobile and HC-05 are connected, the second ativity appears - presented below:


![android_bt_controll](https://user-images.githubusercontent.com/63510085/110690662-7cb9a580-81e4-11eb-97f8-3f0d1a02c803.png)


This activity is used to choose manipulator's axis and send appropriate data via Bluetooth, depending on accelerometer's readings. In the top-right corner there is a help button. After pressing that button, short instruction is shown:


![android_instruction](https://user-images.githubusercontent.com/63510085/110690729-90fda280-81e4-11eb-8738-7c80b57f588d.png)


Manipulator was designed using Autodesk Fusion 360 software. It looks like on the image below:


![fusion](https://user-images.githubusercontent.com/63510085/110691694-c0f97580-81e5-11eb-82d9-848deaa2ef00.png) 


Film presenting the manipulator:
https://www.youtube.com/watch?v=UypQaZqsjMM

