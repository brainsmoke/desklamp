EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny1614-SS U2
U 1 1 642360DC
P 9150 2300
F 0 "U2" H 9150 3181 50  0000 C CNN
F 1 "ATtiny1624" H 9150 3090 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 9150 2300 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny1614-data-sheet-40001995A.pdf" H 9150 2300 50  0001 C CNN
	1    9150 2300
	1    0    0    -1  
$EndComp
Text GLabel 8950 1200 0    50   Input ~ 0
3V3
$Comp
L Device:R R4
U 1 1 64239BED
P 10050 1750
F 0 "R4" H 10120 1796 50  0000 L CNN
F 1 "4k7 Ohm" H 10120 1705 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 9980 1750 50  0001 C CNN
F 3 "~" H 10050 1750 50  0001 C CNN
	1    10050 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 1900 10050 1900
Text GLabel 10300 1600 2    50   Input ~ 0
UPDI_RX
Text GLabel 10300 1900 2    50   Input ~ 0
UPDI_TX
Wire Wire Line
	10050 1600 10300 1600
Wire Wire Line
	10050 1900 10300 1900
Connection ~ 10050 1900
Wire Wire Line
	9150 1600 9150 1200
Wire Wire Line
	9150 1200 8950 1200
$Comp
L power:GND #PWR06
U 1 1 6423CF83
P 9150 3250
F 0 "#PWR06" H 9150 3000 50  0001 C CNN
F 1 "GND" H 9155 3077 50  0000 C CNN
F 2 "" H 9150 3250 50  0001 C CNN
F 3 "" H 9150 3250 50  0001 C CNN
	1    9150 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9150 3000 9150 3250
$Comp
L Device:R_POT RV1
U 1 1 6423DBEC
P 8700 5650
F 0 "RV1" H 8631 5696 50  0000 R CNN
F 1 "R_POT" H 8631 5605 50  0000 R CNN
F 2 "footprints:Potentiometer_Alps_RK09L_Single_Vertical_centered" H 8700 5650 50  0001 C CNN
F 3 "~" H 8700 5650 50  0001 C CNN
	1    8700 5650
	1    0    0    -1  
$EndComp
Text GLabel 8300 2100 0    50   Input ~ 0
UART0_TX
Wire Wire Line
	8300 2100 8550 2100
Text GLabel 10300 2000 2    50   Input ~ 0
UART1_TX
Text GLabel 10300 2100 2    50   Input ~ 0
UART1_RX
Wire Wire Line
	9750 2000 10300 2000
Text GLabel 4250 2100 2    50   Input ~ 0
UPDI_TX
Text GLabel 8000 4900 0    50   Input ~ 0
3V3
$Comp
L Device:R_POT RV2
U 1 1 6424C543
P 9700 5650
F 0 "RV2" H 9631 5696 50  0000 R CNN
F 1 "R_POT" H 9631 5605 50  0000 R CNN
F 2 "footprints:Potentiometer_Alps_RK09L_Single_Vertical_centered" H 9700 5650 50  0001 C CNN
F 3 "~" H 9700 5650 50  0001 C CNN
	1    9700 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT RV3
U 1 1 6424C984
P 10700 5650
F 0 "RV3" H 10631 5696 50  0000 R CNN
F 1 "R_POT" H 10631 5605 50  0000 R CNN
F 2 "footprints:Potentiometer_Alps_RK09L_Single_Vertical_centered" H 10700 5650 50  0001 C CNN
F 3 "~" H 10700 5650 50  0001 C CNN
	1    10700 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 6425204B
P 8700 5150
F 0 "R1" H 8770 5196 50  0000 L CNN
F 1 "22K Ohm" H 8770 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 8630 5150 50  0001 C CNN
F 3 "~" H 8700 5150 50  0001 C CNN
	1    8700 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 642527B5
P 9700 5150
F 0 "R2" H 9770 5196 50  0000 L CNN
F 1 "22K Ohm" H 9770 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 9630 5150 50  0001 C CNN
F 3 "~" H 9700 5150 50  0001 C CNN
	1    9700 5150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 64252C36
P 10700 5150
F 0 "R3" H 10770 5196 50  0000 L CNN
F 1 "22K Ohm" H 10770 5105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 10630 5150 50  0001 C CNN
F 3 "~" H 10700 5150 50  0001 C CNN
	1    10700 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 5650 8850 5650
