#include "ARPParser.h"

// Function to parse ARP packet data
void ParseARPPacket(const uint8_t* pkt_data) {
    arp_t* a = (arp_t*)pkt_data;

    cout << hex << setfill('0');

    // Display hardware and protocol types, sizes, and opcode
    cout << "\tHardware type:\t\t\t0x" << setw(4) << ((a->hardwareType[0] << 8) | a->hardwareType[1]) << endl;
    cout << "\tProtocol type:\t\t\t0x" << setw(4) << ((a->protocolType[0] << 8) | a->protocolType[1]) << endl;
    cout << "\tHardware size:\t\t\t0x" << setw(2) << unsigned(a->hardwareSize[0]) << endl;
    cout << "\tProtocol size:\t\t\t0x" << setw(2) << unsigned(a->protocolSize[0]) << endl;
    cout << "\tOpcode:\t\t\t\t0x" << setw(4) << ((a->opcode[0] << 8) | a->opcode[1]) << endl;

    cout << dec;

    // Display sender and target IP addresses
    cout << "\tSource IP:\t\t\t";
    for (int i = 0; i < 4; i++) {
        cout << unsigned(a->senderIP[i]) << (i < 3 ? "." : "\n");
    }

    cout << "\tDestination IP:\t\t\t";
    for (int i = 0; i < 4; i++) {
        cout << unsigned(a->targetIP[i]) << (i < 3 ? "." : "\n");
    }
}