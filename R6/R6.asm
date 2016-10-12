; Recitation 6
; Author: <name>
; Date:   <date>
; Email:  <email>
; Class:  CS270
;
; Description: Implements integer (16-bit) addition and subtraction
;
;------------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000
                BR Main

; A jump table defined as an array of addresses
Functions       .FILL IntAdd         ; address of add routine      (option 0)
                .FILL IntSub         ; address of subtract routine (option 1)
                .FILL IntMul         ; address of multiply routine (option 2)

Main            LEA R0,Functions     ; get base of jump table
                LD  R1,Option        ; get option to use, no error checking
                ADD R0,R0,R1         ; add index of array
                LDR R0,R0,0          ; get address of function
                JSRR R0              ; call selected function
                HALT

; Parameters and return values for all functions
Option          .BLKW 1              ; which function to call
Param1          .BLKW 1              ; space to specify first parameter
Param2          .BLKW 1              ; space to specify second parameter
Result          .BLKW 1              ; space to store result

; End reserved section: do not change ANYTHING in reserved section!
;------------------------------------------------------------------------------
IntAdd          LD R0, Param1        ; Your code goes here
                LD R1, Param2
		ADD R2, R0, R1
		ST R2, Result	             ; Solution has ~4 instructions
                RET
;------------------------------------------------------------------------------
IntSub          LD R0, Param1        ; Your code goes here
                LD R1, Param2        ; Solution has ~6 instructions
		
		NOT R1, R1
		ADD R1, R1, #1

		ADD R2, R0, R1
		
		ST R2, Result


                RET

;------------------------------------------------------------------------------
IntMul          .ZERO R3                     ; Your code goes here
                
		LD R0, Param1
		LD R1, Param2
		
		ADD R1, R1, #0
		BRz Done

		
Loop1		ADD R3, R0, R3
		ADD R1, R1, #-1
		BRp Loop1
		
Done		ST R3, Result
                RET

;------------------------------------------------------------------------------
               .END

