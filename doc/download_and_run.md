# Run the program

## Table of contents

- [Download](#download)
- [Prerequisites](#prerequisites)
- [Compilation](#compilation)
- [Run the program](#run-the-program)

## Download

To download the library you can proceed in two independent ways.

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/SAFD-algorithm) of the repository and click on the upper right green button called `Code`. Then click on `Download ZIP` and wait the download to be completed.

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link

## Prerequisites

To correclty compile and run the program you need some prerequisite installed in your device:

- A `g++` compiler.
- The [`exprtk`](https://github.com/ArashPartow/exprtk) library, to correctly parse the <img src="https://render.githubusercontent.com/render/math?math=\color{green}{f(\theta, \phi)}"> function.
- My [`osmanip`](https://github.com/JustWhit3/osmanip) library, for the output-stream color of the program.
- Optional: the [`doctest`](https://github.com/doctest/doctest) library, to run tests.
- Optional: [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) programs to run the debugging script.

## Compilation

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
## Run the program

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