#include "manage_tokens.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <iostream>
#include <gmpxx.h>

NfToken::NfToken(const std::string& name) : assetName(name) {
    hashValue = generateHash(name + std::to_string(std::chrono::system_clock::now().time_since_epoch().count()));
}

std::string NfToken::generateHash(const std::string& input) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.data()), input.size(), digest);
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::setw(2) << static_cast<int>(digest[i]);
    }
    return ss.str();
}

void ManageTokens::mintToken(const std::string& name, std::vector<std::unique_ptr<NfToken>>& wallet) {
    wallet.push_back(std::make_unique<NfToken>(name));
}

void ManageTokens::transferToken(size_t index, std::vector<std::unique_ptr<NfToken>>& from, std::vector<std::unique_ptr<NfToken>>& to) {
    if (index >= from.size()) {
        std::cerr << "Error: transfer index " << index << " out of range (size=" << from.size() << ")\n";
        return;
    }
    to.push_back(std::move(from[index]));
    from.erase(from.begin() + index);
}

void benchmark() {
    const int iterations = 10000000;
    auto start = std::chrono::high_resolution_clock::now();
    int a = 0;
    for (int i = 0; i < iterations; ++i) a += i;
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "int: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";

    start = std::chrono::high_resolution_clock::now();
    long int b = 0;
    for (int i = 0; i < iterations; ++i) b += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "long int: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";

    start = std::chrono::high_resolution_clock::now();
    mpz_class c = 0;
    for (int i = 0; i < iterations; ++i) c += i;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "bigint: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n";
}
