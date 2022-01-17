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

There is also an extra script to debug the code with 

## Algorithm explanation

Il codice va bene fino a m = 4/5

### Phisical background

### Algorithm description

## Examples