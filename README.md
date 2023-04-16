# desk lamp

White LED lamp made with aluminium PCBs

| <img src="img/lamp0.jpg" width="512"> | <img src="img/lamp1.jpg" width="512"> |
|-|-|
| <img src="img/lamp2.jpg" width="512"> | <img src="img/lamp3.jpg" width="512"> |

# Serial commands (115200 baud)

```
$ screen /dev/ttyUSB1 115200

lampsh> help
commands:

blink
debug
factory reset
help
load
off
on
reset
save
set gamma {1.0-5.5}
set led {0..8} [dial{0,1,2}][:][0.00-100.00]
set leds [dial{0,1,2}][:][0.00-100.00] ... x 9
set max brightness {0.00-100.00}

```

## examples


```
lampsh> set max brightness 50.00               # set maximum brightness to 50%
lampsh> save                                   # make it permanent by saving it to eeprom
```

```
lampsh> set led 2 dial2:50.00                  # use dial2 to scale up to 50%

lampsh> set leds dial0 0 0 0 dial1 0 0 0 dial2 # drive one led/dial, each a different temp & pcb

lampsh> set leds dial0 dial1 dial2 dial0 dial1 dial2 dial0 dial1 dial2 # default setting
```

# LED PCBs are leftovers from:

https://github.com/brainsmoke/aluball

## PADAUK software:

https://github.com/brainsmoke/esp32leddriver/tree/master/firmware/pdk/softpwm

`make ADDRESS=...` each in 0..2