Wire Wire Line
	9900 5650 9850 5650
$Comp
L power:GND #PWR05
U 1 1 6425A428
P 8700 6000
F 0 "#PWR05" H 8700 5750 50  0001 C CNN
F 1 "GND" H 8705 5827 50  0000 C CNN
F 2 "" H 8700 6000 50  0001 C CNN
F 3 "" H 8700 6000 50  0001 C CNN
	1    8700 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR07
U 1 1 6425A7AA
P 9700 6000
F 0 "#PWR07" H 9700 5750 50  0001 C CNN
F 1 "GND" H 9705 5827 50  0000 C CNN
F 2 "" H 9700 6000 50  0001 C CNN
F 3 "" H 9700 6000 50  0001 C CNN
	1    9700 6000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 6425ABA4
P 10700 6000
F 0 "#PWR08" H 10700 5750 50  0001 C CNN
F 1 "GND" H 10705 5827 50  0000 C CNN
F 2 "" H 10700 6000 50  0001 C CNN
F 3 "" H 10700 6000 50  0001 C CNN
	1    10700 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5800 8700 5900
Wire Wire Line
	9700 5800 9700 5900
Wire Wire Line
	10700 5800 10700 5900
Wire Wire Line
	8700 5000 8700 4900
Wire Wire Line
	9700 5000 9700 4900
Wire Wire Line
	10700 5000 10700 4900
Text GLabel 9900 5650 2    50   Input ~ 0
POT1
Text GLabel 10900 5650 2    50   Input ~ 0
POT2
Text GLabel 10300 2200 2    50   Input ~ 0
POT0
Text GLabel 10300 2300 2    50   Input ~ 0
POT1
Text GLabel 10300 2400 2    50   Input ~ 0
POT2
Wire Wire Line
	9750 2200 10300 2200
Wire Wire Line
	9750 2300 10300 2300
Wire Wire Line
	9750 2400 10300 2400
$Comp
L Regulator_Linear:AP2204K-3.3 U1
U 1 1 64276A0E
P 6650 1300
F 0 "U1" H 6650 1642 50  0000 C CNN
F 1 "AP2204K-3.3" H 6650 1551 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6650 1625 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/AP2204.pdf" H 6650 1400 50  0001 C CNN
	1    6650 1300
	1    0    0    -1  
$EndComp
Text GLabel 7150 1200 2    50   Input ~ 0
3V3
Wire Wire Line
	7150 1200 7050 1200
Text GLabel 5950 1200 0    50   Input ~ 0
VIN
Wire Wire Line
	5950 1200 6100 1200
Wire Wire Line
	6350 1300 6250 1300
Wire Wire Line
	6250 1300 6250 1200
Connection ~ 6250 1200
Wire Wire Line
	6250 1200 6350 1200
$Comp
L Device:C C1
U 1 1 6427A81C
P 6100 1450
F 0 "C1" H 6215 1496 50  0000 L CNN
F 1 "1uF" H 6215 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 6138 1300 50  0001 C CNN
F 3 "~" H 6100 1450 50  0001 C CNN
	1    6100 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 6427AEBB
P 7050 1450
F 0 "C4" H 7165 1496 50  0000 L CNN
F 1 "2.2uF" H 7165 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 7088 1300 50  0001 C CNN
F 3 "~" H 7050 1450 50  0001 C CNN
	1    7050 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 6427EDB7
P 6650 1800
F 0 "#PWR03" H 6650 1550 50  0001 C CNN
F 1 "GND" H 6655 1627 50  0000 C CNN
F 2 "" H 6650 1800 50  0001 C CNN
F 3 "" H 6650 1800 50  0001 C CNN
	1    6650 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 1600 7050 1700
Wire Wire Line
	7050 1700 6650 1700
Wire Wire Line
	6100 1700 6100 1600
Wire Wire Line
	6650 1600 6650 1700
Connection ~ 6650 1700
Wire Wire Line
	6650 1700 6100 1700
Wire Wire Line
	6650 1700 6650 1800
Wire Wire Line
	6100 1300 6100 1200
Connection ~ 6100 1200
Wire Wire Line
	6100 1200 6250 1200
