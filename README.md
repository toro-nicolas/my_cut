# my_cut ✂️

## Table of contents 📑
- [Description](https://github.com/toro-nicolas/my_cut/blob/main/README.md#description-)
- [Usage](https://github.com/toro-nicolas/my_cut/blob/main/README.md#usage-%EF%B8%8F)
- [Result](https://github.com/toro-nicolas/my_cut/blob/main/README.md#result-)
- [Compilation](https://github.com/toro-nicolas/my_cut/blob/main/README.md#compilation-%EF%B8%8F)
- [Code mandatory](https://github.com/toro-nicolas/my_cut/blob/main/README.md#code-mandatory-)
- [What's next ?](https://github.com/toro-nicolas/my_cut/blob/main/README.md#whats-next--)
- [Contributors](https://github.com/toro-nicolas/my_cut/blob/main/README.md#contributors-)


## Description 📝
The **my_cut** is a **personal project** I did on my own during a study break.  
Its purpose is to create in [**C**](https://en.wikipedia.org/wiki/C_(programming_language)) a **reproduction of the cut command**.  
The cut command allows you to **display only certain parts** of what you **give it as input**.  
This project applies to the **EPITECH Duo Stumper** (the stumper version can be found in the **bonus folder**).  
The following **flags** are **supported**:  
- **-f / --field**: select only these fields
- **-c / --characters**: select only these characters
- **-d / --delimiter**: use DELIM instead of TAB for field delimiter


## Usage ⚔️
You can run the my_cut like this :
```sh
cat file | ./my_cut [OPTIONS]
```


## Result 🚩
The result of this project is a **a simple recreation** of the **cut command**, with **fewer features** than the **real thing** for the moment.  
If you discover a **problem** or an **error**, don't hesitate to **create an issue** and **report it** to us as soon as possible.


### Tests and code coverage
**Unit tests** were performed using [criterion](https://criterion.readthedocs.io/en/master/intro.html).  
In this project, **only** the **library code is covered**.
Unit tests are still to be performed, but a large part of the code is already covered.

You can compile the project and run the unit tests with this command :
```sh
make tests_run
```


## Compilation 🛠️
You can compile the project with this command :
```sh
make
```

If you want clean the project, you can run this command :
```sh
make fclean
```

You can clean and compile the project with ```make re```.

You can compile the unit tests with this command :
```sh
make unit_tests
```


## Code mandatory 📦
- You'll need to create a branch where you'll push your code. Once you've completed your tasks on this branch, we'll work together to merge it and check that everything works.
- Every function you add must be code-style.
- Before merging, you'll need to check that all unit tests pass by running ```make tests_run```.
- Each commit will contain ```[+]``` or ```[-]``` or ```[~]``` followed by a message
    - ```[+]``` : Add feature
    - ```[-]``` : Delete feature
    - ```[~]``` : Edit feature

**Of course, in exceptional cases, we may depart from these rules.**


## What's next ? 🚀
- Add help section
- Add and handle more flags
- Improve github actions
- Improve the memory management
- Add a documentation for each function
- Add unit tests on each piece of code


## Contributors 👤
This project was carried out alone by [**Nicolas TORO**](https://github.com/toro-nicolas).
