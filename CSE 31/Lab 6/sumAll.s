		.data
enter: .asciiz "Please enter a number: "
even: .asciiz "Sum of even numbers is: "
odd: .asciiz "Sum of odd numbers is: "
line_break: .asciiz "\n"

.text

main:
	li $v0, 5 #Get int from user
	syscall
	
	addi $t0, $v0, 0 #Move the input to $t0
	add $a0, $t0, $0
	beq $t0, $0, print #If the value the user enters is a 0 print out the data and finish the program
		andi $t1, $t0, 1
		beq $t1, $0, add_even
		j add_odd

add_odd:
	add $s0, $s0, $a0
	j main
	
add_even:
	add $s1, $s1, $a0
	j main

print:
	li $v0, 4 #Print out the even sum string
	la $a0, even
	syscall
	
	li $v0, 1 #print out the even sum
	move $a0, $s1
	syscall
	
	
	li $v0, 4 #Print out new line char
	la $a0, line_break
	syscall
	
	li $v0, 4 #Print out the odd sum string
	la $a0, odd
	syscall
	
	li $v0, 1 #Print out the odd sum
	move $a0, $s0
	syscall
	
	li $v0, 4 #Print out new line char
	la $a0, line_break
	syscall
	
	j finish
	
finish: 
		li $v0, 10	#End the program
		syscall		