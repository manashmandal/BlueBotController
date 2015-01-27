# Arduino-Bluetooth Bot Controller

This is a simple arduino powered bluetooth bot controller. If you have an arduino board, a bluetooth module and a robotic chassis. You can control your robot with this application in no time. Just make proper connection with motor driver, bt module, batteries and other stuff, upload the code to your arduino board. Forget everything and enjoy a remote-control car type RF control via PC without expensive joystick or gamepad. 

## Requirements
Of course you need some equipments to test out the application by yourself! Gather the things listed below
* Arduino Board [UNO or Mega 2560, works on both]
* Bluetooth Module [HC-05 Or similar]
* Robotic Chassis [Any 2WD Chassis with motors and tires would work]
* Battery to powerup motors, bluetooth and arduino board
* Motor Driver [L293D/L298N/Ardumoto Motor Driver Shield or similar]
* Qt 4/5
* QtSerialPort Library
* Arduino IDE
* Toshiba Bluetooth Stack for Windows [Recommended for windows users but not mandatory]

## Features 

* Required COM Ports and baud rate can be selected from the list
* Both Keyboard and push button control
* Speed of the bot can be changed on the go
* Built in Arduino Source code viewer

## 

### How to use

If you have your bot ready, the application is quite easy to use. Upload the arduino code to your arduino board. Prepare the connections appropriately and then do the following things

* Establish Connection with the HC-05 Bluetooth Module and find out the COM Port

![alt text](http://i.imgur.com/3fqbutT.png "Connection and COM Port")

* Open the app, select the COM Port on which the bluetooth module is connected [If needed change the baud rate according to your configuration, if you do not know what to do then leave it as it is], press connect

![alt text](http://i.imgur.com/k359mxP.png "")

* A message will pop up, if it says connection successful, don't hesitate to press W/A/S/D on your keyboard or push the buttons to control it

![alt text](http://i.imgur.com/8K5AUqB.png "")


* On the second tab you will find the speed control button. Press the button to reduce or increase the speed of your bot

![alt text](http://i.imgur.com/d8W7jLZ.png "")

* That's it 

#### Pros
* Does not work with arduino Serial Library, it works with only SoftwareSerial library
* Pressing multiple buttons will hamper the flow of control, press one button at a time to maintain a proper control over the bot

#### A quick demo video wouldn't hurt you

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/7E7vei3Ps4A/0.jpg)](http://www.youtube.com/watch?v=7E7vei3Ps4A)


#### Close up shot of my bot

![alt text](http://i.imgur.com/2wXLkVg.jpg "")

