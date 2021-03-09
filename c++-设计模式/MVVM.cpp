#include <iostream>
#include <functional>
#include <map>
#include <string>

//模拟数据绑定
std::map<std::string, std::function<void(std::string)> > viewChange;
std::map<std::string, std::function<void(std::string)> > modelChange;
std::string properName = "name";

class View
{
    public:
        explicit View(std::string properName, std::string data) : _data(data), _properName(properName) {
            viewChange[_properName] = std::bind(&View::setData, this, std::placeholders::_1);
        }
        void ViewChange(std::string data)
        {
            modelChange[_properName](data);
        }
        void printViewData() {
            std::cout << this->_data << std::endl;
        }
    private:
        std::string _data;
        std::string _properName;
        void setData(std::string data){
            this->_data = data;
        }
};

class Model
{
    public:
        explicit Model(std::string properName, std::string data) : _data(data), _properName(properName){
            modelChange[_properName] = std::bind(&Model::setData, this, std::placeholders::_1);
        }
        void ModelChange(std::string data){
            viewChange[_properName](data);
        }
        void printModelData(){
            std::cout << this->_data << std::endl;
        }

    private: 
        std::string _data;
        std::string _properName;
        void setData(std::string data){
            this->_data = data;
        }
};

class ViewModel
{
    public:
        explicit ViewModel() : _model("name", "zhjwangModel"), _view("name", "zhjwangView"){}
        void changeModel(std::string data)
        {
            _model.ModelChange(data);
        }
        void changeView(std::string data){
            _view.ViewChange(data);
        }
    private:
        Model _model;
        View _view;
};

int main()
{
    //一开始会改变map中的函数绑定，因为我们都是在初始化的时候做的std::bind，而ViewModel中也要初始化两个对象，所以一开始std::bind的是ViewModel中的两个对象。后面又会改变
    ViewModel viewmodel; //这个必须写在前面，一开始写在匿名对象，ViewModel().changModel，你会发现结果不对，是因为std::bind的时机在初始化的时候，有可能绑定不同的this指针上

    auto view = View(properName, "zhjwang");
    view.printViewData();
    viewmodel.changeModel("laowang"); //模拟model改变时，通知到ViewModel
    view.printViewData();

    auto model = Model(properName, "aaa");
    model.printModelData();
    viewmodel.changeView("bbb");  //模拟view改变时，通知到model
    model.printModelData();

    return 0;
}