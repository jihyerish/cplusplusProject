#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // STL의 함수 

using namespace std;

int main()
{
	vector<int> v;

	// 1. 난수를 10개 구해서 v에 넣으세요
	int cmd = 0;

	while (1)
	{
		cin >> cmd;
		// 2. cmd가 1이면 v의 모든 내용을 화면에 출력해 주세요

		// 3. cmd가 2이면 v를 오름 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
		// 비교 정책으로 함수 객체를 사용해서 만들어 주세요

		// 4. cmd가 3이면 v를 내림 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
		// 비교 정책으로 람다 표현식을 사용해 주세요

		// 5. cmd가 4이면 또 다른 숫자를 하나 입력 받으세요.
		// 해당 숫자가 vector에 있으면 제거한후 vector를 다시 출력해 주세요

		// 6. cmd가 5이면 또 다른 숫자를 하나 입력 받으세요.
		// 해당 숫자를 찾아서 0으로 변경한후 vector를 다시 출력해 주세요

		// 7. cmd가 6이면 v의 size를 20개로 늘린 후 v의 내용을 출력해 주세요
	}
}
