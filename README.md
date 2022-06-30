<p align="center"><img src="https://github.com/JustWhit3/SAFD-algorithm/blob/main/img/logo.svg" height=220></p>

<h3 align="center">An app to compute the coefficients of a function development in a spherical harmonics convergent series</h3>
<p align="center">
    <img title="v1.1" alt="v1.1" src="https://img.shields.io/badge/version-v1.1-informational?style=flat-square"
    <a href="LICENSE">
        <img title="MIT License" alt="license" src="https://img.shields.io/badge/license-MIT-informational?style=flat-square">
    </a>
	<img title="C++17" alt="C++17" src="https://img.shields.io/badge/c++-17-informational?style=flat-square">
    </a></br>
	<img title="Code size" alt="code size" src="https://img.shields.io/github/languages/code-size/JustWhit3/SAFD-algorithm?color=red">
	<img title="Repo size" alt="repo size" src="https://img.shields.io/github/repo-size/JustWhit3/SAFD-algorithm?color=red">
	<img title="Lines of code" alt="total lines" src="https://img.shields.io/tokei/lines/github/JustWhit3/SAFD-algorithm?color=red"></br>
  <img title="codeq" alt="codeq" src="https://github.com/JustWhit3/SAFD-algorithm/actions/workflows/codeql-analysis.yml/badge.svg">
  <img title="doc" alt="doc" src="https://github.com/JustWhit3/SAFD-algorithm/actions/workflows/DocGenerator.yml/badge.svg">
</p>

## Table of contents

- [Introduction](#introduction)
- [Repository structure](#repository-structure)
- [Supported operating systems](#supported-operating-systems)
- [Install and run](#install-and-run)
- [Extra documentation](#documentation)
- [How to use](#how-to-use)
- [Credits](#credits)
  - [Project leaders](#project-leaders)
  - [Other contributors](#other-contributors)
  - [Other contributors with no GitHub account](Other-contributors-with-no-GitHub-account)

## Introduction

This program computes the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients of a function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> development in a spherical harmonics convergent series, by using a standard mathematical [algorithm](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc/algorithm_explanation.md).

When running the program, you have simply to input the generic shape of the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> equation and the values of m and l and the coefficients will be calculated.

Some program features:

 - Can calculate <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients for any generic <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function, entered by the user during the program running.
 - <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients are expressed as complex numbers.
 - It works well for each negative or positive value of m, with very good accuracy until m < 5. For higher m values, the accuracy gradually decrease.

> **NOTE**: equations are displayed in green color in order to be correctly visualized in both normal and dark mode.

Output example (terminal graphics has been produced using [`osmanip`](https://github.com/JustWhit3/osmanip)):

<img src="https://github.com/JustWhit3/SAFD-algorithm/blob/main/img/SAFD.gif">

> **NOTE**: inserted functions are plotted only in the case in which they are 1D (i.e. only one of the two angles is present in their expression) since the [`osmanip`](https://github.com/JustWhit3/osmanip) library at the moment doesn't feature 2D plotting.

The software is and will stay **free**, but if you want to support me with a donation it would be really appreciated!

<a href="https://www.buymeacoffee.com/JustWhit33" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-orange.png" alt="Buy Me A Coffee" height="41" width="174"></a>

If you want to use this software please cite it following [this](https://github.com/JustWhit3/SAFD-algorithm/tree/main/CITATION.cff) citation template file.

## Repository structure

Here the diagram structure of the repository:

```txt
SAFD-agorithm/
├── .github/
│   ├── workflows
│   │   ├── codeql-analysis.yml
│   │   ├── cDocGenerator.yml
├── include/
│   ├── utils.hpp
│   ├── functions.hpp
├── src/
│   ├── utils.cpp
│   ├── functions.cpp
│   ├── main.cpp
├── scripts/
│   ├── debug.sh
│   ├── install_dependencies.sh
│   ├── update.sh
├── test/
│   ├── test_utils.cpp
│   ├── test_functions.cpp
├── doc/
│   ├── Algorithm-explanation.md
│   ├── Download-compile-run.md
│   ├── Contributing.md
├── img/
│── README.md
│── LICENSE
│── CITATION.cff
│── Doxyfile
│── .gitignore
│── .valgrindrc
│── .all-contributorsrc
│── makefile
```

## Supported operating systems

- **Linux**
  - *Ubuntu* (tested)
- **MacOS**

## Install an run

Steps to be reproduced:

1) Download one of the releases of the repository or clone the main branch.

2) Unzip and enter the downloaded repository directory.

3) Install all the prerequisites:

```bash
./script/install_dependencies.sh
```

Prerequisites list:

- A `g++` compiler.
- C++17 standard.
- [`exprtk`](https://github.com/ArashPartow/exprtk) library.
- [`osmanip`](https://github.com/JustWhit3/osmanip) library.
- [`arsenalgear`](https://github.com/JustWhit3/arsenalgear) library.

Optional (only for developers)

- [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck).
- [Clang formatter](https://stackoverflow.com/questions/20756924/how-can-i-install-clang-format-in-ubuntu#:~:text=16.04%2C%20simply%20do%3A-,sudo%20apt%20install%20clang%2Dformat,-Share).
- A terminal supporting ANSI escape sequences.

4) Compile:

```bash
make main
```

> **NOTE**: to compile test code run `make tests`.

5) Run the main program:

```bash
./bin/main
```

## Extra documentation

Extra documentation is available in the [doc](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc) folder:

- [Algorithm explanation and physical background](https://github.com/JustWhit3/SAFD-algorithm/blob/main/doc/Algorithm-explanation.md): contains information about the mathematical and physical explanation related to the coefficients computation and a detailed description of the used algorithm.
- [Contributing](https://github.com/JustWhit3/SAFD-algorithm/tree/main/doc/Contributing.md): contains information about how to contribute to this project.
- [Extra scripts](https://github.com/JustWhit3/SAFD-algorithm/blob/main/doc/Extra-scripts.md): contains extra documentation about the other scripts.

Code documentation is generated using Doxygen and can be accessed [here](https://justwhit3.github.io/SAFD-algorithm/index.html).

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

## Credits

### Project leaders

<table>
  <tr>
    <td align="center"><a href="https://justwhit3.github.io/"><img src="https://avatars.githubusercontent.com/u/48323961?v=4" width="100px;" alt=""/><br /><sub><b>Gianluca Bianco</b></sub></a></td>
  </tr>
</table>

### Other contributors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://github.com/AdamTas"><img src="https://avatars.githubusercontent.com/u/17808974?v=4" width="100px;" alt=""/><br /><sub><b>Adam_T</b></sub></a></td>
    <td align="center"><a href="https://github.com/patlefort"><img src="https://avatars.githubusercontent.com/u/3423714?v=4" width="100px;" alt=""/><br /><sub><b>patlefort</b></sub></a></td>
    <td align="center"><a href="https://github.com/myermo"><img src="https://avatars.githubusercontent.com/u/93035284?v=4" width="100px;" alt=""/><br /><sub><b>myermo</b></sub></a></td>
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

### Other contributors with no GitHub account

- [adnukator](https://www.reddit.com/user/adnukator).
