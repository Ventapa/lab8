# NFT Lab: unique_ptr-based NFT Manager

## Overview
This project implements a non-fungible token (NFT) manager in C++ using `std::unique_ptr`. It supports:
- Minting NFTs with SHA-256 hashing via OpenSSL.
- Transferring tokens between wallets with edge-case handling.
- Benchmarking integer vs. big-integer performance.
- Unit tests to validate minting and transfer logic.

## Prerequisites

### Linux
- C++17 compiler (e.g., g++)
- GMP library (`libgmpxx`, `libgmp`)
- OpenSSL development library (`libssl-dev` on Debian/Ubuntu)

### macOS
1. Install dependencies via Homebrew:
   ```bash
   brew install openssl gmp
   ```
2. Note the installation prefixes:
   ```bash
   OPENSSL_PREFIX=$(brew --prefix openssl)
   GMP_PREFIX=$(brew --prefix gmp)
   ```

## Build & Run

### 1. Build and run the demo application

#### Linux
```bash
g++ main.cpp manage_tokens.cpp -std=c++17 -lcrypto -lgmpxx -lgmp -o nft_app
./nft_app
```

#### macOS
```bash
g++ main.cpp manage_tokens.cpp \
    -std=c++17 \
    -I${OPENSSL_PREFIX}/include \
    -I${GMP_PREFIX}/include \
    -L${OPENSSL_PREFIX}/lib \
    -L${GMP_PREFIX}/lib \
    -lcrypto -lgmpxx -lgmp \
    -o nft_app
./nft_app
```

### 2. Build & run unit tests

#### Linux
```bash
g++ test_tokens.cpp manage_tokens.cpp -std=c++17 -lcrypto -lgmpxx -lgmp -o tests
./tests
```

#### macOS
```bash
g++ test_tokens.cpp manage_tokens.cpp \
    -std=c++17 \
    -I${OPENSSL_PREFIX}/include \
    -I${GMP_PREFIX}/include \
    -L${OPENSSL_PREFIX}/lib \
    -L${GMP_PREFIX}/lib \
    -lcrypto -lgmpxx -lgmp \
    -o tests
./tests
```
