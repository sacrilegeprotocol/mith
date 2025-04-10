// Copyright (c) 2025 The dwarf Developers
// Copyright (c) 2018-2019 The Ring Developers
// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RING_KEY_IO_H
#define RING_KEY_IO_H

#include <chainparams.h>
#include <key.h>
#include <pubkey.h>
#include <script/standard.h>

#include <string>

CKey DecodeSecret(const std::string& str);
std::string EncodeSecret(const CKey& key);

CExtKey DecodeExtKey(const std::string& str);
std::string EncodeExtKey(const CExtKey& extkey);
CExtPubKey DecodeExtPubKey(const std::string& str);
std::string EncodeExtPubKey(const CExtPubKey& extpubkey);

std::string EncodeDestination(const CTxDestination& dest);
CTxDestination DecodeDestination(const std::string& str);
CTxDestination DecodeAnyDestination(const std::string& str, std::string& detectedType); // Ring-fork: Decode any foreign address and transform it into a Ring CTxDestination
bool IsValidDestinationString(const std::string& str);
bool IsValidDestinationString(const std::string& str, const CChainParams& params);

// Function to validate if an address is a valid Mith address
bool IsValidMithAddress(const std::string& address);

// Function to validate if an address is a valid Ring address
bool IsValidRingAddress(const std::string& address);

// Function to check if an address is either Mith or Ring address
bool IsValidAddress(const std::string& address);

// Function to set the currency type for a given address
std::string GetCurrencyType(const std::string& address);

// Function to validate a transaction based on currency isolation rules
bool IsValidTransaction(const CTransaction& tx);

#endif // RING_KEY_IO_H
