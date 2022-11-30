/*
	▶ 계산기 서버&클라이언트 어플리케이션 프로토콜 정의.
		
		- 클라이언트는 서버에 접속하자마자 피연산자의 개수정보를 1바이트 정수형태로 전달한다.
		- 클라이언트가 서버에 전달하는 정수 하나는 4바이트로 표현한다.
		- 정수를 전달한 다음에는 연산의 종류를 전달한다. 연산정보는 1바이트로 전달한다.
		- 문자 +, -, * 중 하나를 선택해서 전다한다.
		- 서버는 연산결과를 4바이트 정수의 형태로 클라이언트에게 전달한다.
		- 연산결과를 얻은 클라이언트는 서버와의 연결을 종료한다.
*/	