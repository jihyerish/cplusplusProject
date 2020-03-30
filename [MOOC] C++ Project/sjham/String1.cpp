#include <iostream>
#include <cstring>

using namespace std;

//  String 클래서 메모리 형태

//  1번) String 클래스가 직접 참조계수를 가리키는 포인터를 관리하는 모델
class String {
    char*   buff;
    int*    ref;
public:
    String(const char* s){
        int size = strlen(s) + 1;
        buff = new char[size];
        strcpy_s(buff, size, s);

        ref = new int;
        *ref = 1;
    }
    String(const String& s) : buff(s.buff), ref(s.ref) {
        ++(*ref);
    }
    String() {
        buff = nullptr;
        ref = nullptr;
    }
    ~String() {
        if (ref == nullptr)
            return;
        if (--(*ref) == 0) {
            delete[] buff;
            delete ref;
        }
    };
    String& operator=(const String& s) {
        if (this == &s)
            return *this;
        if (--(*(this->ref)) == 0) {
            delete[] this->buff;
            delete this->ref;
        }

        this->buff = s.buff;
        this->ref = s.ref;
        ++(*(this->ref));

        return *this;
    }
    friend ostream& operator<<(ostream& os, const String& s);
};

ostream& operator<<(ostream& os, const String& s)
{
    if (s.buff != nullptr)
        os << s.buff;
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
