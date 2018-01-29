# Zeus v1.0.0

Golang Daemon to accept requests and execute some python code to do some magic.

## Installation
### Requirements
* Go version 1.9
* PyTesseract 0.18
* Python 3

### Compilation
* Navigate to desired directory
* `git clone https://github.com/jparr721/Zeus.git /your-directory`
* Run `go get ./...` 
* Interactions `Zeus start | stop | reload | install | remove | status`

### Executing
If this is your first time installing and compiling this, please run the following:
* `systemctl daemon-reload`
* `systemctl start Zeus`

