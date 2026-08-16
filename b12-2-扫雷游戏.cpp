#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n = 0, m = 0, total = 0;	// total -> 雷的个数
char mp[105][105];	// 雷场地图
int show[105][105];	// 显示给玩家的数据, -1 -> 未翻开, 0~8 -> 周围有几个雷, 9 -> 当前是雷

int dx[10] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 8方向
int dy[10] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 8方向
bool gameover = false;	// 是否游戏结束
queue<int> qx, qy;


void bfs() {
    while (!qx.empty() && !qy.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();

        for (int i = 0; i < 8; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            
            // 是否是空地、是否访问过
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m 
                  && show[tx][ty] == -1) {

				if(mp[tx][ty] == '0') {
					qx.push(tx);
					qy.push(ty);
				}
				show[tx][ty] = mp[tx][ty] - '0';
            }
        }
    }
}

// 显示游戏界面
void display() {
	cout << "雷区地图：" << endl;
	cout << "   ";
	for(int i = 1; i <= m; i++) {
		printf("%3d", i); // 为了美观，所有输出内容占3个位置
	}
	cout << endl;
	// 遍历输出
	for(int i = 1; i <= n; i++) {
		printf("%3d", i);
		for(int j = 1; j <= m; j++) {
			if(show[i][j] == -1) {	// 未翻开位置
				printf("%3c", '.');
			}
			else if(show[i][j] == 9) {	// 地雷位置
				printf("%3c", '*');
			}
			else {
				printf("%3d", show[i][j]);
			}
		}
		printf("\n");
	}
}

// 点击x,y位置, 返回是否踩到雷
bool click(int x, int y) {
	// 检查是否踩到雷
	if(mp[x][y] == '*') {
		cout << "游戏结束，你踩到雷了" << endl;
		show[x][y] = 9;
		gameover = true;
		return true;
	}
	// 翻开当前位置
	show[x][y] = mp[x][y] - '0';
	if(mp[x][y] == '0') {
		qx.push(x);
		qy.push(y);
		bfs();
	}
	return false;
}

// 检查是否获胜
bool checkwin() {
	int safe = n * m - total;	// 排除雷后的总数量
	int cnt = 0;	// 统计已经翻开的位置数量
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(show[i][j] != -1 && show[i][j] != 9) {
				cnt++;
			}
		}
	}
	return cnt == safe;
}

int main(){
	// // 重定向输入流，从文件中读取
	// freopen("b12-2-雷场.txt", "r", stdin);
	
	cin >> total >> n >> m;
	cout << "\n雷场 大小: " << n << "行 " << m << "列, 地雷数量 " << total << "个" << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}

	// // 恢复标准输入流
	// freopen("/dev/tty", "r", stdin);

	// 初始化显示数组
	memset(show, -1, sizeof(show));
	
	cout << "========= 游戏开始 =========" << endl;
	// 显示游戏界面
	display();
	
	while( !gameover ) {
		cout << "请输入你要翻看的位置(x y): ";
		int x = 0, y = 0;
		cin >> x >> y;
		// 翻看x, y位置
		if(click(y, x)) {
			break;
		}
		// 显示游戏界面
		display();
		// 检查是否获胜
		if(checkwin() == true) {
			cout << "恭喜你，你成功扫除了雷区" << endl << endl;
			break;
		}
	}
	
	return 0;
}


