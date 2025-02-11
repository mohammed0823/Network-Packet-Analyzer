#pragma once
#include <iostream>
#include <light_pcapng_ext.h>

using namespace std;

// Ethernet frame structure
typedef struct ethernet {
    uint8_t destination[6];
    uint8_t source[6];
    uint8_t type[2];
} ethernet_t;

// Function to parse Ethernet frames from packets
void ParseEthernetFrame(light_pcapng_t* packets);