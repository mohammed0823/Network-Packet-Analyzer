#include <iostream>
#include "EthernetParser.h"
#include <light_pcapng_ext.h>

using namespace std;

int main() {
    char file[256];

    // Prompt user for file path input
    cout << "Enter file path: ";
    cin >> file;

    string file_str(file);

    // Remove any quotes from the file path input
    file_str.erase(remove(file_str.begin(), file_str.end(), '"'), file_str.end());
    strcpy_s(file, sizeof(file), file_str.c_str());
    cout << endl;

    // Open the pcapng file for reading
    light_pcapng_t* pcapng = light_pcapng_open_read(file, LIGHT_FALSE);
    if (pcapng == NULL) {
        cerr << "Unable to read pcapng: " << file << endl;
        return -1;
    }

    // Parse the Ethernet frame from the pcapng file
    ParseEthernetFrame(pcapng);

    // Close the pcapng file
    light_pcapng_close(pcapng);

    return 0;
}