package com.my.staticLogger;

public enum LogLevel {
	// 각 열거형 값에 정수를 대입하면 비교 연산자를 사용할 수 있다.
	DEBUG(0),
    INFORMATION(1),
    WARNING(2),
    ERROR(3),
    CRITICAL(4);

    private int level;

    public int getLogLevel() {
        return this.level;
    }

    private LogLevel(int level) {
        this.level = level;
    }
}
