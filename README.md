# FDF

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments. The coordinates of this landscape are stored in a file passed as a parameter to your program.

*Read this in other languages: [English](README.md), [Русский](README-ru.md).*

#### Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Controls](#controls)
- [Map]
- [Examples](#examples)

## Requirements

Mac OS El Capitan / Sierra / High Sierra / Linux

## Installation

```bash
git clone https://github.com/pprivalov/FDF.git ~/fdf
cd ~/fdf
make && ./fdf test_maps/42.fdf
```

## Controls

Rotations: W/A - around X
           S/D - around Y
           Q/E - around Z
Move: Arrows
Scale: +/- scale
       X - On/Off scale along axis X
       C - On/Off scale along axis Y
       Z - On/Off scale along axis Z
Change color: NUM4/NUM1 - red color
              NUM5/NUM2 - green color
              NUM6/NUM3 - blue color
Return to basic: R
Reset all paramaters: Backspace
Close window: ESC

## Map

#### Each number corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.
- Rows must have same number of values.
- Values must be integer.

For example:
``` 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
```

## Examples

### 42.fdf
![screen shot 2018-05-01 at 15 02 57](https://user-images.githubusercontent.com/25153772/39473116-ddde08fe-4d55-11e8-8203-0ecff0f8ddb2.png)
### pylone.fdf
![screen shot 2018-05-01 at 15 08 03](https://user-images.githubusercontent.com/25153772/39473117-ddf8e5fc-4d55-11e8-849f-014fd893b0ae.png)
### mars.fdf
![screen shot 2018-05-01 at 15 33 48](https://user-images.githubusercontent.com/25153772/39473118-de2cad9c-4d55-11e8-8098-5305aaf9f195.png)
