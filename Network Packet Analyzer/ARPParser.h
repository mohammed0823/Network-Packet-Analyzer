#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

// ARP packet structure
typedef struct arpType {
    uint8_t hardwareType[2];
    uint8_t protocolType[2];
    uint8_t hardwareSize[1];
    uint8_t protocolSize[1];
    uint8_t opcode[2];
    uint8_t senderMac[6];
    uint8_t senderIP[4];
    uint8_t targetMac[6];
    uint8_t targetIP[4];
} arp_t;

// Function to parse ARP packet data
void ParseARPPacket(const uint8_t* pkt_data);