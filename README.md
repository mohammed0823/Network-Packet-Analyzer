# Network Packet Analyzer

A simple C++ project that parses pcapng files and analyzes network packets (Ethernet, ARP, IP).

## Features

- Parse pcapng files using the `light_pcapng` library
- Display Ethernet, ARP, and IP packet details
- Validate packet checksums for IP packets
- Analyze packet headers and payload data
- Lightweight and fast for basic network analysis

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/network-packet-analyzer.git
   ```

2. Compile the project:
   ```bash
   g++ -o packet_analyzer main.cpp -lpcap
   ```

## Usage

Run the analyzer with a pcapng file:
   ```bash
   ./packet_analyzer example.pcapng
   ```

## License

MIT License
