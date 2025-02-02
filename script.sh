#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m'

run_test() {
    input="$1"
    description="$2"
    
    echo -e "${BLUE}Testing: ${description}${NC}"
    echo "Input: $input"
    
    # Run your program and capture stderr
    your_output=$(./a.out $input 2>&1)
    
    # Run checker with timeout to handle hanging state
    checker_output=$(timeout 0.5 ./checker_linux $input 2>&1)
    timeout_status=$?
    
    # Compare outputs
    if [ $timeout_status -eq 124 ]; then
        # Checker is hanging (valid input)
        if [ "$your_output" = "" ]; then
            echo -e "${GREEN}✓ PASS${NC} (Valid input)"
        else
            echo -e "${RED}✗ FAIL${NC}"
            echo "Your output: $your_output"
            echo "Checker: Waiting for input (valid case)"
        fi
    else
        # Checker returned Error
        if [[ "$your_output" == *"Error"* ]]; then
            echo -e "${GREEN}✓ PASS${NC} (Invalid input)"
        else
            echo -e "${RED}✗ FAIL${NC}"
            echo "Your output: $your_output"
            echo "Checker: Error"
        fi
    fi
    echo "----------------------------------------"
}

# Basic Tests
run_test "42" "Single number"
run_test "" "Empty input"
run_test " " "Single space"
run_test "      " "Multiple spaces"

# Crazy Space Tests
run_test "1        2          3" "Many spaces between numbers"
run_test " 1 2 3 " "Space before and after"
run_test "                    42                    " "Many spaces around single number"
run_test "1 2 3     4         5     6" "Random spaces"

# Sign Tests
run_test "+" "Just plus"
run_test "-" "Just minus"
run_test "+-42" "Plus then minus"
run_test "-+42" "Minus then plus"
run_test "+ 42" "Space after sign"
run_test "- 42" "Space after minus"
run_test "+42 -42" "Mixed signs"
run_test "1 +2 -3 +4 -5" "Alternating signs"

# Zero Tests
run_test "0" "Single zero"
run_test "-0" "Negative zero"
run_test "+0" "Positive zero"
run_test "00" "Double zero"
run_test "000000" "Many zeros"
run_test "-000" "Negative many zeros"
run_test "+000" "Positive many zeros"
run_test "0 00 000 0000" "Different zero lengths"

# INT_MAX/MIN Edge Cases
run_test "2147483647" "INT_MAX"
run_test "2147483648" "INT_MAX + 1"
run_test "-2147483648" "INT_MIN"
run_test "-2147483649" "INT_MIN - 1"
run_test "2147483646 2147483647" "INT_MAX sequence"
run_test "-2147483648 -2147483647" "INT_MIN sequence"

# Invalid Character Tests
run_test "42a" "Number with letter after"
run_test "a42" "Number with letter before"
run_test "4a2" "Number with letter middle"
run_test "42%" "Number with symbol after"
run_test "42.0" "Decimal number"
run_test "42,0" "Comma number"
run_test "42_42" "Underscore between"
run_test "42\n42" "Newline between"
run_test "42\t42" "Tab between"

# Multiple Signs Tests
run_test "++42" "Double plus"
run_test "--42" "Double minus"
run_test "+++42" "Triple plus"
run_test "---42" "Triple minus"
run_test "+42+42" "No space between signed numbers"
run_test "-42-42" "No space between negative numbers"

# Whitespace Torture Tests
run_test " 1  2   3    4     5" "Increasing spaces"
run_test "1 2  3   4    5     " "Trailing increasing spaces"
run_test "     1    2   3  4 5" "Decreasing spaces"
run_test "1	2 3  4   5" "Mixed tabs and spaces"

# Empty Parts Tests
run_test "1  2  3  " "Trailing spaces"
run_test "  1  2  3" "Leading spaces"
run_test "1 2   3     " "Multiple trailing spaces"
run_test "1  2  3  4  5  " "Spaces after each number"

# Zero Combinations
run_test "0 00 000 0000 00000" "Multiple zeros different lengths"
run_test "-0 +0 00 -00 +00" "Signed zeros"
run_test "0 1 0 2 0 3 0" "Zeros between numbers"

# Number Format Tests
run_test "042" "Leading zero"
run_test "0042" "Multiple leading zeros"
run_test "-042" "Negative with leading zero"
run_test "+042" "Positive with leading zero"
run_test "00000042" "Many leading zeros"

# Complex Mixed Tests
run_test "-0 +0 -1 +1 -2 +2" "Alternating signed numbers"
run_test "2147483647 -2147483648 0 1" "Mixed extremes"
run_test "1 -0 2 +0 3 000" "Mixed with different zeros"
run_test "-1 -2 -3 -4 -5" "All negative sequence"
run_test "+1 +2 +3 +4 +5" "All positive sequence"

# Really Evil Tests
run_test "- 42" "Space after minus"
run_test "+ 42" "Space after plus"
run_test "--42--43" "Double minus no space"
run_test "++42++43" "Double plus no space"
run_test "42 -" "Number then minus"
run_test "42 +" "Number then plus"
run_test "9999999999999999999" "Way too big number"
run_test "-9999999999999999999" "Way too small number"
run_test "0000000000000000001" "Many leading zeros valid"
run_test "0000000000000000000" "Many leading zeros zero"

# Duplicate Tests
run_test "42 42" "Simple duplicate"
run_test "42 1 42" "Duplicate with number between"
run_test "1 2 3 1" "Duplicate at end"
run_test "1 1 1 1 1" "All same number"
run_test "0 -0 +0 00 000" "Different forms of zero"

# Random Stress Tests
for i in {1..5}; do
    size=$((RANDOM % 50 + 1))
    numbers=$(for j in $(seq 1 $size); do 
        if [ $((RANDOM % 2)) -eq 0 ]; then
            echo -n "+"
        else
            echo -n "-"
        fi
        echo $((RANDOM % 2147483647))
    done | tr '\n' ' ')
    run_test "$numbers" "Random signed test $i ($size numbers)"
done

echo "Testing completed!"
