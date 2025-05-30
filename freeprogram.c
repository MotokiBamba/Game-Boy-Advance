typedef volatile unsigned short hword;
#define VRAM 0x06000000 

void draw_point(hword, hword, hword);
void draw_rectangle(hword, hword, hword);
hword color_check(hword, hword);

int main(void) {
	hword *p;
	
	do {
		hword *ptr;
		hword colororigin = 0x0000;
		hword colorfinish = 0x03FF;
		hword colorfinish2 = 0x7FE0;
		hword colorrestart = 0x7C1F;
		hword colorback = 0x7FFF;
		hword colorback2 = 0x03E0;
		hword colorwall = 0x0000;
		hword colorstart = 0x7FE0;
		hword colorgoal = 0x03FF;
		hword colorplayer = 0x001F;
		hword colorenemy = 0x7C00;
		hword xwall;
		hword ywall;
		hword xplayer = 29;
		hword yplayer = 24;
		hword xenemy1 = 75;
		hword yenemy1 = 120;
		hword xenemy2 = 65;
		hword yenemy2 = 80;
		hword xenemy3 = 155;
		hword yenemy3 = 130;
		hword xenemy4 = 35;
		hword yenemy4 = 20;
		hword xenemy5 = 195;
		hword yenemy5 = 80;
		hword enemy1check = 240;
		hword enemy2check = 240;
		hword enemy3check = 240;
		hword enemy4check = 160;
		hword enemy5check = 160;
		hword i;
		int level1 = 0;
		int level2 = 0;

		ptr = (hword*)0x04000000;
		*ptr = 0x0F03;

		p = (hword*)0x04000130;
		ptr = (hword*)VRAM;
		for(i = 0; i < 38400; i++){
			*ptr = colororigin;
			ptr = ptr + 1;
		}
		while(1) {
			if((*p & 0x0001) == 0x0000) {
				level1++;
				level2 = 0;
				break;
			}else if((*p & 0x0002) == 0x0000) {
				level2++;
				level1 = 0;
				break;
			}
		}
		
		ptr = (hword*)VRAM;
		for(i = 0; i < 38400; i++){
			*ptr = colorback;
			ptr = ptr + 1;
		}

		xwall = 24;
		for(ywall = 19; ywall <= 139; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 34;
		for(ywall = 19; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 44;
		for(ywall = 19; ywall <= 39; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 49; ywall <= 69; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 109; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 119; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 54;
		for(ywall = 49; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 79; ywall <= 99; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 64;
		for(ywall = 39; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 89; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 74;
		for(ywall = 39; ywall <= 49; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 59; ywall <= 69; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 84;
		for(ywall = 39; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 119; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 129; ywall <= 139; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 94;
		for(ywall = 39; ywall <= 49; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 109; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 104;
		for(ywall = 29; ywall <= 49; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 99; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 114;
		for(ywall = 39; ywall <= 49; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 124;
		for(ywall = 49; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 109; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 134;
		for(ywall = 49; ywall <= 69; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 119; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 144;
		for(ywall = 49; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 154;
		for(ywall = 39; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 164;
		for(ywall = 29; ywall <= 69; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 79; ywall <= 89; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 99; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 174;
		for(ywall = 29; ywall <= 49; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 109; ywall <= 119; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 184;
		for(ywall = 19; ywall <= 39; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 79; ywall <= 89; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 119; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 194;
		for(ywall = 49; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 79; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 204;
		for(ywall = 19; ywall <= 29; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 39; ywall <= 59; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 69; ywall <= 79; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 89; ywall <= 109; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(ywall = 119; ywall <= 129; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		xwall = 214;
		for(ywall = 19; ywall <= 139; ywall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 19;
		for(xwall = 24; xwall <= 214; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 29;
		for(xwall = 54; xwall <= 164; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 194; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 39;
		for(xwall = 44; xwall <= 74; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 84; xwall <= 94; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 114; xwall <= 154; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 184; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 49;
		for(xwall = 44; xwall <= 54; xwall++) {
		draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 104; xwall <= 114; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 124; xwall <= 134; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 174; xwall <= 194; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 59;
		for(xwall = 64; xwall <= 124; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 144; xwall <= 154; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 164; xwall <= 184; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 194; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 69;
		for(xwall = 44; xwall <= 64; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 74; xwall <= 94; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 104; xwall <= 124; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 134; xwall <= 164; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 174; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 79;
		for(xwall = 34; xwall <= 54; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 74; xwall <= 84; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 104; xwall <= 144; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 164; xwall <= 174; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 194; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 89;
		for(xwall = 34; xwall <= 44; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 64; xwall <= 94; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 104; xwall <= 114; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 124; xwall <= 154; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 164; xwall <= 184; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 204; xwall <= 214; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 99;
		for(xwall = 54; xwall <= 74; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 84; xwall <= 94; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 104; xwall <= 124; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 134; xwall <= 144; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 164; xwall <= 194; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 109;
		for(xwall = 44; xwall <= 64; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 94; xwall <= 124; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 174; xwall <= 184; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 119;
		for(xwall = 44; xwall <= 74; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 84; xwall <= 134; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 174; xwall <= 184; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 204; xwall <= 214; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 129;
		for(xwall = 34; xwall <= 44; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 54; xwall <= 74; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 84; xwall <= 144; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 164; xwall <= 184; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		for(xwall = 194; xwall <= 204; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		ywall = 139;
		for(xwall = 24; xwall <= 214; xwall++) {
			draw_point(xwall, ywall, colorwall);
		}
		
		for(xwall = 0; xwall <= 239; xwall++) {
			for(ywall = 0; ywall <= 18; ywall++) {
				draw_point(xwall, ywall, colorback2);
			}
		}
		for(xwall = 0; xwall <= 239; xwall++) {
			for(ywall = 140; ywall <= 159; ywall++) {
				draw_point(xwall, ywall, colorback2);
			}
		}
		for(xwall = 0; xwall <= 23; xwall++) {
			for(ywall = 19; ywall <= 139; ywall++) {
				draw_point(xwall, ywall, colorback2);
			}
		}
		for(xwall = 215; xwall <= 239; xwall++) {
			for(ywall = 19; ywall <= 139; ywall++) {
				draw_point(xwall, ywall, colorback2);
			}
		}	
		
		for(xwall = 25; xwall <= 33; xwall++) {
			for(ywall = 11; ywall <= 18; ywall++) {
				draw_point(xwall, ywall, colorstart);
			}
		}
		for(xwall = 214; xwall <= 222; xwall++) {
			for(ywall = 130; ywall <= 138; ywall++) {
				draw_point(xwall, ywall, colorgoal);
			}
		}	

		if(level1 > 0) {
			while(1) {
				for(i = 0; i < 10000; i++);

				if(xplayer < 215) {	
					if((*p & 0x0010) == 0x0000) {
						if(xplayer < 239) {
							draw_point(xplayer, yplayer, colorback);
							xplayer++;
							if(color_check(xplayer, yplayer) != colorwall) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(xplayer >= 239) {
							draw_point(xplayer, yplayer, colorplayer);
						}
					}else if((*p & 0x0020) == 0x0000) {
						if(xplayer > 0) {
							draw_point(xplayer, yplayer, colorback);
							xplayer--;
							if(color_check(xplayer, yplayer) != colorwall) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(xplayer <= 0) {
							draw_point(xplayer, yplayer, colorplayer);
						}
					}else if((*p & 0x0040) == 0x0000) {
						if(yplayer > 0) {
							draw_point(xplayer, yplayer, colorback);
							yplayer--;
							if(color_check(xplayer, yplayer) != colorwall) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(yplayer <= 0) {
							draw_point(xplayer, yplayer, colorplayer);
						}	
					}else if((*p & 0x0080) == 0x0000) {
						if(yplayer < 159) {
							draw_point(xplayer, yplayer, colorback);
							yplayer++;
							if(color_check(xplayer, yplayer) != colorwall) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(yplayer >= 159) {
							draw_point(xplayer, yplayer, colorplayer);
						}	
					}else {
						draw_point(xplayer, yplayer, colorplayer);
					}
				}else {
					while(1) {
						ptr = (hword*)VRAM;
						for(i = 0; i < 38400; i++){
							*ptr = colorfinish;
							ptr = ptr + 1;
						}
						ptr = (hword*)VRAM;
						for(i = 0; i < 38400; i++){
							*ptr = colorfinish2;
							ptr = ptr + 1;
						}
						if((*p & 0x0008) == 0x0000) {
							break;
						}
					}
				}
				if((*p & 0x0008) == 0x0000) {
					break;
				}
			}
			p = (hword*)0x4000130;
			ptr = (hword*)VRAM;
			for(i = 0; i < 38400; i++){
				*ptr = colorrestart;
				ptr = ptr + 1;
			}
			while(1) {
				if((*p & 0x0004) == 0x0000) {
					break;
				}
			}
		}else if(level2 > 0) {
			while(1) {
				for(i = 0; i < 10000; i++);
				
				if(enemy1check >= 240) {
					draw_rectangle(xenemy1, yenemy1, colorback);
					xenemy1++;
					draw_rectangle(xenemy1, yenemy1, colorenemy);
					enemy1check++;
					if(xenemy1 >= 134) {
						enemy1check = 239;
					}
				}else if(enemy1check < 240) {
					draw_rectangle(xenemy1, yenemy1, colorback);
					xenemy1--;
					draw_rectangle(xenemy1, yenemy1, colorenemy);
					enemy1check--;
					if(xenemy1 <= 75) {
						enemy1check = 240;
					}
				}

				if(color_check(xplayer, yplayer) == colorenemy) {
					xplayer = 29;
					yplayer = 24;
					draw_point(xplayer, yplayer, colorplayer);
				}

				if(xplayer < 215) {	
					if((*p & 0x0010) == 0x0000) {
						if(enemy2check >= 240) {
							draw_rectangle(xenemy2, yenemy2, colorback);
							xenemy2++;
							draw_rectangle(xenemy2, yenemy2, colorenemy);
							enemy2check++;
							if(xenemy2 >= 154) {
								enemy2check = 239;
							}
						}else if(enemy2check < 240) {
							draw_rectangle(xenemy2, yenemy2, colorback);
							xenemy2--;
							draw_rectangle(xenemy2, yenemy2, colorenemy);
							enemy2check--;
							if(xenemy2 <= 65) {
								enemy2check = 240;
							}
						}

						if(xplayer < 239) {
							draw_point(xplayer, yplayer, colorback);
							xplayer++;
							if(color_check(xplayer, yplayer) != colorwall && color_check(xplayer, yplayer) != colorenemy) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(xplayer >= 239) {
							draw_point(xplayer, yplayer, colorplayer);
						}
					}else if((*p & 0x0020) == 0x0000) {
						if(enemy3check >= 240) {
							draw_rectangle(xenemy3, yenemy3, colorback);
							xenemy3++;
							draw_rectangle(xenemy3, yenemy3, colorenemy);
							enemy3check++;
							if(xenemy3 >= 194) {
								enemy3check = 239;
							}
						}else if(enemy3check < 240) {
							draw_rectangle(xenemy3, yenemy3, colorback);
							xenemy3--;
							draw_rectangle(xenemy3, yenemy3, colorenemy);
							enemy3check--;
							if(xenemy3 <= 155) {
								enemy3check = 240;
							}
						}

						if(xplayer > 0) {
							draw_point(xplayer, yplayer, colorback);
							xplayer--;
							if(color_check(xplayer, yplayer) != colorwall && color_check(xplayer, yplayer) != colorenemy) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(xplayer <= 0) {
							draw_point(xplayer, yplayer, colorplayer);
						}
					}else if((*p & 0x0040) == 0x0000) {
						if(enemy4check >= 160) {
							draw_rectangle(xenemy4, yenemy4, colorback);
							yenemy4++;
							draw_rectangle(xenemy4, yenemy4, colorenemy);
							enemy4check++;
							if(yenemy4 >= 69) {
								enemy4check = 159;
							}
						}else if(enemy4check < 160) {
							draw_rectangle(xenemy4, yenemy4, colorback);
							yenemy4--;
							draw_rectangle(xenemy4, yenemy4, colorenemy);
							enemy4check--;
							if(yenemy4 <= 20) {
								enemy4check = 160;
							}
						}

						if(yplayer > 0) {
							draw_point(xplayer, yplayer, colorback);
							yplayer--;
							if(color_check(xplayer, yplayer) != colorwall && color_check(xplayer, yplayer) != colorenemy) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(yplayer <= 0) {
							draw_point(xplayer, yplayer, colorplayer);
						}	
					}else if((*p & 0x0080) == 0x0000) {
						if(enemy5check >= 160) {
							draw_rectangle(xenemy5, yenemy5, colorback);
							yenemy5++;
							draw_rectangle(xenemy5, yenemy5, colorenemy);
							enemy5check++;
							if(yenemy5 >= 119) {
								enemy5check = 159;
							}
						}else if(enemy5check < 160) {
							draw_rectangle(xenemy5, yenemy5, colorback);
							yenemy5--;
							draw_rectangle(xenemy5, yenemy5, colorenemy);
							enemy5check--;
							if(yenemy5 <= 80) {
								enemy5check = 160;
							}
						}

						if(yplayer < 159) {
							draw_point(xplayer, yplayer, colorback);
							yplayer++;
							if(color_check(xplayer, yplayer) != colorwall && color_check(xplayer, yplayer) != colorenemy) {
								draw_point(xplayer, yplayer, colorplayer);
							}else {
								xplayer = 29;
								yplayer = 24;
								draw_point(xplayer, yplayer, colorplayer);
							}
						}else if(yplayer >= 159) {
							draw_point(xplayer, yplayer, colorplayer);
						}	
					}else {
						draw_point(xplayer, yplayer, colorplayer);
						draw_rectangle(xenemy2, yenemy2, colorenemy);
						draw_rectangle(xenemy3, yenemy3, colorenemy);
						draw_rectangle(xenemy4, yenemy4, colorenemy);
						draw_rectangle(xenemy5, yenemy5, colorenemy);
					}
				}else {
					while(1) {
						ptr = (hword*)VRAM;
						for(i = 0; i < 38400; i++){
							*ptr = colorfinish;
							ptr = ptr + 1;
						}
						ptr = (hword*)VRAM;
						for(i = 0; i < 38400; i++){
							*ptr = colorfinish2;
							ptr = ptr + 1;
						}
						if((*p & 0x0008) == 0x0000) {
							break;
						}
					}
				}
				if((*p & 0x0008) == 0x0000) {
					break;
				}
			}
		}
		p = (hword*)0x4000130;
		ptr = (hword*)VRAM;
		for(i = 0; i < 38400; i++){
			*ptr = colorrestart;
			ptr = ptr + 1;
		}
		while(1) {
			if((*p & 0x0004) == 0x0000) {
				break;
			}
		}
	}while((*p & 0x0004) == 0x0000);

	while(1);
	return 0;
}

void draw_point(hword x, hword y, hword color) {
	hword *ptr;
	ptr = (hword*)VRAM;
	ptr += x + (240 * y);
	*ptr = color;
}

void draw_rectangle(hword x,hword y, hword color) {
	hword i;
	hword j;
	for(i = x; i <= (x + 8); i++) {
		for(j = y; j <= (y + 8); j++) {
			draw_point(i, j, color);
		}
	}
}

hword color_check(hword x, hword y) {
	hword *ptr;
	ptr = (hword*)VRAM;
	ptr += x + (240 * y);
	return *ptr;
}