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


// ���α׷� ���� �� �߻��ϴ� �α׸� �ܺ� ���Ϸ� ����ϴ� Ŭ����
public class Logger {
	
	// �α� ������ �о� �� ���� ����.
	private static final String CONFIG_FILENAME = "logger-config.txt";
	// ������ logLevel �̻��� logLevel�� �������ִ� �޽����鸸 ���Ͽ� �����Ѵ�.
	//	= WARNING(2) ���� ��޵��� �����Ŵ� ���Ͽ� �޽����� ���� �ʴ´�.
    private static LogLevel logLevel = LogLevel.WARNING;
    // ������ �о����� Ȯ���ϴ� ����
    private static boolean isConfigLoaded = false;
    // ��Ʈ���� �ؽ�Ʈ�� �� �� �ְ� �� ��
    private static BufferedWriter bufferOut;

    // �����ϰ� �������θ� ����� Ŭ������ ������ ���̱� ������ ��ü�� ������� �ϱ����� �����ڿ� ���������ڸ� �ٿ��ش�.
    private Logger() {
    }
    // ���Ϸκ��� ������ �о���� �޼���
    public static void loadConfig() {
        try {
        	// Logger.class�� ��ġ�� ���͸��� ��θ� ������.
            String classPath = getClassPath();
            Path loggerConfigPath = Paths.get(classPath, CONFIG_FILENAME);

            File configFile = new File(loggerConfigPath.toString());
            // �⺻ ��� ���� �̸�. ���� ���Ͽ� ��� ���� �̸��� �����Ǿ� ���� ������ �� �̸��� ��� ���.
            String outputFilename = "log.txt";

            // logger-config.txt�� �����ϰ�, �̰��� �����̸�..
            if (configFile.isFile()) {
            	// �� ������ ��� ������ �о��.
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
            // ������ ���� �� BufferWriter ��ü�� ����� ���Ͽ� �ۼ��� �Ѵ�.
            bufferOut = new BufferedWriter(new FileWriter(outputPath));

            isConfigLoaded = true;
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    // BufferedWriter�� ��Ŵ����� ���ҽ��� GC�� �ڵ����� �ݾ����� ����.
    // ������ �̰� ���� �ݾ��� �޼��尡 �ʿ�.
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

    // �޽����� bufferOut�� �ۼ��ϴ� �޼���
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
