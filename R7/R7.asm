; Recitation 7
; Author: <name>
; Date:   <date>
; Email:  <email>
; Class:  CS270
; Description: Mirrors least significant byte to most significant
;--------------------------------------------------------------------------
; Begin reserved section: do not change ANYTHING in reserved section!

                .ORIG x3000

                JSR mirror           ; call function
                HALT

; Parameter and return value
Param           .BLKW 1              ; space to specify parameter
Result          .BLKW 1              ; space to store result

; Constants
One             .FILL #1             ; the number 1       
Eight           .FILL #8             ; the number 8
Mask            .FILL x00ff          ; mask top bits

; End reserved section: do not change ANYTHING in reserved section!
;--------------------------------------------------------------------------
mirror                               ; Mirrors bits 7:0 to 15:8
                                     ; ~20 lines of assembly code
 
                LD R0,Param          ; load pattern
               	AND R1, R0 
		LD R2, Mask           ; your code here
		NOT R2, R2
		AND Result, Result, R2
		ADD R2, R2, #1
		ADD R3, R3, #1
		ADD R4, R4, #8

Loop		
		ADD R3, R3, R3
		ADD R4, R4, #-1

		BRp Loop
		
		ADD R4, R4, #8
		
Loop1		
		
		ADD Result, Result, R3
		ADD R2, R2, R2
		ADD R3, R3, R3
		ADD R4, R4 #-1

		BR Loop1
		
                ST R1,Result         ; store result
                RET
;--------------------------------------------------------------------------
               .END

