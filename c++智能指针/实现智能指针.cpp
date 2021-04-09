#include <iostream>
#include <cstring>

using namespace std;

class CStudent
{
public:
    CStudent(const char *pszName);
    CStudent(CStudent &obj);
    ~CStudent();

    CStudent &operator=(CStudent &obj);

    void release();

    void Show()
    {
        cout << hex << (int &)m_pszName << m_pszName << endl;
    }

private:
    char * m_pszName;
    int * m_pcount;  //添加一个变量，记录内存的使用次数
};

CStudent::CStudent(const char *pszName)
{
    m_pszName = new char[256];
    m_pcount = new int;

    strcpy(m_pszName, pszName);
    *m_pcount = 1;
}

CStudent::CStudent(CStudent &obj)
{
    m_pszName = obj.m_pszName; //浅拷贝
    m_pcount = obj.m_pcount;
    (*m_pcount)++;
    //strcpy(m_pszName, obj.m_pszName);
}

CStudent::~CStudent()
{
    release();
}

CStudent &CStudent::operator=(CStudent &obj)
{
    if(obj.m_pszName ==  m_pszName) {
        return *this;
    }
    if (--(*m_pcount) == 0)
    {
        delete m_pszName;
        m_pszName = NULL;
        delete m_pcount;
    }
    m_pszName = obj.m_pszName; //浅拷贝
    m_pcount = obj.m_pcount;
    (*m_pcount)++;

    return *this;
}

void CStudent::release()
{
    if (m_pszName != NULL && --*m_pcount == 0)
    {
        //通过计数器来避免资源被重复释放
        delete m_pszName;
        m_pszName = NULL;
        delete m_pcount;
    }
}

int main(int argc, char *argv[])
{
    CStudent stu1("zhang san");
    CStudent stu2("li si");
    CStudent stu3 = stu2;

    stu1.Show();
    stu2.Show();
    stu3.Show();
    stu2.release();
    stu3.Show();
    return 0;
}