Wire Wire Line
	7050 1300 7050 1200
Connection ~ 7050 1200
Wire Wire Line
	7050 1200 6950 1200
$Comp
L Device:C C5
U 1 1 64285B13
P 8300 1500
F 0 "C5" H 8415 1546 50  0000 L CNN
F 1 "100nF" H 8415 1455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 8338 1350 50  0001 C CNN
F 3 "~" H 8300 1500 50  0001 C CNN
	1    8300 1500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR04
U 1 1 64288809
P 8300 1750
F 0 "#PWR04" H 8300 1500 50  0001 C CNN
F 1 "GND" H 8305 1577 50  0000 C CNN
F 2 "" H 8300 1750 50  0001 C CNN
F 3 "" H 8300 1750 50  0001 C CNN
	1    8300 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1650 8300 1750
Text GLabel 8150 1200 0    50   Input ~ 0
3V3
Wire Wire Line
	8150 1200 8300 1200
Wire Wire Line
	8300 1200 8300 1350
$Comp
L Device:CP C2
U 1 1 6428DF9F
P 8250 4000
F 0 "C2" H 8368 4046 50  0000 L CNN
F 1 "100uF" H 8368 3955 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_10x10" H 8288 3850 50  0001 C CNN
F 3 "~" H 8250 4000 50  0001 C CNN
	1    8250 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 6428EB57
P 8650 4000
F 0 "C3" H 8768 4046 50  0000 L CNN
F 1 "100uF" H 8768 3955 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_10x10" H 8688 3850 50  0001 C CNN
F 3 "~" H 8650 4000 50  0001 C CNN
	1    8650 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 6429055A
P 8650 4250
F 0 "#PWR02" H 8650 4000 50  0001 C CNN
F 1 "GND" H 8655 4077 50  0000 C CNN
F 2 "" H 8650 4250 50  0001 C CNN
F 3 "" H 8650 4250 50  0001 C CNN
	1    8650 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 4150 8650 4250
$Comp
L power:GND #PWR01
U 1 1 64293AFD
P 8250 4250
F 0 "#PWR01" H 8250 4000 50  0001 C CNN
F 1 "GND" H 8255 4077 50  0000 C CNN
F 2 "" H 8250 4250 50  0001 C CNN
F 3 "" H 8250 4250 50  0001 C CNN
	1    8250 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4150 8250 4250
Text GLabel 8100 3700 0    50   Input ~ 0
VIN
Wire Wire Line
	8100 3700 8250 3700
Wire Wire Line
	8650 3700 8650 3850
Wire Wire Line
	8250 3700 8250 3850
Connection ~ 8250 3700
Wire Wire Line
	8250 3700 8650 3700
$Comp
L ch340b:CH340B U3
U 1 1 64238EC4
P 3600 2400
F 0 "U3" H 3600 1711 50  0000 C CNN
F 1 "CH340B" H 3600 1620 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3650 1850 50  0001 L CNN
F 3 "" H 3250 3200 50  0001 C CNN
	1    3600 2400
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW1
U 1 1 6423CE9A
P 7100 5200
F 0 "SW1" H 7100 5485 50  0000 C CNN
F 1 "SW_DPDT_x2" H 7100 5394 50  0000 C CNN
F 2 "footprints:MTS-20X_DPDT" H 7100 5200 50  0001 C CNN
F 3 "~" H 7100 5200 50  0001 C CNN
	1    7100 5200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_DPDT_x2 SW1
U 2 1 6423CF4C
P 7100 5800
F 0 "SW1" H 7100 6085 50  0000 C CNN
F 1 "SW_DPDT_x2" H 7100 5994 50  0000 C CNN
F 2 "footprints:MTS-20X_DPDT" H 7100 5800 50  0001 C CNN
F 3 "~" H 7100 5800 50  0001 C CNN
	2    7100 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2100 4250 2100
Text GLabel 7500 5700 2    50   Input ~ 0
V_PSU
Text GLabel 6700 5800 0    50   Input ~ 0
VIN
$Comp
L Connector:USB_C_Receptacle_USB2.0 J1
U 1 1 6427861C
P 1100 1750
F 0 "J1" H 1207 2617 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1207 2526 50  0000 C CNN
F 2 "footprints:USB_C_Receptacle_HRO_TYPE-C-31-M-12" H 1250 1750 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1250 1750 50  0001 C CNN
	1    1100 1750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 6428C648
