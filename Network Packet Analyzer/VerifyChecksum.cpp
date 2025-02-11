#include "VerifyChecksum.h"

void VerifyChecksum(ip_t* ip) {
    cout << "\tCalculated Checksum:\t\t0x" << hex << setfill('0') << setw(4);

    // Retrieve the actual checksum from the IP header
    uint16_t actualChecksum = ((uint16_t)(ip->checksum[0]) << 8) | (uint16_t)(ip->checksum[1]);

    // Zero out the checksum in the IP header for calculation
    ip->checksum[0] = 0;
    ip->checksum[1] = 0;

    uint32_t sum = 0;
    uint16_t* ip_ptr = (uint16_t*)ip;

    // Perform the checksum calculation by summing the 16-bit words in the IP header
    for (int i = 0; i < sizeof(ip_t) / 2; i++) {
        sum += ntohs(ip_ptr[i]);
    }

    // Fold any 32-bit sum into 16 bits
    sum = (sum & 0xFFFF) + ((sum & 0xFFFF0000) >> 16);

    // Calculate the checksum by inverting the sum
    uint16_t calculatedChecksum = ~(uint16_t)(sum);
    cout << calculatedChecksum << endl;

    // Restore the original checksum value
    ip->checksum[0] = (uint8_t)(actualChecksum >> 8);
    ip->checksum[1] = (uint8_t)(actualChecksum & 0xFF);

    // Verify if the calculated checksum matches the actual checksum
    if (calculatedChecksum == actualChecksum) {
        cout << "\tChecksum verification succeeds!" << endl;
    }
    else {
        cout << "\tChecksum verification fails!" << endl;
    }
}