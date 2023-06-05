# C-utils
[![Made by David Rosado](https://img.shields.io/badge/Made%20by-David%20Rosado-blue.svg)](https://github.com/davidrosado4)  [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)


<p align="center">
  <img src="img/icon_darkmode-modified.png" alt="Image" style="border-radius: 50%; width: 200px;" />
</p>

This project offers a set of utility libraries that aim to minimize the necessity of writing repetitive code for every project. These libraries address the common requirements I have encountered in numerous mathematical projects. The purpose of this repository is to gather and consolidate the most commonly used C functions in one place.


## How to use it
In the *src* directory, you'll discover various `.c` and `.h` files to allow you the freedom of selecting the ones that perfectly align with your project requirements. 
To utilize any of them, please adhere to the following set of instructions:

Assume that the name of your C script is `myscript.c` and you want to add the `matrix` library (`matrix.h`, `matrix.c`).
1. Copy the `matrix.h` and the `matrix.c` files into your project folder.
2. Add the `matrix.h` file to the `myscript.c` file at the include section.
```
#include <stdio.h>
#include <stdlib.h>
...
#include "matrix.h"
```
3. Compile and execute the code as follows:
```
gcc myscript.c matrix.c -o executable.exe -Wall -lm
./executable.exe
```


The repository is currently in progress...

![](https://geps.dev/progress/20)
