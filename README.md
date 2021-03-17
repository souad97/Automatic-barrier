# Automatic-barrier
![image](https://user-images.githubusercontent.com/80831555/111530673-ddf0f400-8763-11eb-9937-7f2b1be45ab4.png)

Dans ce projet on allons simuler une barrière de parking automatisée avec Arduino. Cette maquette reprend le fonctionnement général des systèmes automatisés qui permettent l’accès aux parcs publiques que l’on trouve les dans les gares, aéroports, cinémas, supermarchés, etc.
Notre barrière s’ouvre à l’aide d’un servomoteur lorsque le capteur sonore HC-SR04 détecte une véhicule et se ferme automatiquement dans le cas contraire , a l’aide d’une afficheur LCD on va jouer sur l’affichage de messages : 
- parking is empty lorsque le parking est vide 
- Parking is full lorsque le parking est pleine 
- Incrémentation et décrémentation de place  en parallèle avec l’entrée ou sortie d’une voiture.
 
Et on a deux leds de visualisation : led rouge s’allume si la barrière est fermée est verte dans le cas inverse 

||réalisation d'une barriere automatique ||

HARDWARE : 

       - ARDUINO UNO 
       - ultrason 3
       - LCD 
       - servomotor 
       - fils de connexion 
       - 2 leds : rouge et verte 
       - cable HDMI pour l'arduino 
       - breadboard 


 ![image](https://user-images.githubusercontent.com/80831555/111506812-5054da80-874a-11eb-88f3-5d25025b71be.png)
       
![image](https://user-images.githubusercontent.com/80831555/111506888-61055080-874a-11eb-8d60-203f55b8211a.png)

![image](https://user-images.githubusercontent.com/80831555/111507344-d83ae480-874a-11eb-8c03-b249d7ac95b4.png)

![image](https://user-images.githubusercontent.com/80831555/111507494-03253880-874b-11eb-9aaa-06698b8b5afe.png)

![image](https://user-images.githubusercontent.com/80831555/111507521-0b7d7380-874b-11eb-830a-67c4a16912d0.png)

![image](https://user-images.githubusercontent.com/80831555/111507557-13d5ae80-874b-11eb-87e8-cb000b464d99.png)

![image](https://user-images.githubusercontent.com/80831555/111507611-1f28da00-874b-11eb-9199-0145206adb8f.png)

![image](https://user-images.githubusercontent.com/80831555/111507639-24862480-874b-11eb-9c38-44de79885dc2.png)


SOFTWARE : 

       - ARDUINO IDE 
       - installation de package LiquidCrystal_I2C sur IDE 
       - le code dans le fichier barriere_electronique.ino

pour plus d'explication  du code dans cette video : 
