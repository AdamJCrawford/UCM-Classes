.data
x: .word 2
y: .word 3
z: .word 4


.text
main:
la $t0, x
lw $s0, 0($t0)

la $t0, y
lw $s1, 0($t0)

la $t0, z
lw $s2, 0($t0)

addi $a0, $s0, 0
addi $a1, $s1, 0
addi $a2, $s2, 0
jal foo

la $t0, x
lw $s0, 0($t0)

la $t0, y
lw $s1, 0($t0)

la $t0, z
lw $s2, 0($t0)

add $t0, $s0, $s1
add $t0, $t0, $s2
add $t0, $t0, $v0

addi $a0, $t0, 0 
li $v0, 1		 
syscall	
j finish

foo:
addi $sp, $sp, -16
sw $ra, 16($sp)
sw $s0, 12($sp)
sw $s1, 8($sp)
sw $s2, 4($sp)

add $a0, $s0, $s1
add $a1, $s1, $s2
add $a2, $s2, $s0
jal bar
addi $s0, $v0, 0

lw $t0, 12($sp) 
lw $t1, 8($sp) 
lw $t2, 4($sp) 

sub $a0, $t0,$t2
sub $a1, $t1, $t0
sll $a2, $t1, 1
jal bar
addi $s1, $v0, 0
add $v0, $s0, $s1

lw $ra, 16($sp)
lw $s0, 12($sp) 
lw $s1, 8($sp) 
lw $s2, 4($sp) 

jr $ra

bar:
sub $t0, $a2, $a0
sllv $v0, $t0, $a1
jr $ra

finish: 
li $v0, 10	#End the program
syscall		