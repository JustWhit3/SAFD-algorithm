# Run the program

## Table of contents

- [Download](#download)
- [Prerequisites](#prerequisites)
  - [Mandatory](#mandatory)
  - [Optional](#optional)
- [Compilation](#compilation)
- [Run the program](#run-the-program)
- [Other scripts](#other-scripts)
  - [debug.sh](#debugsh)
  - [update.sh](#updatesh)

## Download

To download the library you can proceed in two independent ways.

First of all, you need to download the code: go to the [main page](https://github.com/JustWhit3/SAFD-algorithm) of the repository and click on the upper right green button called `Code`. Then click on `Download ZIP` and wait the download to be completed.

Alternatively you can download the latest version of the repository from the ``Releases`` button on the right of the repository main page by clicking on the source code link

## Prerequisites

To correctly compile and run the program you need some prerequisite installed in your device. It is possible to run, directly from the repository main directory, a script `install_dependencies.sh` to automatically install all the prerequisites, through this command:

```bash
./script/install_dependencies.sh
```

### Mandatory

Tools:

- A `g++` compiler.
- C++17 standard.

Libraries and frameworks:

- [`exprtk`](https://github.com/ArashPartow/exprtk) library.
- [`osmanip`](https://github.com/JustWhit3/osmanip) library.
- [`arsenalgear`](https://github.com/JustWhit3/arsenalgear) library.

>**NOTE**: this latter library is automatically installed during the installation of `osmanip`.

### Optional

Tools

- [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) programs to run the debugging script.
- [Clang formatter](https://stackoverflow.com/questions/20756924/how-can-i-install-clang-format-in-ubuntu#:~:text=16.04%2C%20simply%20do%3A-,sudo%20apt%20install%20clang%2Dformat,-Share) to format the code for pull requests.
- A terminal supporting ANSI escape sequences.

Libraries and frameworks:

- [`doctest`](https://github.com/doctest/doctest) for testing.

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
./bin/main
```

Extra information about how to move inside the command line once you have ran the code can be found in the [How to run](#how-to-run) section.

If you want to run the tests you have to type:

```shell
./bin/test
```

## Other scripts

Other scripts have been provided into the [**scripts**](https://github.com/JustWhit3/osmanip/blob/main/scripts) folder. After compiling the source code, they can be run from the repository home directory.

### debug.sh

This script is used to run [Valgrind](https://valgrind.org/) and [Cppcheck](https://github.com/danmar/cppcheck) debugging tools on the whole code.

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

### update.sh

In case you want to update the source code from the latest improvements of the repository, you can use the updater script, called [update.sh](https://github.com/JustWhit3/SAFD-algorithm/blob/main/scripts/update.sh).

From the repository folder type this command on the shell:
```shell
./scripts/update.sh
```