P 1100 2850
F 0 "#PWR0101" H 1100 2600 50  0001 C CNN
F 1 "GND" H 1105 2677 50  0000 C CNN
F 2 "" H 1100 2850 50  0001 C CNN
F 3 "" H 1100 2850 50  0001 C CNN
	1    1100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 2850 1100 2650
$Comp
L Device:R R5
U 1 1 6428F85D
P 2050 1300
F 0 "R5" V 2050 1250 50  0000 L CNN
F 1 "5k1 Ohm" V 1950 1150 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1980 1300 50  0001 C CNN
F 3 "~" H 2050 1300 50  0001 C CNN
	1    2050 1300
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 642975F3
P 2050 1500
F 0 "R6" V 2050 1450 50  0000 L CNN
F 1 "5k1 Ohm" V 1950 1350 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1980 1500 50  0001 C CNN
F 3 "~" H 2050 1500 50  0001 C CNN
	1    2050 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	1700 1350 1800 1350
Wire Wire Line
	1800 1350 1800 1300
Wire Wire Line
	1800 1300 1900 1300
Wire Wire Line
	1700 1450 1800 1450
Wire Wire Line
	1800 1450 1800 1500
Wire Wire Line
	1800 1500 1900 1500
Wire Wire Line
	2200 1300 2300 1300
Wire Wire Line
	2300 1300 2300 1500
Wire Wire Line
	2300 1500 2200 1500
$Comp
L power:GND #PWR0102
U 1 1 6429FDE0
P 2300 1600
F 0 "#PWR0102" H 2300 1350 50  0001 C CNN
F 1 "GND" H 2305 1427 50  0000 C CNN
F 2 "" H 2300 1600 50  0001 C CNN
F 3 "" H 2300 1600 50  0001 C CNN
	1    2300 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 1600 2300 1500
Connection ~ 2300 1500
Wire Wire Line
	1700 1650 1900 1650
Wire Wire Line
	1900 1650 1900 1700
Wire Wire Line
	1900 1750 1700 1750
Wire Wire Line
	1700 1850 1900 1850
Wire Wire Line
	1900 1850 1900 1900
Wire Wire Line
	1900 1950 1700 1950
Wire Wire Line
	1900 1700 2100 1700
Wire Wire Line
	2100 1700 2100 2400
Connection ~ 1900 1700
Wire Wire Line
	1900 1700 1900 1750
Wire Wire Line
	2250 2300 2250 1900
Wire Wire Line
	2250 1900 1900 1900
Connection ~ 1900 1900
Wire Wire Line
	1900 1900 1900 1950
Text GLabel 1950 1000 2    50   Input ~ 0
VUSB
Wire Wire Line
	1700 1150 1800 1150
Wire Wire Line
	1800 1150 1800 1100
Wire Wire Line
	1800 1000 1950 1000
Text GLabel 6700 4550 0    50   Input ~ 0
VUSB
Text GLabel 7500 4550 2    50   Input ~ 0
VIN
$Comp
L Device:D_Schottky D1
U 1 1 642EE55D
P 7100 4550
F 0 "D1" H 7100 4333 50  0000 C CNN
F 1 "D_Schottky" H 7100 4424 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 7100 4550 50  0001 C CNN
F 3 "~" H 7100 4550 50  0001 C CNN
	1    7100 4550
	-1   0    0    1   
$EndComp
Wire Wire Line
	7250 4550 7500 4550
Wire Wire Line
	6700 4550 6950 4550
$Comp
L Connector:Screw_Terminal_01x03 J3
U 1 1 642FAA7F
P 9600 4200
F 0 "J3" H 9680 4242 50  0000 L CNN
F 1 "Screw_Terminal_01x03" H 9680 4151 50  0000 L CNN
F 2 "TerminalBlock_Phoenix:TerminalBlock_Phoenix_PT-1,5-3-5.0-H_1x03_P5.00mm_Horizontal" H 9600 4200 50  0001 C CNN
F 3 "~" H 9600 4200 50  0001 C CNN
	1    9600 4200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 642FCCCB
