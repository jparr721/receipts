package main

import (
	"fmt"
	"log"
	"net"
	"os"
	"os/signal"
	"syscall"

	"github.com/takama/daemon"
)

const (
	name        = "zeus"
	description = "data analysis daemon"
	port        = ":9997"
)

var stdlog, errlog *log.Logger

var dependencies = []string{"dummy.service"}

type service struct {
	daemon.Daemon
}

func (service *service) manageDaemon() (string, error) {
	usage := `
  Zeus Service v 0.1.0
  --
  Usage: zeus install | remove | start | stop | status`

	if len(os.Args) > 1 {
		command := os.Args[1]
		switch command {
		case "install":
			return service.Install()
		case "remove":
			return service.Remove()
		case "stop":
			return service.Stop()
		case "status":
			return service.Status()
		default:
			return usage, nil
		}
	}

	interrupt := make(chan os.Signal, 1)
	signal.Notify(interrupt, os.Interrupt, os.Kill, syscall.SIGTERM)

	// Set up a listener for the port
	listener, err := net.Listen("tcp", port)
	if err != nil {
		return "Error binding to port", err
	}

	// channel for accepted connections
	listen := make(chan net.Conn, 100)
	go acceptConnection(listener, listen)

	for {
		select {
		case conn := <-listen:
			go handleClient(conn)
		case killSignal := <-interrupt:
			stdlog.Println("Got signal:", killSignal)
			stdlog.Println("Stopping listening on ", listener.Addr())
			listener.Close()
			if killSignal == os.Interrupt {
				return "Daemon was interrupted by system signal", nil
			}
			return "Daemon was killed", nil
		}
	}
}

func acceptConnection(listener net.Listener, listen chan<- net.Conn) {
	for {
		conn, err := listener.Accept()
		if err != nil {
			continue
		}
		listen <- conn
	}
}

func handleClient(client net.Conn) {
	for {
		buffer := make([]byte, 4096)
		numbytes, err := client.Read(buffer)
		if numbytes == 0 || err != nil {
			return
		}
		client.Write(buffer[:numbytes])
	}
}

func initDaemon() {
	stdlog = log.New(os.Stdout, "", 0)
	errlog = log.New(os.Stderr, "", 0)
}

func main() {
	srv, err := daemon.New(name, description, dependencies...)
	if err != nil {
		errlog.Println("Error: ", err)
		os.Exit(1)
	}
	service := &service{srv}
	status, err := service.manageDaemon()
	if err != nil {
		errlog.Println(status, "\nError: ", err)
		os.Exit(1)
	}
	fmt.Println(status)
}
