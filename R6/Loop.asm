	.ORIG x3000
	BR Main
Counter	.FILL 5

Main	LD R0, Counter

Loop	NOT R1, R1
	ADD R0, R0, #-1
	BRp Loop

	.END