P 9900 4550
F 0 "#PWR0103" H 9900 4300 50  0001 C CNN
F 1 "GND" H 9905 4377 50  0000 C CNN
F 2 "" H 9900 4550 50  0001 C CNN
F 3 "" H 9900 4550 50  0001 C CNN
	1    9900 4550
	1    0    0    -1  
$EndComp
Text GLabel 7200 3600 2    50   Input ~ 0
V_PSU
Text GLabel 10150 3750 2    50   Input ~ 0
UART0_TX
Text GLabel 10150 4100 2    50   Input ~ 0
DATA_IN
Wire Wire Line
	10150 4100 9800 4100
Text GLabel 8900 5650 2    50   Input ~ 0
POT0
$Comp
L Device:C C9
U 1 1 6433D0CA
P 8250 5150
F 0 "C9" H 8365 5196 50  0000 L CNN
F 1 "100nF" H 8365 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 8288 5000 50  0001 C CNN
F 3 "~" H 8250 5150 50  0001 C CNN
	1    8250 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 5300 8250 5900
Connection ~ 8700 5900
Wire Wire Line
	8700 5900 8700 6000
Wire Wire Line
	8250 4900 8250 5000
Wire Wire Line
	8250 4900 8700 4900
Wire Wire Line
	8000 4900 8250 4900
Connection ~ 8250 4900
$Comp
L Device:C C10
U 1 1 6439BA91
P 9250 5150
F 0 "C10" H 9365 5196 50  0000 L CNN
F 1 "100nF" H 9365 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 9288 5000 50  0001 C CNN
F 3 "~" H 9250 5150 50  0001 C CNN
	1    9250 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 5000 9250 4900
Wire Wire Line
	9250 4900 9700 4900
Wire Wire Line
	9250 5300 9250 5900
Connection ~ 9700 5900
Wire Wire Line
	9700 5900 9700 6000
Wire Wire Line
	8700 4900 9250 4900
Connection ~ 8700 4900
Connection ~ 9250 4900
$Comp
L Device:C C11
U 1 1 643BF643
P 10250 5150
F 0 "C11" H 10365 5196 50  0000 L CNN
F 1 "100nF" H 10365 5105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 10288 5000 50  0001 C CNN
F 3 "~" H 10250 5150 50  0001 C CNN
	1    10250 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 5000 10250 4900
Connection ~ 10250 4900
Wire Wire Line
	10250 4900 10700 4900
Wire Wire Line
	9700 4900 10250 4900
Connection ~ 9700 4900
Wire Wire Line
	10250 5300 10250 5900
Connection ~ 10700 5900
Wire Wire Line
	10700 5900 10700 6000
$Comp
L Device:R R7
U 1 1 643DC749
P 9900 3750
F 0 "R7" V 10000 3700 50  0000 L CNN
F 1 "68 Ohm" V 9800 3650 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 9830 3750 50  0001 C CNN
F 3 "~" H 9900 3750 50  0001 C CNN
	1    9900 3750
	0    1    1    0   
$EndComp
Text GLabel 9650 3750 0    50   Input ~ 0
DATA_IN
Wire Wire Line
	9650 3750 9750 3750
Wire Wire Line
	10050 3750 10150 3750
$Comp
L power:GND #PWR0104
U 1 1 643FB176
P 7200 3900
F 0 "#PWR0104" H 7200 3650 50  0001 C CNN
F 1 "GND" H 7205 3727 50  0000 C CNN
F 2 "" H 7200 3900 50  0001 C CNN
F 3 "" H 7200 3900 50  0001 C CNN
	1    7200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 3900 7200 3800
$Comp
L Device:C C6
U 1 1 6442DCA1
P 2550 1350
F 0 "C6" H 2665 1396 50  0000 L CNN
F 1 "1uF" H 2665 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2588 1200 50  0001 C CNN
F 3 "~" H 2550 1350 50  0001 C CNN
	1    2550 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 6442DD9D
P 2550 1600
F 0 "#PWR0105" H 2550 1350 50  0001 C CNN
F 1 "GND" H 2555 1427 50  0000 C CNN
F 2 "" H 2550 1600 50  0001 C CNN
F 3 "" H 2550 1600 50  0001 C CNN
	1    2550 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1500 2550 1600
