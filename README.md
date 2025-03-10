# 42-c4-miniRT

![Norminette](https://github.com/Muktim/42-c4-miniRT/actions/workflows/norminette.yml/badge.svg)


## Project about bouncing lights and shadows

### TODO

-
- 
- 

---

### Objects recognizing

A - ambient light
C - camear
L - point light
pl - plane object
sp - sphere object
cy - cylinder object


### Testing Library:
- https://github.com/ThrowTheSwitch

### Bonus
- http://raytracerchallenge.com/bonus/texture-mapping.html

### Specific Exit codes:
-1 -> Error AC is not correct number

-2 -> Filename too short

-3 -> Wrong file extension

-4 -> We do not have permission to open the file (specifically checking for O_RDONLY)

-5 -> AV or lux was not passed to Parse section

-6 -> Given .rt file is empty

-7 -> lux is not passed to given function

-8 -> Error encountered in the .rt file (i.e. unknown or missing arguments)

---

## knowledgebase

### XYZ

Blender uses a right-angled “Cartesian” coordinate system with the Z axis pointing upwards.

X axis: Left-   /   Right+

Y axis: Front+  /   Back-

Z axis: Top-    /   Bottom+

### Spesific termins

| name | data type | description |
|------|------------|------------|
|origin|tuple 4x1|Position vector [x, y, z, 1]|
|v_orient|typle 4x1|Direction vector [x, y, z, 0]|
|transform|matrix 4x4|Transform matrix|

---

## DOCUMENTATION

---

## Linear Algebra cheat sheet
<https://betterexplained.com/articles/linear-algebra-guide/>

## read more about dots
<https://betterexplained.com/articles/vector-calculus-understanding-the-dot-product/>

## minilibx doc
<https://harm-smits.github.io/42docs/libs/minilibx/events.html>
<https://harm-smits.github.io/42docs/libs/minilibx/prototypes.html#mlx_get_data_addr>

## XPM example
<https://raw.githubusercontent.com/filestar/File-Type-Sample-Repository/refs/heads/master/xpm/sample.xpm>

## READ PPM
<https://www.cs.rhodes.edu/welshc/COMP141_F16/ppmReader.html>


