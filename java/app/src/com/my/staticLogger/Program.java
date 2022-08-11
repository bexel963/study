package com.my.staticLogger;

public class Program {

	public static void main(String[] args) {
		
		try {
            Logger.loadConfig(); // 설정파일 읽어오기 - (logLevel-INFORMATION, 파일명-static-log.txt)

            Logger.logDebug("Printed if the minimum log level is DEBUG");

            Logger.logInformation("Printed if the minimum log level is INFORMATION or lower");

            Logger.logWarning("Printed if the minimum log level is WARNING or lower");

            Logger.logError("Printed if the minimum log level is ERROR or lower");

            Logger.logCritical("Printed if the minimum log level is CRITICAL or lower");

            int x = 10;
            int y = 20;

            Logger.logDebug("%d * %d = %d",
                    x, y, x * y);

            Logger.logInformation("%d * %d = %d",
                    x, y, x * y);

            Logger.logWarning("%d * %d = %d",
                    x, y, x * y);

            Logger.logError("%d * %d = %d",
                    x, y, x * y);

            Logger.logCritical("%d * %d = %d",
                    x, y, x * y);

            Logger.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
	}

}
