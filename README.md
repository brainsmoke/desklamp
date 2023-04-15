# desk lamp

White LED lamp made with aluminium PCBs

| <img src="img/lamp0.jpg" width="512"> | <img src="img/lamp1.jpg" width="512"> |
|-|-|
| <img src="img/lamp2.jpg" width="512"> | <img src="img/lamp3.jpg" width="512"> |

# Serial commands (115200 baud)

```
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
set gamma {1.0..5.5}
set led {0..8} [dial{0,1,2}][:]{0..65535}
set leds [dial{0,1,2}][:]{0..65535} ... x 9
set max brightness {0..65535}

```

# LED PCBs are leftovers from:

https://github.com/brainsmoke/aluball

## PADAUK software:

https://github.com/brainsmoke/esp32leddriver/tree/master/firmware/pdk/softpwm

`make ADDRESS=...` each in 0..2

