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
- [How to use](#how-to-use)

## Introduction

This program computes the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients of a function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> development in a spherical harmonics convergent series, by using a standard mathematical [algorithm](#algorithm-explanation).

When running the program, you have simply to input the generic shape of the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> equation and the values of m and l and the coefficients will be calculated.

Some program features:
 - Can calculate <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients for any generic <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function, entered by the user during the program running.
 - <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients are expressed as complex numbers.
 - It works well for each negative or positive value of m, with very good accuracy until m < 5. For higher m values, the accuracy gradually decrease.

> **NOTE**: equations are displayed in green color in order to be correctly visualized in both normal and dark mode.

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
│── README.md
│── LICENSE
│── CITATION.cff
│── .gitignore
│── .valgrindrc
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

> **NOTE**: the compilation will be a bit slow, due to the use of the parsing instructions of the [`exprtk`](https://github.com/ArashPartow/exprtk) library.

Optionally you can compile also the test code with this command:

```shell
make bin/test
```

If you want to compile both them in one step:

```shell
make
```

This compilation steps should be performed only once.
### Running

To run the code you can simply enter this command in the shell:

```shell
./bin/main.exe
```

Extra information about how to move inside the command line once you have ran the code can be found in the [How to run](#how-to-run) section.

If you want to run the tests you have to type:

```shell
./bin/test.exe
```

There is also an extra script to debug the code using [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck), which can be used with some instructions.

You can run Valgrind debugging tools with a specific executable:

```shell
./scripts/debug.sh [valgrind-tool-name] [executable-name]
```

> **NOTE**: where `[tool-name]` is the Valgrind tool name and `[executable-name]` is the executable name (you have to indicate also the path to it).

Or you can run them for all the executables of the repository:

```shell
./scripts/debug.sh [valgrind-tool-name] all
```

You can also run Cppcheck tool for a specific source code directory:

```shell
./scripts/debug.sh cppcheck [source-code-dir]
```

Or for a .cpp file only:

```shell
./scripts/debug.sh cppcheck [file.cpp]
```

> **NOTE**: pay attention when running this script with `memcheck` tool, since it may produce fake errors related to the included libraries. In this case you should prepare a suppression file before running it.

## Algorithm explanation

### Phisical background

Spherical harmonics are simultaneously eigenfunctions of both the module of the angular momentum and of its arbitrary component along an axis.

They are a family of infinite functions, called <img src="https://render.githubusercontent.com/render/math?math=\color{green}{Y^{m}_{l}(\theta,\phi)}">, which depend only on the two angles (defined in the spherical transformation of coordinates) and in which *l* and *m* are are integers which satisfy this relation: <img src="https://render.githubusercontent.com/render/math?math=\color{green}{l \geq 0}"> and <img src="https://render.githubusercontent.com/render/math?math=\color{green}{\left| m \right| \leq l}">.

They can construct an orthonormal basis for any other function depending on the same variables; this means that each function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> can be developed into a spherical harmonics convergent series:

<img src="https://latex.codecogs.com/svg.image?\color{DarkGreen}&space;(1)&space;\hspace{1cm}&space;f(\theta,\phi)=\sum^{\infty}_{l=0}\sum^{l}_{m=-l}&space;f_{m,l}&space;\cdot&space;Y^{m}_{l}(\theta,\phi)" title="\color{DarkGreen} (1) \hspace{1cm} f(\theta,\phi)=\sum^{\infty}_{l=0}\sum^{l}_{m=-l} f_{m,l} \cdot Y^{m}_{l}(\theta,\phi)" />

where the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f_{m,l}}"> coefficients can be written as:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}(2)&space;\hspace{1cm}&space;f_{m,l}=\int^{2\pi}_{0}\int^{\pi}_{0}f(\theta,&space;\phi)&space;\cdot&space;\bar{Y}^{m}_{l}(\theta,\phi)&space;\cdot&space;\sin(\theta)&space;\&space;d\theta&space;d\phi}" title="{\color{DarkGreen}(2) \hspace{1cm} f_{m,l}=\int^{2\pi}_{0}\int^{\pi}_{0}f(\theta, \phi) \cdot \bar{Y}^{m}_{l}(\theta,\phi) \cdot \sin(\theta) \ d\theta d\phi}" />

and the spherical harmonics <img src="https://render.githubusercontent.com/render/math?math=\color{green}{Y^{m}_{l}(\theta,\phi)}"> are defined as follows:

<img src="https://latex.codecogs.com/svg.image?\color{DarkGreen}&space;(3)&space;\hspace{1cm}&space;Y^{m}_{l}(\theta,\phi)&space;=&space;(-1)^{\frac{m&plus;&space;\left|&space;m&space;\right|}{2}&space;}&space;\sqrt{\frac{(2l&plus;1)\cdot&space;(l-&space;\left|&space;m&space;\right|)!}{4&space;\pi&space;\cdot&space;(l&plus;&space;\left|&space;m&space;\right|)!}}&space;\cdot&space;P^{\left|&space;m&space;\right|}_{l}(\cos\theta)&space;\cdot&space;e^{im(\phi&space;&plus;&space;\pi)}" title="\color{DarkGreen} (3) \hspace{1cm} Y^{m}_{l}(\theta,\phi) = (-1)^{\frac{m+ \left| m \right|}{2} } \sqrt{\frac{(2l+1)\cdot (l- \left| m \right|)!}{4 \pi \cdot (l+ \left| m \right|)!}} \cdot P^{\left| m \right|}_{l}(\cos\theta) \cdot e^{im(\phi + \pi)}" />

where *i* is the imaginary unit and <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P^{\left| m \right|}_{l}}"> are the **Legendre associated functions**, defined in the interval *[-1,1]* (for the *x* variable):

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;(4)&space;\hspace{1cm}&space;P_{\alpha}^{\beta}(x)=(-1)^m\cdot(1-x^2)^{\frac{\beta}{2}}\frac{d^\beta}{dx^\beta}P_\alpha&space;(x)}" title="{\color{DarkGreen} (4) \hspace{1cm} P_{\alpha}^{\beta}(x)=(-1)^m\cdot(1-x^2)^{\frac{\beta}{2}}\frac{d^\beta}{dx^\beta}P_\alpha (x)}" />

with <img src="https://render.githubusercontent.com/render/math?math=\color{green}{\alpha \geq \beta \geq 0}">.

The <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P_{\alpha}}"> polynomials are called **Legendre polynomials** and are given by the following recursive relation:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;(5)&space;\hspace{1cm}&space;P_{\alpha&space;&plus;1}(x)=\frac{2\alpha&plus;1}{\alpha&plus;1}xP_{\alpha}(x)-\frac{\alpha}{\alpha&plus;1}P_{\alpha-1}(x)}" title="{\color{DarkGreen} (5) \hspace{1cm} P_{\alpha +1}(x)=\frac{2\alpha+1}{\alpha+1}xP_{\alpha}(x)-\frac{\alpha}{\alpha+1}P_{\alpha-1}(x)}" />

