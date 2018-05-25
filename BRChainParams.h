//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 elicoinwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "seed1.elicoin.net.", "seed2.elicoin.net.", NULL
};

static const char *BRTestNetDNSSeeds[] = {
    "seed1.elicoin.net.", "seed2.elicoin.net.", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {      0, uint256("51aea10af5d8bf104c96cde790d51a5f6ea6cc5d80e49e1aa2389cb5d2166dec"), 1519589181, 0x20000fff }
    // {  20160, uint256("066b8ec9ca1e83ca2684563901ab0b24a96ad6e7b98ae271d1afd0c7f39dea37"), 1520955319, 0x1e00d00d },
    // {  40320, uint256("fa4bc1f993ec7ad742c74d1b493887efba0f5210b87bb864dad3495d49275d2c"), 1522225851, 0x1e00910d },
    // {  60480, uint256("0dfdbb3753b2760fe715d7f0f8c2cf743315f175b35812b4b1da5b95f00d6d4e"), 1523496730, 0x1e009bec },
    // {  80640, uint256("be60ebe224aef503e12203cd927d1d0adf20d0859d4c564adfb7bbaa4e6a8154"), 1524766732, 0x1e00c589 }
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("000000000933ea01ad0ee984209779baaec3ced90fa3f408719526f8d77f4943"), 1296688602, 0x1d00ffff }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
  // const BRMerkleBlock *previous, *b = NULL;
  // uint32_t i;

    assert(block != NULL);
    assert(blockSet != NULL);

    // check if we hit a difficulty transition, and find previous transition block
    // if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //     for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //         b = BRSetGet(blockSet, &b->prevBlock);
    //     }
    // }
    //
    // previous = BRSetGet(blockSet, &block->prevBlock);
    // return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);

    return BRMerkleBlockVerifyDifficultyDarkGravityWave(block,blockSet);
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    2059,       // standardPort
    0x0c6657a6, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints)/sizeof(*BRMainNetCheckpoints)
};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    20595,      // standardPort
    0x54397dcb, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints)/sizeof(*BRTestNetCheckpoints)
};

#endif // BRChainParams_h
