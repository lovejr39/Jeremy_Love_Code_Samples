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
	
	BL System_Clock_Init
	BL UART2_Init

;;;;;;; vv Enable Pins vv ;;;;;;;;;;

	; enable RCC clock for GPIO pins B and C
	
		LDR r0, =RCC_BASE
		LDR r1, [r0, #RCC_AHB2ENR]
		ORR r1, #0x6
		STR r1, [r0, #RCC_AHB2ENR]

	; Set Port C Pins 0, 1, 2, 3 to GPIO Mode Digital Output
	
		MOV r0, #0x55 ; hex target value (0101 0101) for bits of interest
		
		LDR r1, =GPIOC_BASE ; load base address into core register r1
		LDR r2, [r1, #GPIO_MODER] ; load data from given offset value
	
		BFC r2, #0, #8 ; clear all bits of interest (0 through 7)
		ORR r2, r0 ; set bits of interest to target values (r0)
		
		STR r2, [r1, #GPIO_MODER] ; store data back into memory location
		
	; Set Port B Pins 1, 2, 3, 5 to GPIO Mode Digital Input

		MOV r0, #0x0 ; target value 00xx 0000 00xx
	
		LDR r1, =GPIOB_BASE
		LDR r2, [r1, #GPIO_MODER]
	
		BFC r2, #2, #6 ; bits of interest 2 through 7
		BFC r2, #10, #2 ; bits of interest 10, 11
		ORR r2, r0
	
		STR r2, [r1, #GPIO_MODER]
		
;;;;;;; ^^ Enable Pins ^^ ;;;;;;;;;;
	
	; main loop code
		MOV r0, #0x0
		B checkml
mainloop
restartloop

	; pull down all rows
		MOV r1, #0x0 ; target value 0000
		
		LDR r2, =GPIOC_BASE
		LDR r3, [r2, #GPIO_ODR]
		
		BFC r3, #0, #4 ; bits of interest 0 through 3
		ORR r3, r1
		
		STR r3, [r2, #GPIO_ODR]
		
	; delay
		BL delay 
		
	; check if all columns inputs are 1
		MOV r1, #0x2E ; comparison value xx1x 111x
		
		LDR r2, =GPIOB_BASE
		LDR r3, [r2, #GPIO_IDR]
		
		BFC r3, #0, #1
		BFC r3, #4, #1
		BFC r3, #6, #26
		
		CMP r3, r1
		BEQ.W nokeypressed ; bypass button checking code if no button pressed
		
		
	; pull down row 1 only
		MOV r1, #0xE ; target value 1110
		
		LDR r2, =GPIOC_BASE
		LDR r3, [r2, #GPIO_ODR]
		
		BFC r3, #0, #4 ; bits of interest 0 through 3
		ORR r3, r1
		
		STR r3, [r2, #GPIO_ODR]
		
	; delay
		BL delay
		
	; check if all column inputs are 1
		MOV r2, #0x2E ; comparison value xx1x 111x
		
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_IDR]
		
		BFC r4, #0, #1
		BFC r4, #4, #1
		BFC r4, #6, #26
		
		CMP r4, r2
		BNE keyispressed ; proceed to column checking, r1 holding row indicator
		
		
	; pull down row 2 only
		MOV r1, #0xD ; target value 1101
		
		LDR r2, =GPIOC_BASE
		LDR r3, [r2, #GPIO_ODR]
		
		BFC r3, #0, #4 ; bits of interest 0 through 3
		ORR r3, r1
		
		STR r3, [r2, #GPIO_ODR]
		
	; delay
		BL delay
		
	; check if all column inputs are 1
		MOV r2, #0x2E ; comparison value xx1x 111x
		
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_IDR]
		
		BFC r4, #0, #1
		BFC r4, #4, #1
		BFC r4, #6, #26
		
		CMP r4, r2
		BNE keyispressed ; proceed to column checking, r1 holding row indicator
		
		
	; pull down row 3 only
		MOV r1, #0xB ; target value 1011
		
		LDR r2, =GPIOC_BASE
		LDR r3, [r2, #GPIO_ODR]
		
		BFC r3, #0, #4 ; bits of interest 0 through 3
		ORR r3, r1
		
		STR r3, [r2, #GPIO_ODR]
		
	; delay
		BL delay
		
	; check if all column inputs are 1
		MOV r2, #0x2E ; comparison value xx1x 111x
		
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_IDR]
		
		BFC r4, #0, #1
		BFC r4, #4, #1
		BFC r4, #6, #26
		
		CMP r4, r2
		BNE keyispressed ; proceed to column checking, r1 holding row indicator
		
		
	; pull down row 4 only
		MOV r1, #0x7 ; target value 0111
		
		LDR r2, =GPIOC_BASE
		LDR r3, [r2, #GPIO_ODR]
		
		BFC r3, #0, #4 ; bits of interest 0 through 3
		ORR r3, r1
		
		STR r3, [r2, #GPIO_ODR]
		
	; delay
		BL delay
		
	; check if all column inputs are 1
		MOV r2, #0x2E ; comparison value xx1x 111x
		
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_IDR]
		
		BFC r4, #0, #1
		BFC r4, #4, #1
		BFC r4, #6, #26
		
		CMP r4, r2
		BEQ restartloop ; return to beginning of loop to pull all rows to low
		
keyispressed ; note: r1 holding row indicator mask
	
	; read column states
		LDR r3, =GPIOB_BASE
		LDR r4, [r3, #GPIO_IDR]
		
		BFC r4, #0, #1
		BFC r4, #4, #1
		BFC r4, #6, #26
		
	; compare to column 1 mask
		MOV r2, #0x2C
		CMP r4, r2
		BEQ columnfound
		
	; compare to column 2 mask
		MOV r2, #0x2A
		CMP r4, r2
		BEQ columnfound
		
	; compare to column 3 mask
		MOV r2, #0x26
		CMP r4, r2
		BEQ columnfound
		
	; compare to column 4 mask
		MOV r2, #0xE
		CMP r4, r2
		BNE restartloop
		
columnfound
		
	; loop until button is released
		B checkrl
releaseloop
		MOV r3, #0x2E ; comparison value xx1x 111x
		
		LDR r4, =GPIOB_BASE
		LDR r6, [r4, #GPIO_IDR]
		
		BFC r6, #0, #1
		BFC r6, #4, #1
		BFC r6, #6, #26
		
checkrl	CMP r6, r3
		BNE releaseloop

	; determine row character
		MOV r3, #0xE
		CMP r1, r3
		BEQ row1
		
		MOV r3, #0xD
		CMP r1, r3
		BEQ row2
		
		MOV r3, #0xB
		CMP r1, r3
		BEQ row3
		
		MOV r3, #0x7
		CMP r1, r3
		BEQ row4
	
	; determine column, find acsii value (First Argument for writing to TeraTerm
row1
		
		LDR r0, =str1 ; First argument
		MOV r3, #0x2C
		CMP r2, r3
		BEQ asciifound 

		LDR r0, =str2 ; First argument
		MOV r3, #0x2A
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str3 ; First argument 
		MOV r3, #0x26
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str_A ; First argument
		MOV r3, #0xE
		CMP r2, r3
		BEQ asciifound

row2
	
		LDR r0, =str4 ; First argument (etc)
		MOV r3, #0x2C
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str5
		MOV r3, #0x2A
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str6
		MOV r3, #0x26
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str_B
		MOV r3, #0xE
		CMP r2, r3
		BEQ asciifound
	
row3

		LDR r0, =str7
		MOV r3, #0x2C
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str8
		MOV r3, #0x2A
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str9
		MOV r3, #0x26
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str_C
		MOV r3, #0xE
		CMP r2, r3
		BEQ asciifound

row4

		LDR r0, =str_atr
		MOV r3, #0x2C
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str0
		MOV r3, #0x2A
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str_pnd
		MOV r3, #0x26
		CMP r2, r3
		BEQ asciifound

		LDR r0, =str_D
		MOV r3, #0xE
		CMP r2, r3
		BEQ asciifound

asciifound ; r0 holding first argument

	; output to tera term
		STR	r5, [r8]
		MOV r1, #1    ; Second argument
		BL USART2_Write
				
nokeypressed

		MOV r0, #0x0

checkml	CMP r0, #1
		BLT mainloop
endmainloop

; dealy subroutine to delay code execution for software debouncing

delay	PROC
	; Delay for software debouncing
	LDR	r2, =0x9999
delayloop
	SUBS	r2, #1
	BNE	delayloop
	BX LR
	
	ENDP
		
	ALIGN			

	AREA myData, DATA, READWRITE
	ALIGN
	
; Variables for needed ASCII characters
	
str0	DCB 0x30, 0	
str1 	DCB 0x31, 0
str2	DCB 0x32, 0
str3	DCB 0x33, 0
str4	DCB 0x34, 0
str5 	DCB 0x35, 0
str6	DCB 0x36, 0
str7	DCB 0x37, 0
str8	DCB 0x38, 0
str9	DCB 0x39, 0

str_A	DCB 0x41, 0
str_B	DCB 0x42, 0
str_C	DCB 0x43, 0
str_D	DCB 0x44, 0

str_atr	DCB 0x2A, 0
str_pnd	DCB 0x23, 0

;char1	DCD	43

	END