Wire Wire Line
	2250 2300 3200 2300
Wire Wire Line
	2100 2400 3200 2400
$Comp
L Device:C C7
U 1 1 64473799
P 2800 1350
F 0 "C7" H 2915 1396 50  0000 L CNN
F 1 "100nF" H 2915 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2838 1200 50  0001 C CNN
F 3 "~" H 2800 1350 50  0001 C CNN
	1    2800 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 644737A3
P 2800 1600
F 0 "#PWR0106" H 2800 1350 50  0001 C CNN
F 1 "GND" H 2805 1427 50  0000 C CNN
F 2 "" H 2800 1600 50  0001 C CNN
F 3 "" H 2800 1600 50  0001 C CNN
	1    2800 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 1500 2800 1600
$Comp
L Device:C C8
U 1 1 6447DC74
P 3100 1350
F 0 "C8" H 3215 1396 50  0000 L CNN
F 1 "100nF" H 3215 1305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3138 1200 50  0001 C CNN
F 3 "~" H 3100 1350 50  0001 C CNN
	1    3100 1350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 6447DC7E
P 3100 1600
F 0 "#PWR0107" H 3100 1350 50  0001 C CNN
F 1 "GND" H 3105 1427 50  0000 C CNN
F 2 "" H 3100 1600 50  0001 C CNN
F 3 "" H 3100 1600 50  0001 C CNN
	1    3100 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1500 3100 1600
Wire Wire Line
	1800 1100 2550 1100
Wire Wire Line
	2550 1100 2550 1200
Connection ~ 1800 1100
Wire Wire Line
	1800 1100 1800 1000
Wire Wire Line
	2550 1100 2800 1100
Wire Wire Line
	2800 1100 2800 1200
Connection ~ 2550 1100
Wire Wire Line
	2800 1100 3600 1100
Wire Wire Line
	3600 1100 3600 1800
Connection ~ 2800 1100
Wire Wire Line
	3100 1200 3100 1150
Wire Wire Line
	3100 1150 3500 1150
Wire Wire Line
	3500 1150 3500 1800
Wire Wire Line
	4000 2000 4250 2000
Text GLabel 4250 2000 2    50   Input ~ 0
UPDI_RX
$Comp
L Device:R R8
U 1 1 644CE190
P 10050 2100
F 0 "R8" V 10150 2050 50  0000 L CNN
F 1 "1k Ohm" V 10050 2000 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 9980 2100 50  0001 C CNN
F 3 "~" H 10050 2100 50  0001 C CNN
	1    10050 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	10200 2100 10300 2100
Wire Wire Line
	9750 2100 9900 2100
$Comp
L power:GND #PWR0108
U 1 1 645432E3
P 3600 3100
F 0 "#PWR0108" H 3600 2850 50  0001 C CNN
F 1 "GND" H 3605 2927 50  0000 C CNN
F 2 "" H 3600 3100 50  0001 C CNN
F 3 "" H 3600 3100 50  0001 C CNN
	1    3600 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 3000 3600 3100
$Comp
L Connector:Barrel_Jack_Switch J2
U 1 1 6455583C
P 6750 3700
F 0 "J2" H 6807 4017 50  0000 C CNN
F 1 "Barrel_Jack_Switch" H 6807 3926 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_Horizontal" H 6800 3660 50  0001 C CNN
F 3 "~" H 6800 3660 50  0001 C CNN
	1    6750 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3600 7200 3600
Wire Wire Line
	7050 3800 7200 3800
Wire Wire Line
	6900 5800 6700 5800
Wire Wire Line
	7500 5700 7300 5700
$Comp
L ch340b:CH340B U4
U 1 1 64379E5E
P 3550 5450
F 0 "U4" H 3550 4761 50  0000 C CNN
F 1 "CH340B" H 3550 4670 50  0000 C CNN
F 2 "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm" H 3600 4900 50  0001 L CNN
F 3 "" H 3200 6250 50  0001 C CNN
	1    3550 5450
	1    0    0    -1  
