// < 인터페이스의 다형성 >

interface Parseable {
	
	public abstract void parse(String fileName);
}

class XMLParser implements Parseable {
	
	public void parse(String fileName) {
		System.out.println(fileName + "- XML parsing completed");
	}
}

class HTMLParser implements Parseable {
	
	public void parse(String fileName) {
		System.out.println(fileName + "- HTML parsing completed");
	}
}

class ParserManager {
	
	public static Parseable getParser(String fileName) {
		if(fileName.equals("XML")) {
			return new XMLParser();
		} else {
			return new HTMLParser();
		}
	}
}
public class Ex25 {

	public static void main(String[] args) {

		Parseable p = ParserManager.getParser("XML");
		p.parse("document");

		p = ParserManager.getParser("HTML");
		p.parse("document2");
	}

}
