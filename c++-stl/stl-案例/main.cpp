#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>

class Player {
public:
    std::string name;
    int score[3]; //3轮比赛的分数
};

void Create_Player(std::map<int,Player> &mPlist, std::vector<int> &v)
{
    std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(str.begin(), str.end(),g);

    for(int i = 0; i < 24; i++) {
        Player p;
        p.name = "选手";
        p.name += str[i];
        int uid = 100 + i;
        mPlist.insert(std::make_pair(uid, p));
        v.push_back(uid);
    }
}

//选手抽签，随机一下
void Set_Random(std::vector<int> &v)
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(),g);
}

void SET_Score(int index, std::vector<int> &vin, std::map<int,Player> &mPlist, std::vector<int> &vout)
{
    //第一个int是分数，
    //第二个int是编号
    //第三个，内建函数  从大到小
    //multimap<int, int> mGroup;  //默认是从小到大排序
    std::multimap<int ,int, std::greater<int>> mGroup;
    int groupIndex = 0;
    for(auto it = vin.begin(); it != vin.end(); ++it) {
        //打分，为了去掉最高分和最低分，使用deque
        std::deque<int> dScore;
        for (int i = 0; i < 10; i++) {
            int score = rand() % 41 + 60;
            dScore.push_back(score);
        }
        //排序
        std::sort(dScore.begin(), dScore.end());
        //去除最高分 最低分
        dScore.pop_back();
        dScore.pop_front();
        //求平均分
        int totalScore = accumulate(dScore.begin(), dScore.end(), 0);
        int avgScore = totalScore / dScore.size();
        mPlist[*it].score[index-1] = avgScore;//向map容器将得分存储选手的分数，下标从0开始

        //multimap容器可自动排序，后面会选出前三名
        mGroup.insert(std::make_pair(avgScore, *it));
        groupIndex++;
        if (groupIndex % 6 == 0) {  //6的倍数是一组
            int numindex = 0;
            for(auto mit = mGroup.begin(); mit != mGroup.end(); ++mit) {
                if(numindex >= 3) break;
                vout.push_back((*mit).second);//前三名加入晋级名单
                numindex++;
            }
            mGroup.clear();//每一小组比完清空，存下一组数据比赛
        }
    }
}
//结果
void Show_Good_Player(int index, std::vector<int>& v, std::map<int, Player>& mPlist) {

    std::cout << "第" << index << "轮晋级名单：" << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        std::cout << "选手：" << mPlist[*it].name << "  分数：" << mPlist[*it].score[index-1] << std::endl;
    }

}
int main() {

    std::map<int, Player> mPlist;//根据编号存放选手信息
    //比赛列表
    std::vector<int> v1; //初始是所有的选手id
    std::vector<int> v2; //第一轮比赛晋级列表
    std::vector<int> v3; //第二轮比赛晋级列表
    std::vector<int> v4; //第三轮比赛晋级列表

    //创建选手
    Create_Player(mPlist,v1);
    //第一轮比赛
    Set_Random(v1);
    SET_Score(1, v1, mPlist, v2);
    Show_Good_Player(1,v2,mPlist);
    //第二轮比赛
    Set_Random(v2);
    SET_Score(2, v2, mPlist, v3);
    Show_Good_Player(2,v3,mPlist);
    //第三轮比赛
    Set_Random(v3);
    SET_Score(3, v3, mPlist, v4);
    Show_Good_Player(3,v4,mPlist);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}