        .data
n:      .word 20
str1: .asciiz "Less than\n" 
str2: .asciiz "Less than or equal to\n" 
str3: .asciiz "Greater than\n" 
str4: .asciiz "Greater than or equal to\n" 

.text
main: 	
	li $v0, 5 #Get int from user
	syscall
	
	addi $t0, $v0, 0 #Move the input to $t0
	
	la $t2, n #Get the value of n
	lw $t2, 0($t2)
	
	#slt $t3, $t2, $t0 # $t2 < $t0 ?
	#bne $t3, $zero, gte #If $t2 > $t0 jump to greater than or equal to label
		#li $v0, 4 #Print out the string
		#la $a0, str1
		#syscall
		#j finish		
#gte:
	#li $v0, 4 #Print out the string
	#la $a0, str4
	#syscall	
	#j finish
	
	slt $t3, $t0, $t2 # $t2 > $t0 ?
	bne $t3, $zero, lte #If $t2 < $t0 jump to greater than or equal to label
		li $v0, 4 #Print out the string
		la $a0, str3
		syscall
		j finish		
lte:
	li $v0, 4 #Print out the string
	la $a0, str2
	syscall	
	j finish

finish: 
		li $v0, 10	#End the program
		syscall		





