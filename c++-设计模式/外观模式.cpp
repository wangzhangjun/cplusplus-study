#include <iostream>
#include <vector>
#include <string>
using namespace std;

//电视
class TV{
    public:
        void on(){
            cout << "tv on" << endl;
        }
        void off(){
            cout << "tv off" << endl;
        }
};
//灯
class Lights
{
public:
    void on()
    {
        cout << "lights on" << endl;
    }
    void off()
    {
        cout << "lights off" << endl;
    }
};
//音箱
class Audio{
public:
    void on()
    {
        cout << "audio on" << endl;
    }
    void off()
    {
        cout << "audio off" << endl;
    }
};

class KTVModel{
    public:
      KTVModel(){
          pTv = new TV;
          pLights = new Lights;
          pAudio = new Audio;
      }
      ~KTVModel(){
          delete pTv;
          delete pLights;
          delete pAudio;
      }
      void runKTV(){
          pTv->on();
          pLights->off();
          pAudio->on();
      }
      void offkTV()
      {
          pTv->off();
          pLights->on();
          pAudio->off();
      }

    public:
        TV * pTv;
        Lights *pLights;
        Audio *pAudio;
};
void test()
{
    KTVModel *ktv = new KTVModel;
    ktv->runKTV();
    ktv->offkTV();
    delete ktv;
}
int main()
{
    test();
    return 0;
}