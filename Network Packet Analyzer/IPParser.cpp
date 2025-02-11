#include "IPParser.h"
#include "VerifyChecksum.h"

// Function to parse IP packet data
void ParseIPPacket(const uint8_t* pkt_data) {
    ip_t* ip = (ip_t*)pkt_data;

    cout << hex << setfill('0');

    // Display IP version, header length, type of service, and total length
    cout << "\tVersion:\t\t\t0x" << (ip->versionIHL[0] >> 4) << endl;
    cout << "\tHeader Length:\t\t\t0x" << (ip->versionIHL[0] & 0xF) << endl;
    cout << "\tType of Service:\t\t0x" << setw(2) << unsigned(ip->tos[0]) << endl;
    cout << "\tTotal Length:\t\t\t0x" << setw(4) << ((ip->length[0] << 8) | ip->length[1]) << endl;

    // Display IP identification, flags, and fragment offset
    cout << "\tIdentification:\t\t\t0x" << setw(4) << ((ip->identification[0] << 8) | ip->identification[1]) << endl;
    cout << "\tFlags:\t\t\t\t0x" << (ip->flagsFrag[0] >> 5) << endl;
    cout << "\tFragment Offset:\t\t0x" << setw(4) << (((ip->flagsFrag[0] & 0x1F) << 8) | ip->flagsFrag[1]) << endl;

    // Display IP TTL, protocol, and checksum
    cout << dec << "\tTTL:\t\t\t\t" << unsigned(ip->ttl[0]) << endl;
    cout << hex << "\tProtocol:\t\t\t0x" << setw(2) << unsigned(ip->protocol[0]) << endl;
    cout << "\tChecksum:\t\t\t0x" << setw(4) << ((ip->checksum[0] << 8) | ip->checksum[1]) << endl;

    cout << dec;

    // Display source and destination IP addresses
    cout << "\tSource IP:\t\t\t";
    for (int i = 0; i < 4; i++) {
        cout << unsigned(ip->sourceIP[i]) << (i < 3 ? "." : "\n");
    }

    cout << "\tDestination IP:\t\t\t";
    for (int i = 0; i < 4; i++) {
        cout << unsigned(ip->destinationIP[i]) << (i < 3 ? "." : "\n");
    }

    // Verify IP checksum
    VerifyChecksum(ip);
}