$EndComp
$Comp
L Connector:USB_C_Receptacle_USB2.0 J4
U 1 1 64379E83
P 1050 4800
F 0 "J4" H 1157 5667 50  0000 C CNN
F 1 "USB_C_Receptacle_USB2.0" H 1157 5576 50  0000 C CNN
F 2 "footprints:USB_C_Receptacle_HRO_TYPE-C-31-M-12" H 1200 4800 50  0001 C CNN
F 3 "https://www.usb.org/sites/default/files/documents/usb_type-c.zip" H 1200 4800 50  0001 C CNN
	1    1050 4800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 64379E8D
P 1050 5900
F 0 "#PWR0109" H 1050 5650 50  0001 C CNN
F 1 "GND" H 1055 5727 50  0000 C CNN
F 2 "" H 1050 5900 50  0001 C CNN
F 3 "" H 1050 5900 50  0001 C CNN
	1    1050 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 5900 1050 5700
$Comp
L Device:R R9
U 1 1 64379E98
P 2000 4350
F 0 "R9" V 2000 4300 50  0000 L CNN
F 1 "5k1 Ohm" V 1900 4200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1930 4350 50  0001 C CNN
F 3 "~" H 2000 4350 50  0001 C CNN
	1    2000 4350
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 64379EA2
P 2000 4550
F 0 "R10" V 2000 4500 50  0000 L CNN
F 1 "5k1 Ohm" V 1900 4400 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad0.98x0.95mm_HandSolder" V 1930 4550 50  0001 C CNN
F 3 "~" H 2000 4550 50  0001 C CNN
	1    2000 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 4400 1750 4400
Wire Wire Line
	1750 4400 1750 4350
Wire Wire Line
	1750 4350 1850 4350
Wire Wire Line
	1650 4500 1750 4500
Wire Wire Line
	1750 4500 1750 4550
Wire Wire Line
	1750 4550 1850 4550
Wire Wire Line
	2150 4350 2250 4350
Wire Wire Line
	2250 4350 2250 4550
Wire Wire Line
	2250 4550 2150 4550
$Comp
L power:GND #PWR0110
U 1 1 64379EB5
P 2250 4650
F 0 "#PWR0110" H 2250 4400 50  0001 C CNN
F 1 "GND" H 2255 4477 50  0000 C CNN
F 2 "" H 2250 4650 50  0001 C CNN
F 3 "" H 2250 4650 50  0001 C CNN
	1    2250 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2250 4650 2250 4550
Connection ~ 2250 4550
Wire Wire Line
	1650 4700 1850 4700
Wire Wire Line
	1850 4700 1850 4750
Wire Wire Line
	1850 4800 1650 4800
Wire Wire Line
	1650 4900 1850 4900
Wire Wire Line
	1850 4900 1850 4950
Wire Wire Line
	1850 5000 1650 5000
Wire Wire Line
	1850 4750 2050 4750
Wire Wire Line
	2050 4750 2050 5450
Connection ~ 1850 4750
Wire Wire Line
	1850 4750 1850 4800
Wire Wire Line
	2200 5350 2200 4950
Wire Wire Line
	2200 4950 1850 4950
Connection ~ 1850 4950
Wire Wire Line
	1850 4950 1850 5000
Text GLabel 1900 4050 2    50   Input ~ 0
VUSB2
Wire Wire Line
	1650 4200 1750 4200
Wire Wire Line
	1750 4200 1750 4150
Wire Wire Line
	1750 4050 1900 4050
$Comp
L Device:C C12
U 1 1 64379ED3
P 2500 4400
F 0 "C12" H 2615 4446 50  0000 L CNN
F 1 "1uF" H 2615 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2538 4250 50  0001 C CNN
F 3 "~" H 2500 4400 50  0001 C CNN
	1    2500 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 64379EDD
P 2500 4650
F 0 "#PWR0111" H 2500 4400 50  0001 C CNN
F 1 "GND" H 2505 4477 50  0000 C CNN
F 2 "" H 2500 4650 50  0001 C CNN
F 3 "" H 2500 4650 50  0001 C CNN
	1    2500 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 4550 2500 4650
Wire Wire Line
	2200 5350 3150 5350
Wire Wire Line
	2050 5450 3150 5450
$Comp
L Device:C C13
U 1 1 64379EEA
P 2750 4400
F 0 "C13" H 2865 4446 50  0000 L CNN
F 1 "100nF" H 2865 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 2788 4250 50  0001 C CNN
F 3 "~" H 2750 4400 50  0001 C CNN
	1    2750 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 64379EF4
