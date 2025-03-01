# CS3502 Project 1 - Multi-Threading & IPC  

This project demonstrates multi-threaded programming, synchronization, deadlock management, and inter-process communication (IPC) using C++. It includes:  

- **Threading:** Creating and managing threads safely.  
- **Synchronization:** Using mutexes to prevent race conditions.  
- **Deadlock:** Demonstrating and resolving deadlock scenarios.  
- **Inter-Process Communication (IPC):** Using named pipes and sockets for data exchange between processes.  

### How to Run  
Compile all programs:  
```bash
g++ -o banking banking.cpp -pthread  
g++ -o deadlock deadlock.cpp -pthread  
g++ -o socket_client socket_client.cpp -pthread  
g++ -o socket_server socket_server.cpp -pthread  
g++ -o pipe_writer pipe_writer.cpp -pthread  
g++ -o pipe_reader pipe_reader.cpp -pthread  
g++ -o test_threads test_threads.cpp -pthread  
