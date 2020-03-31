#include "neslib.h"

#include "bg.h"

const unsigned char palSpr[] = {0x0f, 0x30, 0x15, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const unsigned char palBg[] = { 0x0F, 0x30, 0x15, 0x25, 0x10, 0x13, 0x10, 0x05, 0x0F, 0x20, 0x10, 0x00, 0x0F, 0x13, 0x23, 0x33 };

const unsigned char sin[] = {0x80, 0x83, 0x86, 0x89, 0x8c, 0x8f, 0x92, 0x95, 0x98, 0x9c, 0x9f, 0xa2, 0xa5, 0xa8, 0xab, 0xae, 0xb0, 0xb3, 0xb6, 0xb9, 0xbc, 0xbf, 0xc1, 0xc4, 0xc7, 0xc9, 0xcc, 0xce, 0xd1, 0xd3, 0xd5, 0xd8, 0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xed, 0xef, 0xf0, 0xf2, 0xf3, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfc, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfc, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6, 0xf5, 0xf3, 0xf2, 0xf0, 0xef, 0xed, 0xec, 0xea, 0xe8, 0xe6, 0xe4, 0xe2, 0xe0, 0xde, 0xdc, 0xda, 0xd8, 0xd5, 0xd3, 0xd1, 0xce, 0xcc, 0xc9, 0xc7, 0xc4, 0xc1, 0xbf, 0xbc, 0xb9, 0xb6, 0xb3, 0xb0, 0xae, 0xab, 0xa8, 0xa5, 0xa2, 0x9f, 0x9c, 0x98, 0x95, 0x92, 0x8f, 0x8c, 0x89, 0x86, 0x83, 0x80, 0x7c, 0x79, 0x76, 0x73, 0x70, 0x6d, 0x6a, 0x67, 0x63, 0x60, 0x5d, 0x5a, 0x57, 0x54, 0x51, 0x4f, 0x4c, 0x49, 0x46, 0x43, 0x40, 0x3e, 0x3b, 0x38, 0x36, 0x33, 0x31, 0x2e, 0x2c, 0x2a, 0x27, 0x25, 0x23, 0x21, 0x1f, 0x1d, 0x1b, 0x19, 0x17, 0x15, 0x13, 0x12, 0x10, 0xf, 0xd, 0xc, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x3, 0x2, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x3, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xc, 0xd, 0xf, 0x10, 0x12, 0x13, 0x15, 0x17, 0x19, 0x1b, 0x1d, 0x1f, 0x21, 0x23, 0x25, 0x27, 0x2a, 0x2c, 0x2e, 0x31, 0x33, 0x36, 0x38, 0x3b, 0x3e, 0x40, 0x43, 0x46, 0x49, 0x4c, 0x4f, 0x51, 0x54, 0x57, 0x5a, 0x5d, 0x60, 0x63, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x76, 0x79, 0x7c};

const unsigned char sprBall[] = {
	 0,  0, 0x00, 0,
	 8,  0, 0x01, 0,
	16,  0, 0x02, 0,
	24,  0, 0x03, 0,
	 0,  8, 0x10, 0,
	 8,  8, 0x11, 0,
	16,  8, 0x12, 0,
	24,  8, 0x13, 0,
	 0, 16, 0x20, 0,
	 8, 16, 0x21, 0,
	16, 16, 0x22, 0,
	24, 16, 0x23, 0,
	 0, 24, 0x30, 0,
	 8, 24, 0x31, 0,
	16, 24, 0x32, 0,
	24, 24, 0x33, 0,
	128,
	 0,  0, 0x04, 0,
	 8,  0, 0x05, 0,
	16,  0, 0x06, 0,
	24,  0, 0x07, 0,
	 0,  8, 0x14, 0,
	 8,  8, 0x15, 0,
	16,  8, 0x16, 0,
	24,  8, 0x17, 0,
	 0, 16, 0x24, 0,
	 8, 16, 0x25, 0,
	16, 16, 0x26, 0,
	24, 16, 0x27, 0,
	 0, 24, 0x34, 0,
	 8, 24, 0x35, 0,
	16, 24, 0x36, 0,
	24, 24, 0x37, 0,
	128,
	 0,  0, 0x08, 0,
	 8,  0, 0x09, 0,
	16,  0, 0x0a, 0,
	24,  0, 0x0b, 0,
	 0,  8, 0x18, 0,
	 8,  8, 0x19, 0,
	16,  8, 0x1a, 0,
	24,  8, 0x1b, 0,
	 0, 16, 0x28, 0,
	 8, 16, 0x29, 0,
	16, 16, 0x2a, 0,
	24, 16, 0x2b, 0,
	 0, 24, 0x38, 0,
	 8, 24, 0x39, 0,
	16, 24, 0x3a, 0,
	24, 24, 0x3b, 0,
	128,
	 0,  0, 0x0c, 0,
	 8,  0, 0x0d, 0,
	16,  0, 0x0e, 0,
	24,  0, 0x0f, 0,
	 0,  8, 0x1c, 0,
	 8,  8, 0x1d, 0,
	16,  8, 0x1e, 0,
	24,  8, 0x1f, 0,
	 0, 16, 0x2c, 0,
	 8, 16, 0x2d, 0,
	16, 16, 0x2e, 0,
	24, 16, 0x2f, 0,
	 0, 24, 0x3c, 0,
	 8, 24, 0x3d, 0,
	16, 24, 0x3e, 0,
	24, 24, 0x3f, 0,
	128,
};

// boundaries for the screen, low and high on x and y
// y is no longer used after making the ball's y position mandated by sine
const unsigned lx = 0x10;
const unsigned ly = 0x08;
const unsigned hx = 0xd0;
const unsigned hy = 0xd8;

void main(void) {
	unsigned char cnt;
	unsigned char cycle;
	unsigned char x;
	unsigned char y;
	signed char dx;
	signed char dy;
	// delta/velocity, y is no longer used
	dx = 1;
	dy = 1;

	// start at a point inside the bounds
	x = lx;
	y = ly;

	ppu_off();
	pal_spr(palSpr);
	pal_bg(palBg);
	vram_adr(NAMETABLE_A);
	vram_unrle(bg);
	ppu_on_all();

	// main loop
	while(1) {
		ppu_wait_frame();

		// moves in x by the amount of its delta, y is simply looked up on the sine table
		x += dx;
		y = 0x20 - (sin[cnt]);

		// if the x bounds have been reached swap velocity and play thump
		if (x < lx || x > hx) {
			dx *= -1;
			sfx_play(0,0);
		}
		
		// draw the ball at its position
		oam_clear();
		oam_meta_spr(x, y, 0, sprBall+cycle);

		// cnt (frame count) controls where in the sin table we look up. it is reset every 128 steps (half sine)
		// coincidentally, that is where our ball "hits the floor", so also play a thump
		cnt++;
		if (cnt > 127) {
			cnt = 0;
			sfx_play(0,0);
		}

		// every 8 frames cycle ahead on the metasprite table to animate the ball
		if (cnt%8==0) {
			if(dx > 0)
				cycle+=65;
			else
				cycle-=65;

			// wrapping fuckery!
			// this is a very hackish way to do this, basically since 4 frames are 260 bytes, that would overflow a byte counter
			// however, it overflows in a particular way where it lands somewhere that's not the beginning of a metasprite
			// we can account for it and correct accordingly, eliminating the need to use two bytes for the counter (int)
			if (cycle == 4) cycle -= 4;
			else if (cycle == 191) cycle += 4;
		}
	}
}