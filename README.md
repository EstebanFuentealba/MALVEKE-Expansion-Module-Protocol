WIP

Example decode frame data in Javascript


```html
<!-- index.html -->
<canvas id="canvas" width="128" height="64" style="width:128px;height:64px;" />
<script>
const data = [
	// Offset 0x00000000 to 0x000003FF
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x83, 0x0D, 0x0D,
	0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04,
	0x04, 0x04, 0x07, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0x09, 0x09,
	0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x08,
	0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xA0, 0x20, 0x20, 0x20, 0xA0,
	0x00, 0xA0, 0x20, 0x20, 0x20, 0x20, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40,
	0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x04, 0x04, 0x04,
	0x88, 0x00, 0xE0, 0x10, 0x10, 0xE0, 0x00, 0xF0, 0x10, 0x10, 0xE0, 0x00,
	0xF0, 0x10, 0x10, 0xE0, 0x00, 0xE0, 0x50, 0x50, 0x60, 0x00, 0xE0, 0x10,
	0x10, 0xA0, 0x00, 0x10, 0xFC, 0x10, 0x00, 0xE0, 0x50, 0x50, 0x60, 0x00,
	0xE0, 0x10, 0x10, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0xE0, 0x10, 0x10,
	0x22, 0x26, 0x24, 0x24, 0x24, 0x44, 0x4C, 0x48, 0x48, 0x48, 0x48, 0x88,
	0x88, 0x90, 0x90, 0x90, 0x90, 0x90, 0x10, 0x20, 0x20, 0x20, 0x20, 0x60,
	0x60, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x07, 0x84, 0x0D, 0x01, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
	0x01, 0xE0, 0x20, 0xA0, 0xA0, 0x20, 0x20, 0x20, 0x10, 0x0F, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xF8, 0xF9, 0x71, 0xC1, 0x00, 0xC0, 0x70, 0xF9,
	0xF9, 0x00, 0x00, 0xE1, 0xF8, 0x18, 0xF9, 0xE0, 0x01, 0x00, 0xF8, 0xF9,
	0x00, 0x00, 0x01, 0x01, 0x18, 0xF8, 0xE0, 0x01, 0xE1, 0xF8, 0x18, 0x00,
	0xF9, 0xF8, 0x48, 0x48, 0x49, 0x01, 0xF8, 0xF8, 0xE0, 0xB1, 0x19, 0x09,
	0x00, 0xF8, 0xF8, 0x48, 0x48, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xE0, 0x80, 0x8F, 0x10, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x40, 0x40, 0x40, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x02, 0x02, 0x06, 0x00,
	0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x08, 0x08, 0xC8, 0x01, 0x01, 0x01,
	0x01, 0xFE, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC1, 0x21, 0x21,
	0x41, 0x41, 0x41, 0x41, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xA7, 0x07, 0x80, 0x81, 0x87, 0x01, 0x00, 0x87, 0xE7, 0x80, 0x07, 0x07,
	0x81, 0x81, 0x01, 0x07, 0x07, 0x00, 0xE7, 0x27, 0x24, 0x24, 0x24, 0x00,
	0xE0, 0x00, 0xA3, 0x07, 0x83, 0x80, 0x80, 0x00, 0x07, 0x87, 0x84, 0x84,
	0x04, 0x00, 0x07, 0x87, 0x80, 0x01, 0x03, 0x86, 0x84, 0x87, 0x07, 0x04,
	0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05,
	0x0A, 0x0B, 0x1C, 0x34, 0xF4, 0x78, 0x69, 0xE9, 0xF2, 0xD2, 0xD2, 0xE2,
	0xA4, 0xA4, 0x44, 0xC9, 0x89, 0x09, 0x01, 0x13, 0x12, 0x12, 0x22, 0x26,
	0x24, 0x44, 0x44, 0x48, 0x08, 0x80, 0x80, 0x90, 0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x80, 0xFF, 0x80, 0x80, 0xC0, 0x20, 0xFF, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xF9, 0x8A, 0x8A, 0x8A, 0x91, 0x11, 0x1F,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x0F, 0x00,
	0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x07, 0x08, 0x08, 0x07, 0x00,
	0x00, 0x00, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x0F, 0x00,
	0x3F, 0x08, 0x08, 0x07, 0x00, 0x3F, 0x08, 0x08, 0x07, 0x00, 0x07, 0x0A,
	0x0A, 0x03, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x00, 0x00, 0x07, 0x00, 0x00, 0x0F, 0x01, 0x01, 0x1F, 0x03, 0x3F,
	0x07, 0x01, 0x01, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x08, 0x08, 0xF8,
	0x44, 0xF8, 0x88, 0xE8, 0x99, 0xD1, 0x11, 0x20, 0x22, 0x22, 0x60, 0x44,
	0x45, 0x81, 0x90, 0x88, 0x84, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xF0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0x70, 0xB0, 0xB0, 0xB0, 0x70,
	0xF0, 0xF0, 0xF0, 0xF0, 0x70, 0xB0, 0xB0, 0xB0, 0x70, 0xF0, 0x30, 0xF0,
	0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0x00, 0x07,
	0x00, 0x0F, 0x01, 0x0F, 0x01, 0x1F, 0x02, 0x3F, 0x04, 0x7E, 0x04, 0x7E,
	0x09, 0x09, 0xFD, 0x10, 0x18, 0x04, 0x04, 0x08, 0x10, 0x10, 0x10, 0x10,
	0x08, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
	0xFF, 0xFF, 0xF8, 0xF7, 0xE8, 0xE8, 0xE8, 0xF7, 0xF8, 0xFF, 0xFF, 0xFF,
	0xF0, 0xEF, 0xEF, 0xEF, 0xF0, 0xFF, 0xE0, 0xFB, 0xF5, 0xEE, 0xFF, 0xFF,
	0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00
];
const canvas = document.getElementById('canvas')
const ctx = canvas.getContext('2d')
ctx.lineWidth = 1
ctx.lineCap = 'square'
ctx.imageSmoothingEnabled = false
ctx.fillStyle = '#ff8201'
ctx.fillRect(0, 0, 128 * 1, 64 * 1)
ctx.fillStyle = 'black'

for (let x = 0; x < 128; x++) {
	for (let y = 0; y < 64; y++) {
	const i = Math.floor(y / 8) * 128 + x
	const z = y & 7
	if (data.at(i) & (1 << z)) {
		ctx.fillStyle = 'black'
		ctx.fillRect(x * 1, y * 1, 1 * 1, 1 * 1)
	} else {
		ctx.fillStyle = '#ff8201'
		ctx.fillRect(x * 1, y * 1, 1 * 1, 1 * 1)
	}
	}
}
</script>
```