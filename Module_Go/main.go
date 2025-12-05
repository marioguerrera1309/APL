package main
/*
#include <stdlib.h>
void hello();
#cgo LDFLAGS: -L${SRCDIR}/../Module_Cpp -lhello -lstdc++
*/
import "C"
func main() {
    C.hello()
}
// import (
//     "fmt"
//     "net"
//     "os"
// )
// const (
//     CONN_HOST = "localhost"
//     CONN_PORT = "50000"
//     CONN_TYPE = "tcp"
// )
// func main() {
//     l, err := net.Listen(CONN_TYPE, CONN_HOST+":"+CONN_PORT)
//     if err != nil {
//         fmt.Println("Errore nell'ascolto:", err.Error())
//         os.Exit(1)
//     }
//     defer l.Close()
//     fmt.Println("Server Go in ascolto su " + CONN_HOST + ":" + CONN_PORT)
//     for {
//         conn, err := l.Accept()
//         if err != nil {
//             fmt.Println("Errore nell'accettare la connessione:", err.Error())
//             continue
//         }
//         go handleRequest(conn)
//     }
// }
// func handleRequest(conn net.Conn) {
//     defer conn.Close()
//     for {
//         buf := make([]byte, 1024)
//         reqLen, err := conn.Read(buf)
//         if err != nil {
//             fmt.Println("Errore nella lettura:", err.Error())
//             return
//         }
//         message := string(buf[:reqLen])
//         fmt.Println("", message)
//         if message == "Pingpy" {
//             response := []byte("Pong")
//             _, err = conn.Write(response)
//             //fmt.Println("Messaggio inviato: ", string(response))
//             if err != nil {
//                 fmt.Println("Errore nella scrittura:", err.Error())
//             }
//             //fmt.Println("Messaggio inviato al client")
//         }
//         if message == "Pingcpp" {
//             response := []byte("Pong")
//             _, err = conn.Write(response)
//             //fmt.Println("Messaggio inviato: ", string(response))
//             if err != nil {
//                 fmt.Println("Errore nella scrittura:", err.Error())
//             }
//             //fmt.Println("Messaggio inviato al client")
//         }
//     }
// }
