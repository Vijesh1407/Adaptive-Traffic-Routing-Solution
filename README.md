🛣️ Adaptive Traffic Routing Solution (City-to-City) 🚦

📘 Overview

This project implements a city-based traffic routing system using Dijkstra's Algorithm to determine the shortest travel time between cities in Tamil Nadu.

Key features include:
- Dynamic path additions between cities
- Real-time traffic updates
- Fast computation of shortest travel time using priority queues

🧠 Concept

- Each city is treated as a node.
- Roads (with travel time) are edges in a weighted undirected graph.
- Traffic congestion can be updated by modifying edge weights.
- Dijkstra's algorithm is used to find the shortest path between cities based on current traffic.

🏙️ Supported Cities

The system currently includes the following 10 Tamil Nadu cities:

1. Chennai  
2. Viluppuram  
3. Dindigul  
4. Trichy  
5. Madurai  
6. Coimbatore  
7. Salem  
8. Tuticorin  
9. Tirunelveli  
10. Nagercoil  

🛠️ Technologies Used

- Language: C++
- Algorithm: Dijkstra's Shortest Path
- Data Structures: Graph (Adjacency List), Priority Queue
