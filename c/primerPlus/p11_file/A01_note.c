/*
	- fprint(), fscanf()
		: 적당한 파일을 나타내는 부가적인 첫 번째 전달인자를 요구한다는 것만 제외하고 printf(), scanf()와 같은 방식으로 동작한다.

	- fgets()
		: 첫 번째 인자 -> 입력을 저장할 주소
		  두 번째 인자 -> 입력 문자열의 최대 크기를 나타내는 정수
		  세 번째 인자 -> 읽을 파일을 가리키는 파일 포인터
		: 상한보다 하나 적은 수의 문자들을 읽을 때까지 또는 파일 끝을 만날 때까지 문자들을 읽되, 첫 개행 문자까지 읽는다.
		  그리고 읽은 것이 문자열이 되도록 종결 널 문자를 추가한다.
		  상한은 문자들의 최대 개수에 종결 널 문자를 더한 것이다.
		  fgets()가 상한에 도달하기 전에 전체 라인을 읽는다면, 널 문자 바로 앞에 라인의 끝을 표시하는 개행 문자를 추가한다.
		  fgets()는 EOF를 만나면 NULL값을 반환한다.
		  이 값을 사용하여 파일의 끝에 도달했는지 검사할 수 있다.

	- fputs()
		: 첫 번째 인자 -> 문자열의 주소
		  두 번째 인자 -> 파일 포인터
		: 그 주소에 들어 있는 문자열을 파일 포인터가 가리키는 파일에 기록한다.
		  출력할 때 개행 문자를 덧붙이지 않는다.
		: fgets()는 개행 문자를 유지하고, fputs()는 개행 문자를 덧붙이지 않기 때문에, 이들은 서로 협력하여 잘 동작한다.

	- fseek()
		: 첫 번째 인자 -> 처리할 파일을 가리키는 FILE포인터. (이 파일은 fopen()에 의해 미리 열려 있어야 한다.)
		  두 번째 인자 -> 오프셋 (시작 위치로부터 얼마나 멀리 가야 하는지 알려 준다.)			
				: 이 전달 인자는 long형 값이어야 한다.
				  양수(앞으로 간다.)
				  음수(뒤로 간다.)
				  0(현재 위치에 머문다.)
		  세 번째 인자 -> 모드 (시작 위치를 나타낸다.)
				 <모드>      <시작위치>
				SEEK_SET	파일의 시작	
				SEEK_CUR	현재 위치
				SEEK_END	파일의 끝
		: 파일을 배열처럼 다룰 수 있게 한다.
		  fopen()에 의해 열려진 파일에 들어 있는 특정 바이트로 직접 이동할 수 있게 해 준다.
		: fseek()는 성공하면 0을 리턴하고, 파일의 경계를 벗어나려는 시도와 같은 에러가 있으면 -1을 리턴한다.

		: seek(fp, 0L, SEEK_SET);		// 파일의 시작으로 간다.
		  seek(fp, 10L, SEEK_SET);		// 파일의 시작에서 10바이트 앞으로 간다.
		  seek(fp, 2L, SEEK_CUR);		// 현재 위치에서 2바이트 앞으로 간다.
		  seek(fp, 0L, SEEK_END);		// 파일의 끝으로 간다.
		  seek(fp, -10L, SEEK_END);		// 파일의 끝에서 10바이트 뒤로 간다.
		    
	- ftell()
		: 파일에서의 현재 위치를 long형 값으로 리턴한다.

	- 요약
		: 일반적으로 표준 입출력을 사용하는 첫 단계는 fopen()으로 파일을 여는 것이다.
		  (stdin, stdout, stderr 파일들은 자동으로 열린다.)
		  fopen()은 파일을 열 뿐만 아니라 버퍼(일기, 쓰기 모드를 위한 두개의 버퍼)도 설정한다.
		  fopen()은 파일과 버퍼에 관한 데이터가 들어 있는 데이터 구조체를 설정한다.
		  그리고 다른 함수들이 그 구조체를 어디에서 찾아야 하는지 알 수 있도록 그 구조체를 가리키는 포인터를 리턴한다.
		  이 값이 fp라는 이름의 포인터 변수에 대입되었다고 가정했을 때, 이것을 fopen()가 "하나의 스트림을 열었다" 라고 한다.
		  파일을 텍스트 모드로 열면, 텍스트 스트림을 얻고, 바이너리 모드로 열면, 바이너리 스트림을 얻는다.
		: 데이터 구조체에는 스트림에서의 현재 위치를 나타내는 파일 위치 표시자를 가지고 있다.
		  또한 에러와 파일 끝을 나타내는 지시자, 버퍼의 시작을 알리는 포인터, 파일 식별자, 버퍼 안으로 실제로 복사된 바이트 수에 해당하는
		  카운트도 가지고 있다.
		: 최초의 입력 함수 호출은, 파일로부터 데이터를 버퍼에 채울 뿐만 아니라, fp가 가리키는 구조체에 있는 값들을 설정한다.
		  특별히 스트림 안에서의 현재 위치, 버퍼 안으로 복사된 바이트 수가 설정된다.
		  버퍼 크기는 컴파일러에 따라 다르지만 일반적으로 512바이트 또는 그것의 배수인 4,096바이트 또는 16,384바이트 이다.
		: 데이터 구조체와 버퍼가 초기화된 후, 입력 함수는 데이터를 버퍼로부터 읽는다.
		  이 과정에서 파일 위치 표시자는 마지막으로 읽은 문자 바로 다음 문자를 가리키도록 설정된다.
		  stdio.h 계열의 모든 입력 함수들이 같은 버퍼를 사용하기 때문에, 그들 중 한 함수의 호출은 직전에 이루어진 어느 함수 호출이 행동을 끝낸
		  위치에서 부터 시작한다.
		  버퍼에 있는 모든 문자들을 읽었다는 것을 알게 되었을 때, 입력 함수는 버퍼 크기 만큼의 그 다음 데이터 덩어리를 파일로부터 버퍼로
		  복사하도록 요청한다.
		  이와 같은 방법으로, 입력 함수들은 파일의 끝까지 모든 내용을 읽을 수 있다.
		  마지막 버퍼만큼의 데이터 덩어리에 있는 마지막 문자를 읽은 후에, 입력 함수는 파일 끝 지시자를 참으로 설정한다.
		  그러고 나면 입력 함수의 다음 번 호출은 EOF를 리턴한다.
		: 이와 마찬가지로 출력 함수도 버퍼에 저장한다. 버퍼가 가득 찼을 때, 데이터는 파일로 복사된다.
*/