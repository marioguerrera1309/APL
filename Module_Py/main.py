import socket
import time
import sys
SERVER_IP = "127.0.0.1"
PORT = 50000
BUFFER_SIZE = 1024
MESSAGE = "Pingpy"
def run_client():
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except socket.error as err:
        print(f"Errore: Creazione socket fallita: {err}")
        sys.exit(1)
    server_address = (SERVER_IP, PORT)
    print(f"Tentativo di connessione al server Go su {SERVER_IP}:{PORT}...")
    try:
        sock.connect(server_address)
        print("Connessione stabilita con successo.")
    except socket.error as err:
        print(f"Errore: Connessione fallita. Assicurati che il server Go sia in esecuzione: {err}")
        sys.exit(1)
    try:
        while True:
            #print(f"Invio: {MESSAGE}")
            sock.sendall(MESSAGE.encode('utf-8'))
            time.sleep(1)
            data = sock.recv(BUFFER_SIZE)
            if not data:
                print("Connessione chiusa dal server Go.")
                break
            response = data.decode('utf-8').strip()
            #print(f"Risposta ricevuta: {response}")
            if response == "Pong":
                print("Pong")
                time.sleep(1)
            else:
                print(f"Errore: Risposta inaspettata dal server Go: {response}")
                break
    except socket.error as err:
        print(f"Errore nella comunicazione: {err}")
    finally:
        print("Chiusura della connessione.")
        sock.close()
if __name__ == '__main__':
    run_client()
