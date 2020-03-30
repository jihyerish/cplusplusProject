#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // STL의 함수 
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	vector<int> v;

	// 1. 난수를 10개 구해서 v에 넣으세요
	int cmd = 0;
	srand((unsigned int)time(NULL));
	for (auto i = 0; i < 10; i++) {
		v.push_back(rand()%100);
	}

	while (1)
	{
		cin >> cmd;
		bool print = false;

		// 2. cmd가 1이면 v의 모든 내용을 화면에 출력해 주세요
		if (cmd == 1)
			print = true;
		// 3. cmd가 2이면 v를 오름 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
		// 비교 정책으로 함수 객체를 사용해서 만들어 주세요
		else if (cmd == 2) {
			less<int> l;
			sort(v.begin(), v.end(), l);
			print = true;
		}
		// 4. cmd가 3이면 v를 내림 차순으로 정렬한 후 v의 내용을 화면 출력해 주세요
		// 비교 정책으로 람다 표현식을 사용해 주세요
		else if (cmd == 3) {
			sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
			print = true;
		}
		// 5. cmd가 4이면 또 다른 숫자를 하나 입력 받으세요.
		// 해당 숫자가 vector에 있으면 제거한후 vector를 다시 출력해 주세요
		else if (cmd == 4) {
			int val = 0;
			cin >> val;
			auto it = remove(v.begin(), v.end(), val);
			if (it != v.end()) {
				v.erase(it, v.end());
				print = true;
			}
		}
		// 6. cmd가 5이면 또 다른 숫자를 하나 입력 받으세요.
		// 해당 숫자를 찾아서 0으로 변경한후 vector를 다시 출력해 주세요
		else if (cmd == 5) {
			int val = 0;
			cin >> val;
			replace(v.begin(), v.end(), val, 0);
			print = true;
		}
		// 7. cmd가 6이면 v의 size를 20개로 늘린 후 v의 내용을 출력해 주세요
		else if (cmd == 6) {
			for (auto i = v.size(); i < 20; i++) {
				v.push_back(rand() % 100);
			}
			print = true;
		}

		if (print) {
			for (auto n : v)
				cout << n << ", ";
			cout << endl;
		}
	}
}
