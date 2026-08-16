#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flag[100],ANS = 0;

void dg(int deep,int x,int n) {
    if(deep > n) {
        ANS++;
        return ;
    }
    for(int i = 0; i <= 9; i++) {
        if(i != x) {
            dg(deep+1,i,n);
        }
    }
}

int select_dir;
char select_tem;
int ans,cnt = 0,temp;

int main(){
    
    srand(time(NULL));
     
    cout << "欢迎来到坠机大冒险的世界~（^_^）~" << endl;
    cout << "现在游戏正式开始" << endl;
    cout << "你作为某个公司雇佣的最佳“亡牌飞行员”，现在正在执行一项秘密任务" << endl;
    cout << "但是不幸的是，你的这架飞机在经过一座无名海岛上空时，突然仪表失灵开始坠落" << endl;
    cout << "危急情况，你选择跳伞保命，此时你可以选择带走飞机上的一件物品与你一同逃生" << endl;
    cout << "有三件物品：a、笔和纸；b、指南针；c、打火机" << endl;
    cout << "请选择，（输入 a 或 b 或 c）" << endl;
    
    cin >> select_tem;
    flag[1] = select_tem - 'a' + 1;
    
    cout << "你已经选择好了要带走的东西，鼓起勇气，纵身一跃，降落到了一片空地上" << endl;
    cout << "现在你的面前，有两条路：1、往左，2、往右；请你做出选择" << endl;
    
    if(flag[1] == 2) {
        cout << "由于你携带了指南针，可知左边路向北，通往山顶；右边路向南，通往山谷！" << endl;
    }
    
    cout << "请选择：（输入1 或者 2）" << endl;
    
    cin >> select_dir;
    
    switch(select_dir) {
        case 1:goto left_1;    //跳转山顶 
        case 2:goto right_1;    //跳转山谷 
    }
    
    //山顶 
    left_1:cout << "你选择了左边的路，爬到了山顶。山顶风大、气温低。你抓紧收集了一堆柴火" << endl;
    if(flag[1] != 3) {
        cout << "可惜你身上没有带打火机，无法将柴火引燃；你只能躲在一个背风的角落瑟瑟发抖。" << endl;
        cout << "一夜过去，你的身体承受不了低温，你长眠在了山顶~~" << endl;
        cout << "Game Over~~ 游戏结束" << endl;
        return 0;
    }
    cout << "幸好你带着了打火机，你将柴火点燃，在温暖中度过了夜晚" << endl;
    cout << "第二天醒来，你发现不远处有个鸟窝" << endl;
    cout << "里面有三件物品：a、镜子，b、压缩饼干，c、绳子；你可以选择带走一样" << endl;
    cout << "请选择：（输入a 或 b 或 c）" << endl;
    
    cin >> select_tem;
    flag[2] = select_tem - 'a' + 1;
    
    cout << "你收拾好行囊，打算下山，不原路返回，因此你的面前有两条路选择" << endl;
    cout << "两条路：1、往左前方，2、往右前方" << endl;
    cout << "请选择：（输入1 或 2）" << endl;
    
    cin >> select_dir;
    
    switch(select_dir) {
        case 1:goto left_0_2;    //跳转悬崖 
        case 2:goto right_0_2;    //跳转森林 
    }
    
    //山谷 
    right_1:cout << "你选择了右边的路，到达了山谷。天色渐暗，你开始收集材料，搭建过夜的庇护所" << endl;
    cout << "在你收集材料过程中，突然发现有一个隐蔽的洞窟，你决定：" << endl;
    cout << "1、进入探索；2、放弃；（请输入 1 或 2）" << endl;
    
    int select;
    cin >> select;
    
    switch(select) {
        case 1:goto extra;    //跳转密室 
    }
    
    cout << "你放弃探索，抓紧搭建好了庇护所。" << endl;
    cout << "一夜无事发生，天亮了，你收拾行囊，准备出发" << endl;
    cout << "你的面前有两条路：1、往左前方，2、往右前方；" << endl;
    cout << "请输入 1 或 2" << endl;
    
    cin >> select_dir;
    switch(select_dir) {
        case 1:goto left_1_2;    //跳转瘴气林 
        case 2:goto right_0_2;    //跳转森林 
    }
    
    //密室 
    extra:cout << "你进入了洞穴，发现一片漆黑" << endl;
    if(flag[1] == 3) {
        cout << "你想到前面拿的打火机，顺势打开，照亮了空间，开始一步步探索" << endl;
    }
    else {
        cout << "你尽量克服黑暗的恐惧，在黑暗中摸索前进，突然你脚撞到了一个很重的东西" << endl;
        cout << "撞击让你感到脚流血了，但你顾不了那么多，忍着疼痛弯腰摸索这个物品" << endl;
    }
    
    cout << "突然，你发现是个发电机，你用力拉动发电机的引擎" << endl;
    cout << "一阵嘈杂的声音之后，整个房间亮起来了，但同时你发现刚才的入口已被石门关闭" << endl;
    cout << "你已身处一间密室中了" << endl;
    cout << "你仔细搜寻着密室的线索，突然发现一面墙壁上刻着如下几个字：" << endl;
    temp = rand() % 6 + 1; 
    cout << "问题：现在有一个" << temp << "位的密码箱，每一位都由0~9组成，请计算出在相邻数字不能相同的情况下，总共有多少种方案数？" << endl;
    if(flag[1] != 1) {
        cout << "你心想着，要是有笔和纸，就能算出结果了。可惜你没有" << endl;
        cout << "你被困在了密室中，由于没有食物补给，你很快就饿死了" << endl;
        cout << "GameOver~~游戏结束" << endl;
        return 0; 
    }
    
    cout << "你庆幸自己有笔和纸，通过一顿猛如虎的计算，你算出了结果" << endl;
    cout << "请输入你计算出来的结果" << endl;
    
    cin >> ans;
    dg(1,-1,temp);
    while(ans != ANS) {
        cout << "你的计算结果有误，请重新输入" << endl;
        cin >> ans;
        cnt++;
        if(cnt > 3) {
            cout << "你已经输错3次密码，机关开始执行自毁程序" << endl;
            cout << "你被困在了密室中，由于没有食物补给，你很快就饿死了" << endl;
            cout << "GameOver~~游戏结束" << endl;
            return 0;
        }
    }
    
    cout << "你的答案输入正确，四面墙壁开始震动，你获得了一个箱子，里面有一些信号弹" << endl;
    cout << "同时一扇门缓缓打开，你抓紧奔向那扇门，进入一条通道" << endl;
    cout << "你跑了很久很久，终于看到了尽头亮光，你跑了出去，发现在一片海滩上，远处有一艘轮船" << endl;
    cout << "你欣喜若狂，赶紧释放刚刚拿到的信号弹，轮船上的人注意到了你" << endl;
    cout << "你获救了，恭喜游戏通关" << endl;
    return 0;    
    
    //悬崖 
    left_0_2:cout << "你一直往前走，越走你越发现不对劲，突然你听到了一声尖锐的狼嚎" << endl;
    cout << "你发现你闯入了狼窝，你立马拔腿就跑，可惜狼群紧追不舍" << endl;
    cout << "突然你一个不注意，一脚踏空，摔落了悬崖" << endl;
    cout << "GameOver~~游戏结束" << endl; 
    return 0;
    
    //瘴气林    
    left_1_2:cout << "你一直往前走，越走你越发现不对劲，突然你身遭冒起了白雾" << endl;
    cout << "你发现走进了瘴气迷雾中，你赶紧捂住口鼻，但为时已晚" << endl;
    cout << "你吸入了一定量的瘴气，头晕眼花，最终丢了性命" << endl;
    cout << "GameOver~~游戏结束" << endl;
    return 0;
    
    //森林    
    right_0_2:cout << "你一直往前走，走着走着，发现已然处在一片白桦树林中" << endl;
    cout << "此时天色尚早，你打算搜寻一下附近，果然不负努力，你找到了一桶汽油" << endl;
    cout << "你带上了汽油，并开始搭建营地，打算在此处过夜" << endl;
    cout << "你美美的睡了一觉，天亮后，背起包裹，你继续向前进发" << endl;
    goto end;
    
    end:cout << "你不知走了多久，突然发现自己走到了一片沙滩上，正好远处有一艘轮船，你欣喜若狂" << endl;
    if(flag[1] != 3) {
        cout << "你想点火堆弄出烟雾，引起轮船注意，可惜你没有打火机，无法点火堆" << endl;
        cout << "无奈的你，只能眼睁睁看着轮船远去" << endl;
        cout << "GameOver~~游戏结束" << endl;
        return 0;
    }
    
    cout << "你立马用打火机和汽油，点了个火堆，弄出了大量烟雾，希望能引起轮船注意" << endl;
    cout << "可是轮船毕竟比较远，没注意到这边的烟雾" << endl;
    
    if(flag[2] == 1) {
        cout << "你突然想到自己有一面镜子，可以通过反射阳光，将光线照到轮船上去" << endl;
        cout << "不一会，轮船上的人注意到了你反射的光线，轮船调转航向，向你靠近" << endl;
        cout << "你获救了，恭喜游戏通关" << endl;
        return 0;
    }
    
    cout << "你等了很久，轮船都没注意到你" << endl;
    cout << "无奈的你，只能眼睁睁看着轮船远去" << endl;
    cout << "GameOver~~游戏结束" << endl;
    
    return 0;
} 

