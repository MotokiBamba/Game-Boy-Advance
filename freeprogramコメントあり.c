typedef volatile unsigned short hword;
#define VRAM 0x06000000 

void draw_point(hword, hword, hword);
void draw_rectangle(hword, hword, hword);
hword color_check(hword, hword);

int main(void) {
	hword *p;
	
	do {
		hword *ptr;
		hword colororigin = 0x0000; //初期画面の背景色
		hword colorfinish = 0x03FF; //ゴール時の背景色1
		hword colorfinish2 = 0x7FE0; //ゴール時の背景色2
		hword colorrestart = 0x7C1F; //ステージリセット時の背景色
		hword colorback = 0x7FFF; //迷路内の背景色
		hword colorback2 = 0x03E0; //迷路外の背景色
		hword colorwall = 0x0000; //迷路の壁の色
		hword colorstart = 0x7FE0; //スタート地点の色
		hword colorgoal = 0x03FF; //ゴール地点の色
		hword colorplayer = 0x001F; //プレイヤーの色
		hword colorenemy = 0x7C00; //敵の色
		hword xwall; //壁のx座標
		hword ywall; //壁のy座標
		hword xplayer = 29; //プレイヤーの初期x座標
		hword yplayer = 24; //プレイヤーの初期y座標
		hword xenemy1 = 75; //敵1の初期x座標
		hword yenemy1 = 120; //敵1の初期y座標
		hword xenemy2 = 65; //敵2の初期x座標
		hword yenemy2 = 80; //敵2の初期y座標
		hword xenemy3 = 155; //敵3の初期x座標
		hword yenemy3 = 130; //敵3の初期y座標
		hword xenemy4 = 35; //敵4の初期x座標
		hword yenemy4 = 20; //敵4の初期y座標
		hword xenemy5 = 195; //敵5の初期x座標
		hword yenemy5 = 80; //敵5の初期y座標
		hword enemy1check = 240; //敵1の移動位置判定用変数
		hword enemy2check = 240; //敵2の移動位置判定用変数
		hword enemy3check = 240; //敵3の移動位置判定用変数
		hword enemy4check = 160; //敵4の移動位置判定用変数
		hword enemy5check = 160; //敵5の移動位置判定用変数
		hword i; //for文用変数
		int level1 = 0; //難易度イージー設定用変数
		int level2 = 0; //難易度ハード設定用変数

		ptr = (hword*)0x04000000;
		*ptr = 0x0F03;

		//初期画面の背景を設定
		p = (hword*)0x04000130; 
		ptr = (hword*)VRAM;
		for(i = 0; i < 38400; i++){
			*ptr = colororigin;
			ptr = ptr + 1;
		}
		//プレイヤーの入力合わせて難易度の切り替え
		while(1) { 
			if((*p & 0x0001) == 0x0000) { //Aボタンが押された時
				level1++;
				level2 = 0;
				break;
			}else if((*p & 0x0002) == 0x0000) { //Bボタンが押された時
				level2++;
				level1 = 0;
				break;
			}
		}
		
		//迷路内背景の設定
		ptr = (hword*)VRAM; 
		for(i = 0; i < 38400; i++){
			*ptr = colorback;
			ptr = ptr + 1;
		}

		//迷路の生成
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
		
		//迷路外背景の設定
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
		
		//スタート地点の色の設定
		for(xwall = 25; xwall <= 33; xwall++) {
			for(ywall = 11; ywall <= 18; ywall++) {
				draw_point(xwall, ywall, colorstart);
			}
		}
		//ゴール地点の色の設定
		for(xwall = 214; xwall <= 222; xwall++) {
			for(ywall = 130; ywall <= 138; ywall++) {
				draw_point(xwall, ywall, colorgoal);
			}
		}	

		//難易度イージー
		if(level1 > 0) {
			while(1) {
				for(i = 0; i < 10000; i++);

				if(xplayer < 215) { //ゴール前
					//プレイヤーの移動
					if((*p & 0x0010) == 0x0000) { //右ボタンが押された時
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
					}else if((*p & 0x0020) == 0x0000) { //左ボタンが押された時
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
					}else if((*p & 0x0040) == 0x0000) { //上ボタンが押された時
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
					}else if((*p & 0x0080) == 0x0000) { //下ボタンが押された時
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
					}else { //ボタンが押されていない時
						draw_point(xplayer, yplayer, colorplayer);
					}
				}else { //ゴール後
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
						if((*p & 0x0008) == 0x0000) { //startボタンが押された時
							break;
						}
					}
				}
				if((*p & 0x0008) == 0x0000) { //startボタンが押された時
					break;
				}
			}
			//ステージリセット時の背景の設定
			p = (hword*)0x4000130;
			ptr = (hword*)VRAM;
			for(i = 0; i < 38400; i++){
				*ptr = colorrestart;
				ptr = ptr + 1;
			}
			while(1) {
				if((*p & 0x0004) == 0x0000) { //selectボタンが押された時
					break;
				}
			}
		}
		//難易度ハード
		else if(level2 > 0) {
			while(1) {
				for(i = 0; i < 10000; i++);
				
				//敵1
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

				//プレイヤーが止まっている時に敵1がぶつかってきた時
				if(color_check(xplayer, yplayer) == colorenemy) {
					xplayer = 29;
					yplayer = 24;
					draw_point(xplayer, yplayer, colorplayer);
				}

				if(xplayer < 215) {	//ゴール前
					//プレイヤーの移動
					if((*p & 0x0010) == 0x0000) { //右ボタンが押された時
						//敵2
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

						//プレイヤーの右移動
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
					}else if((*p & 0x0020) == 0x0000) {//左ボタンが押された時
						//敵3
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

						//プレイヤーの左移動
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
					}else if((*p & 0x0040) == 0x0000) {//上ボタンが押された時
						//敵4
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

						//プレイヤーの上移動
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
					}else if((*p & 0x0080) == 0x0000) {//下ボタンが押された時
						//敵5
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

						//プレイヤーの下移動
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
					}else { //ボタンが押されていない時
						draw_point(xplayer, yplayer, colorplayer);
						draw_rectangle(xenemy2, yenemy2, colorenemy);
						draw_rectangle(xenemy3, yenemy3, colorenemy);
						draw_rectangle(xenemy4, yenemy4, colorenemy);
						draw_rectangle(xenemy5, yenemy5, colorenemy);
					}
				}else { //ゴール後
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
						if((*p & 0x0008) == 0x0000) { //startボタンが押された時
							break;
						}
					}
				}
				if((*p & 0x0008) == 0x0000) { //startボタンが押された時
					break;
				}
			}
		}
		//ステージリセット時の背景の設定
		p = (hword*)0x4000130;
		ptr = (hword*)VRAM;
		for(i = 0; i < 38400; i++){
			*ptr = colorrestart;
			ptr = ptr + 1;
		}
		while(1) {
			if((*p & 0x0004) == 0x0000) { //selectボタンが押された時
				break;
			}
		}
	}while((*p & 0x0004) == 0x0000); //selectボタンが押された時11行目に戻る

	while(1);
	return 0;
}

void draw_point(hword x, hword y, hword color) { //点を描画するメソッド
	hword *ptr;
	ptr = (hword*)VRAM;
	ptr += x + (240 * y);
	*ptr = color;
}

void draw_rectangle(hword x,hword y, hword color) { //8×8四角形を描画するメソッド
	hword i;
	hword j;
	for(i = x; i <= (x + 8); i++) {
		for(j = y; j <= (y + 8); j++) {
			draw_point(i, j, color);
		}
	}
}

hword color_check(hword x, hword y) { //プレイヤーのいる座標を返すメソッド
	hword *ptr;
	ptr = (hword*)VRAM;
	ptr += x + (240 * y);
	return *ptr;
}