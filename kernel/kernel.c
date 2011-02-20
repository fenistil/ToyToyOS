int kmain() {
	/* just to see if we were actually able to boot up */
	short *vidmem = (short *)0xB8000;
	/* let's proceed to the second line*/
	vidmem += 80*1 + 0;
	*vidmem = 'H' | 0x0F << 8;
	vidmem++;
	*vidmem = 'e' | 0x07 << 8;

	/* infinite loop */
	for( ;; );

	return 0xDEADBABA;
}
