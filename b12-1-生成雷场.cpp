#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define RATIO 5 // 地雷占比(%)

int n, m;
char mp[100][100];	// 雷场存储
int dx[10] = {-1, -1, -1, 0, 0, 1, 1, 1};	// 8方向
int dy[10] = {-1, 0, 1, -1, 1, -1, 0, 1};	// 8方向

int main(){
	cout << "------------ 构建雷场 ------------" << endl;
	// 构建雷场的大小
	cout << "请输入要构建的雷场的行数(1~20):" << endl;
	cin >> n;
	cout << "请输入要构建的雷场的列数(1~20):" << endl;
	cin >> m;

	// 初始化雷场
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			mp[i][j] = '.';
		}
	}

	// 设定随机数种子
	srand(time(NULL));

	// 设置雷的数量
	int num = n * m * RATIO / 100;
	if(num < 1) {
		num = 1;
	}
	cout << "生成的雷场中地雷的数量为：" << endl << num<< endl;

	// 创建txt文件，以只写的形式打开
	freopen("b12-2-雷场.txt", "w", stdout);

	cout << n << " " << m << endl;

	// 随机生成雷
	for(int i = 1; i <= num; i++) {
		// 生成雷的位置
		int x = rand() % n + 1;
		int y = rand() % m + 1;
		while(mp[x][y] == '*') {
			x = rand() % n + 1;
			y = rand() % m + 1;
		}
		mp[x][y] = '*';
	}

	// 计算储存非雷位置的周围雷数量
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int cnt = 0;	// 统计周围雷的数量
			if(mp[i][j] != '*') {
				// 遍历8方向
				for(int k = 0; k <= 7; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if(tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
						if(mp[tx][ty] == '*') {
							cnt++;
						}
					}
				}
				mp[i][j] = char(cnt + '0'); // 存储周围雷数量
			}
		}
	}

	// 输出雷场
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << mp[i][j] << " ";
		}
		cout << endl;
	}

	// 关闭标准输出流
	fclose(stdout);

	return 0;
}


