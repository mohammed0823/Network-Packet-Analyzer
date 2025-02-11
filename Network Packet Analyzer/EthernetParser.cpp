#include "EthernetParser.h"
#include "ARPParser.h"
#include "IPParser.h"

// Function to parse Ethernet frames from packets
void ParseEthernetFrame(light_pcapng_t* packets) {
    int index = 1;
    light_packet_header pkt_header;
    const uint8_t* pkt_data = nullptr;

    // Iterate over each packet in the capture
    while (light_get_next_packet(packets, &pkt_header, &pkt_data)) {
        if (pkt_data == nullptr) continue;

        cout << dec << "Packet #" << index << ": ";
        ethernet_t* e = (ethernet_t*)pkt_data;
        uint16_t etherType = (e->type[0] << 8) | e->type[1];

        // Identify EtherType and display packet type
        if (etherType == 0x0806) {
            cout << "ARP";
        }
        else if (etherType == 0x0800) {
            cout << "IPv4";
        }
        else {
            cout << "Other";
        }
        cout << endl;

        // Display packet lengths
        cout << "\tOriginal length:\t\t" << pkt_header.original_length << endl;
        cout << "\tCaptured length:\t\t" << pkt_header.captured_length << endl;
        index++;

        cout << hex << setfill('0') << uppercase;

        // Display destination and source MAC addresses
        cout << "\tDestination MAC Address:\t";
        for (int i = 0; i < 6; i++) {
            cout << setw(2) << unsigned(e->destination[i]) << (i < 5 ? ":" : "\n");
        }

        cout << "\tSource MAC Address:\t\t";
        for (int i = 0; i < 6; i++) {
            cout << setw(2) << unsigned(e->source[i]) << (i < 5 ? ":" : "\n");
        }

        // Display EtherType value
        cout << "\tEtherType:\t\t\t0x" << setw(4) << etherType << endl;

        // Parse ARP or IPv4 packet based on EtherType
        if (etherType == 0x0806) {
            ParseARPPacket(pkt_data + sizeof(ethernet_t));
        }
        else if (etherType == 0x0800) {
            ParseIPPacket(pkt_data + sizeof(ethernet_t));
        }

        cout << endl;
    }
}