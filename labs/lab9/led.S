// led.S
// turn LED on GPIO 5 on or off

.section .text                  // define this file as code
.align 2                        // make sure code aligns on word boundaries
.globl led                      // declare LED to be called externally

.equ GPIO_OUTPUT_VAL, 0x1001200C

// Our led output value passed into a0

led:
    addi sp, sp, -16            // Setup our stack frame
    sw ra, 12(sp)               // Save return address

    li t1, GPIO_OUTPUT_VAL      // Put address of GPIO0 output_val register in t1
    lw t2, 0(t1)                // Store current state of output_val register in  t2
    li t3, 0x20                 // Put a 1 in the 6th bit corresponding to GPIO 5
    beqz a0, ledoff
ledon:
    or t2, t2, t3
    j finish
ledoff:
    not t3, t3
    and t2, t2, t3
finish:
    sw t2, 0(t1)
    lw ra, 12(sp)               // Restore the return address
    addi sp, sp, 16             // Deallocate stack frame
    ret 