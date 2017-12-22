# Zeus v0.4.0

Linux daemon to interact with incoming requests and perform data analysis.

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
If this is your first time installing and compiling this, please run the following:
* `systemctl daemon-reload`
* `systemctl start zeus.service`

Right now it only supports start and stop. More is coming.
