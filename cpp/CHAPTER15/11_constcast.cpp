/*
	- C의 데이터형 변환 연산자는 너무 느슨하다.
				
				struct Data
				{
					double data[200];
				};

				struct Junk
				{
					int junk[100];
				};

				Data d = { 2.5e33, 3.5e-19, 20.e32 };

				char* pch = (char*)(&d);		// 1) 주소를 문자열로 변환
				char ch = (char)(&d);			// 2) 주소를 문자로 변환
				Junk* pj = (Junk*)(&d);			// 3) Junk 포인터로 변환

		: 위 세 가지 형변환은 어느 것도 이치에 맞지 않지만, C에서는 세 가지가 모두 허용된다.
		  이러한 느슨함을 해결하기 위해 일반적인 데이터형 변환을 허용하는 것을 공고히 하고, 데이터형 변환 과정을 더욱 엄격하게 규정하는
		  4개의 데이터형 변환 연산자를 추가햐였다.
				1) dynamic_cast
				2) const_cast   - p.1196
				3) static_cast
				4) reinterpret_cast
				
*/