P 2750 4650
F 0 "#PWR0112" H 2750 4400 50  0001 C CNN
F 1 "GND" H 2755 4477 50  0000 C CNN
F 2 "" H 2750 4650 50  0001 C CNN
F 3 "" H 2750 4650 50  0001 C CNN
	1    2750 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4550 2750 4650
$Comp
L Device:C C14
U 1 1 64379EFF
P 3050 4400
F 0 "C14" H 3165 4446 50  0000 L CNN
F 1 "100nF" H 3165 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.08x0.95mm_HandSolder" H 3088 4250 50  0001 C CNN
F 3 "~" H 3050 4400 50  0001 C CNN
	1    3050 4400
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 64379F09
P 3050 4650
F 0 "#PWR0113" H 3050 4400 50  0001 C CNN
F 1 "GND" H 3055 4477 50  0000 C CNN
F 2 "" H 3050 4650 50  0001 C CNN
F 3 "" H 3050 4650 50  0001 C CNN
	1    3050 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 4550 3050 4650
Wire Wire Line
	1750 4150 2500 4150
Wire Wire Line
	2500 4150 2500 4250
Connection ~ 1750 4150
Wire Wire Line
	1750 4150 1750 4050
Wire Wire Line
	2500 4150 2750 4150
Wire Wire Line
	2750 4150 2750 4250
Connection ~ 2500 4150
Wire Wire Line
	2750 4150 3550 4150
Wire Wire Line
	3550 4150 3550 4850
Connection ~ 2750 4150
Wire Wire Line
	3050 4250 3050 4200
Wire Wire Line
	3050 4200 3450 4200
Wire Wire Line
	3450 4200 3450 4850
Text GLabel 4200 5050 2    50   Input ~ 0
UART1_RX
Wire Wire Line
	3950 5050 4200 5050
Text GLabel 4200 5150 2    50   Input ~ 0
UART1_TX
Wire Wire Line
	3950 5150 4200 5150
$Comp
L power:GND #PWR0114
U 1 1 64379F27
P 3550 6150
F 0 "#PWR0114" H 3550 5900 50  0001 C CNN
F 1 "GND" H 3555 5977 50  0000 C CNN
F 2 "" H 3550 6150 50  0001 C CNN
F 3 "" H 3550 6150 50  0001 C CNN
	1    3550 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 6050 3550 6150
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 643F3962
P 5100 2700
F 0 "J5" H 5072 2582 50  0000 R CNN
F 1 "Conn_01x04_Male" H 5072 2673 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 5100 2700 50  0001 C CNN
F 3 "~" H 5100 2700 50  0001 C CNN
	1    5100 2700
	-1   0    0    1   
$EndComp
Text GLabel 4650 2600 0    50   Input ~ 0
UPDI_TX
Wire Wire Line
	4900 2600 4650 2600
Wire Wire Line
	4900 2700 4650 2700
Text GLabel 4650 2700 0    50   Input ~ 0
UPDI_RX
Text GLabel 4650 2500 0    50   Input ~ 0
VUSB
Wire Wire Line
	4650 2500 4900 2500
$Comp
L power:GND #PWR0115
U 1 1 64428915
P 4650 2900
F 0 "#PWR0115" H 4650 2650 50  0001 C CNN
F 1 "GND" H 4655 2727 50  0000 C CNN
F 2 "" H 4650 2900 50  0001 C CNN
F 3 "" H 4650 2900 50  0001 C CNN
	1    4650 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2800 4650 2900
Wire Wire Line
	4650 2800 4900 2800
Wire Wire Line
	10900 5650 10850 5650
Wire Wire Line
	10250 5900 10700 5900
Wire Wire Line
	9250 5900 9700 5900
Wire Wire Line
	8250 5900 8700 5900
Wire Wire Line
	8700 5300 8700 5500
Wire Wire Line
	9700 5300 9700 5500
Wire Wire Line
	10700 5300 10700 5500
Wire Wire Line
	9800 4300 9900 4300
Wire Wire Line
	9900 4300 9900 4550
Wire Wire Line
	9950 4200 9800 4200
Text GLabel 9950 4200 2    50   Input ~ 0
VIN
$EndSCHEMATC
