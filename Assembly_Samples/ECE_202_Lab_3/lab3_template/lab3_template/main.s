;******************** (C) Yifeng ZHU *******************************************
; @file    main.s
; @author  Yifeng Zhu
; @date    May-17-2015
; @note
;           This code is for the book "Embedded Systems with ARM Cortex-M 
;           Microcontrollers in Assembly Language and C, Yifeng Zhu, 
;           ISBN-13: 978-0982692639, ISBN-10: 0982692633
; @attension
;           This code is provided for education purpose. The author shall not be 
;           held liable for any direct, indirect or consequential damages, for any 
;           reason whatever. More information can be found from book website: 
;           http:;www.eece.maine.edu/~zhu/book
;*******************************************************************************


	INCLUDE core_cm4_constants.s		; Load Constant Definitions
	INCLUDE stm32l476xx_constants.s      

	IMPORT 	System_Clock_Init
	IMPORT 	UART2_Init
	IMPORT	USART2_Write
	
	AREA    main, CODE, READONLY
	EXPORT	__main				; make __main visible to linker
	ENTRY			
				
__main	PROC
	
;;;;;;; vv Jeremy Love Added Code vv ;;;;;;;;;;
	
;;;;;;; vv Enable Pins vv ;;;;;;;;;;

; Enable the Clock for Port B (7-Seg Pins) and Port C (User Button)
	
	MOV r0, #0x6 ; hex target value (x11x) for bits of interest
	
	LDR r1, =RCC_BASE ; load base address into core register r1
	LDR r2, [r1, #RCC_AHB2ENR] ; load data from given offset value
		
	BFC r2, #1, #2 ; clear all bits of interest (1, 2)
	ORR r2, r0 ; set bits of interest to target values (r0)
	
	STR r2, [r1, #RCC_AHB2ENR] ; store data back into memory location

; Pin Initialization for User Button

	; Set Mode of PC 13 to Input

		MOV r0, #0x0 ; hex target value (00xx xxxx xxxx xxxx xxxx xxxx xxxx) for bits of interest

		LDR r1, =GPIOC_BASE ; load base address into core register r1
		LDR r2, [r1, #GPIO_MODER] ; load data from given offset value
	
		BFC r2, #26, #2 ; clear all bits of interest (26, 27)
		ORR r2, r0 ; set bits of interest to target values (r0)
	
		STR r2, [r1, #GPIO_MODER] ; store data back into memory location

	; Set PC 13 (User Button) to No Pullup and No Pulldown
		
		MOV r0, #0x0 ; target value 00xx xxxx xxxx xxxx xxxx xxxx xxxx
	
		LDR r1, =GPIOC_BASE
		LDR r2, [r1, #GPIO_PUPDR]
	
		BFC r2, #26, #2 ; bits of interest 26, 27
		ORR r2, r0
	
		STR r2, [r1, #GPIO_PUPDR]
	
; Pin Initialization for 7 Seg Pins

	; Set the Mode to Output
	
		MOV r0, #0x5050 ; target value 0101 xxxx 0101 xxxx
	
		LDR r1, =GPIOB_BASE
		LDR r2, [r1, #GPIO_MODER]
	
		BFC r2, #4, #4 ; bits of interest 4, 5, 6, 7
		BFC r2, #12, #4 ; bits of interest 12, 13, 14, 15
		ORR r2, r0
	
		STR r2, [r1, #GPIO_MODER]

	; Set the Output Type to Push-Pull
	
		MOV r0, #0x0 ; target value 00xx 00xx
	
		LDR r1, =GPIOB_BASE
		LDR r2, [r1, #GPIO_OTYPER]
		
		BFC r2, #2, #2 ; bits of interest 2, 3
		BFC r2, #6, #2 ; bits of interest 6, 7
		ORR r2, r0
		
		STR r2, [r1, #GPIO_OTYPER]
	
	; Set to No Pullup and No Pulldown
	
		MOV r0, #0x0 ; target value 0000 xxxx 0000 xxxx
	
		LDR r1, =GPIOB_BASE
		LDR r2, [r1, #GPIO_PUPDR]
		
		BFC r2, #4, #4 ; bits of interest 4, 5, 6, 7
		BFC r2, #12, #4 ; bits of interest 12, 13, 14, 15
		ORR r2, r0
		
		STR r2, [r1, #GPIO_PUPDR]
		
;;;;;;; ^^ Enable Pins ^^ ;;;;;;;;;;

;;;;;;; vv Count Loop vv ;;;;;;;;;;
	
	; Set count pin register values
		MOV r1, #0x0 ; B pins 3, 2
		MOV r2, #0x0 ; B pins 7, 6	
	
	; main loop code
		MOV r0, #0
		B check
loop	
		
;;;;;;; vv Delay Loop vv ;;;;;;;;;;

		MOV r3, #0
		B check2
loop2	ADD r3, r3, #0x1

		MOV r4, #0
		B check3
loop3	ADD r4, r4, #0x1
check3	CMP r4, #0x990
		BNE loop3
endloop3

check2	CMP r3, #0x50
		BNE loop2
endloop2
		
;;;;;;; ^^ Delay Loop ^^ ;;;;;;;;;;
		
;;;;;;; vv Output Logic vv ;;;;;;;;;;	
		
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_ODR]
		
		BFI r4, r1, #2, #2
		BFI r4, r2, #6, #2
		
		STR r4, [r3, #GPIO_ODR]
		
;;;;;;; ^^ Output Logic ^^ ;;;;;;;;;;
		
;;;;;;; vv Count Logic vv ;;;;;;;;;;	
		
	; increment r1
		ADD r1, r1, #0x1
		
	; check if r2 needs incremented and do so if true
		CMP r1, #4
		BNE endif
		ADD r2, r2, #0x1
		MOV r1, #0x0
endif

	; check if value = 1001 and reset if so
		CMP r2, #2
		BNE endif2
		CMP r1, #2
		BNE endif2
		MOV r1, #0x0
		MOV r2, #0x0
endif2
		
;;;;;;; ^^ Count Logic ^^ ;;;;;;;;;;

;;;;;;; vv Button Logic vv ;;;;;;;;;;

		LDR r3, =GPIOC_BASE
		LDR r4, [r3, #GPIO_IDR]

		CMP r4, #0
		BGT endif3
		MOV r1, #0x0
		MOV r2, #0x0
endif3

;;;;;;; ^^ Button Logic ^^ ;;;;;;;;;;

check	CMP r0, #1
		BLT loop
endloop

;;;;;;; ^^ Count Loop ^^ ;;;;;;;;;;
	
;;;;;;; ^^ Jeremy Love Added Code ^^ ;;;;;;;;;;
	
stop 	B 		stop     		; dead loop & program hangs here

	ENDP
								

	AREA myData, DATA, READWRITE
	ALIGN

	END