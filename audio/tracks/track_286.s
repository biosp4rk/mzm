.align 2

.section .rodata
.global track_286

track_286_0:
	.byte 188, 0, 187, 75, 189, 8, 190, 69
	.byte 191, 80, 211, 57, 40, 132, 210, 60
	.byte 60, 131, 59, 80, 131, 211, 57, 100
	.byte 132, 55, 120, 132, 53, 80, 132, 212
	.byte 50, 60, 133, 213, 48, 134, 215, 45
	.byte 156, 131, 177

track_286_1:
	.byte 188, 0, 189, 9, 190, 69, 191, 80
	.byte 218, 60, 112, 130, 190, 77, 130, 86
	.byte 130, 95, 130, 103, 130, 110, 129, 189
	.byte 10, 220, 60, 127, 141, 60, 60, 141
	.byte 226, 60, 32, 155, 131, 177

track_286_2:
	.byte 188, 0, 189, 11, 190, 103, 191, 80
	.byte 130, 209, 57, 100, 130, 211, 59, 132
	.byte 222, 53, 127, 132, 190, 110, 164, 177
	.byte 

.align 2

track_286:
	.byte 3
	.byte 0
	.byte 251
	.byte 0
	.word voice_group4
	.word track_286_0
	.word track_286_1
	.word track_286_2

.align 2