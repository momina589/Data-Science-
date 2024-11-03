.data
prompt1: .asciiz "Enter your expression (e.g., 3+2*3): "
result_msg: .asciiz "The result is: "
newline: .asciiz "\n"
error_msg: .asciiz "Invalid operation or input.\n"
div_zero_msg: .asciiz "Error: Division by zero.\n"
expr_buffer: .space 100  # Buffer to store the expression input
temp_buffer: .space 10   # Buffer to store temporary numbers

.text
.globl main

main:
    # Prompt for the expression
    li $v0, 4
    la $a0, prompt1
    syscall

    # Read the expression
    li $v0, 8
    la $a0, expr_buffer
    li $a1, 100  # Buffer length
    syscall

    # Evaluate the expression
    la $t0, expr_buffer
    jal evaluate_expression

    # Print the result message
    li $v0, 4
    la $a0, result_msg
    syscall

    # Print the result
    li $v0, 1
    move $a0, $t2  # $t2 contains the result
    syscall

    # Print newline
    li $v0, 4
    la $a0, newline
    syscall

    # Exit the program
    li $v0, 10
    syscall

evaluate_expression:
    li $t2, 0
    li $t4, 0
    loop_start:
        lb $t3, 0($t0)  # Load the next character
        beq $t3, 0, loop_end  # End of string
        # Check if character is a digit
        blt $t3, 48, check_operator  # Less than '0'
        bgt $t3, 57, check_operator  # Greater than '9'
        # Convert character to integer and store in $t5
        sub $t5, $t3, 48
        # Update the current number
        mul $t6, $t1, 10
        add $t1, $t6, $t5
        # Move to the next character
        addi $t0, $t0, 1
        j loop_start

    check_operator:
        # Process the previous number
        bne $t1, $zero, process_number
        # Move to the next character
        addi $t0, $t0, 1
        j loop_start
    process_number:
        # Perform the operation
        beq $t4, 0, add_operation
        beq $t4, 1, sub_operation
        beq $t4, 2, mul_operation
        beq $t4, 3, div_operation
    add_operation:
        add $t2, $t2, $t1
        j update_operation
    sub_operation:
        sub $t2, $t2, $t1
        j update_operation
    mul_operation:
        mul $t2, $t2, $t1
        j update_operation
    div_operation:
        beq $t1, 0, div_zero_error  # If divisor is 0, go to div_zero_error
        div $t2, $t1
        mflo $t2
        j update_operation
    update_operation:
        # Reset the current number
        li $t1, 0
        beq $t3, 43, set_add  # '+'
        beq $t3, 45, set_sub  # '-'
        beq $t3, 42, set_mul  # '*'
        beq $t3, 47, set_div  # '/'
        # Move to the next character
        addi $t0, $t0, 1
        j loop_start
    set_add:
        li $t4, 0
        j loop_start
    set_sub:
        li $t4, 1
        j loop_start
    set_mul:
        li $t4, 2
        j loop_start
    set_div:
        li $t4, 3
        j loop_start

    loop_end:
        # Process the last number
        beq $t1, $zero, end_evaluation
        beq $t4, 0, add_operation
        beq $t4, 1, sub_operation
        beq $t4, 2, mul_operation
        beq $t4, 3, div_operation
    end_evaluation:
        jr $ra
div_zero_error:
    li $v0, 4
    la $a0, div_zero_msg
    syscall
    li $v0, 10
    syscall
# Function to compare strings
string_compare:
    li $v0, 1  # Assume strings are equal
    move $t0, $zero  # Index

compare_loop:
    lb $t6, 0($t2)
    lb $t7, 0($t4)
    bne $t6, $t7, strings_not_equal
    addi $t2, $t2, 1
    addi $t4, $t4, 1
    addi $t0, $t0, 1
    blt $t0, $t5, compare_loop
    jr $ra

strings_not_equal:
    li $v0, 0  # Strings are not equal
    jr $ra
