#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'
BLUE='\033[0;34m'

# Error test cases
error_tests=(
    ""                          # Empty input
    "1 one"                     # Non-numeric
    "1 2 one 3"                # Non-numeric in middle
    "2147483648"               # Greater than INT_MAX
    "-2147483649"              # Less than INT_MIN
    "1 1"                      # Duplicate numbers
    "1 2 1"                    # Duplicate numbers
    "+"                        # Just a plus sign
    "-"                        # Just a minus sign
    "1 + 2"                    # Invalid sign usage
    "1.5"                      # Float number
    "a b c"                    # All non-numeric
    "2147483647+1"            # INT_MAX overflow
    "-2147483648-1"           # INT_MIN overflow
    " "                       # Just space
    "  "                      # Multiple spaces
)

# Valid test cases
valid_tests=(
    "0"                        # Single zero
    "-0"                       # Negative zero
    "+0"                       # Positive zero
    "1 2 3"                   # Simple ascending
    "3 2 1"                   # Simple descending
    "-1 -2 -3"               # Negative ascending
    "-3 -2 -1"               # Negative descending
    "2147483647"             # INT_MAX
    "-2147483648"            # INT_MIN
    "-2147483648 2147483647" # Both extremes
    "1 -1"                   # Positive and negative
    "+1 +2 +3"              # With plus signs
)

# Random number test cases
function generate_random_sequence() {
    local size=$1
    seq 1 $size | shuf | tr '\n' ' '
}

echo -e "${BLUE}=== Push_Swap Tester ===${NC}\n"

# Test error cases
echo -e "${YELLOW}Testing Error Cases:${NC}"
for test in "${error_tests[@]}"; do
    echo -n "Testing: '$test' -> "
    output=$(./a.out $test 2>&1)
    if [[ $output == *"Error"* ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC} (Expected 'Error', got '$output')"
    fi
done

echo -e "\n${YELLOW}Testing Valid Cases:${NC}"
for test in "${valid_tests[@]}"; do
    echo -n "Testing: '$test' -> "
    output=$(./a.out $test 2>&1)
    if [[ $? -eq 0 ]]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC} (Program failed)"
    fi
done

echo -e "\n${YELLOW}Testing Random Sequences:${NC}"
# Test different sizes
sizes=(3 5 10 100 500)
for size in "${sizes[@]}"; do
    echo -e "\nTesting size $size:"
    for i in {1..3}; do
        sequence=$(generate_random_sequence $size)
        echo -n "Test $i: "
        operations=$(./a.out $sequence | wc -l)
        if [ $size -eq 3 ]; then
            [ $operations -le 3 ] && result="${GREEN}OK${NC}" || result="${RED}KO${NC}"
        elif [ $size -eq 5 ]; then
            [ $operations -le 12 ] && result="${GREEN}OK${NC}" || result="${RED}KO${NC}"
        elif [ $size -eq 100 ]; then
            [ $operations -le 700 ] && result="${GREEN}OK${NC}" || result="${RED}KO${NC}"
        elif [ $size -eq 500 ]; then
            [ $operations -le 5500 ] && result="${GREEN}OK${NC}" || result="${RED}KO${NC}"
        else
            result="${BLUE}INFO${NC}"
        fi
        echo -e "Operations: $operations -> $result"
    done
done

# Memory leak test with valgrind if available
echo -e "\n${YELLOW}Testing Memory Leaks:${NC}"
if command -v valgrind &> /dev/null; then
    echo "Running valgrind..."
    valgrind --leak-check=full ./a.out "3 2 1" 2>&1 | grep -A1 "LEAK SUMMARY"
else
    echo -e "${RED}Valgrind not installed. Skipping memory leak test.${NC}"
fi

echo -e "\n${BLUE}=== Test Complete ===${NC}"

