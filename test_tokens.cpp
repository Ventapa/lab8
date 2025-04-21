#include "manage_tokens.h"
#include <cassert>
#include <iostream>

int main() {
    ManageTokens manager;
    // Test minting
    manager.mintToken("UnitTestNFT", manager.wallet1);
    assert(manager.wallet1.size() == 1);
    std::string firstHash = manager.wallet1[0]->hashValue;

    // Test invalid transfer (out-of-range)
    manager.transferToken(5, manager.wallet1, manager.wallet2);
    assert(manager.wallet1.size() == 1);
    assert(manager.wallet2.size() == 0);

    // Test valid transfer
    manager.transferToken(0, manager.wallet1, manager.wallet2);
    assert(manager.wallet1.empty());
    assert(manager.wallet2.size() == 1);
    assert(manager.wallet2[0]->hashValue == firstHash);

    std::cout << "All tests passed\n";
    return 0;
}
