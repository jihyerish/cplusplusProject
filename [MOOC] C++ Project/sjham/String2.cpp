#include <iostream>
#include <cstring>>

using namespace std;

//  String 클래서 메모리 형태

//  2번) 문자열을 관리하는 관리객체를 만드는 모델
class Str_ptr {
    char* buff;
    int ref;
public:
    Str_ptr(const char* s) {
        int size = strlen(s) + 1;
        buff = new char[size];
        strcpy_s(buff, size, s);

        ref = 1;;
    }
    ~Str_ptr() {
        delete[] buff;
    }
    const char* readBuff() {
        return buff;
    }
    int& readRef() {
        return ref;
    }
};


class String {
    Str_ptr*   obj;
public:
    String(const char* s){
        obj = new Str_ptr(s);
    }
    ~String() {
        if (obj != nullptr && --(obj->readRef()) == 0){
            delete obj;
        }
    }    
    String(const String& s) {
        this->obj = s.obj;
        ++(this->obj->readRef());
    }
    String() {
        obj = nullptr;
    }
    String& operator=(const String& s) {
        if (this == &s)
            return *this;

        if (--(this->obj->readRef()) == 0)
            delete this->obj;

        this->obj = s.obj;
        ++(this->obj->readRef());

        return *this;
    }
    friend ostream& operator<<(ostream& os, const String& s);
};

ostream& operator<<(ostream& os, const String& s)
{
    if (s.obj != nullptr)
        os << s.obj->readBuff();
    return os;
}


int main()
{
    // 1단계. 생성자, 소멸자, 화면 출력
    String s1 = "hello";
    cout << s1 << endl;
   
    // 2단계. 복사 생성자
    String s2 = s1;
    cout << s2 << endl;
    
    // 3단계. 대입연산자
    String s3 = "student";
    s3 = s1;
    cout << s3 << endl;
    
    // 4단계. 자신과의 대입
    s1 = s1;
    cout << s1 << endl;

    // 5단계. 디폴트 생성자
    String s4;
    cout << s4 << endl;
}