they are also defined in *[-1,1]* and have <img src="https://render.githubusercontent.com/render/math?math=\color{green}{P_{0}(x)=1}">.

### Algorithm description

The algorithm starts from the computation of the Legendre polynomials, for which has been created a function `Leg_pol` which reproduces the equation (5) (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/functions.cpp#:~:text=cmplx%20coefficient%3B-,//%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D,%7D,-//%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D)). So, nothing special for this one.

To compute the Legendre associated functions of equation (4) it has been firstly defined an `n_derivative` function to compute the n-th derivative of a real given function, using this recursive relation:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;f^{n}(x_0)\approx\frac{f^{n-1}(x&plus;h)-f^{n-1}(x-h)}{2h}}" title="{\color{DarkGreen} f^{n}(x_0)\approx\frac{f^{n-1}(x+h)-f^{n-1}(x-h)}{2h}}" />

(see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/utils.cpp#:~:text=//%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D-,//Function%20used%20to%20calculate%20the%20%22n%22%2Dth%20derivative%20of%20a,%7D,-//%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D%3D)).

The derivative step-size *h* has been defined with this function:

```C++
const double STEP_SIZE = 2 * cbrt( __DBL_EPSILON__ );

d_const h( i_const n, d_const x_0 )
 {
  if ( n < 4 && n > 0 ) return STEP_SIZE * x_0;
  else return n * 0.09;
 }
 ```

This derivation algorithm is not optimal, in fact the calculation is not too much accurate for n > 5, but should work not so bad for higher values of n. This is the motivation for which the computation of the equation (2) is precise until m = 5.

Finally, the Legendre associated functions has been computed writing a new function `Leg_func`, using the equation (4) and the previously defined derivative (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/functions.cpp#:~:text=d_const%20Leg_func(%20i_const%20b%2C%20i_const%20a%2C%20d_const%20x%20))).

Then, to compute the spherical harmonics defined in (3) it has been simply implemented a complex function `sph_arm` (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/functions.cpp#:~:text=cmplx_const%20sph_arm(%20i_const%20m%2C%20i_const%20l%2C%20d_const%20theta%2C%20d_const%20phi%20))).

Next step has been the one of writing an `integral` function to compute the double-integral of equation (2). For this, it has been used the **Simpson 1/3 rule**:

<img src="https://latex.codecogs.com/svg.image?{\color{DarkGreen}&space;\int^a_bf(x)dx&space;\approx\frac{b-a}{6}\left[&space;f(a)&space;&plus;&space;4f\left(\frac{a&plus;b}{2}&space;\right&space;)&plus;f(b)&space;\right&space;]}" title="{\color{DarkGreen} \int^a_bf(x)dx \approx\frac{b-a}{6}\left[ f(a) + 4f\left(\frac{a+b}{2} \right )+f(b) \right ]}" />

which has been extended to two-dimensions.

The integration step size for x and y variables has been defined as:

```C++
double const h_x = 0.07;
double const h_y = 0.15;
```

A table of the values of the function <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(x,y)}"> for all possible combinations of all x and y points has been created and the Simpson rule has been applied on each row to find integral with reference to y at each x and store the values in an array. Finally, the rule has been again applied on the values of the array to calculate the integral with reference to x (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/utils.cpp#:~:text=d_const%20integral(%20four_param_func%20f%2C%20s_const%20expr%2C%20i_const%20m%2C%20i_const%20l%20))).

Another function `f_m_l` has been then created to compute the final resulting coefficients of equation (2), bu using the integral algorithm defined previously (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/functions.cpp#:~:text=cmplx_const%20f_m_l(%20s_const%20expr%2C%20i_const%20m%2C%20i_const%20l%20))).

At the end, a main program has been provided, in order to run all the necessary code and to parse the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function from input, by simply entering its shape during the running of the whole program (see [here](https://github.com/JustWhit3/SAFD-algorithm/blob/main/src/main.cpp)). This final feature was possible thanks to the [`exprtk`](https://github.com/ArashPartow/exprtk) library tools.

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