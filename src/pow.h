// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Copyright (c) 2025 The dwarf developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef RING_POW_H
#define RING_POW_H

#include <consensus/params.h>

#include <stdint.h>

class CBlockHeader;
class CBlockIndex;
class uint256;
class CBlock;   // Ring-fork: Hive

// Ring-fork: Hive
struct DwarfPopGraphPoint {
    int immaturePop;
    int maturePop;
};

unsigned int GetNextWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params&);

/** Check whether a block hash satisfies the proof-of-work requirement specified by nBits */
bool CheckProofOfWork(uint256 hash, unsigned int nBits, const Consensus::Params&);

unsigned int GetNextHiveWorkRequired(const CBlockIndex* pindexLast, const Consensus::Params& params);           // Ring-fork: Hive: Get the current Dwarf Hash Target
bool CheckHiveProof(const CBlock* pblock, const Consensus::Params& params);                                     // Ring-fork: Hive: Check the hive proof for given block
bool GetNetworkHiveInfo(int& immatureDwarves, int& immatureDCTs, int& matureDwarves, int& matureDCTs, CAmount& potentialLifespanRewards, const Consensus::Params& consensusParams, bool recalcGraph = false); // Ring-fork: Hive: Get count of all live and gestating DCTs on the network
// Declare the ASERT difficulty adjustment mechanism
unsigned int GetNextASERTWorkRequired(const CBlockIndex* pindexLast, const CBlockHeader *pblock, const Consensus::Params& params);

// Declare the Argon2iD mining algorithm
bool Argon2idHash(const void* password, const size_t password_len, const void* salt, const size_t salt_len, void* out, const size_t out_len);

#endif // RING_POW_H
