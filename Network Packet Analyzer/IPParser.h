#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

// IP packet structure
typedef struct ipType {
    uint8_t versionIHL[1];
    uint8_t tos[1];
    uint8_t length[2];
    uint8_t identification[2];
    uint8_t flagsFrag[2];
    uint8_t ttl[1];
    uint8_t protocol[1];
    uint8_t checksum[2];
    uint8_t sourceIP[4];
    uint8_t destinationIP[4];
} ip_t;

// Function to parse IP packet data
void ParseIPPacket(const uint8_t* pkt_data);

// Function to verify the IP header checksum
void VerifyChecksum(ip_t* ip);