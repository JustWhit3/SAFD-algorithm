# SAFD (Spherical Armonics Function Developer)

## Table of contents

- [Introduction](#Introduction)
- [Repository structure](#repository-structure)
- [Run the program](#run-the-program)
  - [Download](#download)
  - [Prerequisites](#prerequisites)
  - [Compilation](#compilation)
  - [Running](#running)
- [Algorithm explanation](#algorithm-explanation)
  - [Phisical background](#phisical-background)
  - [Algorithm description](#algorithm-description)
- [Examples](#examples)

## Introduction

This program computes the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients of a function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> development in a spherical harmonics convergent series, by using a standard mathematical [algorithm](#algorithm-description).

> **NOTE**: equations are displayed in green color in order to be correctly visualized in normal and dark mode.

> **NOTE 2**: the current version of the algorithm works well for values of m = 4/5

## Repository structure

Here is shown the diagram structure of the repository:

```txt
SAFD-agorithm/
├── include/
│   ├── aliases.hpp
│   ├── utils.hpp
│   ├── functions.hpp
├── src/
│   ├── utils.cpp
│   ├── functions.cpp
│   ├── main.cpp
├── scripts/
│   ├── debug.sh
├── test/
│   ├── test_utils.cpp
│   ├── test_functions.cpp
│── README.md
│── License
│── .gitignore
│── CITATION.cff
│── makefile
```

## Run the program

### Download

To download the library you can proceed in two independent ways.

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/SAFD-algorithm) of the repository and click on the upper right green button called `Code`. Then click on `Download ZIP` and wait the download to be completed.

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link
### Prerequisites

To correclty compile and run the program you need some prerequisite installed in your device:

- A `g++` compiler.
- The [`exprtk`](https://github.com/ArashPartow/exprtk) library, to correctly parse the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function.
- My [`osmanip`](https://github.com/JustWhit3/osmanip) library, for the output-stream color of the program.
- Optional: the [`doctest`](https://github.com/doctest/doctest) library, to run tests.
- Optional: [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) programs to run the debugging script.

### Compilation

Once you have downloaded the repository, enter the directory through the terminal and type:

```shell
make bin/main
```

to compile the source code.

> **NOTE**: the compilation will be a bit slow, due to the use of the parsing commands, taken from the [`exprtk`](https://github.com/ArashPartow/exprtk) library.

Optionally, you can compile also the test code with this command:

```shell
make bin/main
```

If you want to compile both them in one step:

```shell
make
```

This compilation step should be performed only once.
### Running

To run the code you can simply enter this command in the shell:

```shell
./bin/main
```

Extra information about how to move inside the command line, once you have ran the code can be found in the [Examples](#examples) section.

If you want to run the tests also, you have to enter:

```shell
./bin/test
```

There is also an extra script to debug the code using [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck), which can be used with this command:

```shell
./script/debug.sh
```

> **NOTE**: pay attention when running this script with `memcheck` tool, since it may produce fake errors related to the included libraries. In this case you should prepare a suppression file before running it.

## Algorithm explanation

### Phisical background

Spherical harmonics are simultaneously eigenfunctions of both the module of the angular momentum and of its arbitrary component along an axis.

They are a family of infinite functions, called <img src="https://render.githubusercontent.com/render/math?math=\color{green}{Y^{m}_{l}(\theta,\phi)}">, which depend only on the two angles (defined in the spherical transformation of coordinates) and in which *l* and *m* are are integers which satisfy this relation: <img src="https://render.githubusercontent.com/render/math?math=\color{green}{l \geq 0}"> and <img src="https://render.githubusercontent.com/render/math?math=\color{green}{\left| m \right| \leq l}">.

They can construct an orthonormal basis for any other function depending on the same variables; this means that each function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> can be developed into a spherical harmonics convergent series:

<img src="https://latex.codecogs.com/svg.image?\color{DarkGreen}f(\theta,\phi)=\sum^{\infty}_{l=0}\sum^{l}_{m=-l}&space;f_{m,l}&space;\cdot&space;Y^{m}_{l}(\theta,\phi)" title="\color{DarkGreen}f(\theta,\phi)=\sum^{\infty}_{l=0}\sum^{l}_{m=-l} f_{m,l} \cdot Y^{m}_{l}(\theta,\phi)" />

where the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients can be written as:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}f_{m,l}=\int^{2\pi}_{0}\int^{\pi}_{0}f(\theta,&space;\phi)&space;\cdot&space;\bar{Y}^{m}_{l}(\theta,\phi)&space;\cdot&space;\sin(\theta)&space;\&space;d\theta&space;d\phi}" title="{\color{DarkGreen}f_{m,l}=\int^{2\pi}_{0}\int^{\pi}_{0}f(\theta, \phi) \cdot \bar{Y}^{m}_{l}(\theta,\phi) \cdot \sin(\theta) \ d\theta d\phi}" />

Where the spherical harmonics <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> are defined as follows:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;Y^{m}_{l}(\theta,\phi)&space;=&space;-1^{\frac{m&plus;&space;\left|&space;m&space;\right|}{2}&space;}&space;\cdot&space;\sqrt{\frac{(2l&plus;1)\cdot&space;(l-&space;\left|&space;m&space;\right|)!}{4&space;\pi&space;\cdot&space;(l&plus;&space;\left|&space;m&space;\right|)!}}&space;\cdot&space;P^{\left|&space;m&space;\right|}_{l}(\cos\theta)&space;\cdot&space;\exp(im\phi)}" title="{\color{DarkGreen} Y^{m}_{l}(\theta,\phi) = -1^{\frac{m+ \left| m \right|}{2} } \cdot \sqrt{\frac{(2l+1)\cdot (l- \left| m \right|)!}{4 \pi \cdot (l+ \left| m \right|)!}} \cdot P^{\left| m \right|}_{l}(\cos\theta) \cdot \exp(im\phi)}" />

where *i* is the imaginary unit and <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P^{\left| m \right|}_{l}}"> are the **Legendre associated functions**, defined in the interval *[-1,1]* for the *x* variable:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}P_{\alpha}^{\beta}(x)=(1-x^2)^{\frac{\beta}{2}}\frac{d^\beta}{dx^\beta}P_\alpha&space;(x)}" title="{\color{DarkGreen}P_{\alpha}^{\beta}(x)=(1-x^2)^{\frac{\beta}{2}}\frac{d^\beta}{dx^\beta}P_\alpha (x)}" />

with <img src="https://render.githubusercontent.com/render/math?math=\color{green}{\alpha \geq \beta \geq 0}">. The <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P_{\alpha}}"> polynomials are called **Legendre polynomials** and are defined by the following recursive relation:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;P_{\alpha&space;&plus;1}(x)=\frac{2\alpha&plus;1}{\alpha&plus;1}xP_{\alpha}(x)-\frac{\alpha}{\alpha&plus;1}P_{\alpha-1}(x)}" title="{\color{DarkGreen} P_{\alpha +1}(x)=\frac{2\alpha+1}{\alpha+1}xP_{\alpha}(x)-\frac{\alpha}{\alpha+1}P_{\alpha-1}(x)}" />

they are also defined in *[-1,1]* and have <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P_{0}(x)=1}">.

### Algorithm description

Il codice va bene fino a m = 4/5

## Examples