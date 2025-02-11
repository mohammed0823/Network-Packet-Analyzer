#pragma once
#include <iostream>
#include <iomanip>
#include <light_pcapng_ext.h>
#include "IPParser.h"

using namespace std;

// Function to verify the IP header checksum
void VerifyChecksum(ip_t* ip);