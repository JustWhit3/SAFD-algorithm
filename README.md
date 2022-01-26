<p align="center"><img src="https://github.com/JustWhit3/SAFD-algorithm/blob/main/img/logo.svg" height=220></p>

<h3 align="center">An algorithm to compute the coefficients of a function development in a spherical harmonics convergent series</h3>
<p align="center">
    <img title="v1.0" alt="v1.0" src="https://img.shields.io/badge/version-v1.0-informational?style=flat-square"
    <a href="LICENSE">
        <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
    </a>
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square">
    </a>
</p>

## Table of contents

- [Introduction](#introduction)
- [Repository structure](#repository-structure)
- [Documentation](#documentation)
- [How to use](#how-to-use)

## Introduction

This program computes the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients of a function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> development in a spherical harmonics convergent series, by using a standard mathematical [algorithm](#algorithm-explanation).

When running the program, you have simply to input the generic shape of the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> equation and the values of m and l and the coefficients will be calculated.

Some program features:
 - Can calculate <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients for any generic <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function, entered by the user during the program running.
 - <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients are expressed as complex numbers.
 - It works well for each negative or positive value of m, with very good accuracy until m < 5. For higher m values, the accuracy gradually decrease.

> **NOTE**: equations are displayed in green color in order to be correctly visualized in both normal and dark mode.

Output example:

<img src="https://github.com/JustWhit3/SAFD-algorithm/blob/main/img/SAFD.gif">

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

## Repository structure

Here the diagram structure of the repository:

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
├── img/
│── README.md
│── LICENSE
│── CITATION.cff
│── CREDITS.md
│── .gitignore
│── .valgrindrc
│── makefile
```

## Documentation

Extra documentation is available in the [doc](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc) folder:

- [Download, compile and run](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc/download_and_run.md): contains documentation about how to download, compile and run the program as well as a complete list of prerequisites.
- [Algorithm explanation and physical background](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc/algorithm_explanation.md): contains information about the mathematical and physical explanation related to the coefficients computation and a detailed description of the used algorithm.

## How to use

When running the program, some options are displayed:

```Shell
Available options:
   1. Display the single value of a f(m,l) coefficient.
   2. Display all the values of f(m,l) coefficients from m to 0 and from l to 0.
   3. Quit the program. 

Option choice: 
```

The first one is used to compute a single value of the coefficient <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> for a certain m and l.

The second one is used, instead, to compute all the values of <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> from m to 0 and from l to 0.

Third option explanation is trivial.

When one of the options has been chosen, an output like this will be displayed:

```Shell
Option choice: 1

Enter the f(th,phi) equation shape (avoid backspaces): 
```

You can enter the function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> shape and the values of m and l. For example:

```Shell
Enter the f(th,phi) equation shape (avoid backspaces): 3*cos(th)+pow(sin(phi),5)
Enter the value of m: 2
Enter the value of l: 3
```

and the final result is displayed with both real and imaginary parts:

```Shell
f(2,3) = 0.0546019 + -0.00160564i
```
