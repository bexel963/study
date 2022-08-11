package com.my.staticLogger;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.Instant;
import java.util.List;


// 프로그램 실행 중 발생하는 로그를 외부 파일로 출력하는 클래스
public class Logger {
	
	// 로그 설정을 읽어 올 파일 설정.
	private static final String CONFIG_FILENAME = "logger-config.txt";
	// 지정한 logLevel 이상의 logLevel을 가지고있는 메시지들만 파일에 저장한다.
	//	= WARNING(2) 보다 긴급도가 낮은거는 파일에 메시지를 적지 않는다.
    private static LogLevel logLevel = LogLevel.WARNING;
    // 설정을 읽었는지 확인하는 변수
    private static boolean isConfigLoaded = false;
    // 스트림에 텍스트를 쓸 수 있게 해 줌
    private static BufferedWriter bufferOut;

    // 순수하게 정적으로만 사용할 클래스로 설계할 것이기 때문에 객체를 못만들게 하기위해 생성자에 접근제어자를 붙여준다.
    private Logger() {
    }
    // 파일로부터 설정을 읽어오는 메서드
    public static void loadConfig() {
        try {
        	// Logger.class가 위치한 디렉터리의 경로를 가져옴.
            String classPath = getClassPath();
            Path loggerConfigPath = Paths.get(classPath, CONFIG_FILENAME);

            File configFile = new File(loggerConfigPath.toString());
            // 기본 출력 파일 이름. 설정 파일에 출력 파일 이름이 지정되어 있지 않으면 이 이름을 대신 사용.
            String outputFilename = "log.txt";

            // logger-config.txt가 존재하고, 이것이 파일이면..
            if (configFile.isFile()) {
            	// 그 파일의 모든 내용을 읽어옴.
                List<String> lines = Files.readAllLines(loggerConfigPath, StandardCharsets.UTF_8);

                for (String line : lines) {
                    String[] splits = line.split("=");

                    switch (splits[0]) {
                        case "loglevel":
                            logLevel = LogLevel.valueOf(splits[1]);
                            break;

                        case "output":
                            outputFilename = splits[1];
                            break;

                        default:
                            throw new IllegalArgumentException("Unknown configuration setting: " + splits[0]);
                    }
                }
            }

            Path path = Paths.get(classPath, outputFilename);
            String outputPath = path.toString();
            // 설정을 읽은 뒤 BufferWriter 객체를 만들고 파일에 작성을 한다.
            bufferOut = new BufferedWriter(new FileWriter(outputPath));

            isConfigLoaded = true;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    // BufferedWriter는 언매니지드 리소스라서 GC가 자동으로 닫아주지 않음.
    // 따러서 이건 직접 닫아줄 메서드가 필요.
    public static void close() {
        if (bufferOut != null) {
            try {
                bufferOut.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public static void logDebug(String message, Object... args) {
        assert (isConfigLoaded) : "Configuration not loaded";
        writeToFile(LogLevel.DEBUG, message, args);
    }

    public static void logInformation(String message, Object... args) {
        assert (isConfigLoaded) : "Configuration not loaded";
        writeToFile(LogLevel.INFORMATION, message, args);
    }

    public static void logWarning(String message, Object... args) {
        assert (isConfigLoaded) : "Configuration not loaded";
        writeToFile(LogLevel.WARNING, message, args);
    }

    public static void logError(String message, Object... args) {
        assert (isConfigLoaded) : "Configuration not loaded";
        writeToFile(LogLevel.ERROR, message, args);
    }

    public static void logCritical(String message, Object... args) {
        assert (isConfigLoaded) : "Configuration not loaded";
        writeToFile(LogLevel.CRITICAL, message, args);
    }

    // 메시지를 bufferOut에 작성하는 메서드
    private static void writeToFile(LogLevel logLevel, String message, Object... args) {

        if (!isConfigLoaded || Logger.logLevel.getLogLevel() > logLevel.getLogLevel()) {
            return;
        }

        try {
            String log = String.format("[%s] %s: %s",
                    Instant.now().toString(),
                    logLevel.toString(),
                    String.format(message, args));
            bufferOut.write(log);
            bufferOut.newLine();
            bufferOut.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String getClassPath() {
        File f = new File(Logger.class.getProtectionDomain().getCodeSource().getLocation().getPath());
        String packageName = Logger.class.getPackageName();
        packageName = packageName.replace('.', '/');

        Path p = Paths.get(f.getPath(), packageName);

        return p.toAbsolutePath().normalize().toString();
    }
}
