#!/bin/bash

# Colors and formatting
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[1;37m'
BOLD='\033[1m'
DIM='\033[2m'
ITALIC='\033[3m'
UNDERLINE='\033[4m'
NC='\033[0m'

# Tracking variables
WORST_MOVES=0
WORST_PATTERN=""
TOTAL_TESTS=0
FAILED_TESTS=0
START_TIME=$(date +%s)
LOG_FILE="test_log.txt"

# Initialize log file
echo "Push_swap Test Results - $(date)" > $LOG_FILE
echo "================================" >> $LOG_FILE

print_banner() {
    clear
    echo -e "${BLUE}${BOLD}"
    echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗"
    echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
    echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
    echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝"
    echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║"
    echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝"
    echo -e "${NC}"
    echo -e "${CYAN}${BOLD}                     MEGA EVIL PATTERN TESTER${NC}"
    echo -e "${DIM}                        by isel-kha @ 42${NC}"
    echo
}

show_progress() {
    local current=$1
    local total=$2
    local width=50
    local percentage=$((current * 100 / total))
    local completed=$((width * current / total))
    
    printf "\r${YELLOW}Progress: [${NC}"
    for ((i = 0; i < completed; i++)); do printf "█"; done
    for ((i = completed; i < width; i++)); do printf "░"; done
    printf "${YELLOW}] %d%%${NC}" $percentage
}

test_pattern() {
    local name=$1
    local arg=$2
    
    ((TOTAL_TESTS++))
    show_progress $TOTAL_TESTS 1000
    
    # Run push_swap and checker
    local output=$(./push_swap $arg 2>/dev/null)
    if [ $? -ne 0 ]; then
        echo -e "\n${RED}Error: push_swap failed to execute${NC}"
        return
    fi
    
    local moves=$(echo "$output" | wc -l | tr -d ' ')
    local result=$(echo "$output" | ./checker_linux $arg 2>/dev/null)
    
    # Update worst case
    if [ "$moves" -gt "$WORST_MOVES" ]; then
        WORST_MOVES=$moves
        WORST_PATTERN="$arg"
        echo -e "\n${RED}${BOLD}New worst case found: $moves moves!${NC}"
        
        # Log worst case
        echo -e "\nNew Worst Case Found:" >> $LOG_FILE
        echo "Pattern: $name" >> $LOG_FILE
        echo "Moves: $moves" >> $LOG_FILE
        echo "Numbers: $arg" >> $LOG_FILE
        echo "------------------------" >> $LOG_FILE
    fi
    
    # Count failures
    if [ "$moves" -gt 700 ]; then
        ((FAILED_TESTS++))
    fi
    
    # Log test
    echo "Test #$TOTAL_TESTS: $name" >> $LOG_FILE
    echo "Moves: $moves" >> $LOG_FILE
    echo "Result: $result" >> $LOG_FILE
    echo "-------------------" >> $LOG_FILE
}

generate_evil_patterns() {
    # Original evil pattern
    local EVIL="94 98 97 96 95 99 93 92 91 90 84 88 87 86 85 89 83 82 81 80 74 78 77 76 75 79 73 72 71 70 64 68 67 66 65 69 63 62 61 60 54 58 57 56 55 59 53 52 51 50 44 48 47 46 45 49 43 42 41 40 34 38 37 36 35 39 33 32 31 30 24 28 27 26 25 29 23 22 21 20 14 18 17 16 15 19 13 12 11 10 4 8 7 6 5 9 3 2 1 0"
    test_pattern "Original Evil Pattern" "$EVIL"
    
    # Generate variations using Python
    for ((i=1; i<=50; i++)); do
        # Multi-level swaps
        ARG=$(python3 -c "
import random
nums = list(range(99, -1, -1))
for j in range(0, 98, 2):
    if random.random() < 0.7:
        nums[j], nums[j+1] = nums[j+1], nums[j]
for j in range(0, 96, 4):
    if random.random() < 0.5:
        nums[j:j+2], nums[j+2:j+4] = nums[j+2:j+4], nums[j:j+2]
for j in range(5):
    a, b = random.sample(range(100), 2)
    nums[a], nums[b] = nums[b], nums[a]
print(' '.join(map(str, nums)))")
        test_pattern "Multi-level Pattern $i" "$ARG"

        # Wave pattern
        ARG=$(python3 -c "
import random
nums = list(range(99, -1, -1))
for j in range(0, 90, 10):
    if random.random() < 0.8:
        section = nums[j:j+10]
        mid = len(section)//2
        section[:mid], section[mid:] = section[mid:], section[:mid]
        if random.random() < 0.6:
            a, b = random.sample(range(len(section)), 2)
            section[a], section[b] = section[b], section[a]
        nums[j:j+10] = section
print(' '.join(map(str, nums)))")
        test_pattern "Wave Pattern $i" "$ARG"

        # Strategic reverse
        ARG=$(python3 -c "
import random
nums = list(range(99, -1, -1))
step = random.randint(5, 15)
for j in range(0, 100-step, step):
    if random.random() < 0.7:
        nums[j], nums[j+step-1] = nums[j+step-1], nums[j]
        if random.random() < 0.5:
            mid = j + step//2
            if mid+1 < len(nums):
                nums[mid], nums[mid+1] = nums[mid+1], nums[mid]
print(' '.join(map(str, nums)))")
        test_pattern "Strategic Reverse $i" "$ARG"
    done
}

print_summary() {
    local end_time=$(date +%s)
    local total_time=$((end_time - START_TIME))
    
    clear
    print_banner
    
    echo -e "${PURPLE}${BOLD}Test Results Summary${NC}"
    echo -e "${DIM}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${WHITE}Total tests run:     ${YELLOW}$TOTAL_TESTS${NC}"
    echo -e "${WHITE}Failed tests:        ${RED}$FAILED_TESTS${NC}"
    echo -e "${WHITE}Pass rate:           ${GREEN}$(( (TOTAL_TESTS - FAILED_TESTS) * 100 / TOTAL_TESTS ))%${NC}"
    echo -e "${WHITE}Worst case moves:    ${RED}$WORST_MOVES${NC}"
    echo -e "${WHITE}Total time:          ${YELLOW}${total_time}s${NC}"
    
    echo -e "\n${PURPLE}${BOLD}Worst Case Pattern${NC}"
    echo -e "${DIM}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${WHITE}$WORST_PATTERN${NC}"
    
    echo -e "\n${GREEN}${BOLD}Detailed results have been saved to $LOG_FILE${NC}"
}

# Main execution
print_banner
echo -e "${YELLOW}Starting comprehensive push_swap testing...${NC}\n"

# Check for push_swap and checker
if [ ! -f "./push_swap" ]; then
    echo -e "${RED}Error: push_swap not found in current directory${NC}"
    exit 1
fi

if [ ! -f "./checker_linux" ]; then
    echo -e "${RED}Error: checker not found in current directory${NC}"
    exit 1
fi

# Run tests
generate_evil_patterns

# Show final results
print_summary
