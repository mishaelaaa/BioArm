# BioArm
## "𝘍𝘳𝘦𝘦𝘥𝘰𝘮 𝘰𝘧 𝘮𝘰𝘷𝘦𝘮𝘦𝘯𝘵."

The first robotic prosthesis in Bulgaria, offering the full set of functionalities of the user. 
What distinguishes us : 

- Young team; 
- Motivated future engineers;
- On first place for us are the consumers;
- We using technologies that are easily accessible;
- ✨Magic ✨

## Conception

- Foreign companies offering their services on the Balkan Peninsula are strictly specialized in the medical field of this device, having no focus on the mechanics, electronics and freedom that programming of such a device can give;
- Our realization is at a much lower cost than medical prostheses of the same size;
- Our lightweight 3D-printed protesis is robust enough to perform normal daily routine movements such as holding utensils, handshakes and more;

## Features

- To broaden our horizons and not limit ourselves to prosthetics of upper limbs;
- We provide a solution to the problem - how users will feel what they are touching;

Now a little more technical information. What we use:
### Hardware 

- [Arduino Uno Rev3](https://store.arduino.cc/products/arduino-uno-rev3) 
- [Raspberry Pi Zero WH](https://www.generationrobots.com/en/403184-complete-raspberry-pi-zero-wh-starter-kit.html)
- [Servo motor with metal gears](https://www.electronicevolution.bg/bg-product-details-44.html)
- [Raise3D Premium PETG Filament](https://www.raise3d.com/products/r3d-premium-petg-filament/)
- [ Muscle signal sensor EMG Sensor for Arduino](https://www.ebay.co.uk/itm/194943771025?hash=item2d638de191:g:pEoAAOSwarliQpKL)
- [SEN-12969](https://www.tme.eu/bg/details/sf-sen-12969/drugi-datchitsi/sparkfun-electronics-inc/sen-12969/)

> If you want to power your system from the mains please take into account that there will most likely be noise / interference at a frequency of 50 Hz

### 3D 

- [Silicone grease](https://www.servina.net/stroitelna-himiya/spreyove-i-smazki/gres-silikonova-cx80-40gr-za-plastmasa-i-guma-cx033-2br-34555.html)
- [InMoov](http://inmoov.fr/inmoov-stl-parts-viewer/?bodyparts=Right-Hand) - We use the InMoov project. From here you can access the .stl files

### Software

BioArm's software is built from several layers. 
> The first layer only cares about reading the information from the sensors and directly controlling the motors;
> Then we have a layer that is only interested in whether there is communication between the microcontroller and the computer;
> Then there is a layer that sends the information to ML, which separates the noises from the useful signal. We do this to ensure that we receive the maximum amount of useful information.
> After receiving the output from ml, we go through math operations to determine the rotation angle, then send the information to the lower layers.

- [Arduino IDE](https://www.arduino.cc/en/software) - This software can be used with any Arduino board.
- [PyCharm](https://www.jetbrains.com/pycharm/download/#section=windows) - IDE, distributed by JetBrain, for Python. An open-source version is available as PyCharm Community Edition, and a proprietary version as PyCharm Professional Edition. 
- [Notepad++](https://notepad-plus-plus.org/downloads/) - Notepad++ is a text and source code editor for use with Microsoft Windows.
- [Jupyter](https://jupyter.org/install) - Jupyter Notebook is a web-based interactive computational environment for creating notebook documents. 

## License
Apache License 2.0