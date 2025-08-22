.align 2

.global track_535

track_535_0:
	.byte KEYSH, 0
	.byte TEMPO, 75
	.byte VOICE, 2
	.byte VOL, 51 * 3
	.byte PAN, c_v
	.byte N04
	.byte Fs3, Cn3
	.byte W04
	.byte Bn2, Gs4
	.byte W04
	.byte Gn2, En1
	.byte W04

	.byte FINE

.align 2

track_535:
	.byte 1
	.byte 0
	.byte 251
	.byte 0
	.word voicegroup016
	.word track_535_0

.align 2
