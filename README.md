# Zeus v0.3.18

Modular Machine Learning Daemon framework custom written by me to allow for reusable daemons to sit in my linux server and interact with my database. 

## Installation
### Requirements
* CMake >= 3.2
* Curl
* C++11
* OpenCV __(for now)__

### Compilation
`cd <project directory>`

`mkdir build`

`cd build`

`cmake -DCMAKE_INSTALL_PREFIX=../_install ../modules/`

`make`

`make install`

### Executing
This program currently has three(3) arguments:
`<install path>/bin/ast [URL] [USERNAME] [PASSWORD]`

Example: `<install path>/bin/ast imaps://imap.gmail.com username@gmail.com default`
