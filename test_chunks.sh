#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Check if argument is provided
if [ "$#" -ne 1 ]; then
    echo -e "${RED}Usage: $0 \"<number sequence>\"${NC}"
    exit 1
fi

PATTERN="$1"

# Best results tracking
BEST_CHUNK=0
BEST_MOVES=999999

echo -e "${BLUE}Testing chunk sizes 1-100...${NC}\n"

for size in {1..100}
do
    # Create test pattener.c for each iteration
    cat > pattener.c << EOL
#include "push_swap.h"

int    calculate_optimal_chunk(t_stacks *stacks)
{
    if (stacks->size_a <= 20)
        return (stacks->size_a);
    return ($size);
}
EOL
    
    # Recompile
    make re >/dev/null 2>&1
    
    # Test and count moves
    MOVES=$(./push_swap "$PATTERN" | wc -l | tr -d ' ')
    
    # Check if better than previous best
    if [ $MOVES -lt $BEST_MOVES ]; then
        BEST_MOVES=$MOVES
        BEST_CHUNK=$size
        echo -e "${GREEN}New best: Chunk size $size with $MOVES moves${NC}"
    fi
    
    # If moves > 700, mark in red
    if [ $MOVES -gt 700 ]; then
        echo -e "${RED}Size $size: $MOVES moves${NC}"
    else
        echo -e "Size $size: $MOVES moves"
    fi
done

echo -e "\n${BLUE}=== Final Results ===${NC}"
echo -e "Best chunk size: ${GREEN}$BEST_CHUNK${NC}"
echo -e "Best moves: ${GREEN}$BEST_MOVES${NC}"
