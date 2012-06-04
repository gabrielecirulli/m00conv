# M00Conv
## About
A simple translator for my school's old PLC-based mechanical machines which don't support the format the newer machines use.
Done for a school assignment.

## Example
*Source file*:
```
(* WinCAM - EMCO [c] 1995-2001,  Programma NCDIN 66025 T       *)

N0005 G54
N0010 G95 G96 S0
N0015 G58 X0. Z0.
N0020 S130
N0025 F0.300
N0030 G0 X40. Z5.
N0035 M4
N0040 T1 D1 (* Utensile destro *)


(**#00009  Sgrossatura, formato ISO **)
N0300 G95 F0.300 G96 S130
N0305 G0 X40. Z5.
N0310 G1 X36.
N0315 Z-36.4
N0320 X38. Z-35.4
N0325 G0 Z5.
N0330 G1 X32.
N0335 Z-32.609
N0340 X34. Z-31.609
N0345 G0 Z5.
N0350 G1 X28.
N0355 Z-29.053
N0360 X30. Z-28.053
N0365 G0 Z5.
N0370 G1 X24.
N0375 Z-1.469
N0380 X26. Z-0.469
N0385 G0 Z5.
N0390 G1 X20.
N0395 Z-0.01
N0400 X22. Z0.99
N0405 G0 Z5.
N0410 G1 X16.
N0415 Z0.486
N0420 X18. Z1.486
N0425 G0 Z5.
N0430 G1 X12.
N0435 Z0.5
N0440 X14. Z1.5
N0445 G0 Z5.
N0450 G1 X8.
N0455 Z0.5
N0460 X10. Z1.5
N0465 G0 Z5.
N0470 G1 X4.
N0475 Z0.5
N0480 X6. Z1.5
N0485 G0 Z5.
N0490 G1 X40.
N0590 M30
```

*Command*:
```
m00conv source.M00 out.txt
```

*Output*:
```
%!*
    N` G`   X`     Z`   F` H
    00 21
    01 90
    02 92  0000   0000
    03 00  4000   0500
    04 00  4000   0500
    05 01  3600   0500
    06 01  3600  -3640
    07 01  3800  -3540
    08 00  3800   0500
    09 01  3200   0500
    10 01  3200  -3260
    11 01  3400  -3160
    12 00  3400   0500
    13 01  2800   0500
    14 01  2800  -2905
    15 01  3000  -2805
    16 00  3000   0500
    17 01  2400   0500
    18 01  2400  -0146
    19 01  2600  -0046
    20 00  2600   0500
    21 01  2000   0500
    22 01  2000  -0001
    23 01  2200   0099
    24 00  2200   0500
    25 01  1600   0500
    26 01  1600   0048
    27 01  1800   0148
    28 00  1800   0500
    29 01  1200   0500
    30 01  1200   0050
    31 01  1400   0150
    32 00  1400   0500
    33 01  0800   0500
    34 01  0800   0050
    35 01  1000   0150
    36M30
   M
```

## License
The code of this program is licensed under the Simplified BSD license:
```
Copyright (c) 2012, Charlie Somerville
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
```
