#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Test tracking
WORST_MOVES=0
WORST_PATTERN=""

# Function to test a pattern
test_pattern() {
    local name=$1
    local arg=$2
    
    echo -e "${YELLOW}Testing: $name${NC}"
    
    # Run push_swap and capture output
    local output=$(./push_swap $arg)
    local moves=$(echo "$output" | wc -l | tr -d ' ')
    
    # Run checker
    local result=$(echo "$output" | ./checker_linux $arg)
    
    # Update worst case if needed
    if [ "$moves" -gt "$WORST_MOVES" ]; then
        WORST_MOVES=$moves
        WORST_PATTERN="$arg"
        echo -e "${RED}New worst case found!${NC}"
    fi
    
    # Print results
    if [ "$moves" -gt 700 ]; then
        echo -e "${RED}Failed: $moves moves (> 700)${NC}"
    else
        echo -e "${GREEN}Passed: $moves moves${NC}"
    fi
    echo -e "Checker result: $result\n"
}

echo -e "${BLUE}=== Push_swap Evil Pattern Tester (Linux) ===${NC}\n"

# Test 1: Cross-group swaps
ARG=$(python3 -c 'nums = list(range(99, -1, -1))
for i in range(0, 80, 20):
    if i+15 < 100:
        nums[i], nums[i+15] = nums[i+15], nums[i]
        nums[i+5], nums[i+10] = nums[i+10], nums[i+5]
print(" ".join(map(str, nums)))')
test_pattern "Cross-group swaps" "$ARG"

# Test 2: Triple-swap cascade
ARG=$(python3 -c 'nums = list(range(99, -1, -1))
for i in range(0, 90, 10):
    if i+6 < 100:
        nums[i], nums[i+2] = nums[i+2], nums[i]
        nums[i+3], nums[i+5] = nums[i+5], nums[i+3]
        nums[i+4], nums[i+6] = nums[i+6], nums[i+4]
print(" ".join(map(str, nums)))')
test_pattern "Triple-swap cascade" "$ARG"

# Test 3: Complex interleaved
ARG=$(python3 -c 'nums = list(range(99, -1, -1))
for i in range(0, 95, 5):
    if i+4 < 100:
        nums[i], nums[i+2] = nums[i+2], nums[i]
        nums[i+1], nums[i+3] = nums[i+3], nums[i+1]
        if i % 10 == 0:
            nums[i], nums[i+4] = nums[i+4], nums[i]
print(" ".join(map(str, nums)))')
test_pattern "Complex interleaved" "$ARG"

# Test 4: Known evil pattern
ARG="94 98 97 96 95 99 93 92 91 90 84 88 87 86 85 89 83 82 81 80 74 78 77 76 75 79 73 72 71 70 64 68 67 66 65 69 63 62 61 60 54 58 57 56 55 59 53 52 51 50 44 48 47 46 45 49 43 42 41 40 34 38 37 36 35 39 33 32 31 30 24 28 27 26 25 29 23 22 21 20 14 18 17 16 15 19 13 12 11 10 4 8 7 6 5 9 3 2 1 0"
test_pattern "Known evil pattern" "$ARG"

# Test 5: Reverse with strategic swaps
ARG=$(python3 -c 'nums = list(range(99, -1, -1))
for i in range(0, 100, 7):
    if i+3 < 100:
        nums[i], nums[i+3] = nums[i+3], nums[i]
print(" ".join(map(str, nums)))')
test_pattern "Reverse with strategic swaps" "$ARG"

# Summary
echo -e "${BLUE}=== Testing Complete ===${NC}"
echo -e "${YELLOW}Worst case found:${NC}"
echo "Moves: $WORST_MOVES"
if [ "$WORST_MOVES" -gt 700 ]; then
    echo -e "${RED}Pattern exceeds limit!${NC}"
    echo "Pattern: $WORST_PATTERN"
fi
